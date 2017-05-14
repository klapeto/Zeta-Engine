--[[
Copyright (c) Jérôme Vuarand

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
]]--

local _M = {}
local _NAME = ... or 'test'

local io = require 'io'
local os = require 'os'
local table = require 'table'
local string = require 'string'

_M.groupsize = 10000

local dumptablecontent

local tkeys = {
	boolean = true,
	number = true,
	string = true,
}
local tvalues = {
	boolean = true,
	number = true,
	string = true,
	table = true,
}

local function dumptable(table, write, level)
	-- prefix and suffix
	local mt = getmetatable(table)
	local prefix = mt and mt.__dump_prefix
	local suffix = mt and mt.__dump_suffix
	if type(prefix)=='function' then
		prefix = prefix(table)
	end
	prefix = prefix or ""
	if type(suffix)=='function' then
		suffix = suffix(table)
	end
	suffix = suffix or ""
	
	-- count keys
	local nkeys = 0
	for k,v in pairs(table) do
		nkeys = nkeys + 1
		local tk,tv = type(k),type(v)
		if not tkeys[tk] then
			return nil,"unsupported key type '"..tk.."'"
		end
		if not (tvalues[tv] or getmetatable(v) and getmetatable(v).__dump) then
			return nil,"unsupported value type '"..tv.."'"
		end
	end
	
	-- if too many keys, use multiple closures
	if nkeys > _M.groupsize then
		local success,err
		success,err = write(((prefix..[[
(function()
	local t = { function() return {
]]):gsub("\n", "\n"..("\t"):rep(level))))
		if not success then return nil,err end
		success,err = dumptablecontent(table, write, level+2, _M.groupsize, ("\t"):rep(level+1)..'} end, function() return {\n')
		if not success then return nil,err end
		success,err = write((([[
	} end }
	local result = {}
	for _,f in ipairs(t) do
		for k,v in pairs(f()) do
			result[k] = v
		end
	end
	return result
end)()]]..suffix):gsub("\n", "\n"..("\t"):rep(level))))
		if not success then return nil,err end
		return true
	elseif nkeys==0 then
		local success,err = write(prefix.."{ }"..suffix)
		if not success then return nil,err end
		return true
	else
		local success,err
		success,err = write(prefix.."{\n")
		if not success then return nil,err end
		success,err = dumptablecontent(table, write, level+1)
		if not success then return nil,err end
		success,err = write(("\t"):rep(level).."}"..suffix)
		if not success then return nil,err end
		return true
	end
end

local function dumpvalue(v, write, level)
	local mt = getmetatable(v)
	local dump = mt and mt.__dump
	if type(dump)=='function' then
		dump = dump(v)
	end
	if dump~=nil then
		return write(dump)
	end
	local t = type(v)
	if t=='string' then
		return write('"'..v:gsub('[%z\1-\31\127"\\]', function(c)
			if c=='\\' then
				return '\\\\'
			elseif c=='"' then
				return '\\"'
			elseif c=='\t' then
				return '\\t'
			elseif c=='\n' then
				return '\\n'
			elseif c=='\r' then
				return '\\r'
			else
				return string.format('\\%03d', string.byte(c))
			end
		end)..'"')
	elseif t=='number' then
		if v~=v then -- nan
			return write('0/0')
		elseif v==1/0 then -- +inf
			return write('1/0')
		elseif v==-1/0 then -- -inf
			return write('-1/0')
		else
			return write(tostring(v))
		end
	elseif t=='boolean' then
		if v then
			return write('true')
		else
			return write('false')
		end
	elseif t=='nil' then
		return write('nil')
	elseif t=='table' then
		return dumptable(v, write, level)
	else
		return nil,"unsupported value type '"..t.."'"
	end
end

local lua_keywords = {
	['and'] = true,
	['break'] = true,
	['do'] = true,
	['else'] = true,
	['elseif'] = true,
	['end'] = true,
	['false'] = true,
	['for'] = true,
	['function'] = true,
	['if'] = true,
	['in'] = true,
	['local'] = true,
	['nil'] = true,
	['not'] = true,
	['or'] = true,
	['repeat'] = true,
	['return'] = true,
	['then'] = true,
	['true'] = true,
	['until'] = true,
	['while'] = true,
}

local function dumppair(k, v, write, level)
	local success,err
	success,err = write(("\t"):rep(level))
	if not success then return nil,err end
	local assignment = " = "
	local tk = type(k)
	if tk=='string' and k:match("^[_a-zA-Z][_a-zA-Z0-9]*$") and not lua_keywords[k] then
		success,err = write(k)
		if not success then return nil,err end
	elseif tk=='string' or tk=='number' or tk=='boolean' then
		success,err = write('[')
		if not success then return nil,err end
		success,err = dumpvalue(k, write, level)
		if not success then return nil,err end
		success,err = write(']')
		if not success then return nil,err end
	elseif tk=='nil' then
		-- we are in the array part
		assignment = ""
	else
		error("unsupported key type '"..type(k).."'")
	end
	success,err = write(assignment)
	if not success then return nil,err end
	success,err = dumpvalue(v, write, level)
	if not success then return nil,err end
	success,err = write(",\n")
	if not success then return nil,err end
	return true
end

local function keycomp(a, b)
	local ta,tb = type(a),type(b)
	if ta==tb then
		return a < b
	else
		return ta=='string'
	end
end

local tsort = table.sort
local function dumptablesection(table, write, level, keys, state)
	-- sort keys
	local skeys = {}
	for k in pairs(keys) do skeys[#skeys+1] = k end
	tsort(skeys, keycomp)
	-- dump pairs
	for _,k in pairs(skeys) do
		local v = table[k]
		if state then
			state.i = state.i + 1
			if state.i % state.size == 0 then
				local success,err = write(state.sep)
				if not success then return nil,err end
			end
		end
		local success,err = dumppair(k, v, write, level)
		if not success then return nil,err end
	end
	return true
end

local function dumptableimplicitsection(table, write, level, state)
	for k,v in ipairs(table) do
		if state then
			state.i = state.i + 1
			if state.i % state.size == 0 then
				local success,err = write(state.sep)
				if not success then return nil,err end
			end
		end
		local success,err
		if state then
			success,err = dumppair(k, v, write, level)
		else
			success,err = dumppair(nil, v, write, level)
		end
		if not success then return nil,err end
	end
	return true
end

function dumptablecontent(table, write, level, groupsize, groupsep)
	-- order of groups:
	-- - explicit keys
	--   - keys with simple values
	--   - keys with structure values (table with only explicit keys)
	--   - keys with mixed values (table with both exiplicit and implicit keys)
	--   - keys with array values (table with only implicit keys)
	-- - set part (explicit key with boolean value)
	-- - implicit keys
	-- order within a group:
	-- - string keys in lexicographic order
	-- - numbers in increasing order
	-- :TODO: handle tables as keys
	-- :TODO: handle sets
	
	-- extract implicit keys
	local implicit = {}
	for k,v in ipairs(table) do
		implicit[k] = true
	end
	-- categorize explicit keys
	local set = {}
	local simples = {}
	local structures = {}
	local mixeds = {}
	local arrays = {}
	for k,v in pairs(table) do
		if not implicit[k] then
			if type(v)=='table' then
				if v[1]==nil then
					structures[k] = true
				else
					local implicit = {}
					for k in ipairs(v) do
						implicit[k] = true
					end
					local mixed = false
					for k in pairs(v) do
						if not implicit[k] then
							mixed = true
							break
						end
					end
					if mixed then
						mixeds[k] = true
					else
						arrays[k] = true
					end
				end
			else
				simples[k] = true
			end
		end
	end
	
	local success,err,state
	if groupsize and groupsep then
		state = {
			i = 0,
			size = groupsize,
			sep = groupsep,
		}
	end
	success,err = dumptablesection(table, write, level, simples, state)
	if not success then return nil,err end
	success,err = dumptablesection(table, write, level, structures, state)
	if not success then return nil,err end
	success,err = dumptablesection(table, write, level, mixeds, state)
	if not success then return nil,err end
	success,err = dumptablesection(table, write, level, arrays, state)
	if not success then return nil,err end
	success,err = dumptableimplicitsection(table, write, level, state)
	if not success then return nil,err end
	return true
	
	--[[
	local done = {}
	for k,v in ipairs(table) do
		local success,err = dumppair(nil, v, write, level)
		if not success then return nil,err end
		done[k] = true
	end
	for k,v in pairs(table) do
		if not done[k] then
			local success,err = dumppair(k, v, write, level)
			if not success then return nil,err end
			done[k] = true
		end
	end
	return true
	--]]
end

local function ref_helper(processed, pending, cycles, refs, value, parent, key)
	if type(value)=='table' then
		local vrefs = refs[value]
		if not vrefs then
			vrefs = {
				value = value,
			}
			refs[value] = vrefs
		end
		table.insert(vrefs, {parent=parent, key=key})
		if pending[value] then
			cycles[value] = true
			return
		end
		if not processed[value] then
			processed[value] = true
			pending[value] = true
			for k,v in pairs(value) do
				ref_helper(processed, pending, cycles, refs, k, value, nil)
				ref_helper(processed, pending, cycles, refs, v, value, k)
			end
			pending[value] = nil
			-- only assign an index once the children have one
			refs.last = refs.last + 1
			vrefs.index = refs.last
		end
	end
end

local prefixes = {
	table = 't',
	['function'] = 'f',
	thread = 'c',
	userdata = 'u',
}

local function check_refs(root)
	local processed = {}
	local pending = {}
	local cycles = {}
	local refs = {last=0}
	ref_helper(processed, pending, cycles, refs, root, nil, nil)
	refs.last = nil
	for value,vrefs in pairs(refs) do
		if #vrefs==1 then
			refs[value] = nil
		end
	end
	return cycles,refs
end

local function dumprefs(refs, file, last)
	if not last then last = {0} end
	if next(refs) then
		-- order the values from last to first discovered according to .index
		local refs2 = {}
		for value,vrefs in pairs(refs) do
			assert(vrefs.value == value)
			table.insert(refs2, vrefs)
		end
		table.sort(refs2, function(a, b) return a.index < b.index end)
		-- generate an id
		for i,vrefs in ipairs(refs2) do
			vrefs.id = prefixes[type(vrefs.value)]..tostring(i)
		end
		-- patch references
		for _,vrefs in ipairs(refs2) do
			local link = setmetatable({}, {__dump=vrefs.id})
			for _,ref in ipairs(vrefs) do
				assert(ref.parent, "reference has no parent") -- this should trigger a cycle error earlier
				assert(ref.key~=nil, "not yet implemented") -- tables as keys
				ref.parent[ref.key] = link
			end
		end
		-- dump shared values
		for _,vrefs in ipairs(refs2) do
			local success,err = file:write("local "..vrefs.id.." = ")
			if not success then return nil,err end
			success,err = dumpvalue(vrefs.value, function(...) return file:write(...) end, 0)
			if not success then return nil,err end
			success,err = file:write("\n")
			if not success then return nil,err end
		end
	end
	return true
end

function _M.tostring(value)
	local cycles,refs = check_refs(value)
	if next(cycles) then
		return nil,"cycles in value"
	end
	if next(refs) then
		return nil,"mutable values (tables) with multiple references"
	end
	local t = {}
	local success,err = dumpvalue(value, function(str) table.insert(t, str); return true end, 0)
	if not success then return nil,err end
	return table.concat(t)
end

function _M.tofile(value, file)
	local cycles,refs = check_refs(value)
	if next(cycles) then
		return nil,"cycles in value"
	end
	local filename
	if type(file)=='string' then
		filename = file
		file = nil
	end
	local success,err
	if filename then
		file,err = io.open(filename, 'wb')
		if not file then return nil,err end
	end
	success,err = dumprefs(refs, file)
	if not success then return nil,err end
	success,err = file:write"return "
	if not success then return nil,err end
	success,err = dumpvalue(value, function(...) return file:write(...) end, 0)
	if not success then return nil,err end
	success,err = file:write("\n-- v".."i: ft=lua\n")
	if not success then return nil,err end
	if filename then
		success,err = file:close()
		if not success then return nil,err end
	end
	return true
end

function _M.toscript(value)
	local file = {}
	function file:write(str)
		self[#self+1] = str
		return true
	end
	local success,err = _M.tofile(value, file)
	if not success then return nil,err end
	return table.concat(file)
end

function _M.tofile_safe(value, filename, oldsuffix)
	local lfs = require 'lfs'
	
	if oldsuffix and lfs.attributes(filename, 'mode') then
		local i,suffix = 0,oldsuffix
		while io.open(filename..suffix, "rb") do
			i = i+1
			suffix = oldsuffix..i
		end
		assert(os.rename(filename, filename..suffix))
	end
	local tmpfilename = filename..'.new'
	local err,file,success
	file,err = io.open(tmpfilename, "wb")
	if not file then return nil,err end
	success,err = _M.tofile(value, file)
	if not success then
		file:close()
		os.remove(tmpfilename)
		return nil,err
	end
	success,err = file:close()
	if not success then
		os.remove(tmpfilename)
		return nil,err
	end
	if lfs.attributes(filename, 'mode') then
		assert(os.remove(filename))
	end
	assert(os.rename(tmpfilename, filename))
	return true
end

if _NAME=='test' then
	require 'test'
	
	-- some simple values
	expect([["\000\001\007\t\n\r\014\031 !~\127]].."\128\129\254\255"..[["]],
		_M.tostring(string.char(0, 1, 7, 9, 10, 13, 14, 31, 32, 33, 126, 127, 128, 129, 254, 255)))
	expect('0/0', _M.tostring(0/0))
	expect('1/0', _M.tostring(1/0))
	expect('-1/0', _M.tostring(-1/0))
	
	-- a complete file showing key ordering
	local str = [[
return {
	Abc = false,
	FOO = 42,
	Foo = "42",
	abc = true,
	["f O"] = 42,
	fOO = 42,
	foo = "42",
	[-1] = 37,
	[0] = 37,
	[42] = 37,
	Bar = {
		foo = 142,
	},
	bar = {
		foo = 142,
	},
	Baz = {
		foo = 242,
		237,
	},
	baz = {
		foo = 242,
		237,
	},
	Baf = {
		337,
	},
	baf = {
		337,
	},
	37,
}
-- v]]..[[i: ft=lua
]]
	local t
	if _VERSION=="Lua 5.1" then
		t = assert(loadstring(str))()
	elseif _VERSION=="Lua 5.2" then
		t = assert(load(str))()
	else
		error("unsupported Lua version")
	end
	
	local filename = os.tmpname()
	if pcall(require, 'lfs') then
		assert(_M.tofile_safe(t, filename))
	else
		assert(_M.tofile(t, filename))
	end
	local file = assert(io.open(filename, "rb"))
	local content = assert(file:read"*a")
	assert(file:close())
	expect(str, content)
	local str2 = assert(_M.tostring(t))
	expect(content:sub(8, -16), str2)
	
	-- toscript
	expect(str, _M.toscript(t))
	
	-- cycle detection
	local t = {}
	t[1] = t
	local value,msg = _M.tostring(t)
	expect(nil, value)
	expect('string', type(msg))
	local value,msg = _M.toscript(t)
	expect(nil, value)
	expect('string', type(msg))
	
	-- shared refs support
	local t1 = {}
	local t = {t1, t1}
	local value,msg = _M.tostring(t)
	expect(nil, value)
	expect('string', type(msg))
	local value,msg = _M.toscript(t)
	expect('string', type(value))
	
	-- BFS correctness
	local t1 = {"foo"}
	local t2 = {{t1}}
	local t = {t1, t2, t2}
	local filename = os.tmpname()
	assert(_M.tofile(t, filename))
	local T = dofile(filename)
	expect("foo", T[2][1][1][1])
	assert(T[2]==T[3])
	assert(T[2][1][1]==T[1])
	
	print("all tests passed successfully")
end

return _M

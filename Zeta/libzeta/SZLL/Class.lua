-- Code is taken from http://lua-users.org/wiki/SimpleLuaClasses

--------------------------------------------------------------------------------
-- Module for providing the Class() function
-- Class() returns a table that can be used as class
-- Classes created by this can override the X:init()
-- function for construction. Later they can create objects
-- with the calling notation eg: local p = X(args)
-- 
-- @module SZLL.Class

--------------------------------------------------------------------------------
-- @function [parent=#SZLL.Class] Class
-- @param #table BaseClass The base class to be inherited
-- @param #function Constructor A function to construct the objects
-- @return #table The designated class
local function Class(base, init)
	local c = {}    -- a new class instance
	if not init and type(base) == 'function' then
		init = base
		base = nil
	elseif type(base) == 'table' then
		-- our new class is a shallow copy of the base class!
		for i,v in pairs(base) do
			c[i] = v
		end
		c._base = base
	end
	-- the class will be the metatable for all its objects,
	-- and they will look up their methods in it.
	c.__index = c

	-- expose a constructor which can be called by <classname>(<args>)
	local mt = {}
	mt.__call = function(class_tbl, ...)
		local obj = {}
		setmetatable(obj,c)
		if class_tbl.init then
			class_tbl.init(obj,...)
		else
			-- make sure that any stuff from the base class is initialized!
			if base and base.init then
				base.init(obj, ...)
			end
		end
		return obj
	end
	c.init = init
	c.is_a = function(self, klass)
		local m = getmetatable(self)
		while m do
			if m == klass then return true end
			m = m._base
		end
		return false
	end
	setmetatable(c, mt)
	return c
end

return Class
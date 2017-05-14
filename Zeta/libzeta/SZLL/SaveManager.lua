---	This file is Part of Zeta Engine
--
--	The MIT License
--
-- Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
-- documentation files (the "Software"), to deal in the Software without restriction, including without limitation
-- the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
-- and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
--
-- The above copyright notice and this permission notice shall be included in all copies or substantial
-- portions of the Software.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
-- INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
-- AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
-- DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


local Save = {
	data = {
		maps = {}
	},
	filename = "Save.lua",
	firstLoad = true,
	newGame = false
}

function Save.addMap(name,table)
	Save.data.maps[name] = table
end

function Save.Save()
	local dump = require('SZLL.dump')
	local Demo = require('Demo')
	Save.data.maps[Demo.CurrentMap.name] = Demo.CurrentMap:getData()
	Save.data.CurrentMap = Demo.CurrentMap.name
	local Player = Demo.Player
	Save.data.player = {
		x = Player:getPosition():getX(),
		y = Player:getPosition():getY(),
		class = Player:getClassName(),
		attributes = Player:getAttributesLuaTable()
	}
	dump.tofile(Save.data,Save.filename)
	print("Save Done!")
end

function Save.Load()
	Save.data = dofile(Save.filename)
	Save.newGame=false
	local operations = require('Demo.Operations')
	operations.ChangeMap(require(Save.data.CurrentMap))
end

return Save

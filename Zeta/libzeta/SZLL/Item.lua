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

--------------------------------------------------------------------------------
-- An Abstract class for Items generated from ItemClasses
--
-- @module SZLL.Item

--------------------------------------------------------------------------------
-- Item
--
-- @type Item
-- @field [parent=#Item] #string Name The Name of the Item
local Item = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- Item Constructor
--
-- @callof #SZLL.Item
-- @param #string Name The Name of the Item
function Item:init(Name)
	self.Name = Name
end
--------------------------------------------------------------------------------
-- Executes operation on a Target depending on what the Item Does (E.g. Heal)
--
-- @function [parent=#Item] Invoke
-- @param self
-- @param SZLL.Zeta#Zeta.Player Player The Player the Item will be invoked
function Item:Invoke(Player)
	print("Default Item:Invoke() was called on "..Player:getName())
end

--------------------------------------------------------------------------------
-- Executes operation on a Target depending on what the Item Does (E.g. Heal)
--
-- @function [parent=#Item] Remove
-- @param self
-- @param SZLL.Zeta#Zeta.Player Player The Player the Item will be invoked
function Item:Remove(Player)
	print("Default Item:Remove() was called on "..Player:getName())
end

return Item

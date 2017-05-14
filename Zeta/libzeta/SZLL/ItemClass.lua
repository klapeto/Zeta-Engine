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
-- An Abstract class for Item Classes.
--
-- @module SZLL.ItemClass

--------------------------------------------------------------------------------
-- Item Class
-- 
-- @type ItemClass
-- @field [parent=#ItemClass] #string Name The Name of the ItemClass
local ItemClass = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- Create a new ItemClass
-- @callof #SZLL.ItemClass
-- @param #string Name The name of the desired ItemClass
-- @return #ItemClass the created ItemClass
function ItemClass:init(name)
	self.Name = name
end

--------------------------------------------------------------------------------
-- Create a New Item
--
-- @function [parent=#ItemClass] CreateNewItem()
-- @param self
-- @return SZLL.Item#Item The created Item
function ItemClass:CreateNewItem()
	local Item = require('SZLL.Item')
	print("Default createNewItem was called")
	return Item("Null Item")
end

return ItemClass
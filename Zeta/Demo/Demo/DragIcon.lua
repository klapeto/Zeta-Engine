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

local Drag = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- DragIcon Module
-- 
-- DragIcons used on the Bar
-- 
-- @module Demo.DragIcon

--------------------------------------------------------------------------------
-- DragIcon Type
--
-- @type DragIcon
-- @field [parent=#DragIcon] #table Table The icon's Table
-- @field [parent=#DragIcon] SZLL.CEGUI#CEGUI.Window Window The DragIcon Window

--------------------------------------------------------------------------------
-- DragIcon Constructor
--
-- @callof #Demo.DragIcon
-- @param SZLL.CEGUI#CEGUI.Window Window The Window to be used
-- @return #DragIcon The Drag icon created
function Drag:init(Window)
	self.Table = {}
	self.Window = Window
	Window:setUserString("Table",tostring(self))
	self.Window:setDestroyedByParent(false)
end

--------------------------------------------------------------------------------
-- Swaps Drag Icon properties
--
-- @function [parent=#DragIcon] Swap
-- @param self
-- @param #DragIcon Other The DragIcon to be swapped
function Drag:Swap(Other)
	do
		-- Swap Tables
		local table = Other.Table
		Other.Table = self.Table
		self.Table = table
	end
	do
		-- Swap Window Data
		local Image = Other.Window:getProperty("Image")
		local Table = Other.Window:getUserString("Table")
		local ToolTip = Other.Window:getTooltipText()
		Other.Window:setProperty("Image",self.Window:getProperty("Image"))
		Other.Window:setUserString("Table",self.Window:getUserString("Table"))
		Other.Window:setTooltipText(self.Window:getTooltipText())
		self.Window:setProperty("Image",Image)
		self.Window:setUserString("Table",Table)
		self.Window:setTooltipText(ToolTip)
	end
end

--------------------------------------------------------------------------------
-- Copies the provided DragIcon Properties
--
-- @function [parent=#DragIcon] Copy
-- @param self
-- @param #DragIcon Other The DragIcon to copy
function Drag:Copy(Other)
	self.Table = Other.Table
	self.Window:setProperty("Image",Other.Window:getProperty("Image"))
	self.Window:setTooltipText(Other.Window:getTooltipText())
end

return Drag

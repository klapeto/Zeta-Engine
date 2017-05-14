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
-- Module for providing Demo item Instances
--
-- @module Demo.Item
-- @extends SZLL.Item#SZLL.Item

local Item = require('SZLL.Class')()	-- #Demo.Item

--------------------------------------------------------------------------------
-- Item Type
--
-- @type Item
-- @extends SZLL.Item#Item
-- @field [parent=#Item] Demo.ItemClass#ItemClass Class The Item Class
-- @field [parent=#Item] Demo.DragIcon#DragIcon DragIcon The DragIcon to be used

--------------------------------------------------------------------------------
-- Item Constructor
--
-- @callof #Demo.Item
-- @param Demo.ItemClass#ItemClass Class The item class
-- @return #Item The Created Object

--------------------------------------------------------------------------------
-- Item Constructor
--
-- @function [parent=#Item] init
-- @param self
-- @param Demo.ItemClass#ItemClass Class The item class
-- @return #Item The Created Object
function Item:init(Class)
	self.Class = Class
	self.DragIcon = require('Demo.DragIconPool').Queue:popBack()
	self.DragIcon.Table = require('Demo.ItemDragTable')(self)
	self.DragIcon.Window:setProperty("Image",self.Class.IconName)
end

--------------------------------------------------------------------------------
-- 

return Item

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
-- Invetory Module
--
-- @module Demo.Inventory

local Inventory = require('SZLL.Class')()	-- #Demo.Inventory

--------------------------------------------------------------------------------
-- Inventory Type
--
-- @type Inventory
-- @field [parent=#Inventory] SZLL.DeQueue#DeQueue SlotList The CEGUI Window SZLL.DeQueue

--------------------------------------------------------------------------------
-- Inventory Constructor
--
-- @function [parent=#Inventory] init
-- @param self
-- @param SZLL.DeQueue#DeQueue SlotList The CEGUI Window SZLL.DeQueue
-- @return #Inventory The Returned Item
function Inventory:init(SlotList)
	self.SlotList = SlotList
end

--------------------------------------------------------------------------------
-- Adds an Item to the Inventory if can fit
--
-- @function [parent=#Inventory] AddItem
-- @param self
-- @param Demo.DroppedItem#DroppedItem DroppedItem The item to add
function Inventory:AddItem(DroppedItem)
	local slot = self.SlotList:popBack()	-- SZLL.CEGUI#CEGUI.Window
	if slot then
		local Item = require('Demo.Item')(DroppedItem.DropClass.ItemClass)
		-- TODO: Stacked?? What then?
	else
		require('Demo.Operations').Notify("Δεν υπάρχουν αρκετές θέσεις στην τσάντα!")
	end
end


return Inventory

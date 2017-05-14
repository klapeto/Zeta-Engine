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
-- Drag Icon Pool
-- 
-- @module Demo.DragIconPool
-- @field [parent=#Demo.DragIconPool] SZLL.DeQueue#DeQueue Queue The Icon DeQueue
-- @field [parent=#Demo.DragIconPool] #table Table The Icons Tables
local Pool = {
	Queue = require('SZLL.DeQueue')(),
	Table = {}
}
local winMgr = CEGUI.WindowManager:getSingleton()

function Pool.onDragItemDrop(Event)
	local ev = CEGUI.toDragDropEventArgs(Event)
	local wID = ev.window:getID()
	local dID=ev.dragDropItem:getID()
	local dTable = Pool.Table[ev.dragDropItem:getUserString("Table")]
	local wTable = Pool.Table[ev.window:getUserString("Table")]
	-- If the dropped item is from bar
	if (wID==1 and dID==1) then
		dTable:Swap(wTable)
	elseif (wID==1 and dID == 0) then
		wTable:Copy(dTable)
	elseif (wID==0 and dID==0) then
		dTable:Swap(wTable)
	end
end

--------------------------------------------------------------------------------
-- Adds an icon to the Table's Map
-- 
-- @function [parent=#Demo.DragIconPool] AddIconToTable
-- @param Demo.DragTable#DragTable Icon The Icon to be added
function Pool.AddIconToTable(Icon)
	Pool.Table[tostring(Icon)] = Icon
end

--------------------------------------------------------------------------------
-- Here we add a few Drag Icons to the Pool
local DragIcon = require('Demo.DragIcon')
for i=0, 25 do
	local win = winMgr:createWindow("Eftihia/DragableIcon","ItemDrag"..i)
	win:subscribeEvent("DragDropItemDropped",Pool.onDragItemDrop)
	local itm = DragIcon(win)
	Pool.Table[tostring(itm)] = itm
	Pool.Queue:pushBack(itm)
end

return Pool

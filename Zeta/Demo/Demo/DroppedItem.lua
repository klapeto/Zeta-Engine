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

local Dropped = require('SZLL.Class')() -- #Demo.DroppedItem

--------------------------------------------------------------------------------
-- Module to provide objects for items that have dropped in the world
--
-- @module Demo.DroppedItem

--------------------------------------------------------------------------------
-- @field [parent=#Demo.DroppedItem] #map<SZLL.CEGUI#CEGUI.Window, #DroppedItem> WorldDrops The Dropped items that can be acquired

--------------------------------------------------------------------------------
-- DroppedItem Type
--
-- @type DroppedItem
-- @field [parent=#DroppedItem] SZLL.Zeta#SZLL.CEGUIObject Object The CEGUIObject used
-- @field [parent=#DroppedItem] #number Amount The Amount that was dropped
-- @field [parent=#DroppedItem] Demo.ItemDrop#ItemDrop DropClass the ItemDrop Class

--------------------------------------------------------------------------------
-- DroppedItem Constructor
--
-- @callof #Demo.DroppedItem
-- @param self
-- @param Demo.ItemDrop#ItemDrop ItemDrop The ItemDropClass
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that dropped the item
-- @return #DroppedItem The returned object

--------------------------------------------------------------------------------
-- DroppedItem Constructor
--
-- @function [parent=#DroppedItem] init
-- @param self
-- @param Demo.ItemDrop#ItemDrop ItemDrop The ItemDropClass
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that dropped the item
-- @return #DroppedItem The returned object
function Dropped:init(ItemDrop,Lifeform)
	self.DropClass = ItemDrop
	local Text = require('Demo.ItemTextPool'):popBack() -- SZLL.CEGUI#CEGUI.Window
	self.Amount = math.random(ItemDrop.MinAmount,ItemDrop.MaxAmount)
	if (Text) then
		local pos = Lifeform:getPosition()
		Text:setText(ItemDrop.Item.Name.." ("..self.Amount..")" or "Ανώνυμο Αντικέιμενο")
		Text:show()
		Text:setProperty("NormalTextColour",self.Item.Quality.Colour or "FFFFFFFF")
		local obj = Zeta.CEGUIObject:new(Text,pos:getX()+math.random(50),pos:getY()+math.random(50))
		obj:setLuaTable(self.Item)
		obj:setOnClick(Dropped.onClick)
		local TextSize = Text:getSize()
		obj:getTargetArea():setSize(TextSize.width.offset,TextSize.height.offset)
		obj:setCoolideAble(false)
		self.Object = obj
		require('Demo').World:getCurrentMap():insertObject(obj,true)
		Dropped.WorldDrops[obj] = self
	end
end

--------------------------------------------------------------------------------
-- Drops the item provided
--
-- @function [parent=#DroppedItem] Drop
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that drops the item
-- @param Demo.Item#Item name description

--------------------------------------------------------------------------------
-- Actions when a Dropped Item is clicked
--
-- @function [parent=#Demo.DroppedItem] onClick
-- @param SZLL.Zeta#Zeta.Player Clicker The Player who clicked the Drop
-- @param SZLL.Zeta#Zeta.CEGUIObject Object The Object that was clicked
-- @param #table Table The Lua Table
function Dropped.onClick(Clicker,Object,Table)
	local Demo = require('Demo')
	require('Demo.ItemTextPool'):pushBack(Object:getWindow());
	Demo.World:getCurrentMap():removeObject(Object)
	Dropped.WorldDrops[Object] = nil
	Demo.PlayerValues.Inventory:AddItem(Table)
end

--------------------------------------------------------------------------------
-- Clears the WorldDrops Table
--
-- @function [parent=#Demo.DroppedItem] ClearDroppedItems
function Dropped.ClearDroppedItems()
	local pool = require('Demo.ItemTextPool')
	for k,v in pairs(Dropped.WorldDrops) do
		pool:pushBack(v.Object:getWindow())
	end
	Dropped.WorldDrops = {}
end

return Dropped

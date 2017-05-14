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
-- @module Demo.ItemClass

local ItemClass = require('SZLL.Class')(require('SZLL.ItemClass'))	-- #Demo.ItemClass
--------------------------------------------------------------------------------
-- Item Quality
--
-- @type Quality
-- @field [parent=#Quality] #string Colour The Colour of the quality

--------------------------------------------------------------------------------
-- Item Quality Table
--
-- @type QualityTable
-- @field [parent=#ItemClass] #Quality Normal Normal Quality
-- @field [parent=#ItemClass] #Quality Rare Rare Quality
-- @field [parent=#ItemClass] #Quality UltraRare UltraRare Quality
-- @field [parent=#ItemClass] #Quality Legendary Legendary Quality
-- @field [parent=#ItemClass] #Quality Unique Unique Quality
ItemClass.ItemQuality = {
	Normal = {
		Colour = "FFFFFFFF"
	},
	Rare = {
		Colour = "FFbea7ff"
	},
	UltraRare = {
		Colour = "FFfbd96b"
	},
	Legendary = {
		Colour = "FF9bf3b0"
	},
	Unique = {
		Colour = "FFd71a1f"
	}
}

--------------------------------------------------------------------------------
-- Item Class
-- 
-- @type ItemClass
-- @field [parent=#ItemClass] #string Name The Name of the ItemClass
-- @field [parent=#ItemClass] #string Quality The Item Quality
-- @field [parent=#ItemClass] #string IconName The Icon Name
-- @field [parent=#ItemClass] #string Description The Item Description
-- @field [parent=#ItemClass] #boolean Stackable If the item is stackable
-- @field [parent=#ItemClass] SZLL.Zeta#Zeta.Timer Cooldown The cooldown timer (if it has)

--------------------------------------------------------------------------------
-- Create a new ItemClass
-- @callof #Demo.ItemClass
-- @param #string Name The name of the desired ItemClass
-- @return #ItemClass the created ItemClass

--------------------------------------------------------------------------------
-- Create a new ItemClass
-- @function [parent=#ItemClass] init
-- @param self
-- @param #string Name The name of the desired ItemClass
-- @return #ItemClass the created ItemClass 
function ItemClass:init(Name)
	self.Name = Name
	self.Quality = ItemClass.ItemQuality.Normal
	self.Stackable = false
end

--------------------------------------------------------------------------------
-- Create a New Item
--
-- @function [parent=#ItemClass] CreateNewItem
-- @param self
-- @return Demo.Item#Item The created Item
function ItemClass:CreateNewItem()
	return require('Demo.Item')(self)
end

--------------------------------------------------------------------------------
-- Executes operation on a Target depending on what the Item Does (E.g. Heal)
--
-- @function [parent=#ItemClass] Invoke
-- @param self
-- @param SZLL.Zeta#Zeta.Player Player The Player the Item will be invoked
function ItemClass:Invoke(Player)
	print("Default ItemClass:Invoke() was called on "..Player:getName())
end

--------------------------------------------------------------------------------
-- Executes operation on a Target depending on what the Item Does (E.g. Heal)
--
-- @function [parent=#ItemClass] Remove
-- @param self
-- @param SZLL.Zeta#Zeta.Player Player The Player the Item will be invoked
function ItemClass:Remove(Player)
	print("Default ItemClass:Remove() was called on "..Player:getName())
end

return ItemClass
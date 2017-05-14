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
-- Ability Node
--
-- @module Demo.AbilityNode
local Node = require('SZLL.Class')()
local winMgr = CEGUI.WindowManager:getSingleton()

--------------------------------------------------------------------------------
-- Ability Node Type
--
-- @type AbilityNode
-- @field [parent=#AbilityNode] SZLL.Ability#Ability Ability The Ability
-- @field [parent=#AbilityNode] SZLL.CEGUI#CEGUI.DragContainer Icon The ability Window
-- @field [parent=#AbilityNode] #list<Demo.Requirement#Requirement> Requirements The Requirement List
-- @field [parent=#AbilityNode] #number Level The Level of the ability
-- @field [parent=#AbilityNode] #number x X on the Abilities Grid
-- @field [parent=#AbilityNode] #number y Y on the Abilities Grid

--------------------------------------------------------------------------------
-- Constructs a new Ability Node
--
-- @function [parent=#AbilityNode] init
-- @param self
-- @param SZLL.Ability#Ability Ability The Ability
function Node:init(Ability)
	self.Requirements = {}
	self.Ability = Ability
	Ability.Node = self
	self.Level = 0
	self.Icon = CEGUI.toDragContainer(winMgr:createWindow("Eftihia/TreeIcon",self.Ability.Name or tostring(self)))
	do
		-- Create the Data that will come with the DragContainer Window
		local iTable = require('Demo.DragIcon')(self.Icon)
		iTable.Table = require('Demo.AbilityDragTable')(self)
		self.Icon:setUserString("Table",tostring(iTable))
		require('Demo.DragIconPool').AddIconToTable(iTable)
	end
	self.Icon:setProperty("Image",self.Ability.IconPath)
	self.Icon:setText("0/"..self.Ability.Levels)
	self.Icon:subscribeEvent("MouseClick",Node.OnClick)
	self.Icon:setDraggingEnabled(false)
	self.Icon:setProperty("ImageColours","tl:FF707070 tr:FF707070 bl:FF707070 br:FF707070")
	self.Icon:setUserString("AbilityType",tostring(Ability.Internal:getType()))
end

--------------------------------------------------------------------------------
-- Checks if Requirements are met
--
-- @function [parent=#AbilityNode] CheckRequirements
-- @param self
-- @return #boolean True if Requirements are met
function Node:CheckRequirements()
	for k,v in pairs(self.Requirements) do
		if (not v:CheckCondition()) then
			return v
		end
	end
	return nil
end

--------------------------------------------------------------------------------
-- Adds a requirement
--
-- @function [parent=#AbilityNode] AddRequirement
-- @param self
-- @param Demo.Requirement#Requirement Requirement The Requirement to add
function Node:AddRequirement(Requirement)
	self.Requirements[Requirement] = Requirement
end

--------------------------------------------------------------------------------
-- Updates the Node
--
-- @function [parent=#AbilityNode] Update
-- @param self
function Node:Update()
--	if (self.Icon:isDisabled()) then
--		if (self:CheckRequirements()) then
--			self.Icon:enable()
--		end
--	end
end

--------------------------------------------------------------------------------
-- Resets the Node
--
-- @function [parent=#AbilityNode] Reset
-- @param self
function Node:Reset()
	self.Icon:setDraggingEnabled(false)
	self.Icon:setPosition(CEGUI.PropertyHelper:stringToUVector2('{{0,0},{0,0}}'))
end

--------------------------------------------------------------------------------
-- Applies the current Ability State to the Current Player
--
-- @function [parent=#AbilityNode] SetToPlayer()
-- @param self
function Node:SetToPlayer()
	local Demo = require('Demo')
	local Type = self.Ability.Internal:getType()
	local ability
	local DragEn
	if (Type == Zeta.AbilityClass.Type.Active) then
		ability = Demo.Player:getActiveAbility(self.Ability.Name)
		if (not ability) then
			Demo.Player:addAbility(self.Ability.Internal,self.Level)
			ability = Demo.Player:getActiveAbility(self.Ability.Name)
		end
		DragEn = true
	elseif (Type == Zeta.AbilityClass.Type.Passive) then
		ability = Demo.Player:getPassiveAbility(self.Ability.Name)
		if (not ability) then
			Demo.Player:addAbility(self.Ability.Internal,self.Level)
			ability = Demo.Player:getPassiveAbility(self.Ability.Name)
		end
		DragEn = false
	else
		ability = Demo.Player:getRegeneration(self.Ability.Name)
		if (not ability) then
			Demo.Player:addAbility(self.Ability.Internal,self.Level)
			ability = Demo.Player:getRegeneration(self.Ability.Name)
		end
		DragEn = false
	end
	ability:setLevel(self.Level)
	require('Demo.Operations').SkillTooltip(ability,self.Icon,self)
	self.Icon:setText(self.Level.."/"..self.Ability.Levels)
	-- If ability is enabled, set the right colours
	if (self.Level>0) then
		self.Icon:setDraggingEnabled(DragEn)
		self.Icon:setProperty("ImageColours","tl:FFFFFFFF tr:FFFFFFFF bl:FFFFFFFF br:FFFFFFFF")
	else
		self.Icon:setDraggingEnabled(false)
		self.Icon:setProperty("ImageColours","tl:FF707070 tr:FF707070 bl:FF707070 br:FF707070")
	end
end

--------------------------------------------------------------------------------
-- Actions happening when the Icon is clicked
--
-- @function [parent=#Demo.AbilityNode] OnClick
-- @param SZLL.CEGUI#CEGUI.MouseEventArgs Event The event
function Node.OnClick(Event)
	Event = CEGUI.toMouseEventArgs(Event)
	local Demo = require('Demo')
	-- Check if the right button was pressed
	if (Event.button==CEGUI.RightButton) then

		local Type = tonumber(Event.window:getUserString("AbilityType"))

		-- Get The Active Ability with the name the window defines
		local ability			-- SZLL.Zeta#Zeta.ActiveAbility
		local DragEn
		if (Type == Zeta.AbilityClass.Type.Active) then
			ability = Demo.Player:getActiveAbility(Event.window:getName())
			DragEn = true
		elseif (Type == Zeta.AbilityClass.Type.Passive) then
			ability = Demo.Player:getPassiveAbility(Event.window:getName())
			DragEn = false
		else
			ability = Demo.Player:getRegeneration(Event.window:getName())
			DragEn = false
		end
		-- If the ability exists
		if (ability) then
			-- Update the Window Texts --
			local Table = ability:getClass():getLuaTable()
			local Requirement = Table.Node:CheckRequirements()
			if (not Requirement) then
				local level = ability:getLevel()
				local maxLevel = ability:getClass():getLevels()
				-- If the Player has enought SkillPoints and the Ability can be increased
				if (Demo.PlayerValues.SkillPoints > 0 and level < maxLevel) then
					-- Decrease the SkillPoints by 1
					Demo.PlayerValues.SkillPoints=Demo.PlayerValues.SkillPoints-1
					-- Increase the Ability Level by 1
					ability:setLevel(level+1)
					-- Update the Texts
					Event.window:setText(tostring(level+1).."/"..maxLevel)
					-- Get the New Tooltip
					require('Demo.Operations').SkillTooltip(ability,Event.window)
					-- Enable to be dragged (If not already)
					CEGUI.toDragContainer(Event.window):setDraggingEnabled(DragEn)
					Event.window:setProperty("ImageColours","tl:FFFFFFFF tr:FFFFFFFF bl:FFFFFFFF br:FFFFFFFF")
				end
			else
				require('Demo.Operations').Notify(Requirement:getText())
			end
		end
		-- Update the Window Text
		require('Demo.GUI.GameInterface').this:getChild("Abilities/Points"):setText(tostring(Demo.PlayerValues.SkillPoints))
	end
end

return Node

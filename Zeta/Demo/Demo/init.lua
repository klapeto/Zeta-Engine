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
-- An Abstract class for Generic Abilities.
-- This type provides with the standard callbacks for any
-- sub-ability type. Do not use directly this type
-- as it may cause undesired results. Use the Subclasses Instead.
--
-- @module Demo

--------------------------------------------------------------------------------
-- Ability Class
--
-- @type Demo
-- @field [parent=#Demo] SZLL.Zeta#Zeta.WorldManager World The Game World
-- @field [parent=#Demo] SZLL.Zeta#Zeta.Player Player The Game player
-- @field [parent=#Demo] #table PlayerValues Player Specific Values
-- @field [parent=#Demo] #map<Demo.Npc#Npc,Demo.Npc#Npc> Npcs The Loaded Npcs
-- @field [parent=#Demo] #map<Demo.Quest#Quest,Demo.Quest#Quest> Quests The Loaded Quests
local Demo = {
	World = Zeta.WorldManager:getInstance(),
	Player = Zeta.WorldManager:getInstance():getPlayer(),
	PlayerValues = {
		SkillPoints= 0,
		Inventory = require('Demo.Inventory')(require('Demo.GUI.GameInterface').Items.Slots)
	},
	DragItems = {},
	Npcs = {},
	Quests = {}
}

--------------------------------------------------------------------------------
-- Here we create a custom Null-Ability for lifeforms to use when there no other available
local ability = require('SZLL.ActiveAbility')
ability.onApply = function(Ability,Caster,Target)
	local patk = Caster:getAttributeValue("Patk")
	local dmg = patk+math.random(10)
	local Operations = require('Demo.Operations')

	dmg = Operations.doPhysicalDamage(Target,dmg)
end

ability.Name = "Απλό χτύπημα"
ability.CoolDown = 1.5
ability.Range = 80
ability.ReleaseAnimation = "Slash"
ability.ReleaseSound = "Demo/Abilities/Sounds/swing.ogg"

Demo.NullAbility = Zeta.AbilityClass(ability)

--------------------------------------------------------------------------------
-- Loads the Player according to Game Mode (New or Load)
-- 
-- @function [parent=#Demo] LoadPlayer
function Demo.LoadPlayer()
	local Save = require('SZLL.SaveManager')

	if (not Save.newGame) then
		Demo.Player:setClass(Save.data.player.class)
		Demo.Player:teleportToCordinates(Save.data.player.x,Save.data.player.y)
		local att = Save.data.player.attributes
		if (att) then
			for k,v in pairs(att) do
				Demo.Player:setAttributeBaseValue(k,v)
			end
		end
	end
	-- Set the Target Indicator
	Demo.Player:addChildObject(0,0,"trgInd","Demo/Sprites/Mark/trgPos.xml","Default")
	Demo.Player:setTargetIndicator("trgInd")
	-- Set the Xp needed to next level
	Demo.Player:setXpToNextLevel(500)
end

--------------------------------------------------------------------------------
-- Resets the Game State
-- Resets NPCS and removes Quests and Resets GUI
-- 
-- @function [parent=#Demo] GameReset
function Demo.GameReset()
	for k,v in pairs(Demo.Npcs) do
		v:Reset()
	end
	for k,v in pairs(Demo.Quests) do
		v:Reset()
	end
	require('Demo.GUI.GameInterface').Reset()
end

-- Seed the Randomizer
math.randomseed(os.time())
-- Add animations FXS to be available any time
Zeta.AnimationEffectsManager:getInstance():addAnimationPack("Demo/Sprites/FX1.anim","FX")
return Demo

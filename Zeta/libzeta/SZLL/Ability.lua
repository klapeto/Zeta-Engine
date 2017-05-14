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


local Class = require('SZLL.Class')
--------------------------------------------------------------------------------
-- An Abstract class for Generic Abilities.
-- This type provides with the standard callbacks for any
-- sub-ability type. Do not use directly this type
-- as it may cause undesired results. Use the Subclasses Instead.
--
-- @module SZLL.Ability

--------------------------------------------------------------------------------
-- Ability Class
--
-- @type Ability
-- @field [parent=#Ability] #string Name The Name of the Ability
-- @field [parent=#Ability] #number Levels How many Levels has the Ability
-- @field [parent=#Ability] #string IconPath The Path to Icon

local Ability = Class()
--------------------------------------------------------------------------------
-- Create a new Ability
-- @callof #SZLL.Ability
-- @param #string AbilityName The name of the desired ability
-- @param #number AbilityLevels How many levels the ability will have
-- @return #Ability the created Ability
function Ability:init(name,levels)
	self.Name = name or "Unamed"
	self.Levels=levels or 1
	self.Effects = {}
	self.Tables = {}
	self.IconPath = "null"
end

--------------------------------------------------------------------------------
-- Add a created Effect
--
-- @function [parent=#Ability] addEffect
-- @param self
-- @param #string EffectName The name of the Effect. You will use that name to access it later
-- @param SZLL.Effect#Effect Effect The created effect
function Ability:addEffect(EffectName,Effect)
	if (EffectName and Effect) then
		self.Effects[EffectName]=Effect
		self.Effects[EffectName].Ability=self
	end
end

--------------------------------------------------------------------------------
-- Add a created Table
--
-- @function [parent=#Ability] addTable
-- @param self
-- @param #string TableName The name of the Data Table. You will use that name to access it later
-- @param #table Table The created Table
function Ability:addTable(TableName,Table)
	if (TableName and Table) then
		self.Tables[TableName] = Table
	end
end

--------------------------------------------------------------------------------
-- Generates a Zeta::AbilityClass with this Table
-- Internal is on self.Internal
--
-- @function [parent=#Ability] generateInternal
-- @param self
function Ability:generateInternal()
	self.Internal = Zeta.AbilityClass(self)
end

--------------------------------------------------------------------------------
-- Callback to onApply
-- This function should be overloaded by the created Abilities.
-- You should not call this function from lua. The core does it
-- when the Ability was Invoked.
--
-- @function [parent=#SZLL.Ability] onApply
-- @param SZLL.Zeta#Zeta.Ability Ability The ability. Depending on the attributes, this can be Active or Passive
-- @param SZLL.Zeta#Zeta.Lifeform Caster The ability Caster
-- @param SZLL.Zeta#Zeta.Lifeform Target The target of the ability
function Ability.onApply(Ability,Caster,Target)
	print("Default callback 'onApply' was called from ability: "..Ability.Name)
end

--------------------------------------------------------------------------------
-- Callback to onApply
-- This function should be overloaded by the created Abilities.
-- You should not call this function from lua. The core does it
-- when the Ability's effect where off.
--
-- @function [parent=#SZLL.Ability] onRemove
-- @param SZLL.Zeta#Zeta.Ability Ability ability. Depending on the attributes, this can be Active or Passive
-- @param SZLL.Zeta#Zeta.Lifeform Caster The ability Caster
-- @param SZLL.Zeta#Zeta.Lifeform Target The target of the ability
function Ability.onRemove(Ability,Caster,Target)
	print("Default callback 'onRemove' was called from ability: "..Ability.Name)
end

return Ability

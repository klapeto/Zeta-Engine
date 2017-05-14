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

local Ability = require('SZLL.Ability')
local Class = require('SZLL.Class')

--------------------------------------------------------------------------------
-- An Ability class for Active Abilities.
-- This class creates abilities that can be invoked manualy.
-- They have cooldown, manacost and range
--
-- @module SZLL.ActiveAbility
-- @extends SZLL.Ability#SZLL.Ability

--------------------------------------------------------------------------------
-- ActiveAbility Class
--
-- @type ActiveAbility
-- @extends SZLL.Ability#Ability 
-- @field [parent=#ActiveAbility] #number Cooldown The cooldown in Seconds
-- @field [parent=#ActiveAbility] #number ManaCost The ManaCost per use
-- @field [parent=#ActiveAbility] #number Range The Minimun Range of the Ability
local ActiveAbility = Class(Ability)

--------------------------------------------------------------------------------
-- Create a new ActiveAbility
--
-- @callof #SZLL.ActiveAbility
-- @param #string Name The name of the desired ability
-- @param #number Levels How many levels the ability will have
-- @param #number Cooldown The cooldown of the Ability in Seconds
-- @param #number Manacost How much mana is consumed by the user when the Ability Invokes
-- @param #number Range How far from the target the ability can be used
-- @return #ActiveAbility the created Ability
function ActiveAbility:init(name,levels,coolDown,manaCost,range)
	self.Name = name or "Unamed Active Ability"
	self.Levels=levels or 1
	self.CoolDown = coolDown or 1
	self.ManaCost = manaCost or 10
	self.Range = range or 100
	self.Type = Zeta.AbilityClass.Type.Active
	self.Effects = {}
	self.Tables = {}
	self.Projectiles = {}
end

--------------------------------------------------------------------------------
-- Adds a Projectile to the list
-- 
-- @function [parent=#ActiveAbility] addProjectile
-- @param self
-- @param #string Name The Projectile Name
-- @param SZLL.Zeta#Zeta.Projectile Projectile The Projectile
function ActiveAbility:addProjectile(Name,Projectile)
	self.Projectiles[Name] = Projectile
end

return ActiveAbility

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
-- Module for providing the EnemyClass
--
-- @module Demo.EnemyClass

--------------------------------------------------------------------------------
-- Demo.DropTable
--
-- @type DropTable
-- @list <Demo.Drop#Demo.Drop> The drop Table

--------------------------------------------------------------------------------
-- EnemyClass Class
--
-- @type EnemyClass
-- @field [parent=#EnemyClass] SZLL.Zeta#Zeta.LifeformClass Class The class of the enemy
-- @field [parent=#EnemyClass] #number RespawnTime The time it takes to respawn
-- @field [parent=#EnemyClass] #number VanishTime The time it takes for enemy to vanish after it dies
-- @field [parent=#EnemyClass] #DropTable Drops The drop Table of the Enemy Class
local EnemyClass = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- EnemyClass Constructor
--
-- @callof #Demo.EnemyClass
-- @param #string Path The path to the Lifeform Class
-- @return #EnemyClass The EnemyClass
function EnemyClass:init(Path)
	self.Class = Zeta.LifeformClass(Path)
	self.Class:setTable(self)
	self.Class:addAbility(require('Demo.Abilities.Melee').Internal,1)
	self.RespawnTime = 30
	self.VanishTime = 10
	self.Drops = {}
end

--------------------------------------------------------------------------------
-- Creates and returns a new Enemy
--
-- @function [parent=#EnemyClass] generate
-- @param self
-- @param #number x The X spawn location
-- @param #number y The Y spawn location
-- @return SZLL.Zeta#Zeta.Enemy The returned enemy
function EnemyClass:generate(x,y)
	return Zeta.Enemy(self.Class,x,y,self.RespawnTime,self.VanishTime)
end

--------------------------------------------------------------------------------
-- Adds a drop to the Enemy's Drop Table
--
-- @function [parent=#EnemyClass] addDrop
-- @param self
-- @param Demo.Drop#Drop Drop The drop to be added
function EnemyClass:addDrop(Drop)
	self.Drops[Drop] = Drop
end

--------------------------------------------------------------------------------
-- Adds an ability to the Enemy's Class Ability Set
--
-- @function [parent=#EnemyClass] AddAbility
-- @param self
-- @param SZLL.Ability#SZLL.Ability AbilityClass The Ability Class of the ability
-- @param #number Level The level of the ability
function EnemyClass:AddAbility(AbilityClass,Level)
	self.Class:addAbility(AbilityClass.Internal,Level)
end

return EnemyClass

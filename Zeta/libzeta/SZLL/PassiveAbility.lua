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
-- An Ability class for Passive Abilities.
-- This class creates abilities that are Passive
--
-- @module SZLL.PassiveAbility
-- @extends SZLL.Ability#SZLL.Ability

--------------------------------------------------------------------------------
-- PassiveAbility Class
-- 
-- @type PassiveAbility

local PassiveAbility = Class(Ability)
--------------------------------------------------------------------
-- Create a new PassiveAbility
-- 
-- @callof #SZLL.PassiveAbility
-- @param #string Name The name of the desired ability
-- @param #number Levels How many levels the ability will have
-- @return #PasiveAbility the created Ability
function PassiveAbility:init(name,levels)
	self.Name = name or "Unamed Passive Ability"
	self.Levels=levels or 1
	self.Passive=true
	self.Effects = {}
	self.Tables = {}
end

return PassiveAbility
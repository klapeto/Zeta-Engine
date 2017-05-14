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
-- A class for creating Abilities to assign to Lifeform Classes
--
-- @module SZLL.LifeformAbility

local lfAbility = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- A class for creating Abilities to assign to Lifeform Classes
--
-- @type LifeformAbility
-- @field [parent=#LifeformAbility] #string Class The Class table of the Ability
-- @field [parent=#LifeformAbility] #number Level The level of the ability

--------------------------------------------------------------------------------
-- Lifeform Ability Constructor
--
-- @function [parent=#LifeformAbility] init
-- @param self
-- @param SZLL.Ability#Ability Class The ability class table
-- @param #number Level The level of the ability
-- @return #LifeformAbility The returned object

--------------------------------------------------------------------------------
-- Lifeform Ability Constructor
--
-- @callof #SZLL.LifeformAbility
-- @param SZLL.Ability#Ability Class The ability class table
-- @param #number Level The level of the ability
-- @return #LifeformAbility The returned object
function lfAbility:init(Class,Level)
	self.Class = Class
	self.Level = Level
end

return lfAbility

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
-- Regeneration Module
-- 
-- @module SZLL.Regeneration
local Regeneration = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- Regeneration Type
-- 
-- @type Regeneration
-- @field [parent=#Regeneration] #string Name The Regeneration Name
-- @field [parent=#Regeneration] #string Attribute The attribute name that this Regeneration Applies (eg. Mana)
-- @field [parent=#Regeneration] #string MaxValue The attribute that has the max value of the affected Attribute (eg. MaxMana)
-- @field [parent=#Regeneration] #string Modifier The Attribute that will be added to the modified Attribute
-- @field [parent=#Regeneration] #number Levels How many levels it has
-- @field [parent=#Regeneration] #number TriggerEvery How many seconds it will be invoked

--------------------------------------------------------------------------------
-- Regeneration Constructor
-- 
-- @function [parent=#Regeneration] init
-- @param self
-- @param #string Attribute The Affected Attribute
-- @param #string MaxValue The name of the Attribute that has the max value
-- @param #string Modifier The name of the Attribute that will be added to Affected attribute
-- @param #number TriggerEvery Every how many seconds it will trigger
function Regeneration:init(attribute,maxValue,modifier,triggerEvery)
	self.Name = "Regeneration: "..attribute
	self.Attribute = attribute or "HP"
	self.MaxValue = maxValue or "MaxHP"
	self.Modifier = modifier or "HP5"
	self.Levels = 1
	self.TriggerEvery = triggerEvery
	self.Type = Zeta.AbilityClass.Type.Regeneration
end

--------------------------------------------------------------------------------
-- Generates a Zeta::AbilityClass with this Table
-- Internal is on self.Internal
--
-- @function [parent=#Regeneration] generateInternal
-- @param self
function Regeneration:generateInternal()
	self.Internal = Zeta.AbilityClass(self)
end

return Regeneration

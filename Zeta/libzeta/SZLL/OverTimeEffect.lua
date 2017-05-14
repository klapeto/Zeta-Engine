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

local DurableEffect = require('SZLL.DurableEffect')
local Class = require('SZLL.Class')
--------------------------------------------------------------------------------
-- A OverTimeEffect Class
-- This is an extension to the DurableClass
-- This type of effect triggers an Event every tick
-- So you have to Override the function onTick()
--
-- @module SZLL.OverTimeEffect
-- @extends SZLL.DurableEffect#SZLL.DurableEffect 

--------------------------------------------------------------------------------
-- OverTimeEffect Class
-- 
-- @type OverTimeEffect
-- @field [parent=#OverTimeEffect] #number TickEvery The second's where every, the Effect will invoke: onTick()
local OverTimeEffect = Class(DurableEffect)
--------------------------------------------------------------------------------
-- OverTimeEffect Constructor
-- Creates a new OverTimeEffect
--
-- @callof #SZLL.OverTimeEffect
-- @param #string Name The name of this effect
-- @param #number Uptime The uptime of this effect in secons
-- @param #number TickEvery Secons to tick every
-- @return #OverTimeEffect Returned Effect
function OverTimeEffect:init(name,uptime,tickEvery)
	self.Name = name or "Unamed Over Time Effect"
	self.UpTime=uptime or 10
	self.TickEvery = tickEvery or 2
	self.Durable=true;
	self.OverTime=true
	self.Ability = "None"
end

--------------------------------------------------------------------------------
-- On Tick Callback
-- This function is called every self.tickEvery seconds
-- You must override this function for this Effect to be meaningful
-- 
-- @function [parent=#SZLL.OverTimeEffect] onTick\
-- @param SZLL.Zeta#Zeta.Lifeform Owner The one who has the Effect
-- @param #number Level The level of the Effect
function OverTimeEffect.onTick(owner,level)
	print("Default callback 'onTick' was called from effect: "..OverTimeEffect.Name)
end

return OverTimeEffect
	
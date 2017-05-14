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

local Effect = require('SZLL.Effect')
local Class = require('SZLL.Class')
--------------------------------------------------------------------------------
-- Class for creating Durable Effects
-- Durable Effects are effects that have specific uptime
-- Like default Effects, objects created by this class should
-- override the functions onApply() and onRemove()
--
-- @module SZLL.DurableEffect
-- @extends SZLL.Effect#SZLL.Effect

--------------------------------------------------------------------------------
-- DurableEffect Class
-- 
-- @type DurableEffect
-- @extends SZLL.Effect#Effect 
-- @field [parent=#DurableEffect] #number Uptime The duration in Seconds
local DurableEffect = Class(Effect)

--------------------------------------------------------------------------------
-- Constructor for a new DurableEffect
-- 
-- @callof #SZLL.DurableEffect
-- @param #string Name The name of the effect
-- @param #number Uptime The duration of the effect in Seconds
-- @return #DurableEffect Returned DurableEffect
function DurableEffect:init(Name,Uptime)
	self.Name = Name or "Unamed Durable Effect"
	self.UpTime = Uptime or 10
	self.Durable = true;
	self.Ability = "None"
end

return DurableEffect
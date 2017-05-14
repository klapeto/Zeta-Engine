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
-- Level Requirement
--
-- @module Demo.LevelRequirement
-- @extends Demo.Requirement#Demo.Requirement 
local Req = require('SZLL.Class')()
--------------------------------------------------------------------------------
-- Level Requirment
--
-- @type LevelRequirement
-- @extends Demo.Requirement#Requirement 
-- @field [parent=#LevelRequirement] #number Level The level that is required

--------------------------------------------------------------------------------
-- Constructs a new Level Requirement
--
-- @callof #Demo.LevelRequirement
-- @param self
-- @param #number Level The level that is required
-- @return #LevelRequirement The returned object

--------------------------------------------------------------------------------
-- Constructs a new Level Requirement
--
-- @function [parent=#LevelRequirement] init
-- @param self
-- @param #number Level The level that is required
-- @return #LevelRequirement The returned object
function Req:init(Level)
	self.Level = Level
	--require('Demo.EventManager').AddListener("LevelChanged",self)
end

--------------------------------------------------------------------------------
-- Checks if the Condition is met
--
-- @function [parent=#LevelRequirement] CheckCondition
-- @param self
-- @return #boolean True if Condition met
function Req:CheckCondition()
	return require('Demo').Player:getLevel() >= self.Level
end

--------------------------------------------------------------------------------
-- Returns a string with the requirement text
--
-- @function [parent=#LevelRequirement] getText()
-- @param self
-- @return #string The returned Text
function Req:getText()
	return "Απαιτεί Επίπεδο: "..self.Level
end

--------------------------------------------------------------------------------
-- Receives the Event and does appropriate work
-- 
-- @function [parent=#LevelRequirement] AcknowledgeEvent
-- @param self
-- @param #table Event The Event to receive
function Req:AcknowledgeEvent(Event)
	self.RequirementMet = Req:CheckCondition()
end

return Req

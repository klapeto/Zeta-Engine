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
-- Requirement
--
-- @module Demo.Requirement
local Req = require('SZLL.Class')()
--------------------------------------------------------------------------------
-- Level Requirment
--
-- @type Requirement
-- @field [parent=#Requirement] #boolean RequirementMet True if requirement Met

--------------------------------------------------------------------------------
-- Constructs a new Requirement
--
-- @callof #Demo.Requirement
-- @param self
-- @return #Requirement The returned object

--------------------------------------------------------------------------------
-- Constructs a new Requirement
--
-- @function [parent=#Requirement] init
-- @param self
-- @return #Requirement The returned object
function Req:init()
	self.RequirementMet = false
end

--------------------------------------------------------------------------------
-- Checks if the Condition is met
--
-- @function [parent=#Demo.Requirement] CheckCondition
-- @param self
-- @return #boolean True if Condition met
function Req:CheckCondition()
	return true
end

--------------------------------------------------------------------------------
-- Returns a string with the requirement text
--
-- @function [parent=#Requirement] getText()
-- @param self
-- @return #string The returned Text
function Req:getText()
	return ""
end


--------------------------------------------------------------------------------
-- Receives the Event and does appropriate work
-- 
-- @function [parent=#Requirement] AcknowledgeEvent
-- @param self
-- @param #table Event The Event to receive
function Req:AcknowledgeEvent(Event)
	
end

return Req

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
-- A Quest State Class
-- This class creates objects that contain Objectives to be
-- completed by the parent Quest. Once all States are completed
-- the Parent quest is complete. For a State to complete, the containing
-- Objectives must be completed.
--
-- @module SZLL.QuestState

--------------------------------------------------------------------------------
-- Quest State Class
--
-- @type QuestState
-- @field [parent=#QuestState] #string name Name of the State
local QuestState = Class()

--------------------------------------------------------------------------------
-- Quest State Constructor
-- Creates a Quest State
--
-- @callof #SZLL.QuestState
-- @param self
-- @param #string Name The state name
-- @return #QuestState The returned Object
function QuestState:init(name)
	self.Name = name or ""
	self.Kill = {}
	self.Interact = {}
end

--------------------------------------------------------------------------------
-- Add A Kill Objective
-- adds to the state a kill objective and a handler (Optional)
--
-- @function [parent=#QuestState] addKillObjective
-- @param self
-- @param #string TargetName The name of the Target
-- @param #number num The amount of kills to be done
-- @param #function onComplete Function for specific behaviour on complete
function QuestState:addKillObjective(targetName,num,onCompleteF)
	self.Kill[targetName] = {
		Name = "Σκότωσε "..tostring(num).." "..targetName,
		TargetName = targetName or "",
		Amount = num or 1,
		onComplete = onCompleteF
	}
end

--------------------------------------------------------------------------------
-- Add An Interact Objective
-- adds to the state an interact objective and a handler (Optional)
--
-- @function [parent=#QuestState] addInteractObjective
-- @param self
-- @param #string TargetName The name of the Target
-- @param #string Map The map the target is
-- @param #function onComplete Function for specific behaviour on complete
function QuestState:addInteractObjective(name,map,onCompleteF)
	self.Interact[name] = {
		Name = "Μίλα με "..name,
		TargetName = name,
		TargetMap = map,
		onComplete = onCompleteF
	}
end

return QuestState

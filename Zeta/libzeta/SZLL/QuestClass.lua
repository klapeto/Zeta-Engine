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

local QClass = require('SZLL.Class')()
--------------------------------------------------------------------------------
-- Quest Class module
-- Provides fundamental data for QuestClass creation
-- @module SZLL.QuestClass

--------------------------------------------------------------------------------
-- Quest Class
-- QuestClasses are created to define the Quests that can be accepted
-- @type QuestClass
-- @field [parent=#QuestClass] #string Name The Name of the Quest
-- @field [parent=#QuestClass] #table Objectives The Objectives Queue

--------------------------------------------------------------------------------
-- QuestClass constructor
--
-- @function [parent=#QuestClass] init
-- @param self
-- @param #string Name The Quest Name

--------------------------------------------------------------------------------
-- QuestClass constructor
--
-- @callof #SZLL.QuestClass
-- @param self
-- @param #string Name The Quest Name
function QClass:init(Name)
	self.Name = Name or "Anonymous Quest"
	self.Objectives = {}
end

--------------------------------------------------------------------------------
-- Adds the Objective to the front of the Queue
--
-- @function [parent=#QuestClass] addObjective
-- @param self
-- @param SZLL.Objective#Objective Objective The Objective to be added
function QClass:addObjective(Objective)
	self.Objectives[#self.Objectives+1] = Objective
end

--------------------------------------------------------------------------------
-- Creates a new Quest
-- 
-- @function [parent=#QuestClass] CreateQuest
-- @param sefl
-- @return SZLL.Quest#Quest The new Quest
function QClass:CreateQuest()
	return require('SZLL.Quest')(self)
end

return QClass

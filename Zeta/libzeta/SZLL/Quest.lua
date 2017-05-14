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
-- Quest Class
-- This class provides easy Quest Data Structure Creation
--
-- @module SZLL.Quest

--------------------------------------------------------------------------------
-- Quest Class
--
-- @type Quest
-- @field [parent=#Quest] SZLL.QuestClass#QuestClass Class The Class of the Quest
-- @field [parent=#Quest] SZLL.DeQueue#DeQueue Objectives The Quest Objectives
-- @field [parent=#Quest] SZLL.Objective#Objective CurObjective The Current Objective
-- @field [parent=#Quest] #boolean Complete True if Complete
local Quest = Class()	-- #SZLL.Quest
--------------------------------------------------------------------------------
-- Quest Constructor
-- Creates a Quest
--
-- @function [parent=#Quest] init
-- @param self
-- @param SZLL.QuestClass#QuestClass Class The Class of the quest
-- @return #Quest Returns the Created Quest

--------------------------------------------------------------------------------
-- Quest Constructor
-- Creates a Quest
--
-- @callof #SZLL.Quest
-- @param SZLL.QuestClass#QuestClass Class The Class of the quest
-- @return #Quest Returns the Created Quest
function Quest:init(Class)
	self.Class = Class
	self.Objectives = require('SZLL.DeQueue')()
	for i,v in ipairs(self.Class.Objectives) do
		self.Objectives:pushFront(v)
	end
end

--------------------------------------------------------------------------------
-- Activates this Quest
--
-- @function [parent=#Quest] Activate
-- @param self
function Quest:Activate()
	self.CurObjective = require('SZLL.Objective')(self.Objectives:popFront())
	self.CurObjective:Activate(self)
	self.Complete = false
end

--------------------------------------------------------------------------------
-- Notifies the Quest that an Objective was completed
--
-- @function [parent=#Quest] NotifyObjectiveCompleted
-- @param self
-- @param SZLL.Objective#Objective Objective The Completed Objective
function Quest:NotifyObjectiveCompleted(Objective)
	if (self.Objectives:isEmpty()) then
		self.Complete = true
		self.CurObjective = nil
	else
		self.CurObjective = require('SZLL.Objective')(self.Objectives:popBack())
		self.CurObjective:Activate(self)
	end
end

return Quest

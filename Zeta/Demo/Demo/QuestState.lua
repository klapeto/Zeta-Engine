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
-- @module Demo.QuestState
-- @extends SZLL.QuestState#SZLL.QuestState  

--------------------------------------------------------------------------------
-- Quest State Class
-- 
-- @type QuestState
-- @extends SZLL.QuestState#QuestState
-- @field [parent=#QuestState] #string out the out string to produce

local State = Class(require('SZLL.QuestState'))
--------------------------------------------------------------------------------
-- Quest Constructor
-- Creates a Quest
-- 
-- @callof #Demo.QuestState
-- @param self
-- @param #string Name QuestState Name
-- @return #QuestState Returns the Created QuestState
function State:init(name)
	self.Name = name or ""
	self.out = "No out Text"
	self.Kill = {}
	self.Interact = {}
end

return State
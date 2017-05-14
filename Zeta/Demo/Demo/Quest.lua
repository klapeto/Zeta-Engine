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
-- @module Demo.Quest
-- @extends SZLL.Quest#SZLL.Quest

--------------------------------------------------------------------------------
-- Quest Class
--
-- @type Quest
-- @extends SZLL.Quest#Quest
-- @field [parent=#Quest] Demo.QuestClass#QuestClass Class The Quest Class
-- @field [parent=#Quest] Demo.Npc#Npc Npc The Npc that gave you this quest
local Quest = Class(require('SZLL.Quest')) -- #Demo.Quest

--------------------------------------------------------------------------------
-- Quest Constructor
-- Creates a Quest
--
-- @function [parent=#Quest] init
-- @param self
-- @param Demo.QuestClass#QuestClass Class The Quest Class
-- @return #Quest Returns the Created Quest

--------------------------------------------------------------------------------
-- Quest Constructor
-- Creates a Quest
--
-- @callof #Demo.Quest
-- @param self
-- @param Demo.QuestClass#QuestClass Class The Quest Class
-- @param Demo.Npc#Npc Npc The Npc that gave this Quest
-- @return #Quest Returns the Created Quest
function Quest:init(Class,Npc)
	self.Class = Class
	self.Npc = Npc
	require('Demo').Quests[Class.Name] = self

	for k,v in pairs(self.Class.QuestText) do
		Npc.Dialog[k] = v
	end

	Npc.Quests.count = Npc.Quests.count + 1

	do
		local replies= Npc.Dialog[Npc.IntroLine].Replies or {}
		replies[self.Class.Answer] = self.Class.Answer
		Npc.Dialog[Npc.IntroLine].Replies = replies
	end

	if (Npc.Quests.count == 1) then
		Npc:addOffAnimation(require('Demo.Sprites.QuestMark'))
	end

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
	self.CurObjective = require('Demo.Objective')(self.Objectives:popFront())
	self.CurObjective:Activate(self)
	self.Complete = false
	do
		local Npc = self.Npc
		Npc.Dialog[Npc.IntroLine].Replies[self.Class.Answer] = nil
		Npc.Quests.count = Npc.Quests.count-1
		if (Npc.Quests.count==0) then
			Npc:stopOffAnimation(require('Demo.Sprites.QuestMark'))
		end
	end

	require('Demo.Operations').onQuestAdd(self)
end

--------------------------------------------------------------------------------
-- Notifies the Quest that an Objective was completed
--
-- @function [parent=#Quest] NotifyObjectiveCompleted
-- @param self
-- @param Demo.Objective#Objective Objective The Completed Objective
function Quest:NotifyObjectiveCompleted(Objective)
	if (self.Objectives:isEmpty()) then
		self.Complete = true
		self.CurObjective = nil
		if (self.Npc) then
			self.Npc.Dialog[self.Npc.IntroLine].Replies[self.Class.End] = self.Class.End
			self.Npc:addOffAnimation(require('Demo.Sprites.QuestTurnIn'))
		end
	else
		self.CurObjective = require('Demo.Objective')(self.Objectives:popBack())
		self.CurObjective:Activate(self)
	end
end

--------------------------------------------------------------------------------
-- Actions Happening when Quest is actually complete
--
-- @function [parent=#Quest] onComplete
-- @param self
function Quest:onComplete()
	local Npc = self.Npc
	Npc.Dialog[Npc.IntroLine].Replies[self.Class.End] = nil

	Npc.Quests[self] = nil
	for k,v in pairs(self.Class.QuestText) do
		Npc.Dialog[k] = nil
	end
	self.Npc:stopOffAnimation(require('Demo.Sprites.QuestTurnIn'))
end

--------------------------------------------------------------------------------
-- Reset the Internal State
-- It sets self.Internal = nil
--
-- @function [parent=#Quest] Reset
-- @param self
function Quest:Reset()
	self.Internal = nil
	self.Track = nil
	self.QListItem = nil
end


return Quest

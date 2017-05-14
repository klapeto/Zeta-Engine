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
-- A Specialized Quest Class Module
--
-- @module Demo.QuestClass
-- @extends SZLL.QuestClass#SZLL.QuestClass

local QClass = require('SZLL.Class')(require('SZLL.QuestClass')) -- #Demo.QuestClass

--------------------------------------------------------------------------------
-- Quest Class With Quest Text
--
-- @type QuestClass
-- @extends SZLL.QuestClass#QuestClass
-- @field [parent=#QuestClass] Demo.Dialog#Dialog QuestText The Quest Text Dialog
-- @field [parent=#QuestClass] Demo.Dialog#Reply Answer The reply to start the Dialog of the Quest
-- @field [parent=#QuestClass] Demo.Dialog#Reply End The reply to the Dialog  that completes the Quest
-- @field [parent=#QuestClass] Demo.Quest#Quest Instance The Quest Instance if there is any
-- @field [parent=#QuestClass] #string Description The Quest description

--------------------------------------------------------------------------------
-- Quest Class Constructor
--
-- @callof #Demo.QuestClass
-- @param self
-- @param #string Name The Quest name
-- @return #QuestClass The New Quest Class

--------------------------------------------------------------------------------
-- Quest Class Constructor
--
-- @function [parent=#QuestClass] init
-- @param self
-- @param #string Name The Quest name
-- @return #QuestClass The New Quest Class
function QClass:init(Name)
	self.Name = Name
	self.Description = "No Description"
	self.Objectives = {}
	self.Answer = {Text = "Προχώρα στο παρασύνθημα!", NextLine = Name..'1'}
	self.End = {Text = "Τελείωσα την αποστολή"..self.Name, onInvoke = function() self:Complete() end}
	self.QuestText = {
		[Name..'1'] = {
			Text = "Bayer Leverkusen?",
			Replies = {
				{Text = "ΆΝΤΕ ΓΕΙΑ!!! ΆΝΤΕ ΓΕΙΑ!!", NextLine = Name..'2'}
			}
		},
		[Name..'2'] = {
			Text = "Ώρα να πηγαίνεις",
			onInvoke = function()
				self:Activate()
			end
		}
	}
end

--------------------------------------------------------------------------------
-- Activates the Quest
--
-- @function [parent=#QuestClass] Activate
-- @param self
-- @param Demo.Npc#Npc Npc The Npc that game this Quest
function QClass:Activate()
	self.Instance:Activate()
end

--------------------------------------------------------------------------------
-- Completes the Quest
--
-- @function [parent=#QuestClass] Complete
-- @param self
function QClass:Complete()
	self.Instance:onComplete()
	require('Demo.Operations').onQuestComplete(self.Instance)
	require('Demo').Quests[self.Name] = nil
	self.Instance = nil
end

--------------------------------------------------------------------------------
-- Creates a new Quest
--
-- @function [parent=#QuestClass] CreateQuest
-- @param self
-- @param Demo.Npc#Npc Npc The Npc that gave this Quest
-- @return Demo.Quest#Quest The new Quest
function QClass:CreateQuest(Npc)
	self.Instance = require('Demo.Quest')(self,Npc)
	return self.Instance
end


return QClass

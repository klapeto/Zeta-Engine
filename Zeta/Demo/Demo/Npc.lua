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
local Operations = require('Demo.Operations')

--------------------------------------------------------------------------------
-- Module for providing the Npc Class
-- Npc Objects can do various things
--
-- @module Demo.Npc
-- @extends SZLL.Npc#SZLL.Npc

--------------------------------------------------------------------------------
-- Npc Class
--
-- @type Npc
-- @extends SZLL.Npc#Npc
-- @field [parent=#Npc] #table Quests The Quests
local Npc = Class(require('SZLL.Npc'))

--------------------------------------------------------------------------------
-- Npc Constructor.
-- Creates a Npc from with the target Class,x,y
-- Be advised that a Core Npc is created too.
--
-- @callof #Demo.Npc
-- @param #string Class Filename of the Npc Class
-- @param #number x x cordinate
-- @param #number y y cordinate
-- @return #Npc Returned Npc
function Npc:init(class,x,y)
	self.Class = class or ""
	self.x = x or 0
	self.y = y or 0
	self.Name = "Uninitialized Npc"
	-- Set a default Dialog
	self.Dialog = {
		Default = {
			Text = "Γεία σου! Ωραία μέρα δεν είναι σήμερα;",
			Replies = {
				Text = "Ναι όντως!"
			}
		}
	}
	-- Set the Introductory Line
	self.IntroLine = "Default"
	self.Quests = {count=0}
	-- Register this NPC
	require('Demo').Npcs[self] = self
	self.Animations = {}
end

--------------------------------------------------------------------------------
--
-- @function [parent=#Npc] onClick
-- @param self
-- @param SZLL.Zeta#Zeta.Npc This The Npc Instance that was clicked
-- @param SZLL.Zeta#Zeta.Lifeform Other The One who clicked this Npc
function Npc:onClick(This, Other)
	if (This:getDistance(Other)<100) then
		if (self.Dialog[self.IntroLine]) then
			This:face(Other)
			Operations.SetDialog(self,This,self.IntroLine)
		end
		Other:face(This)
		local event = Zeta.WorldEvent()
		event:setAsInteractEvent(This,Other)
		event:broadcast()
	end
end

--------------------------------------------------------------------------------
-- Reset Function
-- Resets the Npc State to the Default. (Npc specific)
-- Useful when starting a new game
--
-- @function [parent=#Npc] Reset
-- @param self
function Npc:Reset()
	print("Empty Npc:Reset() was called")
end

--------------------------------------------------------------------------------
-- Adds a quest to available
--
-- @function [parent=#Npc] addQuest
-- @param self
-- @param Demo.QuestClass#Demo.QuestClass Quest The Quest to add
function Npc:addQuest(Quest)
	if (not Quest.Instance) then
		self.Quests[Quest] = Quest:CreateQuest(self)
	end
end

--------------------------------------------------------------------------------
-- Removes a quest
--
-- @function [parent=#Npc] removeQuest
-- @param self
-- @param Demo.Quest#Quest Quest The Quest to remove
function Npc:removeQuest(Quest)
	self.Quests[Quest] = nil
	self.Quests.count = self.Quests.count-1
	-- Remove all the Quest Dialog the Quest gave to it
	for k,v in pairs(Quest.QuestText) do
		self.Dialog[k] = nil
	end
	self.Dialog[self.IntroLine].Replies[Quest.Answer] = nil
	-- If it has no Quests, then remove the Questionmark
	if (self.Quests.count==0) then
		self:stopOffAnimation(require('Demo.Sprites.QuestMark'))
	end
end

--------------------------------------------------------------------------------
-- Removes a quest
--
-- @function [parent=#Npc] hasQuests
-- @param self
-- @return #boolean True if it has
function Npc:hasQuests()
	return self.Quests.count > 0
end

return Npc

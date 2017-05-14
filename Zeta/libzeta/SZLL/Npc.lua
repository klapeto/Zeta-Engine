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
--             ____           ______     _         _                          --
--            / _  \         / _   /    | |       | |                         --
--            \/ / /         |/ / /     | |       | |                         --
--              / /            / /      | |       | |                         --
--             / /_/\         / /_/|    | |____   | |____                     --
--             \____/tandard /_____/eta |_____/ua |_____/ibrary               --
--                                                                            --
--                      Standard Zeta Lua Library                             --
--------------------------------------------------------------------------------

local Class = require('SZLL.Class')

--------------------------------------------------------------------------------
-- Module for providing the Npc Class
-- Npc Objects can do various things
--
-- @module SZLL.Npc

--------------------------------------------------------------------------------
-- Reply
--
-- @type Reply
-- @field [parent=#Reply] #string Text The reply Text
-- @field [parent=#Reply] #string NextLine The Next Line onReply
-- @field [parent=#Reply] #function onInvoke What calls onReply

--------------------------------------------------------------------------------
-- Dialog Line
--
-- @type DialogLine
-- @field [parent=#SZLL.Npc.DialogLine] #string Text The Line Text
-- @field [parent=#SZLL.Npc.DialogLine] #map<#string,#Reply> Replies The Replies
-- @field [parent=#SZLL.Npc.DialogLine] #function onInvoke Actions when Line is loaded

--------------------------------------------------------------------------------
-- Dialog
--
-- @type Dialog
-- @map <#string,#DialogLine>

--------------------------------------------------------------------------------
-- Npc Class
--
-- @type Npc
-- @field [parent=#Npc] #string Name The Npc's Name
-- @field [parent=#Npc] SZLL.Zeta#Zeta.Lifeform Internal The Core data
-- @field [parent=#Npc] #Dialog Dialog The Npc Dialog Lines
-- @field [parent=#Npc] #string IntroLine The first Line of the Dialog
-- @field [parent=#Npc] #list<SZLL.OffAnimation#OffAnimation> Animations The OffAnimations
local Npc = Class()

--------------------------------------------------------------------------------
-- Npc Constructor.
-- Creates a Npc from with the target Class,x,y
-- Be advised that a Core Npc is created too.
--
-- @callof #SZLL.Npc
-- @param #string Class Filename of the Npc Class
-- @param #number x x cordinate
-- @param #number y y cordinate
-- @return #Npc Returned Npc
function Npc:init(class,x,y)
	self.Class = class or ""
	self.x = x or 0
	self.y = y or 0
	self.Name = "Uninitialized Npc"
	self.Dialog = {
		Default = {
			Text = "Γεία σου! Ωραία μέρα δεν είναι σήμερα;",
			Replies = {
				Text = "Ναι όντως!"
			}
		}
	}
	self.IntroLine = "Default"
	self.Animations = {}
end

--------------------------------------------------------------------------------
-- Add State (Dialog).
-- Adds a Dialog State Table. This is a non Zeta Engine-Core
-- function, and its behavior is defined by the user.
-- See the Zeta Engine Manual on the 'Standard Zeta Lua Library (SZLL)' Section
-- for the default behavioral details.
--
-- @function [parent=#Npc] addState
-- @param self
-- @param #string Name Name of the state, to be recaled later
-- @param #table Table The table to be added
function Npc:addLine(Name,Table)
	self.Dialog[Name]=Table
end

--------------------------------------------------------------------------------
-- Set States.
-- Set the states table with the one provided.
-- Be advised that the former states table is truncated.
--
-- @function [parent=#Npc] setStates
-- @param self
-- @param #table Tables The new Tables
function Npc:setStates(tables)
	self.Dialog=tables
	for k,v in pairs(self.Dialog) do
		self.IntroLine = k
		return nil
	end
end

--------------------------------------------------------------------------------
-- Set Current States.
-- Sets the current Dialog State
--
-- @function [parent=#Npc] setIntroLine
-- @param self
-- @param #string LineName The stateName to be used
function Npc:setIntroLine(LineName)
	self.IntroLine = LineName
end

--------------------------------------------------------------------------------
-- On Click Callback.
-- A callback that is called when this Npc is clicked
-- You can override it
--
-- @function [parent=#Npc] onClick
-- @param self
-- @param SZLL.Zeta#Zeta.Npc This The Npc Instance that was clicked
-- @param SZLL.Zeta#Zeta.Lifeform Other The One who clicked this Npc
function Npc:onClick(This, Other)
	print(self.Name.." was clicked from "..Other:getName())
end

--------------------------------------------------------------------------------
-- On Collision Callback.
-- A callback that is called when this Npc is collided
-- by another
--
-- @function [parent=#Npc] onCollision
-- @param self
-- @param SZLL.Zeta#Zeta.Npc This The Npc Instance that was clicked
-- @param SZLL.Zeta#Zeta.Lifeform Other The One who clicked this Npc
function Npc:onCollision(This, Other)
	print(self.Name.." was colided from "..Other:getName())
end

--------------------------------------------------------------------------------
-- toString.
-- returns the Name of the Npc
--
-- @function [parent=#Npc] __tostring
-- @param self
-- @return #string Name of the Npc
function Npc:__tostring()
	return self.Name
end

--------------------------------------------------------------------------------
-- Adds an OffAnimation to be loaded on initialazation.
--
-- @function [parent=#Npc] addOffAnimation
-- @param self
-- @param SZLL.OffAnimation#OffAnimation OffAnimation the OffAnimation
function Npc:addOffAnimation(OffAnimation)
	self.Animations[OffAnimation] = OffAnimation
	if (self.Internal) then
		OffAnimation:assign(self.Internal)
	end
end

--------------------------------------------------------------------------------
-- Stops and OffAnimations
--
-- @function [parent=#Npc] stopOffAnimation
-- @param self
-- @param SZLL.OffAnimation#OffAnimation OffAnimation the OffAnimation
function Npc:stopOffAnimation(OffAnimation)
	self.Animations[OffAnimation] = nil
	if (self.Internal) then
		OffAnimation:remove(self.Internal)
	end
end

--------------------------------------------------------------------------------
-- Initializes the NPC
--
-- @function [parent=#Npc] initialize
-- @param self
function Npc:initialize()
	if (not self.Internal) then
		self.Internal = Zeta.Npc:new(self.Class,self.x,self.y,self)
		self.Name = self.Internal:getName()
		for k,v in pairs(self.Animations) do
			v:assign(self.Internal)
		end
		self.Initialized = true
	end
end

--------------------------------------------------------------------------------
-- Deinitializes the NPC
--
-- @function [parent=#Npc] deinitialize
-- @param self
function Npc:deinitialize()
	if (self.Internal) then
		local pos = self.Internal:getPosition()
		self.x = pos:getX()
		self.y = pos:getY()
		self.Internal:delete()
		self.Internal=nil
	end
end

return Npc

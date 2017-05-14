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
-- Playable Class
-- A Class for creating standard Demo Playable Characters
--
-- @module Demo.PlayableCharacter
--
-- @type PlayableCharacter
-- @field [parent=#PlayableCharacter] #string Name The Player's Name
-- @field [parent=#PlayableCharacter] #string Description The Player's description
-- @field [parent=#PlayableCharacter] #string Spec The Player's speciliazation
-- @field [parent=#PlayableCharacter] #string Avatar The Player's GUI Avatar
-- @field [parent=#PlayableCharacter] #string Image The Player's GUI Image
-- @field [parent=#PlayableCharacter] #string Class The Player's Zeta Lifeform Class
-- @field [parent=#PlayableCharacter] #table Abilities The Player's Abilities
local Playable = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- PlayableCharacter Constructor
-- 
-- @callof #Demo.PlayableCharacter
-- @param #string Name The Player Name
-- @return #PlayableCharacter The created character
function Playable:init(Name)
	self.Name = Name or "Unamed"
	self.Description = self.Name.." Description"
	self.Spec = "No Spec"
	self.Avatar = "No Avatar"
	self.Image = "No Image"
	self.Class = "Classless"
	self.Abilities = {}
end

--------------------------------------------------------------------------------
-- Initialise Abilities
-- Initialises the Skills and Windows related
-- 
-- @function [parent=#PlayableCharacter] InitialiseSkills
function Playable:InitialiseSkills(parameters)
	print ("Called empty InitialiseSkills of "..self.Name)
end

return Playable

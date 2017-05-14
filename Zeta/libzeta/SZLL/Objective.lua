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

local Objective = require('SZLL.Class')() -- #SZLL.Objective

--------------------------------------------------------------------------------
-- Module for providing the Objective Class
-- @module SZLL.Objective

--------------------------------------------------------------------------------
-- Objectives are assigned to Quests as to be completed
-- @type Objective
-- @field [parent=#Objective] SZLL.Quest#Quest Parent The Parent Quest
-- @field [parent=#Objective] #number Progress The Current Progress
-- @field [parent=#Objective] SZLL.ObjectiveClass#ObjectiveClass Class The Class of the Object

--------------------------------------------------------------------------------
-- Objective Constructor
--
-- @callof #SZLL.Objective
-- @param self
-- @param SZLL.ObjectiveClass#ObjectiveClass Class The class of the Objective
-- @return #Objective The returned Object

--------------------------------------------------------------------------------
-- Objective Constructor
--
-- @function [parent=#Objective] init
-- @param self
-- @param SZLL.ObjectiveClass#ObjectiveClass Class The class of the Objective
-- @return #Objective The returned Object
function Objective:init(Class)
	self.Progress = 0
	self.Class = Class
end

--------------------------------------------------------------------------------
-- Activates this Objective
--
-- @function [parent=#Objective] Activate
-- @param self
-- @param SZLL.Quest#Quest Parent The Parent Quest that activates this Objective
function Objective:Activate(Parent)
	self.Class.onActive(self)
	self.Parent = Parent
end

--------------------------------------------------------------------------------
-- Called when the Objective is partly completed
--
-- @function [parent=#Objective] Step
-- @param self
function Objective:Step()
	self.Progress = self.Progress + 1
	if (self.Progress >= self.Class.NSteps) then
		self.Parent:NotifyObjectiveCompleted(self)
	end
end

return Objective

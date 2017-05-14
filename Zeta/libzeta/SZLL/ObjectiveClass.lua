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

local OClass = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- Module for providing the Objective Class
-- @module SZLL.ObjectiveClass

--------------------------------------------------------------------------------
-- Objectives are assigned to Quests as to be completed
-- @type ObjectiveClass
-- @field [parent=#ObjectiveClass] #string Name The Name of the Objective
-- @field [parent=#ObjectiveClass] #number NSteps The Number of steps to be completed
-- @field [parent=#ObjectiveClass] SZLL.QuestClass#QuestClass Parent The Parent Quest Class

--------------------------------------------------------------------------------
-- Objective Constructor
--
-- @callof #SZLL.ObjectiveClass
-- @param self
-- @param #string Name The Name of the Objective
-- @return #ObjectiveClass The returned Object

--------------------------------------------------------------------------------
-- Objective Constructor
--
-- @function [parent=#ObjectiveClass] init
-- @param self
-- @param #string Name The Name of the Objective
-- @return #ObjectiveClass The returned Object
function OClass:init(Name)
	self.Name = Name
	self.NSteps = 1
end

--------------------------------------------------------------------------------
-- Called when this Objective becomes Active
--
-- @function [parent=#ObjectiveClass] onActive
-- @param self
function OClass:onActive()
	print(self.Name .." onActive!")
end

--------------------------------------------------------------------------------
-- Called when this Objective is completed
--
-- @function [parent=#ObjectiveClass] onCompleted
-- @param self
function OClass:onCompleted()
	print(self.Name .." onComplete!")
end

return OClass

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
-- An Effect Class for creating non-durable Effects
-- Same as Abilities, Effects should overload the functions:
-- onApply() and onRemove()
--
-- @module SZLL.Effect

local Effect = Class()

--------------------------------------------------------------------------------
-- Ability Class
--
-- @type Effect
-- @field [parent=#Effect] #string Name The Name of the Effect

--------------------------------------------------------------------------------
-- Create a new Effect
-- @callof #SZLL.Effect
-- @param #string Name The name of the desired Effect
-- @return #Effect the created Effect
function Effect:init(Name)
	self.Name = Name or "Unamed Effect"
	self.Ability = "None"
end

--------------------------------------------------------------------------------
-- onApply Callback
-- You should not call this function as it is the Engine's Core responsibility
-- to call it. You should only override it.
--
-- @function [parent=#SZLL.Effect] onApply
-- @param Zeta#Lifeform Owner The Lifeform that has the Effect
-- @param #number Level The level of the Effect
function Effect.onApply(owner,level)
	print("Default callback 'onApply' was called from an Effect: "..Effect.Name.." of ability: "..tostring(Effect.Ability))
end

--------------------------------------------------------------------------------
-- onRemove Callback
-- You should not call this function as it is the Engine's Core responsibility
-- to call it. You should only override it.
--
-- @function [parent=#SZLL.Effect] onRemove
-- @param #number Level The level of the Effect
function Effect.onRemove(owner,level)
	print("Default callback 'onRemove' was called from an Effect: "..Effect.Name.." of ability: "..tostring(Effect.Ability))
end

return Effect

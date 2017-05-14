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
-- A class for creating OffAnimations
--
-- @module SZLL.OffAnimation

--------------------------------------------------------------------------------
-- OffAnimation Class
--
-- @type OffAnimation
-- @field [parent=#OffAnimation] #string Name The Name of the Ability
-- @field [parent=#OffAnimation] #string AnimationPack The container Animation Pack

local OffAnimation = require('SZLL.Class')()
--------------------------------------------------------------------------------
-- Create a new OffAnimation
-- @callof #SZLL.OffAnimation
-- @param #string Name The name of the desired ability
-- @param #number AnimationPack The container Animation Pack
-- @return #OffAnimation the created Ability
function OffAnimation:init(Name,AnimationPack)
	self.Name = Name
	self.AnimationPack = AnimationPack
end

--------------------------------------------------------------------------------
-- Assigns the Animation to the Lifeform
-- 
-- @function [parent=#OffAnimation] assign
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform to assing to
function OffAnimation:assign(Lifeform)
	Lifeform:addOffAnimation(Zeta.AnimationEffectsManager:getInstance():getAnimationFX(self.Name,self.AnimationPack),0,0,0)
end

--------------------------------------------------------------------------------
-- Removes the Animation to the Lifeform
-- 
-- @function [parent=#OffAnimation] remove
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform to assing to
function OffAnimation:remove(Lifeform)
	Lifeform:getAnimationHandler():getOffAnimation(self.Name,0):stop()
end

return OffAnimation
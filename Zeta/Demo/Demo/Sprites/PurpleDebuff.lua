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

---
-- QuestMark Animation
-- 
-- @module Demo.Sprites.PurpleDebuff
local Mark = require('SZLL.OffAnimation')("PurpleDebuff","FX")

--------------------------------------------------------------------------------
-- QuestMark Animation
--
-- @type Demo.Sprites.PurpleDebuff

--------------------------------------------------------------------------------
-- Assigns the Animation to the Lifeform
-- 
-- @function [parent=#Demo.Sprites.PurpleDebuff] assign
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform to assing to
function Mark:assign(Lifeform)
	Lifeform:addOffAnimation(Zeta.AnimationEffectsManager:getInstance():getAnimationFX(self.Name,self.AnimationPack),0,Lifeform:getTargetArea():getY()-Lifeform:getPosition():getY()-38,0)
end

return Mark
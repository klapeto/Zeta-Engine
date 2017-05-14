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
-- Module for providing Projectiles
-- 
-- @module SZLL.Projectile
local Class = require('SZLL.Class')
local Projectile = Class()

--------------------------------------------------------------------------------
-- Projectile Type
-- 
-- @type Projectile
-- @field [parent=#Projectile] #string AnimationClass The projectiles AnimationClass
-- @field [parent=#Projectile] #number Speed The Projectile speed
-- @field [parent=#Projectile] #number Type The Projectile Type

--------------------------------------------------------------------------------
-- Projectile Constructor
-- 
-- @callof #SZLL.Projectile
-- @param #string AnimationClass The Animation Class Path
-- @param #number Speed The projectile's speed
-- @return #Projectile The new Object

--------------------------------------------------------------------------------
-- Projectile Constructor
-- 
-- @function [parent=#Projectile] init
-- @param self
-- @param #string AnimationClass The Animation Class Path
-- @param #number Speed The projectile's speed
-- @return #Projectile The new Object
function Projectile:init(class,speed)
	self.AnimationClass = class
	self.Speed = speed or 4
	self.Type = 1
end

--------------------------------------------------------------------------------
-- Set the Projectile Type
-- see Zeta.ProjectileClass for available types
-- 
-- @function [parent=#Projectile] setType
-- @param self
-- @param #number Type The new type
function Projectile:setType(value)
	self.Type = value
end

--------------------------------------------------------------------------------
-- Actions Happening when the Projectile is starts it's journey
-- 
-- @function [parent=#SZLL.Projectile] onRelease
-- @param SZLL.Zeta#Zeta.Projectile The Projectile Released
function Projectile.onRelease(projectile)

end

--------------------------------------------------------------------------------
-- Actions Happening when the Projectile collides with an collidable Object
-- 
-- @function [parent=#SZLL.Projectile] onCollision
-- @param SZLL.Zeta#Zeta.Projectile The Projectile Released
function Projectile.onCollision(projectile,victim)
	print("Collide!")
end

--------------------------------------------------------------------------------
-- Actions Happening when the Projectile collides ends the Journey
-- 
-- @function [parent=#SZLL.Projectile] onDestinationReach
-- @param SZLL.Zeta#Zeta.Projectile The Projectile Released
function Projectile.onDestinationReach(projectile)

end

return Projectile

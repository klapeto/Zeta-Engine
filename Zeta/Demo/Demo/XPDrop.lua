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

local XPDrop = require('SZLL.Class')(require('Demo.Drop'))
--------------------------------------------------------------------------------
-- Module for providing XP Drop items Class
--
-- @module Demo.XPDrop

--------------------------------------------------------------------------------
-- XP Drop Class
--
-- @type XPDrop
-- @field [parent=#XPDrop] #number Chance The Drop chance
-- @field [parent=#XPDrop] #number Amount The amount of XP to drop

--------------------------------------------------------------------------------
-- Drop Constructor
--
-- @callof #Demo.XPDrop
-- @param #number Amount The amount of XP to drop
-- @return #XPDrop The drop
function XPDrop:init(Amount)
	self.Chance = 100
	self.Amount = Amount or 100
end

--------------------------------------------------------------------------------
-- Invokes the Drop
--
-- @function [parent=#XPDrop] Invoke
-- @param self
function XPDrop:Invoke()
	require('Demo').Player:offsetXp(self.Amount)
end

return XPDrop

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
-- Double Ended Queue
-- 
-- @module SZLL.DeQueue
local Class = require('SZLL.Class')

--------------------------------------------------------------------------------
-- Double Ended Queue
-- @type DeQueue
local DeQueue = Class()

--------------------------------------------------------------------------------
-- DeQueue Constructor
-- 
-- @callof #SZLL.DeQueue
-- @return #DeQueue The returned Dequeue
function DeQueue:init()
	self.first = 0
	self.last = -1
end

--------------------------------------------------------------------------------
-- Pushes an value to Front
-- 
-- @function [parent=#DeQueue] pushFront
-- @param self
-- @param #string value The value to push
function DeQueue:pushFront(value)
	local first = self.first - 1
	self.first = first
	self[first] = value
end

--------------------------------------------------------------------------------
-- Pushes an value to Back
-- 
-- @function [parent=#DeQueue] pushBack
-- @param self
-- @param #string value The value to push
function DeQueue:pushBack(value)
	local last = self.last + 1
	self.last = last
	self[last] = value
end

--------------------------------------------------------------------------------
-- Pops and returns an value from Front
-- If empty, returns nil
-- 
-- @function [parent=#DeQueue] popFront
-- @param self
-- @return #string The poped value
function DeQueue:popFront()
	local first = self.first
	if first > self.last then return nil end
	local value = self[first]
	self[first] = nil
	self.first = first + 1
	return value
end

--------------------------------------------------------------------------------
-- Pops and returns an value from Back
-- If empty, returns nil
-- 
-- @function [parent=#DeQueue] popBack
-- @param self
-- @return #string The poped value
function DeQueue:popBack()
	local last = self.last
	if self.first > last then return nil end
	local value = self[last]
	self[last] = nil
	self.last = last - 1
	return value
end

--------------------------------------------------------------------------------
-- Checks if Dequeue is Empty
-- 
-- @function [parent=#DeQueue] isEmpty
-- @param self
-- @return #boolean True if empty, false otherwise
function DeQueue:isEmpty()
	return self.first > self.last
end

return DeQueue
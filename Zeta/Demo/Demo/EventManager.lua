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

local Manager = {
	Channels = {
		LevelChanged = {},
		PointsChanced = {},
		AbilityEnabled = {},
	}
}
--------------------------------------------------------------------------------
-- Custom Event Manager
--
-- @module Demo.EventManager

--------------------------------------------------------------------------------
-- Event Manger Type
--
-- @type EventManager

--------------------------------------------------------------------------------
-- Adds a Listener to the target Event Channel
--
-- @function [parent=#EventManager] AddListener
-- @param #string Channel The target channel
-- @param #table Listener The listener to remove
function Manager.AddListener(Channel,Listener)
	Manager.Channels[Channel][Listener] = Listener
end

--------------------------------------------------------------------------------
-- Removes a Listener from the designated Channel
-- 
-- @function [parent=#EventManager] RemoveListener
-- @param #string Channel The target channel
-- @param #table Listener The listener to remove
function Manager.RemoveListener(Channel,Listener)
	Manager.Channels[Channel][Listener] = nil
end

--------------------------------------------------------------------------------
-- Broadcasts an event
-- 
-- @function [parent=#EventManager] BroadcastEvent
-- @param #string Channel The target channel to broadcast the Event
-- @param #table Event The event to broadcast
function Manager.BroadcastEvent(Channel,Event)
	local table = Manager.Channels[Channel]
	for k,v in pairs(table) do
		v:AcknowledgeEvent(Event)
	end
end

return Manager

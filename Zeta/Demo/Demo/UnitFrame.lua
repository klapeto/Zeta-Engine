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
-- Unit Frame Class
--
-- @module Demo.UnitFrame
local Frame = require('SZLL.Class')()	-- #Demo.UnitFrame
--------------------------------------------------------------------------------
-- Unit Frame Type
--
-- @type UnitFrame
-- @field [parent=#UnitFrame] SZLL.CEGUI#CEGUI.Window Window The CEGUI Window the Frame is
-- @field [parent=#UnitFrame] SZLL.CEGUI#CEGUI.Window Name The name Window
-- @field [parent=#UnitFrame] SZLL.CEGUI#CEGUI.Window Level The level Window
-- @field [parent=#UnitFrame] SZLL.CEGUI#CEGUI.ProgressBar Health The health bar
-- @field [parent=#UnitFrame] SZLL.Zeta#Zeta.CEGUIChild ChildObj The ChildWindow
-- @field [parent=#UnitFrame] SZLL.Zeta#Zeta.Lifeform Lifeform Contains the Lifeform that owns this Frame (if any)

--------------------------------------------------------------------------------
-- UntiFrame Constructor
--
-- @function [parent=#UnitFrame] init
-- @param self
-- @param SZLL.CEGUI#CEGUI.Window Window The CEGUI Window the Frame is
function Frame:init(Window)
	self.Window = Window
	self.Name = Window:getChild("Name")
	self.Level = Window:getChild("Level")
	self.Health = CEGUI.toProgressBar(Window:getChild("Health"))
	Window:hide()
	Window:subscribeEvent("MouseButtonDown",Frame.onClick)
	Window:subscribeEvent("MouseEntersArea",Frame.onMouseEnters)
	Window:subscribeEvent("MouseLeavesArea",Frame.onMouseLeaves)
	self.ChildObj = Zeta.CEGUIChild(Window,false)
end

--------------------------------------------------------------------------------
-- Assigns the UnitFrame to a Lifeform
--
-- @function [parent=#UnitFrame] Assign
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Target Lifeform
function Frame:Assign(Lifeform)
	if (not self.Lifeform) then
		self.Lifeform = Lifeform
		self.ChildObj:setPosition(Lifeform:getPosition():getX()-75,Lifeform:getTargetArea():getY()-32)
		self.Name:setText(Lifeform:getName())
		self.Level:setText(tostring(Lifeform:getLevel()))
		self.Window:show()
		Lifeform:addChildObject("UnitFrame",self.ChildObj)
		local Pool = require('Demo.UnitFramePool')
		Pool.Lifeforms[Lifeform] = self
		Pool.Items[self.Window] = Lifeform
	end
end

--------------------------------------------------------------------------------
-- Updates the UnitFrame
--
-- @function [parent=#UnitFrame] Update
-- @param self
function Frame:Update()
	self.Health:setProgress(self.Lifeform:getAttributeValue("HP")/self.Lifeform:getAttributeValue("MaxHP"))
end

--------------------------------------------------------------------------------
-- Removes this UnitFrame from the current Lifeform
--
-- @function [parent=#UnitFrame] Release
-- @param self
function Frame:Release()
	if (self.Lifeform) then
		local Pool = require('Demo.UnitFramePool')
		self.Lifeform:removeChildObject("UnitFrame")
		Pool.Queue:pushBack(self)
		self.Window:hide()
		Pool.Lifeforms[self.Lifeform] = nil
		Pool.Items[self.Window] = nil
		self.Lifeform = nil
	end
end

--------------------------------------------------------------------------------
-- onClick Event Handler
--
-- @function [parent=#Demo.UnitFrame] onClick
-- @param SZLL.CEGUI#CEGUI.EventArgs Event The Event
function Frame.onClick(Event)
	local ev = Event:toMouseEventArgs()
	if (ev.button == CEGUI.RightButton)  then
		require('Demo').Player:moveToWorldPosition(ev.position.x,ev.position.y)
	elseif (ev.button==CEGUI.LeftButton) then
		local demo = require('Demo')
		demo.Player:setTarget(require('Demo.UnitFramePool').Items[ev.window])
	end
end

--------------------------------------------------------------------------------
-- onMouseEnters Event Handler
--
-- @function [parent=#Demo.UnitFrame] onMouseEnters
-- @param SZLL.CEGUI#CEGUI.EventArgs Event The Event
function Frame.onMouseEnters(Event)
	local ev = Event:toMouseEventArgs()
	ev.window:setProperty("ImageColours","tl:FF909090 tr:FF909090 bl:FF909090 br:FF909090")
end

--------------------------------------------------------------------------------
-- onMouseLeave Event Handler
--
-- @function [parent=#Demo.UnitFrame] onMouseLeaves
-- @param SZLL.CEGUI#CEGUI.EventArgs Event The Event
function Frame.onMouseLeaves(Event)
	local ev = Event:toMouseEventArgs()
	ev.window:setProperty("ImageColours","tl:FFFFFFFF tr:FFFFFFFF bl:FFFFFFFF br:FFFFFFFF")
end

return Frame

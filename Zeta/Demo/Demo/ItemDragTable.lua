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

local DragTable = require('SZLL.Class')(require('Demo.DragTable'))	-- #Demo.ItemDragTable
--------------------------------------------------------------------------------
-- Item DragTable Module
--
-- @module Demo.ItemDragTable
-- @extends Demo.DragTable#Demo.DragTable

--------------------------------------------------------------------------------
-- ItemDragTable Type
--
-- @type ItemDragTable
-- @extends Demo.DragTable#DragTable
-- @field [parent=#ItemDragTable] Demo.Item#Item Item The host Item instance

--------------------------------------------------------------------------------
-- ItemDragTable Constructor
--
-- @function [parent=#ItemDragTable] init
-- @param self
-- @param Demo.Item#Item Item The host Item instance
-- @return #ItemDragTable The returned item
function DragTable:init(Item)
	self.Item = Item
end

--------------------------------------------------------------------------------
-- Invocation Method
--
-- @function [parent=#ItemDragTable] Use
-- @param self
function DragTable:Use()
	self.Item.Class:Invoke(require('Demo').Player)
end

--------------------------------------------------------------------------------
-- Update Method
--
-- @function [parent=#ItemDragTable] Update
-- @param self
-- @param #table Container The Container Window
function DragTable:Update(Container)
	local cool = self.Item.Class.Cooldown
	if (cool) then
		cool = cool:getRemainingTime()
		local Progress = CEGUI.toProgressBar(Container.this:getChild("Drag/Progress"))
		if (cool > 0) then
			--If it has Cooldown left
			if (Container.Set == nil) then
				--If Cooldown Progress is not Shown, show it
				Container.Hidden = nil
				Container.Set = true
				Container.CoolDown:show()
			end
			-- Update The cooldown Text, Progresss
			Container.CoolDown:setText(string.format("%.2f",cool))
			Progress:setProgress(cool/ab:getCoolDown())
		else
			-- If there is no cooldown Left
			if (Container.Hidden==nil) then
				-- If it is not hidden, hide the text and progress
				Container.Set=nil
				Container.CoolDown:hide()
				Container.Hidden=true
			end

		end
	end
end

return DragTable

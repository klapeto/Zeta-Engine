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

local Table = require('SZLL.Class')()
local Demo = require('Demo')
local Operations = require('Demo.Operations')
--------------------------------------------------------------------------------
-- AbilityDragTable Module
--
-- @module Demo.AbilityDragTable
--

--------------------------------------------------------------------------------
-- AbilityDragTable Type
--
-- @type AbilityDragTable
-- @field [parent=#AbilityDragTable] Demo.AbilityNode#AbilityNode Node The Ability


--------------------------------------------------------------------------------
-- AbilityDragTable Constructor
--
-- @callof #Demo.AbilityDragTable
-- @param Demo.AbilityNode#AbilityNode Ability The Ability
-- @return #AbilityDragTable The AbilityDragTable
function Table:init(Ability)
	self.Node = Ability
end

--------------------------------------------------------------------------------
-- Invocation Method
--
-- @function [parent=#AbilityDragTable] Use
-- @param self
function Table:Use()
	local skill = Demo.Player:getActiveAbility(self.Node.Ability.Name)

	-- Check if the Ability has valid Level (eg Not yet aquired)
	if (skill:getLevel()>0) then
		-- Invoke the ability and get the result
		local ret =Demo.Player:invokeAbility(self.Node.Ability.Name)
		-- Depending on the result print something
		if (ret==0) then
			Operations.CombatLog("Η Ικανότητα είχε επιτυχία!")
		elseif (ret==1) then
			Operations.CombatLog("Η Ικανότητα έχει ακόμα επαναφόρτωση!")
		elseif (ret==2) then
			Operations.CombatLog("Δεν έχεις στόχο!")
		elseif (ret==3) then
			Operations.CombatLog("Δεν έχεις Mana!")
		elseif (ret==4) then
			Operations.CombatLog("Είσαι εκτός εμβέλειας!")
		elseif (ret==5) then
			Operations.CombatLog("Ο στόχος είναι Νεκρός!")
		elseif (ret==6) then
			Operations.CombatLog("Ο στόχος είναι φιλικός!")
		elseif (ret==7) then
			Operations.CombatLog("Άγνωστο Σφάλμα!")
		end
	else
		-- If the level is 0, then we haven't learned It yet
		Operations.CombatLog("Η τεχνική δεν έχει μαθευτεί!")
	end

end

--------------------------------------------------------------------------------
-- Update Method
--
-- @function [parent=#AbilityDragTable] Update
-- @param self
-- @param #table Container The Container Window
function Table:Update(Container)
	local ab = Demo.Player:getActiveAbility(self.Node.Ability.Name)
	local cool = ab:getRemainingCooldown()
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

return Table

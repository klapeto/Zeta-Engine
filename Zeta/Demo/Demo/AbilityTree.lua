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
-- Ability Tree
--
-- @module Demo.AbilityTree
local Tree = require('SZLL.Class')()

--------------------------------------------------------------------------------
-- Ability Tree Type
--
-- @type AbilityTree

--------------------------------------------------------------------------------
-- Constructs an Ability Tree
--
-- @callof #Demo.AbilityTree
-- @return #AbilityTree The new object

--------------------------------------------------------------------------------
-- Constructs an Ability Tree
--
-- @function [parent=#AbilityTree] init
-- @param self
-- @return #AbilityTree The new object
function Tree:init()
	self.Nodes = {}
end

--------------------------------------------------------------------------------
-- Updates the AbilityTree
--
-- @function [parent=#AbilityTree] Update
-- @param self
function Tree:Update()
	for k,v in pairs(self.Nodes) do
		v:Update()
	end
end

--------------------------------------------------------------------------------
-- Adds an AbilityNode
--
-- @function [parent=#AbilityTree] AddNode
-- @param self
-- @param Demo.AbilityNode#AbilityNode Node The Node to Add
-- @param #number x X Position on the Abilities Window Grid
-- @param #number y y Position on the Abilities Window Grid
function Tree:AddNode(Node,x,y)
	Node.x = x
	Node.y = y
	self.Nodes[Node] = Node
end

--------------------------------------------------------------------------------
-- Applies this tree to The Abilities Window
--
-- @function [parent=#AbilityTree] Apply
-- @param self
function Tree:Apply()
	local Abilities = require('Demo.GUI.GameInterface').Abilities
	self:Reset()
	-- The abilities Window has already another Tree, remove them
	if (Abilities.Items) then
		for k,v in pairs(Abilities.Items) do
			Abilities.Container:removeChild(v)
		end
	end
	-- Create the table
	Abilities.Items = {}
	-- For each node we have
	for k,v in pairs(self.Nodes) do
		-- Set the Icon Position
		if (v.x and v.y) then
			v.Icon:setPosition(CEGUI.PropertyHelper:stringToUVector2('{{0,'..v.x..'},{0,'..v.y..'}}'))
		end
		-- Add this Item to the Window
		Abilities.Container:addChild(v.Icon)
		-- Give the ability to player
		v:SetToPlayer()
		-- Assign the icon to the table
		Abilities.Items[k] = v.Icon
	end
end

--------------------------------------------------------------------------------
-- Resets the Ability Tree and Window
--
-- @function [parent=#AbilityTree] Reset
-- @param self
function Tree:Reset()
	for k,v in pairs(self.Nodes) do
		v:Reset()
	end
end

return Tree

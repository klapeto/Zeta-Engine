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

local ItemDrop = require('SZLL.Class')(require('Demo.Drop'))
--------------------------------------------------------------------------------
-- Module for providing Item Drop items Class
--
-- @module Demo.ItemDrop

--------------------------------------------------------------------------------
-- Item Drop Class
--
-- @type ItemDrop
-- @field [parent=#ItemDrop] #number Chance The Drop chance
-- @field [parent=#ItemDrop] #number MinAmount The minimum amount of Items to drop
-- @field [parent=#ItemDrop] #number MaxAmount The maximum amount of Items to drop
-- @field [parent=#ItemDrop] Demo.ItemClass#ItemClass ItemClass The ItemClass to be dropped

--------------------------------------------------------------------------------
-- Drop Constructor
--
-- @callof #Demo.ItemDrop
-- @param Demo.ItemClass#ItemClass Class The ItemClass to drop
-- @param #number Chance The chance of the Droped item
-- @param #number MinAmount The minimum amount of Items to drop
-- @param #number MaxAmount The maximim amount of Items to drop
-- @return #ItemDrop The drop

--------------------------------------------------------------------------------
-- Drop Constructor
--
-- @function [parent=#ItemDrop] init
-- @param self
-- @param Demo.ItemClass#ItemClass Class The ItemClass to drop
-- @param #number Chance The chance of the Droped item
-- @param #number MinAmount The minimum amount of Items to drop
-- @param #number MaxAmount The maximim amount of Items to drop
-- @return #ItemDrop The drop
function ItemDrop:init(ItemClass, Chance, MinAmount,MaxAmount)
	self.ItemClass = ItemClass
	self.Chance = Chance or 100
	self.MinAmount = MinAmount
	self.MaxAmount = MaxAmount
end

--------------------------------------------------------------------------------
-- Invokes the Drop
--
-- @function [parent=#ItemDrop] Invoke
-- @param self
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that dropped this
function ItemDrop:Invoke(Lifeform)
	require('Demo.DroppedItem')(self,Lifeform)
end

return ItemDrop

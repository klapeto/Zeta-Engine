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
-- DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING F

--------------------------------------------------------------------------------
-- Damage Text Pool
-- 
-- @module Demo.DamageTextPool
-- @field [parent=#Demo.DamageTextPool] SZLL.DeQueue#DeQueue DamageTextPool The Damage Text Pool
local dmgPool = {
	DamageTextPool=require('SZLL.DeQueue')()
}

--------------------------------------------------------------------------------
-- Actions happening when the Window is hidden
-- 
-- @function [parent=#Demo.DamageTextPool] onDamageTextHidden
-- @param SZLL.CEGUI#CEGUI.EventArgs Event The Event arguments
function dmgPool.onDamageTextHidden(Event)
	local ev = CEGUI.toWindowEventArgs(Event)
	ev.window:setAlpha(1)
	local lev = CEGUI.EventArgs:new_local()
	ev.window:fireEvent("StopAnimation",lev)
	
	dmgPool.DamageTextPool:pushBack(ev.window)
end

--------------------------------------------------------------------------------
-- Here we add a few Damage texts to the Pool
do
	local gmInter = require('Demo.GUI.GameInterface').this
	for i=0,10 do
		local win = gmInter:createChild("Eftihia/DamageText") -- SZLL.CEGUI#CEGUI.Window
		win:hide()
		win:subscribeEvent("Hidden",dmgPool.onDamageTextHidden)
		dmgPool.DamageTextPool:pushBack(win)
	end
end

return dmgPool

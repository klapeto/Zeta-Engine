--------------------------------------------------------
-- GUI.MainMenu
-- This module provides easy accsess to Main Menu
-- and its childs
--
-- @module GUI.MainMenu


local GUI = require('Demo.GUI')
local root = GUI.Root
local toBtn = CEGUI.toPushButton
root:addChild(GUI.WindowManager:loadLayoutFromFile("MainMenu.layout"))
--------------------------------------------------------
-- MainMenu
--
-- @field [parent=#GUI.MainMenu] CEGUI#CEGUI.Window this The MainMenu Main window
-- @field [parent=#GUI.MainMenu] #table Buttons Table that contains the Buttons
-- @field [parent=#GUI.MainMenu.Buttons] CEGUI#CEGUI.Window this The Button CEGUI Container
-- @field [parent=#GUI.MainMenu.Buttons] CEGUI#CEGUI.Window Start The Start Button
local MainMenu = {
	this = root:getChild("MenuBackground"),
	Buttons = {
		this = root:getChild("MenuBackground/Buttons"),
		Start = toBtn(root:getChild("MenuBackground/Buttons/Start")),
		Options = toBtn(root:getChild("MenuBackground/Buttons/Options")),
		Load = toBtn(root:getChild("MenuBackground/Buttons/Load")),
		Attributions = toBtn(root:getChild("MenuBackground/Buttons/Attributions")),
		Exit = toBtn(root:getChild("MenuBackground/Buttons/Exit"))
	},
	AttriText = root:getChild("MenuBackground/AttributionsText")
}


function MainMenu.Buttons.Start_onMouseClick(event)
	local char = require('Demo.GUI.CharSelect')
	char.this:show()
	char.this:activate()
	MainMenu.Buttons.this:hide()
end

function MainMenu.Buttons.Load_onMouseClick(event)
	local Save = require('SZLL.SaveManager')
	Save.Load()
end

function MainMenu.Buttons.Options_onMouseClick(event)
	local options = require('Demo.GUI.Options')
	options.this:show()
	options.this:activate()
end

function MainMenu.Buttons.Exit_onMouseClick(event)
	Zeta.System:getInstance():shutdown()
end

function MainMenu.Buttons.Attributions_onMouseClick(event)
	if (MainMenu.AttriText:isVisible()) then
		MainMenu.AttriText:hide()
	else
		MainMenu.AttriText:show()
	end
end

local Buttons = MainMenu.Buttons

Buttons.Start:subscribeEvent("MouseClick",Buttons.Start_onMouseClick)
Buttons.Load:subscribeEvent("MouseClick",Buttons.Load_onMouseClick)
Buttons.Options:subscribeEvent("MouseClick",Buttons.Options_onMouseClick)
Buttons.Attributions:subscribeEvent("MouseClick",Buttons.Attributions_onMouseClick)
Buttons.Exit:subscribeEvent("MouseClick",Buttons.Exit_onMouseClick)

return MainMenu

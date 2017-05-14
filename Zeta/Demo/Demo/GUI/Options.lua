local GUI = require('Demo.GUI')

local root = GUI.Root

root:addChild(GUI.WindowManager:loadLayoutFromFile("Options.layout"))

local Options = {
	this = root:getChild("Options"),
	Resolutions = CEGUI.toCombobox(root:getChild("Options/ResolutionsCombo")),
	Cancel = CEGUI.toPushButton(root:getChild("Options/CancelButton")),
	Ok = CEGUI.toPushButton(root:getChild("Options/OkButton")),
	Music = tolua.cast(root:getChild("Options/Music"),"CEGUI::ToggleButton"),
	FullScreen = tolua.cast(root:getChild("Options/FullScreen"),"CEGUI::ToggleButton")
}

local function init_Options()

	Options.RTable = Zeta.Settings:getInstance():getResolutionsTable()
	local combo=Options.Resolutions
	local textColor = CEGUI.PropertyHelper:stringToColour("FF000000")
	for k,v in pairs(Options.RTable) do
		local itm = CEGUI.createListboxTextItem(k)
		itm:setTextColours(textColor)
		combo:addItem(itm)
	end
end
init_Options()

function Options.onCloseClicked(event)
	Options.this:hide()
end

function Options.Ok_onMouseClick(event)
	local combo=Options.Resolutions
	local res=combo:getSelectedItem()
	local settings = Zeta.Settings:getInstance()
	if (res) then
		settings:setResolution(Options.RTable[res:getText()])
	end
	if (Options.Music:isSelected()) then
		Zeta.System:getInstance():getAudioContext():setMainGain(1)
	else
		Zeta.System:getInstance():getAudioContext():setMainGain(0)
	end
	if (Options.FullScreen:isSelected()) then
		settings:setFullscreen(true)
	else
		settings:setFullscreen(false)
	end
	Options.this:hide()
end

Options.this:subscribeEvent("CloseClicked",Options.onCloseClicked)
Options.Cancel:subscribeEvent("MouseClick",Options.onCloseClicked)
Options.Ok:subscribeEvent("MouseClick",Options.Ok_onMouseClick)

return Options

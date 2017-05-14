local GUI = require('Demo.GUI')
local MainMenu = require('Demo.GUI.MainMenu')
local GameInterface = require('Demo.GUI.GameInterface')

local root = GUI.Root
local toBtn = CEGUI.toPushButton

root:addChild(GUI.WindowManager:loadLayoutFromFile("CharSelect.layout"))

local CharSelect = {
	this = root:getChild("CharacterSelect"),
	Avatar = root:getChild("CharacterSelect/CharAvatar"),
	Name = root:getChild("CharacterSelect/CharName"),
	Spec = root:getChild("CharacterSelect/CharSpec"),
	Descr = root:getChild("CharacterSelect/CharDescr"),

	List = CEGUI.toListbox(root:getChild("CharacterSelect/CharList")),

	Next = toBtn(root:getChild("CharacterSelect/NextStep")),
	Back = toBtn(root:getChild("CharacterSelect/BackStep"))
}

local PlayableCharacters = {
	['Ευτυχία'] = require('Demo.PlayableChars.Eftihia')
}

local function Init_Char()
	local charList = CEGUI.toListbox(CharSelect.List)
	local selColor=CEGUI.PropertyHelper:stringToColour("FF145CED")
	-- For all Playable Characters
	for k,v  in pairs(PlayableCharacters) do
		-- Create a List Box Item with the Char name
		local item=CEGUI.createListboxTextItem(v.Name)
		item:setSelectionBrushImage("Eftihia/LightCentre")
		item:setSelectionColours(selColor)
		-- Add it to the list
		charList:addItem(item)
	end

	do
		-- Select the First item and get the Char refering to
		local itm = charList:getListboxItemFromIndex(0)
		itm:setSelected(true)
		local plyr = PlayableCharacters[itm:getText()]
		-- Set the Text and Avatar
		CharSelect.Avatar:setProperty("Image",plyr.Image)
		CharSelect.Name:setText(plyr.Name)
		CharSelect.Spec:setText(plyr.Spec)
		CharSelect.Descr:setText(plyr.Description)
	end

	-- Subscribe to events
	CharSelect.Back:subscribeEvent("MouseClick",CharSelect.Back_onMouseClick)
	CharSelect.List:subscribeEvent("SelectionChanged",CharSelect.List_onSelectionChanged)
	CharSelect.Next:subscribeEvent("MouseClick",CharSelect.Next_onMouseClick)
	CharSelect.this:hide()
end



function CharSelect.Back_onMouseClick(event)
	-- Show the Main Menu
	MainMenu.Buttons.this:show()
	MainMenu.Buttons.this:activate()
	CharSelect.this:hide()
end


function CharSelect.List_onSelectionChanged(event)
	-- Get the Selected Item
	local item=CharSelect.List:getFirstSelectedItem()
	-- If Selected
	if (item) then
		-- Get the referenced Playable Char
		item=item:getText()
		local selChar = PlayableCharacters[item]
		-- Assign the texts of the Char
		CharSelect.Avatar:setProperty("Image",selChar.Image)
		CharSelect.Name:setText(selChar.Name)
		CharSelect.Spec:setText(selChar.Spec)
		CharSelect.Descr:setText(selChar.Description)
	end
end

function CharSelect.Next_onMouseClick(event)
	-- Check if there is a selected Char
	local item=CharSelect.List:getFirstSelectedItem()
	-- If selected something
	if (item) then
		-- Hide menu and char selection menu
		CharSelect.this:hide()
		MainMenu.this:hide()
		-- Get the Referenced Char
		item = item:getText()
		local charWin = GameInterface.CharWin
		-- Set the Game Interface Texts
		
		
		GameInterface.Avatar:setProperty("Image",PlayableCharacters[item].Avatar)
		charWin.Avatar:setProperty("Image",PlayableCharacters[item].Avatar)
		charWin.Name:setText(PlayableCharacters[item].Name)
		local Demo = require('Demo')
		Demo.GameReset()
		-- Set the Player Class
		Demo.Player:setClass(PlayableCharacters[item].Class)
		-- Change the Map
		require('Demo.Operations').ChangeMap(require('Demo.Maps.BriliosHouse'))
		-- Teleport the Player
		Demo.Player:teleportToCordinates(500,550)
		-- Set as a new Game
		require('SZLL.SaveManager').newGame=true
		-- Set the Player Name
		Demo.Player:setName(item)
		-- Load the Player
		Demo.LoadPlayer()
		-- Initialise the Player Abilities and Windows
		PlayableCharacters[item].InitialiseSkills()
	end
end

Init_Char()

return CharSelect

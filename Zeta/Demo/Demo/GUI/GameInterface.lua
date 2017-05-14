local GUI = require('Demo.GUI')

GUI.Root:addChild(GUI.WindowManager:loadLayoutFromFile("Game.layout"))

local DeQueue = require('SZLL.DeQueue')

local rootWindow = GUI.Root

local GameInterface = {
	this = rootWindow:getChild("GameInterface"),
	Fps = rootWindow:getChild("GameInterface/FPS"),
	PauseMenu = {
		this = rootWindow:getChild("GameInterface/GameMenu"),
		Resume = CEGUI.toPushButton(rootWindow:getChild("GameInterface/GameMenu/ResumeButton")),
		Save = CEGUI.toPushButton(rootWindow:getChild("GameInterface/GameMenu/SaveButton")),
		Exit = CEGUI.toPushButton(rootWindow:getChild("GameInterface/GameMenu/ExitButton"))
	},
	HealthBar = {
		this = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/HealthBar")),
		Text = rootWindow:getChild("GameInterface/HealthBar/Text")
	},
	ManaBar = {
		this = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/ManaBar")),
		Text = rootWindow:getChild("GameInterface/ManaBar/Text")
	},
	XpBar = {
		this = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/XPBar")),
		Text = rootWindow:getChild("GameInterface/XPBar/Text")
	},
	CharWin = {
		this = rootWindow:getChild("GameInterface/CharStats"),
		Name = rootWindow:getChild("GameInterface/CharStats/Name"),
		Hp = rootWindow:getChild("GameInterface/CharStats/Hp"),
		Mana = rootWindow:getChild("GameInterface/CharStats/Mana"),
		Level = rootWindow:getChild("GameInterface/CharStats/Level"),
		Patk = rootWindow:getChild("GameInterface/CharStats/Patk"),
		Matk = rootWindow:getChild("GameInterface/CharStats/Matk"),
		Pdef = rootWindow:getChild("GameInterface/CharStats/Pdef"),
		Mdef = rootWindow:getChild("GameInterface/CharStats/Mdef"),
		Avatar = rootWindow:getChild("GameInterface/CharStats/Avatar")
	},
	TargetStats = {
		this = rootWindow:getChild("GameInterface/TargetStats"),
		Name = rootWindow:getChild("GameInterface/TargetStats/Name"),
		Hp = rootWindow:getChild("GameInterface/TargetStats/Hp"),
		Mana = rootWindow:getChild("GameInterface/TargetStats/Mana"),
		Level = rootWindow:getChild("GameInterface/TargetStats/Level"),
		Patk = rootWindow:getChild("GameInterface/TargetStats/Patk"),
		Matk = rootWindow:getChild("GameInterface/TargetStats/Matk"),
		Pdef = rootWindow:getChild("GameInterface/TargetStats/Pdef"),
		Mdef = rootWindow:getChild("GameInterface/TargetStats/Mdef"),
		set = false
	},
	TargetBox = {
		this = rootWindow:getChild("GameInterface/TargetBox"),
		Name = rootWindow:getChild("GameInterface/TargetBox/Name"),
		HealthBar = {
			this = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/TargetBox/Health")),
			Text = rootWindow:getChild("GameInterface/TargetBox/Health/Text")
		},
		Level = {
			this = rootWindow:getChild("GameInterface/TargetBox/Level"),
			Text = rootWindow:getChild("GameInterface/TargetBox/Level/Text")
		}
	},
	Avatar = rootWindow:getChild("GameInterface/Avatar"),
	Level = {
		this = rootWindow:getChild("GameInterface/LevelBox"),
		Text = rootWindow:getChild("GameInterface/LevelBox/Level")
	},
	CharButton = CEGUI.toPushButton(rootWindow:getChild("GameInterface/CharButton")),
	MenuButton = CEGUI.toPushButton(rootWindow:getChild("GameInterface/MenuButton")),
	QuestsButton = {
		this = CEGUI.toPushButton(rootWindow:getChild("GameInterface/QuestsButton"))
	},
	CombatLog = CEGUI.toListbox(rootWindow:getChild("GameInterface/CombatLog")),
	Dialog = {
		this = CEGUI.toFrameWindow(rootWindow:getChild("GameInterface/Dialog")),
		Text = CEGUI.toMultiLineEditbox(rootWindow:getChild("GameInterface/Dialog/Text")),
		Replies = CEGUI.toListbox(rootWindow:getChild("GameInterface/Dialog/Replies")),
		States = {}
	},
	Quests = {
		this = CEGUI.toFrameWindow(rootWindow:getChild("GameInterface/Quests")),
		QuestList = CEGUI.toListbox(rootWindow:getChild("GameInterface/Quests/QuestList")),
		Text = CEGUI.toMultiLineEditbox(rootWindow:getChild("GameInterface/Quests/QuestText")),
		Rewards = CEGUI.toListbox(rootWindow:getChild("GameInterface/Quests/RewardList")),
		Quests = {},
	},
	SkillBox = {
		Skill1 = {
			this = rootWindow:getChild("GameInterface/SkillBox/SkillSlot1"),
			--Drag = CEGUI.toDragContainer(rootWindow:getChild("GameInterface/SkillBox/SkillSlot1/Skill")),
			--Progress = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/SkillBox/SkillSlot1/Skill/Progress")),
			CoolDown = rootWindow:getChild("GameInterface/SkillBox/SkillSlot1/CoolDown")
		},
		Skill2 = {
			this = rootWindow:getChild("GameInterface/SkillBox/SkillSlot2"),
			--Drag = CEGUI.toDragContainer(rootWindow:getChild("GameInterface/SkillBox/SkillSlot2/Skill")),
			--Progress = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/SkillBox/SkillSlot2/Skill/Progress")),
			CoolDown = rootWindow:getChild("GameInterface/SkillBox/SkillSlot2/CoolDown")
		},
		Skill3 = {
			this = rootWindow:getChild("GameInterface/SkillBox/SkillSlot3"),
			--Drag = CEGUI.toDragContainer(rootWindow:getChild("GameInterface/SkillBox/SkillSlot3/Skill")),
			--Progress = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/SkillBox/SkillSlot3/Skill/Progress")),
			CoolDown = rootWindow:getChild("GameInterface/SkillBox/SkillSlot3/CoolDown")
		},
		Skill4 = {
			this = rootWindow:getChild("GameInterface/SkillBox/SkillSlot4"),
			--Drag = CEGUI.toDragContainer(rootWindow:getChild("GameInterface/SkillBox/SkillSlot4/Skill")),
			--Progress = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/SkillBox/SkillSlot4/Skill/Progress")),
			CoolDown = rootWindow:getChild("GameInterface/SkillBox/SkillSlot4/CoolDown")
		},
		Skill5 = {
			this = rootWindow:getChild("GameInterface/SkillBox/SkillSlot5"),
			--Drag = CEGUI.toDragContainer(rootWindow:getChild("GameInterface/SkillBox/SkillSlot5/Skill")),
			--Progress = CEGUI.toProgressBar(rootWindow:getChild("GameInterface/SkillBox/SkillSlot5/Skill/Progress")),
			CoolDown = rootWindow:getChild("GameInterface/SkillBox/SkillSlot5/CoolDown")
		},
	},
	Notifier = {
		this = rootWindow:getChild("GameInterface/SpeechBuble"),
		Text = rootWindow:getChild("GameInterface/SpeechBuble/Text")
	},
	QuestObjs = CEGUI.toVerticalLayoutContainer(rootWindow:getChild("GameInterface/QuestObjs")),
	Abilities = {
		this = rootWindow:getChild("GameInterface/Abilities"),
		Points = rootWindow:getChild("GameInterface/Abilities/Points"),
		Container = rootWindow:getChild("GameInterface/Abilities/AbilitiesList")
	},
	Equipment = {
		this = rootWindow:getChild("GameInterface/Equipment"),
		Chest = rootWindow:getChild("GameInterface/Equipment/Chest"),
		Head = rootWindow:getChild("GameInterface/Equipment/Head"),
		Hands = rootWindow:getChild("GameInterface/Equipment/Hands"),
		Legs = rootWindow:getChild("GameInterface/Equipment/Legs"),
		Feet = rootWindow:getChild("GameInterface/Equipment/Feet"),
		Back = rootWindow:getChild("GameInterface/Equipment/Back"),
		Weapon = rootWindow:getChild("GameInterface/Equipment/Weapon"),
		OffHand = rootWindow:getChild("GameInterface/Equipment/OffHand"),
		Ring = rootWindow:getChild("GameInterface/Equipment/Ring"),
		Neck = rootWindow:getChild("GameInterface/Equipment/Neck")
	},
	Items = {
		this = rootWindow:getChild("GameInterface/Items"),
		Slots = DeQueue(),
		Slot1 = rootWindow:getChild("GameInterface/Items/Slot1"),
		Slot2 = rootWindow:getChild("GameInterface/Items/Slot2"),
		Slot3 = rootWindow:getChild("GameInterface/Items/Slot3"),
		Slot4 = rootWindow:getChild("GameInterface/Items/Slot4"),
		Slot5 = rootWindow:getChild("GameInterface/Items/Slot5"),
		Slot6 = rootWindow:getChild("GameInterface/Items/Slot6"),
		Slot7 = rootWindow:getChild("GameInterface/Items/Slot7"),
		Slot8 = rootWindow:getChild("GameInterface/Items/Slot8"),
		Slot9 = rootWindow:getChild("GameInterface/Items/Slot9"),
		Slot10 = rootWindow:getChild("GameInterface/Items/Slot10"),
		Slot11 = rootWindow:getChild("GameInterface/Items/Slot11"),
		Slot12 = rootWindow:getChild("GameInterface/Items/Slot12"),
		Slot13 = rootWindow:getChild("GameInterface/Items/Slot13"),
		Slot14 = rootWindow:getChild("GameInterface/Items/Slot14"),
		Slot15 = rootWindow:getChild("GameInterface/Items/Slot15"),
		Slot16 = rootWindow:getChild("GameInterface/Items/Slot16"),
	}
}

---
-- Resets the Interface to Standard mode
-- Like a new Game
--
-- @function [parent=#Demo.GUI.GameInterface] Reset
function GameInterface.Reset()
	GameInterface.this:hide()
	GameInterface.PauseMenu.this:hide()
	GameInterface.CharWin.this:hide()
	GameInterface.Dialog.this:hide()
	GameInterface.Quests.this:hide()
	GameInterface.Notifier.this:hide()
	GameInterface.Items.this:hide()
	GameInterface.Equipment.this:hide()
	GameInterface.Abilities.this:hide()
	do
		local queue = GameInterface.Items.Slots
		queue:pushBack(GameInterface.Items.Slot1)
		queue:pushBack(GameInterface.Items.Slot2)
		queue:pushBack(GameInterface.Items.Slot3)
		queue:pushBack(GameInterface.Items.Slot4)
		queue:pushBack(GameInterface.Items.Slot5)
		queue:pushBack(GameInterface.Items.Slot6)
		queue:pushBack(GameInterface.Items.Slot7)
		queue:pushBack(GameInterface.Items.Slot8)
		queue:pushBack(GameInterface.Items.Slot9)
		queue:pushBack(GameInterface.Items.Slot10)
		queue:pushBack(GameInterface.Items.Slot11)
		queue:pushBack(GameInterface.Items.Slot12)
		queue:pushBack(GameInterface.Items.Slot13)
		queue:pushBack(GameInterface.Items.Slot14)
		queue:pushBack(GameInterface.Items.Slot15)
		queue:pushBack(GameInterface.Items.Slot16)
	end
	do
		local Skill = GameInterface.SkillBox
		Skill.Skill1.CoolDown:hide()
		Skill.Skill2.CoolDown:hide()
		Skill.Skill3.CoolDown:hide()
		Skill.Skill4.CoolDown:hide()
		Skill.Skill5.CoolDown:hide()
	end
	do
		local n = GameInterface.QuestObjs:getChildCount()-1
		local questQueue =require('Demo.QuestTrackPool')
		local ListQueue = require('Demo.ListBoxItemPool')
		for i=0,n do
			local itm = GameInterface.QuestObjs:getChildAtIdx(i)
			questQueue:pushBack(itm)
			do
				local ObjList = CEGUI.toListbox(itm:getChild("Objectives"))
				local lnum = ObjList:getItemCount()-1
				for j=0,lnum do
					local lItem = ObjList:getListboxItemFromIndex(j)
					ListQueue:pushBack(lItem)
					ObjList:removeItem(lItem)
				end
			end
			GameInterface.QuestObjs:removeChild(itm)
		end
	end
end
GameInterface.Reset()

do
	GameInterface.Dialog.ReplyPool = {}
	local selColor = CEGUI.PropertyHelper:stringToColour("FF145CED")
	local textColor = CEGUI.PropertyHelper:stringToColour("FF000000")
	for i=0, 3 do

		local itm = CEGUI.createListboxTextItem(tostring(i),i,nil,false,false)
		itm:setTextColours(textColor)
		itm:setSelectionBrushImage("Eftihia/LightCentre")
		itm:setSelectionColours(selColor)
		GameInterface.Dialog.ReplyPool[i] = itm
	end
end

function GameInterface.Acknowledge_QuestComplete(Quest)
	local track = Quest.Track
	if (track) then
		local List = CEGUI.toListbox(track:getChild("Objectives"))
		local num = List:getItemCount()-1
		local ListQueue = require('Demo.ListBoxItemPool')
		for i=0,num do
			local itm = List:getListboxItemFromIndex(i)
			List:removeItem(itm)
			ListQueue:pushBack(itm)
		end
		GameInterface.QuestObjs:removeChild(track)
		require('Demo.QuestTrackPool'):pushBack(track)
		Quest.Track = nil
	end
end

---
--
-- @function [parent=#Demo.GUI.GameInterface] TrackQuest
-- @param Demo.Quest#Demo.Quest Quest The Quest To Track
function GameInterface.TrackQuest(Quest)
	if (Quest.Track) then
		local curState = Quest.CurObjective
		if (curState) then
			local ListQueue = require('Demo.ListBoxItemPool')
			local List = CEGUI.toListbox(Quest.Track:getChild("Objectives"))
			do
				local num = List:getItemCount()-1
				for i=0,num do
					local itm = List:getListboxItemFromIndex(i)
					List:removeItem(itm)
					ListQueue:pushBack(itm)
				end
			end
			do
				local itm = ListQueue:popFront()
				if (itm) then
					curState.Track = itm
					itm:setText(curState.Class.Name.."\t:"..tostring(curState.Progress).."/"..tostring(curState.Class.NSteps))
					List:addItem(itm)
				end
			end
		end
	else
		local Track = require('Demo.QuestTrackPool'):popFront()
		if (Track) then
			Quest.Track = Track
			Track:show()
			Track:getChild("Name"):setText(Quest.Class.Name)
			local curState = Quest.CurObjective
			if (curState) then
				local ListItems = require('Demo.ListBoxItemPool')
				local List = CEGUI.toListbox(Track:getChild("Objectives"))
				local itm = ListItems:popFront()
				if (itm) then
					curState.Track = itm
					itm:setText(curState.Class.Name.."\t:"..tostring(curState.Progress).."/"..tostring(curState.Class.NSteps))
					List:addItem(itm)
				end
			end
			GameInterface.QuestObjs:addChild(Track)
		end
	end
end

function GameInterface.Quests.QuestList_onSelectionChanged(event)
	GameInterface.Quests.QuestList_UpdateLists()
end

function GameInterface.Quests.QuestList_UpdateLists()
	local QuestW = GameInterface.Quests
	local item = QuestW.QuestList:getFirstSelectedItem()

	if (item) then
		local Qtbl = require('Demo').Quests[item:getText()] -- Demo.Quest#Demo.Quest
		if (Qtbl.Class.Description) then
			QuestW.Text:setText(Qtbl.Class.Description)
		else
			QuestW.Text:setText("Η Αποστολή δεν έχει κείμενο")
		end
	else
		QuestW.Text:setText("Δεν έχει επιλεγεί αποστολή")
	end
end

function GameInterface.Quests.onShown(event)

end

function GameInterface.onCloseClicked(event)
	event = CEGUI.toWindowEventArgs(event)
	event.window:hide()
end

function GameInterface.QuestsButton_onMouseClick(event)
	local qu = GameInterface.Quests.this
	if (qu:isVisible()) then
		qu:hide()
	else
		qu:show()
		qu:activate()
	end
end

function GameInterface.Dialog.Replies_onSelectionChanged(event)
	local item = GameInterface.Dialog.Replies:getFirstSelectedItem()
	if (item) then
		local Operations = require('Demo.Operations')
		Operations.SetDialog(GameInterface.Dialog.Npc,GameInterface.Dialog.NpcInstance,GameInterface.Dialog.States[item:getID()])
	end
end

function GameInterface.onDeactivated(event)
	Zeta.System:getInstance():getAudioContext():stop()
end

function GameInterface.onActivated(event)
	Zeta.System:getInstance():getAudioContext():start()
end

function GameInterface.PauseMenu.Exit_onMouseClick(event)
	local Demo = require('Demo')
	local MainMenu = require('Demo.GUI.MainMenu')
	local Save = require('SZLL.SaveManager')
	Save.firstLoad = true
	--Save.addMap(Demo.CurrentMap.name,Demo.CurrentMap:getData())
	--Demo.CurrentMap:deinitializeObjects()
	if (Demo.PreviousMap) then
	--	Demo.PreviousMap:deinitializeObjects()
	end
	Demo.PreviousMap = nil
	Demo.CurrentMap = nil
	GameInterface.this:hide()
	GameInterface.PauseMenu.this:hide()
	local mp =Zeta.WorldManager:getInstance()
	mp:hide()
	mp:pause()
	MainMenu.this:show()
	MainMenu.this:activate()
	MainMenu.Buttons.this:show()
end

function GameInterface.PauseMenu.Save_onMouseClick(event)
	require('SZLL.SaveManager').Save()
end

function GameInterface.PauseMenu.Resume_onMouseClick(event)
	GameInterface.PauseMenu.this:hide()
	Zeta.WorldManager:getInstance():resume()
end

function GameInterface.onMouseButtonDown(event)
local Demo = require('Demo')
	local ev = CEGUI.toMouseEventArgs(event)
	if (ev.button == CEGUI.RightButton)  then
		Demo.Player:moveToWorldPosition(ev.position.x,ev.position.y)
	elseif (ev.button==CEGUI.LeftButton) then
		Demo.Player:targetLifeformPosition(ev.position.x,ev.position.y)
	end
end

function GameInterface.onKeyUp(event)
	local event=CEGUI.toKeyEventArgs(event)
	if (event.scancode == CEGUI.Key.Escape) then
		local menu=GameInterface.PauseMenu.this
		if (menu:isVisible()) then
			menu:hide()
			Zeta.WorldManager:getInstance():resume()
		else
			menu:show()
			Zeta.WorldManager:getInstance():pause()
		end
	elseif (event.scancode == CEGUI.Key.C) then
		local chr = GameInterface.CharWin.this
		if (chr:isVisible()) then
			chr:hide()
		else
			chr:show()
			chr:activate()
		end
	elseif (event.scancode == CEGUI.Key.A) then
		local chr = GameInterface.this:getChild("Abilities")
		if (chr) then
			if (chr:isVisible()) then
				chr:hide()
			else
				chr:show()
				chr:activate()
			end
		end
	elseif (event.scancode == CEGUI.Key.Q) then
		GameInterface.InvokeAbility(GameInterface.SkillBox.Skill1)
	elseif (event.scancode == CEGUI.Key.W) then
		GameInterface.InvokeAbility(GameInterface.SkillBox.Skill2)
	elseif (event.scancode == CEGUI.Key.E) then
		GameInterface.InvokeAbility(GameInterface.SkillBox.Skill3)
	elseif (event.scancode == CEGUI.Key.R) then
		GameInterface.InvokeAbility(GameInterface.SkillBox.Skill4)
	elseif (event.scancode == CEGUI.Key.T) then
		GameInterface.InvokeAbility(GameInterface.SkillBox.Skill5)
	end
end

function GameInterface.CharButton_onClick(event)
	local win = GameInterface.CharWin.this
	if (win:isVisible()) then
		win:hide()
	else
		win:show()
	end
end


function GameInterface.onSkillDrop(event)
	local evArg = CEGUI.toDragDropEventArgs(event)

	if (evArg.dragDropItem:getID()==1) then
		evArg.dragDropItem:getParent():setID(0)
		evArg.window:addChild(evArg.dragDropItem)
		evArg.window:setID(1)
	else
		local Pool = require('Demo.DragIconPool')

		local itm = Pool.Queue:popBack() -- Demo.DragIcon#Demo.DragIcon

		if (itm) then
			itm:Copy(Pool.Table[evArg.dragDropItem:getUserString("Table")])
			itm.Window:setName("Drag")
			itm.Window:setID(1)
			evArg.window:addChild(itm.Window)
			evArg.window:setID(1)
		end
	end
end

function GameInterface.onDragIconDrop(Event)
	local evArg = CEGUI.toDragDropEventArgs(Event)
	if (evArg.dragDropItem:getID()==1) then
		local parent = evArg.dragDropItem:getParent()
		evArg.dragDropItem:setID(0)
		local Pool = require('Demo.DragIconPool')
		local Table = Pool.Table[evArg.dragDropItem:getUserString("Table")]
		Pool.Queue:pushBack(Table)
		parent:removeChild(evArg.dragDropItem)
		parent:setID(0)
		parent:getChild("CoolDown"):hide()
	end
end

function GameInterface.InvokeAbility(Icon)
	local Operations = require('Demo.Operations')
	if (Icon.this:getID()==1) then
		local Drag = Icon.this:getChild("Drag") -- SZLL.CEGUI#CEGUI.Window
		local Table = require('Demo.DragIconPool').Table[Drag:getUserString("Table")]
		Table.Table:Use()
	end
end

function GameInterface.onItemDrop(Event)
	local event = CEGUI.toDragDropEventArgs(Event)
	if (event.dragDropItem:getID()==1) then
		event.window:addChild(event.dragDropItem)
	end
end

local function init_subscriptions()
	local Console = require('Demo.GUI.Console')
	GameInterface.PauseMenu.this:subscribeEvent("CloseClicked",GameInterface.PauseMenu.Resume_onMouseClick)
	GameInterface.PauseMenu.Resume:subscribeEvent("MouseClick",GameInterface.PauseMenu.Resume_onMouseClick)
	GameInterface.PauseMenu.Save:subscribeEvent("MouseClick",GameInterface.PauseMenu.Save_onMouseClick)
	GameInterface.PauseMenu.Exit:subscribeEvent("MouseClick",GameInterface.PauseMenu.Exit_onMouseClick)
	GameInterface.this:subscribeEvent("KeyUp",GameInterface.onKeyUp)
	GameInterface.this:subscribeEvent("MouseButtonDown",GameInterface.onMouseButtonDown)
	GameInterface.this:subscribeEvent("KeyUp",Console.onKeyUp)
	GameInterface.this:subscribeEvent("Activated",GameInterface.onActivated)
	GameInterface.this:subscribeEvent("Deactivated",GameInterface.onDeactivated)
	GameInterface.Dialog.Replies:subscribeEvent("SelectionChanged",GameInterface.Dialog.Replies_onSelectionChanged)
	GameInterface.Dialog.this:subscribeEvent("CloseClicked",GameInterface.onCloseClicked)
	GameInterface.QuestsButton.this:subscribeEvent("MouseClick",GameInterface.QuestsButton_onMouseClick)
	GameInterface.Quests.this:subscribeEvent("CloseClicked",GameInterface.onCloseClicked)
	GameInterface.Quests.this:subscribeEvent("Shown",GameInterface.Quests.onShown)
	GameInterface.Quests.QuestList:subscribeEvent("SelectionChanged",GameInterface.Quests.QuestList_onSelectionChanged)
	GameInterface.CharButton:subscribeEvent("MouseClick",GameInterface.CharButton_onClick)
	GameInterface.SkillBox.Skill1.this:subscribeEvent("DragDropItemDropped",GameInterface.onSkillDrop)
	GameInterface.SkillBox.Skill2.this:subscribeEvent("DragDropItemDropped",GameInterface.onSkillDrop)
	GameInterface.SkillBox.Skill3.this:subscribeEvent("DragDropItemDropped",GameInterface.onSkillDrop)
	GameInterface.SkillBox.Skill4.this:subscribeEvent("DragDropItemDropped",GameInterface.onSkillDrop)
	GameInterface.SkillBox.Skill5.this:subscribeEvent("DragDropItemDropped",GameInterface.onSkillDrop)
	GameInterface.this:subscribeEvent("DragDropItemDropped",GameInterface.onDragIconDrop)
	do
		local Slots = GameInterface.Items.Slots
		for i=0,16 do
			local itm = Slots:popBack()
			itm:subscribeEvent("DragDropItemDropped",GameInterface.onItemDrop)
			Slots:pushFront(itm)
		end
	end
end
init_subscriptions()

return GameInterface

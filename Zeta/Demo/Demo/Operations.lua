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
local Demo = require('Demo')
local LoadingScreen = require('Demo.GUI.LoadingScreen')
local GameInterface = require('Demo.GUI.GameInterface')
local MainMenu = require('Demo.GUI.MainMenu')
local Pool = require('Demo.DragIconPool')

--------------------------------------------------------------------------------
-- Demo Operations
--
-- @module Demo.Operations
local operations = {}
operations.MainLoop = Zeta.MainLoop:getInstance()

--------------------------------------------------------------------------------
-- Change Map
-- Changes the map
--
-- @function [parent=#Demo.Operations] ChangeMap
-- @param SZLL.Map#SZLL.Map Map The Map Lua Table
function operations.ChangeMap(map)
	local path
	-- Swap the Demo.CurrentMap with the new one
	Demo.PreviousMap = Demo.CurrentMap
	Demo.CurrentMap = map
	-- Get the Map Filename
	path = map.filePath
	if (path) then
		local ld = LoadingScreen.this;
		local btn = LoadingScreen.Continue.this;

		-- Hide the Game Interface
		GameInterface.this:hide()
		-- Get a random Loading Screen to Show
		local i = math.random(#LoadingScreen.Bgs)
		local args = CEGUI.EventArgs()
		-- Stop the Fade out Animation of the Loading Screen (If it fades out from recent load)
		ld:fireEvent("FadeOutStop",args)
		-- Stop the Player's Movement
		Demo.Player:stopMoving()
		-- Remove the Players Target
		Demo.Player:setTarget(nil)
		-- The the Loading Screen Background
		ld:setProperty("Image",LoadingScreen.Bgs[i])
		-- Start the Loading Screen FadeIn animation
		ld:fireEvent("FadeInStart",args)
		ld:show()
		ld:activate()
		LoadingScreen.StatusText:setText("Φορτώνει...")
		-- Hide the Continue Button
		btn:hide()
		-- Let know the Loading Screen the Next Map
		LoadingScreen.NextMap = path
		-- Flag to notify to load it
		LoadingScreen.Loading = true
		-- Pause the game flow
		Zeta.WorldManager:getInstance():pause()
	end
end

--------------------------------------------------------------------------------
-- Adds a message to Message Log
--
-- @function [parent=#Demo.Operations] CombatLog
-- @param #string Message The Messaget to write to Log
function operations.CombatLog(Message)
	-- Get the Log List
	local log = GameInterface.CombatLog
	if (log:getItemCount()<20) then
		-- If list has less than 20 records, add a new one
		local itm = CEGUI.createListboxTextItem(Message,0,nil,false,false)
		itm:setTextColours(CEGUI.PropertyHelper:stringToColour("FFFFFFFF"))
		log:addItem(itm)
		log:ensureItemIsVisible(itm)
	else
		-- If list has 20 or more records, get the last one and bring to front with new text
		local itm = log:getListboxItemFromIndex(0)
		log:removeItem(itm)
		itm:setText(Message)
		log:addItem(itm)
		log:ensureItemIsVisible(itm)
	end
end

--------------------------------------------------------------------------------
-- Calculated and does Physical damage
--
-- @function [parent=#Demo.Operations] doPhysicalDamage
-- @param SZLL.Zeta#Zeta.Lifeform Victim The Damage's Victim
-- @param #number Amount The amount of damage to Deal
-- @return #number The actual Calculated Damage
function operations.doPhysicalDamage(Victim,Amount)
	-- Calculate the actual damage
	local dmg = -math.ceil((Amount*10)/Victim:getAttributeValue("Pdef")+0.5)
	-- Offset the Victims Hp
	Victim:offsetHP(dmg)
	operations.FloatingText(dmg,Victim,"FFac0000")
	-- Add an offanimation (Star Hit) to the Victim
	Victim:addOffAnimation(Zeta.AnimationEffectsManager:getInstance():getAnimationFX("Hit","FX"),0,0,Zeta.AnimationHandler.QueuePlace.Front)
	-- Add a message of the Damage to Log
	operations.CombatLog("O/H "..Victim:getName().. " δέχτηκε "..string.format("%d",dmg).. " άμεση Ζημιά!")
	return dmg
end

--------------------------------------------------------------------------------
-- Opens the Dialog Window and sets the target State
--
-- @function [parent=#Demo.Operations] SetDialog
-- @param Demo.Npc#Npc Npc The Npc we are Talking to
-- @param SZLL.Zeta#Zeta.Npc Npc The Npc Instance
-- @param #string LineName The name of the Line To show
function operations.SetDialog(NpcTable,Npc,LineName)
	local dialog = GameInterface.Dialog
	-- Set the what the Lifeform Says
	local State = NpcTable.Dialog[LineName]
	if (State) then
		dialog.Text:setText(State.Text)
		-- Let the Dialog what state and Lifeform it has
		dialog.Npc = NpcTable
		dialog.NpcInstance = Npc
		local replies = dialog.Replies
		-- Remove all previous replies
		replies:resetList()
		-- For all replies
		if (State.Replies) then
			local i = 0
			for k,v in pairs(State.Replies) do
				-- get an available reply and set the Text
				if (v.Text and v.NextLine) then
					local itm = dialog.ReplyPool[i]
					if (itm) then
						itm:setSelected(false)
						itm:setID(i)
						itm:setText(v.Text)
						dialog.States[i] = v.NextLine
						replies:addItem(itm)
					end
					i=i+1
				end
			end
		end
		-- Show The dialog
		dialog.this:show()
		dialog.this:activate()
		-- Invoke and actions attached to State
		local fn = State.onInvoke
		if (fn) then
			fn()
		end
	end
end

--------------------------------------------------------------------------------
-- Shows a Plate with a Message
--
-- @function [parent=#Demo.Operations] Notify
-- @param #string Message The Message to Show
function operations.Notify(Message)
	if (Message) then
		local ntf = GameInterface.Notifier.this
		local args = CEGUI.EventArgs:new_local()
		ntf:fireEvent("FadeOut2Stop",args)
		GameInterface.Notifier.Text:setText(Message)
		ntf:setAlpha(1)
		ntf:show()
		ntf:activate()
		ntf:fireEvent("FadeOut2Start",args)
		operations.CombatLog(Message)
	end
end

--------------------------------------------------------------------------------
-- Contains actions that will happen on every frame during Gameplay Only
--
-- @function [parent=#Demo.Operations] Update
function operations.Update()
	GameInterface.Fps:setText(string.format("%0.1f",operations.MainLoop:getCurrentFPS()))
	-- Update the Interface Text
	local hp = Demo.Player:getAttributeValue("HP")
	local maxhp = Demo.Player:getAttributeValue("MaxHP")
	local mana = Demo.Player:getAttributeValue("Mana")
	local maxMana = Demo.Player:getAttributeValue("MaxMana")
	local xp = Demo.Player:getXp()
	local maxXp = Demo.Player:getXpToNextLevel()
	GameInterface.HealthBar.this:setProgress(hp/maxhp)
	GameInterface.ManaBar.this:setProgress(mana/maxMana)
	GameInterface.XpBar.this:setProgress(xp/maxXp)
	GameInterface.HealthBar.Text:setText(tostring(hp).."/"..tostring(maxhp))
	GameInterface.ManaBar.Text:setText(tostring(mana).."/"..tostring(maxMana))
	GameInterface.Level.Text:setText(tostring(Demo.Player:getLevel()))
	GameInterface.XpBar.Text:setText(tostring(xp).."/"..tostring(maxXp))
	if (Demo.Player:hasTarget()) then
		-- If Player has a target
		local trg=GameInterface.TargetBox
		local target = Demo.Player:getTarget()
		local stats = GameInterface.TargetStats
		-- Show the Target Box and Target's Info
		if (target:isDirty()) then
			local thp = target:getAttributeValue("HP")
			local tmaxhp = target:getAttributeValue("MaxHP")
			local tname = target:getName()
			trg.Name:setText(tname)
			trg.HealthBar.this:setProgress(thp/tmaxhp)
			trg.HealthBar.Text:setText(tostring(thp).."/"..tostring(tmaxhp))
			trg.Level.Text:setText(tostring(target:getLevel()))
			stats.Name:setText(tname)
			stats.Hp:setText(tostring(thp).."/"..tostring(tmaxhp))
			stats.Level:setText(tostring(target:getLevel()))
			stats.Mana:setText(tostring(target:getAttributeValue("Mana")).."/"..tostring(target:getAttributeValue("MaxMana")))
			stats.Patk:setText(tostring(target:getAttributeValue("Patk")))
			stats.Pdef:setText(tostring(target:getAttributeValue("Pdef")))
			stats.Matk:setText(tostring(target:getAttributeValue("Matk")))
			stats.Mdef:setText(tostring(target:getAttributeValue("Mdef")))
			stats.set = false
		end
		if (not trg.this:isVisible()) then
			trg.this:show()
			trg.this:activate()
		end
	else
		-- If there is no target
		-- Reset Target Info
		local stats = GameInterface.TargetStats
		GameInterface.TargetBox.this:hide()
		if (stats.set==false) then
			stats.Name:setText('----')
			stats.Hp:setText('----/----')
			stats.Level:setText('---')
			stats.Mana:setText('----/----')
			stats.Patk:setText('----')
			stats.Pdef:setText('----')
			stats.Matk:setText('----')
			stats.Mdef:setText('----')
			stats.set = true
		end
	end
	-- If the Char Info Window is Open, Update The Info there
	if (GameInterface.CharWin.this:isVisible()) then
		local stats = GameInterface.CharWin
		stats.Hp:setText(tostring(hp).."/"..tostring(maxhp))
		stats.Mana:setText(tostring(mana).."/"..tostring(maxMana))
		stats.Level:setText(tostring(Demo.Player:getLevel()))
		stats.Patk:setText(tostring(Demo.Player:getAttributeValue("Patk")))
		stats.Pdef:setText(tostring(Demo.Player:getAttributeValue("Pdef")))
		stats.Matk:setText(tostring(Demo.Player:getAttributeValue("Matk")))
		stats.Mdef:setText(tostring(Demo.Player:getAttributeValue("Mdef")))
	end
	-- If the Diaalog Window is Open
	local dial = GameInterface.Dialog.NpcInstance
	if (dial) then
		-- If Player has gone too far from The Lifeform talking
		if (Demo.Player:getDistance(dial)>100) then
			-- End the Conversation (Close Dialog)
			GameInterface.Dialog.this:hide()
			GameInterface.Dialog.NpcInstance = nil
			GameInterface.Dialog.Npc = nil
		end
	end
	-- For all skillslots
	for k,v in pairs(GameInterface.SkillBox) do
		-- if the Skillslot has ID == 1 then it means it has something
		if (v.this:getID()==1) then
			-- Get the Drag Container
			local itm = v.this:getChild("Drag")
			-- Get the Table of the Container and update it.
			-- Every Drag Container has a 'Demo.DragIcon' on Pool which can be get from the Property 'Table'
			-- The 'Table' field of the Demo.DragIcon is a derivative of the 'Demo.DragTable' and the Update
			-- function can do specific operation depending on what the DragContainer Hosts.
			-- E.g if it hosts an Ability, then it should update the Cooldown remaining and etc.
			Pool.Table[itm:getUserString("Table")].Table:Update(v)
		end
	end
	do
		local Frames = require('Demo.UnitFramePool').Lifeforms
		for k,v in pairs(Frames) do
			v:Update()
		end
	end
end

--------------------------------------------------------------------------------
-- Actions happening when Load Ended from The core
--
-- @function [parent=#Demo.Operations] onLoadEnd
function operations.onLoadEnd(parameters)
	local load = require('Demo.GUI.LoadingScreen')
	local Save = require('SZLL.SaveManager')
	require('Demo.UnitFramePool')
	-- If CurrentMap is defined, load the Objects
	if (Demo.CurrentMap) then
	--	Demo.CurrentMap:loadObjects()
	end
	-- If PreviousMap is defined, Unload The Objects
	if (Demo.PreviousMap) then
		-- Add to Save Manager the previous map to be save on Save request
	--	Save.addMap(Demo.PreviousMap.name,Demo.PreviousMap:getData())
	--	Demo.PreviousMap:deinitializeObjects()
	end
	-- If it is First Load (for this game, not session)
	if (Save.firstLoad==true) then
		-- Load the Player
		Demo.LoadPlayer()
		Save.firstLoad=false
	end
	-- If map has music Defined, Play it
	if (Demo.CurrentMap.music) then
		Zeta.System:getInstance():getAudioContext():setMusic(Demo.CurrentMap.music)
	end
	LoadingScreen.StatusText:setText("Η φόρτωση ολοκληρώθηκε. Πατήστε \'Συνέχεια\' να ξεκινήσετε.")
	require('Demo.GUI.MainMenu').this:hide()
	require('Demo.DamageTextPool')
	Demo.Player:teleportToCordinates(Demo.CurrentMap.spawnX,Demo.CurrentMap.spawnY)
	-- Show The continue Button to Carry On
	load.Continue.this:show()
end

--------------------------------------------------------------------------------
-- Actions happening on Quest Added to Player
--
-- @function [parent=#Demo.Operations] onQuestAdd
-- @param Demo.Quest#Quest Quest The Quest Table
function operations.onQuestAdd(Quest)
	-- Let The interface track this Quest (Show Tables)
	GameInterface.TrackQuest(Quest)
	local qName = Quest.Class.Name
	-- get an Available List Item
	local itm = require('Demo.ListBoxItemPool'):popFront() -- SZLL.CEGUI#CEGUI.ListboxItem
	if (itm) then
		-- If there is an available
		Quest.QListItem = itm
		-- Assign the Data to the Quests List Window
		itm:setText(Quest.Class.Name)
		itm:setSelected(false)
		GameInterface.Quests.QuestList:addItem(itm)
		GameInterface.Quests.QuestList_UpdateLists()
	end
	-- Notify that quest was taken
	operations.Notify("Πήρα αποστολή! "..Quest.Class.Name)
end

--------------------------------------------------------------------------------
-- Actions happening when a quest was Completed
-- (All States are complete)
--
-- @function [parent=#Demo.Operations] onQuestComplete
-- @param Demo.Quest#Quest Quest The Quest Table
function operations.onQuestComplete(Quest)
	-- Remove the List item from Quests Window
	GameInterface.Quests.QuestList:removeItem(Quest.QListItem)
	-- Push the Item to be reused
	require('Demo.ListBoxItemPool'):pushBack(Quest.QListItem)
	-- Update the Quests Window
	GameInterface.Quests.QuestList_UpdateLists()
	-- Let Interface Quest Track that This Quest is complete
	GameInterface.Acknowledge_QuestComplete(Quest)
	-- Notify the Player
	operations.Notify("Πάει και αυτή η αποστολή! "..Quest.Class.Name)
end

--------------------------------------------------------------------------------
-- Actions Happening when a Quest state was completed
--
-- @function [parent=#Demo.Operations] onStateComplete
-- @param Demo.Objective#Objective Table The State Table
function operations.onObjectiveComplete(Objective)
	-- Get The Quest Table
	local qTable = Objective.Parent
	if (qTable.Track) then
		-- If Quest is tracked, Update it
		GameInterface.TrackQuest(qTable)
	end
	-- If there is a message to send, send it
	if (Objective.Class.Out) then
		operations.Notify(Objective.Class.Out)
	end
end

--------------------------------------------------------------------------------
-- Actions Happening when an Objective was partly completed
-- Eg. An enemy was killed out of 3
--
-- @function [parent=#Demo.Operations] onObjectiveStep
-- @param SZLL.Objective#Objective Objective The Objective Data
function operations.onObjectiveStep(Objective)
	-- Update the track progress
	if (Objective.Track) then
		local txt = Objective.Class.Name.."\t:"..tostring(Objective.Progress).."/"..tostring(Objective.Class.NSteps)
		Objective.Track:setText(txt)
		CEGUI.toListbox(Objective.Track:getOwnerWindow()):handleUpdatedItemData()
		operations.Notify(txt)
	end
end

--------------------------------------------------------------------------------
-- Actions Happening when a Lifeform Died
--
-- @function [parent=#Demo.Operations] onLifeformDeath
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that died
function operations.onLifeformDeath(Lifeform)
	local DropTable = Lifeform:getLuaTable().Drops
	if (DropTable) then
		for k,v in pairs(DropTable) do
			if (math.random(100)<v.Chance) then
				v:Invoke(Lifeform)
			end
		end
	end
end

--------------------------------------------------------------------------------
-- Actions Happening when the Player Leveled Up
--
-- @function [parent=#Demo.Operations] onLevelUp
-- @param #number Level The New level
function operations.onLevelUp(Level)
	-- Increase the Player Skill Points and Update The Interface
	Demo.PlayerValues.SkillPoints=Demo.PlayerValues.SkillPoints+1
	GameInterface.this:getChild("Abilities/Points"):setText(tostring(Demo.PlayerValues.SkillPoints))
	do
		-- Add some cool Level Up animations
		local AnimMgr = Zeta.AnimationEffectsManager:getInstance()
		Demo.Player:addOffAnimation(AnimMgr:getAnimationFX("GoldBar","FX"),0,-32,Zeta.AnimationHandler.QueuePlace.Front)
		Demo.Player:addOffAnimation(AnimMgr:getAnimationFX("GoldUp","FX"),0,0,Zeta.AnimationHandler.QueuePlace.Front)
	end
end

--------------------------------------------------------------------------------
-- Calls the function provided if the distance conditions between the Objects are met
--
-- @function [parent=#Demo.Operations] InteractAction
-- @param #function Function The function to be called
-- @param #number Distance The Distance of the objects
function operations.InteractAction(Function,Distance,...)
	local args = {...}
	if (args[1]:getDistance(args[2])<Distance) then
		Function(args[1],args[2])
	end
end

--------------------------------------------------------------------------------
-- Is called automatically when an Lifeform is shown
-- Assigns a Unit Frame if available
--
-- @function [parent=#Demo.Operations] onLifeformShow
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that was shown
function operations.onLifeformShow(Lifeform)
	local itm = require('Demo.UnitFramePool') -- Demo.UnitFrame#Demo.UnitFrame
	itm = itm.Queue:popFront()
	if (itm) then
		itm:Assign(Lifeform)
	end
end

--------------------------------------------------------------------------------
-- Is called automatically when an Lifeform is Hidden
-- Removes the Unit Frame if it has any
--
-- @function [parent=#Demo.Operations] onLifeformHide
-- @param SZLL.Zeta#Zeta.Lifeform Lifeform The Lifeform that was shown
function operations.onLifeformHide(Lifeform)
	local itm = require('Demo.UnitFramePool').Lifeforms[Lifeform] -- Demo.UnitFrame#Demo.UnitFrame
	if (itm) then
		itm:Release()
	end
end

--------------------------------------------------------------------------------
-- Format and assign a Tooltip Text with the provided Ability
--
-- @function [parent=#Demo.Operations] SkillTooltip
-- @param SZLL.Zeta#Zeta.ActiveAbility Ability The Provided Ability
-- @param SZLL.CEGUI#CEGUI.Window Window The Window to assign the Tooltip Text
-- @param Demo.AbilityNode#AbilityNode NodeTable The Node of the Ability (on tree)
function operations.SkillTooltip(Ability,Window,NodeTable)
	-- get The Lua Table of the Class of the Ability
	local table = Ability:getClass():getLuaTable()
	local str = ''
	if table and Window then
		do

			if table.Range then
				str = [[[colour='FFa59cff'][font='Ubuntu-10-Bold'] ]]..table.Name.. [[[font='Ubuntu-10']
		[colour='FFFFFFFF']Επίπεδο: [colour='FF2ab58f'] ]] ..Ability:getLevel().. '/'..table.Levels..[[ 
		[colour='FFFFFFFF']Κατανάλωση Μανα: [colour='FF2ab58f'] ]]..Ability:getManaCost()..[[ 
		[colour='FFFFFFFF']Χρ. Επαναφόρτωσης: [colour='FF2ab58f'] ]]..Ability:getCoolDown()..[[ Δεπτερόλεπτα 
		[colour='FFFFFFFF']Εμβέλεια: [colour='FF2ab58f'] ]]..Ability:getRange()..[[ 
		[colour='FFFFFFFF']Χρόνος εκτέλεσης: [colour='FF2ab58f'] ]]..Ability:getCastTime().." Δεπτερόλεπτα "
			else
				str = [[ [colour='FFa59cff'][font='Ubuntu-10-Bold'] ]]..table.Name.. [[[font='Ubuntu-10']
		[colour='FFFFFFFF']Επίπεδο: [colour='FF2ab58f'] ]] ..Ability:getLevel().. '/'..table.Levels
			end
			-- Parse the Description for any References and apply values
			local descr = table.Description
			if descr then
				local tables = table.Tables
				local lvl = Ability:getLevel()
				if tables then
					for w in string.gmatch(descr,"{(%w+)}") do
						if (tables[w]) then
							descr = string.gsub(descr,"{"..w.."}",tables[w][lvl] or "0")
						end
					end
				end
				do
					local plyr = Demo.Player
					for w in string.gmatch(descr,"<(%w+)>") do
						descr = string.gsub(descr,"<"..w..">",tostring(plyr:getAttributeValue(w)))
					end
				end
				str = str..'\n\n'..descr
				if (NodeTable) then
					str = str..'\n\n'
					for k,v in pairs(NodeTable.Requirements) do
						if (not v:CheckCondition()) then
							str = str.."[colour='FFd71a1f']"..v:getText()..'\n'
						end
					end
				end
			end
		end
		-- Set The tooltip
		Window:setTooltipText(str)
	end
end

--------------------------------------------------------------------------------
-- Shows a floating text over the Object
--
-- @function [parent=#Demo.Operations] FloatingText
-- @param #string Text The Text the Floating should have
-- @param SZLL.Zeta#Zeta.Object Object The target Object
-- @param #string Colour The Text Colour
function operations.FloatingText(Text,Object,Colour)
	local win = require('Demo.DamageTextPool').DamageTextPool:popBack()	-- SZLL.CEGUI#CEGUI.Window
	if (win) then
		-- If there is an Damage Text Available
		local pos = Object:getPosition()
		local camera = Demo.World:getView()
		local ev = CEGUI.EventArgs:new_local()
		-- Calculate the Position to be above the Head of the Victim
		local x = CEGUI.UDim:new_local(0,pos:getX()-camera:getX()-(win:getWidth().offset/2))
		local y = CEGUI.UDim:new_local(0,Object:getTargetArea():getY()-camera:getY()-win:getHeight().offset)
		-- Set the Damage Text Position and Text
		win:setXPosition(x)
		win:setYPosition(y)
		local ev = CEGUI.EventArgs()
		win:setText(Text)
		win:show()
		win:setProperty("NormalTextColour",Colour or "FFFFFFFF")
		-- Fire the Animation
		win:fireEvent("StartAnimation",ev)
	end
end

--------------------------------------------------------------------------------
-- Format and assign a Tooltip Text with the provided Item
--
-- @function [parent=#Demo.Operations] ItemTooltip
-- @param Demo.Item#Item Item The Item Provided
-- @param SZLL.CEGUI#CEGUI.Window Window The Window to assign the Tooltip Text
function operations.ItemTooltip(Item,Window)

	local Class = Item.Class
	if Item and Window then
		local str = "[colour='"..Class.ItemQuality.."'][font='Ubuntu-10-Bold']"..Class.Name.."[font='Ubuntu-10']"
	end
end

Demo.Player:setLevelUpCallback(operations.onLevelUp)
do
	local mgr = Zeta.WorldManager:getInstance()
	mgr:setCallback(Zeta.WorldManager.Callback.ChangeMap,operations.ChangeMap)
	mgr:setCallback(Zeta.WorldManager.Callback.LoadEnd,operations.onLoadEnd)
	mgr:setCallback(Zeta.WorldManager.Callback.FrameEnd,operations.Update)
	mgr:setCallback(Zeta.WorldManager.Callback.LifeformDeath,operations.onLifeformDeath)
	mgr:setCallback(Zeta.WorldManager.Callback.LifeformHide,operations.onLifeformHide)
	mgr:setCallback(Zeta.WorldManager.Callback.LifeformShow,operations.onLifeformShow)
end

return operations

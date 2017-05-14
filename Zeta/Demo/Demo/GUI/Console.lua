local GUI = require('Demo.GUI')

--------------------------------------------------------
-- GUI.Console
-- Provides easy access to Console Window
--
-- @module GUI.Console

local root = GUI.Root

root:addChild(CEGUI.WindowManager:getSingleton():loadLayoutFromFile("Console.layout"))

local console = {
	this = root:getChild("Console"),
	Enter = CEGUI.toPushButton(root:getChild("Console/EnterButton")),
	Command = CEGUI.toEditbox(root:getChild("Console/CommandBox")),
	History = CEGUI.toListbox(root:getChild("Console/CommandHistory")),
	activator = 1,
	prevAction = ""
}

console.this:hide()

--------------------------------------------------------
-- GUI.Console.onCloseClicked()
-- Is called when close button of Console is Clicked
-- 
-- @function [parent=#GUI.Console] onCloseClicked
-- @param CEGUI#Event Event CEGUI Passed Event
function console.onCloseClicked(event)
	console.this:hide()
	console.activator:activate()
end

--------------------------------------------------------
-- GUI.Console.onKeyUp()
-- Is called when a key is pressed when Console is 
-- active
-- 
-- @function [parent=#GUI.Console] onKeyUp
-- @param CEGUI#Event Event CEGUI Passed Event
function console.onKeyUp(event)
	event=CEGUI.toKeyEventArgs(event)
	if (event.scancode == CEGUI.Key.F12) then
		local cmd=console.this
		if (cmd:isVisible()) then
			cmd:hide()
			console.activator:activate()
		else
			cmd:show()
			cmd:activate()
			console.Command:activate()
			cmd:moveToFront()
			console.activator=event.window;
		end
		return true
	elseif event.scancode == CEGUI.Key.ArrowUp then
		console.Command:setText(console.prevAction)
		return true
	end
	return false
end

--------------------------------------------------------
-- GUI.Console.Enter_onMouseClick()
-- Is called when Enter Button is pressed on Console
-- 
-- @function [parent=#GUI.Console] Enter_onMouseClick
-- @param CEGUI#Event Event CEGUI Passed Event
function console.Enter_onMouseClick(event)
	console.prevAction = console.Command:getText()
	local ret = Zeta.ConsoleManager:getInstance():excecuteLine(console.prevAction)
	console.Command:setText("")
	local itm = CEGUI.createListboxTextItem(ret)
	local hist= console.History
	itm:setTextColours(CEGUI.PropertyHelper:stringToColour("FF000000"))
	hist:addItem(itm);
	hist:ensureItemIsVisible(itm)
	if (hist:getItemCount()>20) then
		hist:removeItem(hist:getListboxItemFromIndex(0))
	end
end

--------------------------------------------------------
-- GUI.Console.Command_onTextAccepted()
-- Is called when Enter is pressed while Writing on
-- the Command Box
-- 
-- @function [parent=#GUI.Console] Command_onTextAccepted
-- @param CEGUI#Event Event CEGUI Passed Event
function console.Command_onTextAccepted(event)
	console.Enter_onMouseClick()
	return true;
end


console.this:subscribeEvent("CloseClicked",console.onCloseClicked)
console.this:subscribeEvent("KeyUp",console.onKeyUp)
console.Enter:subscribeEvent("MouseClick",console.Enter_onMouseClick)
console.Command:subscribeEvent("TextAccepted",console.Command_onTextAccepted)

return console

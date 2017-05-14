local GUI = require('Demo.GUI')

GUI.Root:addChild(GUI.WindowManager:loadLayoutFromFile("Loading.layout"))

local rootWindow = GUI.Root

local LoadingScreen = {
	this = rootWindow:getChild("LoadingScreen"),
	Continue ={
		this = CEGUI.toPushButton(rootWindow:getChild("LoadingScreen/ReadyButton")),
		Map = ""
	},
	StatusText = rootWindow:getChild("LoadingScreen/StatusText"),
	Bgs = {
		"Lake_BG","Ship_BG","Efi_Child_BG"
	},
	Tips = {
		"Στις πολειτίες των ακτών της λίμνης 'Σηρείνα', είχαν γίνει τα μεγάλα επισόδια του Βαρόνου Νάσιου. Ο ίδιος, ενυσχιμένος απο κειμίλια των αρχαίων ηρώων, προσπάθησε να κατακτήσει όλες τις τρυγύρω πολιτείες.",
		"Ο 'Περιλανόμενος των Αιθέρων' είναι το 2ο μεγαλύτερο όχημα μετα την 'Χαρακιά του αέρα'. Έχει μήκος 9,8 χλμ, πλάτος 2,5 χλμ, και ύψος 4,6 χλμ. Σε αντίθεση όμως με την Χαρακιά, ο Περιπλανόμενος είναι μια κινητή μεγαλουπολη, εξοπλοισμένη με περίπου 38.000.000 κανόνια διαφόρων μεγεθών.",
		"Η γενέτηρα της 'Ευτυχίας' δεν είναι κάποια πόλη του 5ου επιπέδου, αλλα μια πόλη σε έναν άλλο κόσμο, που λέγετε 'Κέρκυρα'. Εκεί μεγάλωσε απο το 1529 έως το 1538 που έγινε το μεγάλο fork();",
	}
}

local imgMgr= CEGUI.ImageManager:getSingleton()
imgMgr:addFromImageFile("Lake_BG","Characters/LoadingScreens/Lake.png","misc")
imgMgr:addFromImageFile("Ship_BG","Characters/LoadingScreens/Ship.png","misc")
imgMgr:addFromImageFile("Efi_Child_BG","Characters/LoadingScreens/Efi.png","misc")

LoadingScreen.this:hide()

function LoadingScreen.Continue_onMouseClick(event)
	local args = CEGUI.EventArgs()
	-- Start the Fade out animation
	LoadingScreen.this:fireEvent("FadeOutStart",args)
	local GameInterface = require('Demo.GUI.GameInterface')
	local Music = Zeta.System:getInstance():getAudioContext()
	-- Show the Interface
	GameInterface.this:show()
	GameInterface.this:activate()
	
	require('Demo').Player:stopMoving()

	local mgr = Zeta.WorldManager:getInstance()
	-- Start the Game...
	mgr:resume()
	mgr:show()
	Music:start()
end

function LoadingScreen.onAlphaChange(e)
	-- Check If we must Load
	if (LoadingScreen.Loading==true) then
	--Check if Loading Screen Alpha is 1 (255)
		if (LoadingScreen.this:getAlpha()==1) then
			-- Invalidate the Flag
			LoadingScreen.Loading = false
			local mgr= Zeta.WorldManager:getInstance()
			-- Stop The Music
			Zeta.System:getInstance():getAudioContext():stop()
			-- Change The actual map
			mgr:changeMap(LoadingScreen.NextMap)
		end
	end
end

LoadingScreen.Continue.this:subscribeEvent("MouseClick",LoadingScreen.Continue_onMouseClick)

LoadingScreen.this:subscribeEvent("AlphaChanged",LoadingScreen.onAlphaChange)

return LoadingScreen

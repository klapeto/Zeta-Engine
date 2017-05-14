

local guiSystem = CEGUI.System:getSingleton()
local winMgr = CEGUI.WindowManager:getSingleton()
local imgMgr = CEGUI.ImageManager:getSingleton()

CEGUI.Scheme:setDefaultResourceGroup("schemes")
CEGUI.ImageManager:setImagesetDefaultResourceGroup("imagesets")
CEGUI.Font:setDefaultResourceGroup("fonts")
CEGUI.WidgetLookManager:setDefaultResourceGroup("looknfeel")
CEGUI.WindowManager:setDefaultResourceGroup("layouts")

CEGUI.SchemeManager:getSingleton():createFromFile("Eftihia.scheme");

rootWindow = winMgr:createWindow("DefaultWindow","root")

rootWindow:addChild(winMgr:loadLayoutFromFile("MainMenu.layout"))
rootWindow:addChild(winMgr:loadLayoutFromFile("CharSelect.layout"))
rootWindow:addChild(winMgr:loadLayoutFromFile("Console.layout"))
rootWindow:addChild(winMgr:loadLayoutFromFile("Game.layout"))
rootWindow:addChild(winMgr:loadLayoutFromFile("Options.layout"))
rootWindow:addChild(winMgr:loadLayoutFromFile("Loading.layout"))

guiSystem:getDefaultGUIContext():setRootWindow(rootWindow)


local LuaEngine = Zeta.LuaEngine:getInstance()
LuaEngine:excecuteScriptFile("Scripts/Console.lua")
LuaEngine:excecuteScriptFile("Scripts/CharSel.lua")
LuaEngine:excecuteScriptFile("Scripts/MainMenu.lua")
LuaEngine:excecuteScriptFile("Scripts/GameInterface.lua")
LuaEngine:excecuteScriptFile("Scripts/Options.lua")
LuaEngine:excecuteScriptFile("Scripts/LoadingScreen.lua")
LuaEngine:excecuteScriptFile("Scripts/Player.lua")

math.randomseed(os.time())
--------------------------------------------------------
-- GUI Module
-- Provides GUI Startup
--
-- @module GUI
local GUI = {}


local guiSystem = CEGUI.System:getSingleton()
local winMgr = CEGUI.WindowManager:getSingleton()

--CEGUI.Logger:getSingleton():setLoggingLevel(CEGUI.Insane)

CEGUI.Scheme:setDefaultResourceGroup("schemes")
CEGUI.ImageManager:setImagesetDefaultResourceGroup("imagesets")
CEGUI.Font:setDefaultResourceGroup("fonts")
CEGUI.WidgetLookManager:setDefaultResourceGroup("looknfeel")
CEGUI.WindowManager:setDefaultResourceGroup("layouts")

CEGUI.SchemeManager:getSingleton():createFromFile("Eftihia.scheme");

GUI.Root = winMgr:createWindow("DefaultWindow","root")
GUI.WindowManager = winMgr
guiSystem:getDefaultGUIContext():setRootWindow(GUI.Root)
guiSystem:getDefaultGUIContext():setDefaultTooltipType("Eftihia/Tooltip")
return GUI

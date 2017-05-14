----
-- A harmless chicken class
--
-- @module Demo.Enemies.Chicken
-- @extends Demo.Npc#Demo.Npc
-- @return Demo.Npc#Demo.Npc The Chicken
local Chicken = require('Demo.Npc')('Demo/Enemies/Chicken/Class.xml',0,0) -- Demo.Npc#Demo.Npc

Chicken:setStates({Intro1 = 
	{Text = "(Η κότα σε κοιτάει περίεργα, τρώγοντας)"}
})

Chicken:setIntroLine("Intro1")

return Chicken

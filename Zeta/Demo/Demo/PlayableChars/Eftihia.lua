

local Eftihia = require('Demo.PlayableCharacter')()

local AbilityNode = require('Demo.AbilityNode')

Eftihia.Name = "Ευτυχία"
Eftihia.Description = "Απο τα πλέον αμφιλεγόμενα άτομα στο 5ο Επιπεδο. Βέβαια αυτό υσχύει μόνο για τα άτομα που την ξέρουν, που είναι κυρίως διανοούμενοι."
Eftihia.Spec = "Θεραπεύτρια"
Eftihia.Image = "EftihiaImage"
Eftihia.Avatar = "EftihiaAvatar"
Eftihia.Class = "Demo/LifeformClasses/Eftihia.xml"
Eftihia.Abilities = {
	Strike = AbilityNode(require('Demo.Abilities.Strike')),
	AuraSphere = AbilityNode(require('Demo.Abilities.AuraSphere')),
	HP5 = AbilityNode(require('Demo.Abilities.HP5')),
	MP5 = AbilityNode(require('Demo.Abilities.MP5'))
}

local Demo = require('Demo')
require('Demo.GUI')

function Eftihia.InitialiseSkills()

	local Tree = require('Demo.AbilityTree')()

	local Abilities = Eftihia.Abilities

	--Abilities.AuraSphere:AddRequirement(require('Demo.LevelRequirement')(2))

	Abilities.Strike.Level = 1
	Abilities.HP5.Level = 1
	Abilities.MP5.Level = 1

	Tree:AddNode(Abilities.Strike,5,5)
	Tree:AddNode(Abilities.AuraSphere,60,90)
	Tree:AddNode(Abilities.HP5,110,5)
	Tree:AddNode(Abilities.MP5,180,5)

	Tree:Apply()
	Demo.PlayerValues.AbilityTree = Tree


	Demo.PlayerValues.SkillPoints = 5
end

do
	local Img = CEGUI.ImageManager:getSingleton()
	-- Load Eftihias Avatar
	Img:addFromImageFile("EftihiaImage","Characters/EftiN_PORT_512.png","misc")
	Img:addFromImageFile("EftihiaAvatar","Characters/EftiN_PORT_Small.png","misc")
end

return Eftihia

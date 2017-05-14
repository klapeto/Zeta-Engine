
local Ability = require('SZLL.ActiveAbility')

local Strike = Ability("Χτύπημα Σπαθιού",3,0.5,0,30)

Strike:addTable("Damage",{10,15,20})

Strike.ReleaseAnimation = "Slash"
Strike.ReleaseSound = "Demo/Abilities/Sounds/swing.ogg"
Strike.Range = 80
Strike.Ranged = true
Strike.IconPath = "Abilities/SwordAttack1"

Strike.Description = [[ [colour='FFFFFFFF']Χτυπάει τον στοχευμένο εχθρό προκαλώντας [colour='FF2ab58f']100%
		[colour='FFFFFFFF']της Φυσικής επίθεσης + [colour='FF2ab58f']{Damage} [colour='FFFFFFFF']σαν Φυσική ζημιά.]]

function Strike.onApply(Ability,Caster,Target)
	local patk = Caster:getAttributeValue("Patk")
	local dmg = patk+Strike.Tables.Damage[Ability:getLevel()]+math.random(2)
	local Operations = require('Demo.Operations')
	
	dmg = Operations.doPhysicalDamage(Target,dmg)

end


Strike:generateInternal()

return Strike

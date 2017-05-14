
local Ability = require('SZLL.ActiveAbility')

local Melee = Ability("Χτύπημα",3,1.5,0,30)

Melee:addTable("Damage",{10,15,20})

Melee.ReleaseAnimation = "Slash"
Melee.ReleaseSound = "Demo/Abilities/Sounds/swing.ogg"
Melee.Range = 80
Melee.Ranged = true
Melee.IconPath = "Abilities/SwordAttack1"

Melee.Description = [[ [colour='FFFFFFFF']Χτυπάει τον στοχευμένο εχθρό προκαλώντας [colour='FF2ab58f']100%
		[colour='FFFFFFFF']της Φυσικής επίθεσης + [colour='FF2ab58f']{Damage} [colour='FFFFFFFF']σαν Φυσική ζημιά.]]

function Melee.onApply(Ability,Caster,Target)
	local patk = Caster:getAttributeValue("Patk")
	local dmg = patk+Melee.Tables.Damage[Ability:getLevel()]+math.random(2)
	local Operations = require('Demo.Operations')
	

	dmg = Operations.doPhysicalDamage(Target,dmg)

end


Melee:generateInternal()

return Melee
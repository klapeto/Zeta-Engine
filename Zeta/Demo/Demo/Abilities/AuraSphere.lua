local Ability = require('SZLL.ActiveAbility')

local Aura = Ability("Αιθέρια Σφαίρα",5,2,50,600)

do
	local Sphere = require('SZLL.Projectile')("Demo/AnimationClasses/AuraSphere.xml",1200)


	Sphere.Offsets = {
		Up ={x=0,y=-35},
		Down={x=0,y=20},
		Left={x=-35,y=1},
		Right={x=35,y=1}
	}

	Sphere.Type = 2

	Aura:addProjectile("Sphere",Sphere)
	Aura:addTable("Damage",{12,25,38,56,85})
	Aura:addTable("PatkM",{80,90,100,120,160})
	Aura.CastAnimation = "Cast"
	Aura.ReleaseAnimation = "Release"
	Aura.ReleaseSound = "Demo/Abilities/Sounds/shoot.ogg"
	Aura.CastSound = "Demo/Abilities/Sounds/charge.ogg"
	Aura.IconPath = "Abilities/MagicAttack1"

	Aura.Description = [[ [colour='FFFFFFFF'] Φορτίζει μια μαγική σφαίρα και την στέλνει στο αντίπαλο
		προκαλώντα [colour='FF2ab58f']{PatkM}% [colour='FFFFFFFF']της Φυσικής επίθεσης + [colour='FF2ab58f']{Damage} [colour='FFFFFFFF']
		σαν Φυσική ζημιά.]]

	Sphere.DirectionalRotate = true
	Aura.CastTime = 2
	Aura.MustFace = true
	Aura.Ranged = true

	do
		local dot = require('SZLL.OverTimeEffect')("Aura Sphere DOT",4,1)	--SZLL.OverTimeEffect#OverTimeEffect
		dot.onTick = function(Effect,Owner,Level,Source)
			require('Demo.Operations').doPhysicalDamage(Owner,100*Level)
		end
		Aura:addEffect("DOT",dot)
end


function Sphere.onCollision(projectile,victim)
	local Ability = projectile:getParentAbility()
	local patk = Ability:getOwner():getAttributeValue("Matk")
	local lvl = Ability:getLevel()
	local dmg = (patk * (Aura.Tables.PatkM[lvl]/100))+Aura.Tables.Damage[lvl]+math.random(2)
	local Operations = require('Demo.Operations')

	dmg = Operations.doPhysicalDamage(victim,dmg)


	projectile:getParentAbility():applyEffect("DOT",victim,1)

	--projectile:destroy()
end

	function Sphere.onDestinationReach(projectile)
		projectile:destroy()
	end

end

function Aura.onApply(Ability,Caster,Target)
	Ability:invokeProjectile("Sphere",0,0)
end


Aura:generateInternal()

return Aura

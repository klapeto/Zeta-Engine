local AuraSphere = {
	Name = "Αιθέρια Σφαίρα",
	Levels = 5,
	CoolDown = 2.5,
	ManaCost = 50.0,
	CastTime = 2.5,
	Range = 600,
	Type = Zeta.AbilityClass.Type.Active,
	CastAnimation = "Cast",
	ReleaseAnimation = "Release",
	ReleaseSound = "Demo/Abilities/Sounds/shoot.ogg",
	CastSound = "Demo/Abilities/Sounds/charge.ogg",
	Tables = {
		DOTDamage = {20,50,80}
	}
}

AuraSphere.Effects = {
	DOT = {
		Levels = 3,
		Durable = true,
		OverTime = true,
		UpTime = 5,
		Stackable = false,
		TickEvery = 1,
		onTick = function(Effect,Owner,Level,Source)
			Owner:offsetHP(-(AuraSphere.Tables.DOTDamage[Level]))
		end
	}
}

AuraSphere.Projectiles = {
	Sphere = {
		Name = "Sphere",
		Type = Zeta.Projectile.Type.Seeking,
		AnimationClass = "Demo/AnimationClasses/AuraSphere.xml",
		Speed = 1200,
		DirectionalRotate = true,
		Offsets = {
			Up = { x=0, y=-35 },
			Down = { x=0, y=20 },
			Left = { x=-35, y=1 },
			Right = { x=35, y=1  }
		},
		onCollision = function(Projectile, Other)
			Other:offsetHP(Other:getAttributeValue("MaxHP") * 0.25)
			Projectile:getParentAbility():applyEffect("DOT",Other,1)
		end
	}
}

function AuraSphere.onApply(Ability,Caster,Target)
	Ability:invokeProjectile("Sphere",0,0)
end

AuraSphere.Internal = Zeta.AbilityClass(AuraSphere)

return AuraSphere

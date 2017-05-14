local UltraMode = {
	Name = "Ultra Mode",
	Levels = 1,
	Durable = true,
	OverTime = true,
	UpTime = 300,
	Stackable = false,
	TickEvery = 1.0,
}

function UltraMode.onApply(Owner,Level)
	Owner:addAttributeModifier("PAtk", "UltraMode", 1.5, Zeta.Modifier.Type.Scalar)
end

function UltraMode.onRemove(Owner,Level)
	Owner:removeAttributeModifier("UltraMode")
end

function UltraMode.onTick(Owner,Level)
	Owner:offsetHP(Owner:getAttributeValue("MaxHP") * 0.1)
end

return Zeta.EffectClass(UltraMode)
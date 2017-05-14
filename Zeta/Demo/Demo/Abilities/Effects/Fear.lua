--------------------------------------------------------------------------------
-- Fear Effect
--
-- @module Demo.Abilities.Effects.Fear
-- @return SZLL.Zeta#Zeta.EffectClass The Fear EffectClass

local Fear = {
  Name = "Τρόμος",
  Durable = true,
  UpTime = 1,
  onApply = function (This,Owner,Level)
    local target = Owner:getTarget()
    if (target) then
      Owner:setInCombat(true)
      local tPos = Owner:getPosition() - target:getPosition()	-- SZLL.Zeta#Zeta.Vector2
      require('Demo.Sprites.PurpleDebuff'):assign(Owner)
      tPos:normalize()
      tPos = tPos * 100
      local fPos = Owner:getPosition() + tPos
      Owner:moveToPosition(fPos)
    end
  end,
  onRemove = function (This,Owner,Level)
    Owner:setInCombat(false)
    require('Demo.Sprites.PurpleDebuff'):remove(Owner)
    Owner:stopMoving()
  end
}

return Zeta.EffectClass(Fear)

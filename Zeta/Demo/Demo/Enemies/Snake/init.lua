----
-- A Snake Class
-- 
-- @module Demo.Enemies.Snake
-- @extends Demo.EnemyClass#Demo.EnemyClass
-- @return Demo.EnemyClass#Demo.EnemyClass The Snake

local Snake = require('Demo.EnemyClass')('Demo/Enemies/Snake/Class.xml') -- Demo.EnemyClass#EnemyClass

Snake:addDrop(require('Demo.XPDrop')(123))
--Snake:addDrop(require('Demo.ItemDrop')(require('Demo.Items.SimpleSword'),100,1))
--Snake:AddAbility(require('Demo.Abilities.AuraSphere'),1)

return Snake
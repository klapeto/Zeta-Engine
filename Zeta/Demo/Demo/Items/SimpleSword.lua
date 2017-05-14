local Item = require('Demo.ItemClass')

local Sword = Item("Μέγα Σπαθί")

Sword.ItemQuality = Item.ItemQuality.Legendary
Sword.IconName = "Icons/Sword8"
Sword.Description = "Σπαθί που δεν αντιστέκεται σε τιποτα."

return Sword


local MP5 = require('SZLL.Regeneration')("Mana","MaxMana","MP5",1)

MP5.Name = "Αναπλήρωση: Μάνα"

MP5.Description = [[ [colour='FFFFFFFF'] Αναπληρώνει [colour='FF7895ff']<MP5> [colour='FFFFFFFF']Μάνα κάθε 1 Δεπτερόλεπτα]]
MP5.IconPath = "Abilities/MagicAttack2"

MP5:generateInternal()

return MP5;


local HP5 = require('SZLL.Regeneration')("HP","MaxHP","HP5",0.1)

HP5.Name = "Αναπλήρωση: Ζωή"

HP5.Description = [[ [colour='FFFFFFFF'] Αναπληρώνει [colour='FF7895ff']<HP5> [colour='FFFFFFFF'] ζωή κάθε 0.1 Δεπτερόλεπτα]]
HP5.IconPath = "Abilities/MagicAttack2"

HP5:generateInternal()

return HP5;
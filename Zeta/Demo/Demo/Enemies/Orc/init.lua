local OrcClass = require('Demo.EnemyClass')("Demo/Enemies/Orc/Class.xml") -- Demo.EnemyClass#EnemyClass

OrcClass:addDrop(require('Demo.XPDrop')(500))

return OrcClass
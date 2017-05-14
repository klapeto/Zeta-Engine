local Map = require('SZLL.Map')

local thisMap = Map('Demo/Maps/Fine_Forest_1.tmx')

local name = ...

thisMap.music = "Demo/Music/MainV2.ogg"

thisMap:setSpawnCords(5536,8128)

return thisMap
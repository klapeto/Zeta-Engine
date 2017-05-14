

local Map = require('SZLL.Map')

local thisMap = Map('Demo/Maps/BriliosHouse.tmx')

local name = ...

thisMap.music = "Demo/Music/MainV2.ogg"

thisMap:setSpawnCords(480,608)

do
	local Npc = require('Demo.Npc')
	thisMap.name = name
	--thisMap:addNpc(require('Demo.NPCS.Maria_Briliou'))
end

return thisMap
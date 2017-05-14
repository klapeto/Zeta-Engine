---	This file is Part of Zeta Engine
--
--	The MIT License
--
-- Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
-- documentation files (the "Software"), to deal in the Software without restriction, including without limitation
-- the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
-- and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
--
-- The above copyright notice and this permission notice shall be included in all copies or substantial
-- portions of the Software.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
-- INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
-- AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
-- DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

local Class = require('SZLL.Class')

local _NAME = ...
--------------------------------------------------------------------------------
-- Module for providing the Map Class
-- Map classes can contain NPCS and Enemies
-- You can also switch maps with these objects
--
-- @module SZLL.Map

--------------------------------------------------------------------------------
-- Map Class
--
-- @type Map
-- @field [parent=#Map] #string filePath The path to the .tmx File
-- @field [parent=#Map] #map<#string,#SZLL.Npc> Npcs The Npcs
local Map = Class()

--------------------------------------------------------------------------------
-- Map Constructor
-- Creates a map from the targetFile
-- Be advised, the map is not loaded, not until it is asked to.
--
-- @callof #SZLL.Map
-- @param self
-- @param #string Filename The filename to the map file
-- @return #Map Returned Map
function Map:init(filePath)
	self.filePath = filePath
	self.name = _NAME
	self.music = ""
	self.Npcs = {}
	self.Enemies = {}
	self.buffer = {}
	self.spawnX = 0
	self.spawnY = 0
end

--------------------------------------------------------------------------------
-- sets The spawn Locations
-- 
-- @function [parent=#Map] setSpawnCords
-- @param self
-- @param #number x The X Cord
-- @param #number yx The Y Cord
function Map:setSpawnCords(x,y)
	self.spawnX = x
	self.spawnY = y	
end

return Map

<?xml version="1.0" encoding="UTF-8"?>
<tileset name="Water" tilewidth="64" tileheight="64">
	<image source="AnimatedWater1.png" width="384" height="512" />
	<terraintypes>
		<terrain name="Water" tile="-1" />
	</terraintypes>
	<tile id="1" terrain="0,0,0,">
		<properties>
			<property name="Collision" value="14" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="1" duration="300" />
			<frame tileid="4" duration="300" />
		</animation>
	</tile>
	<tile id="2" terrain="0,0,,0">
		<properties>
			<property name="Collision" value="13" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="2" duration="300" />
			<frame tileid="5" duration="300" />
		</animation>
	</tile>
	<tile id="7" terrain="0,,0,0">
		<properties>
			<property name="Collision" value="11" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="7" duration="300" />
			<frame tileid="10" duration="300" />
		</animation>
	</tile>
	<tile id="8" terrain=",0,0,0">
		<properties>
			<property name="Collision" value="7" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="8" duration="300" />
			<frame tileid="11" duration="300" />
		</animation>
	</tile>
	<tile id="12" terrain=",,,0">
		<properties>
			<property name="Collision" value="1" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="12" duration="300" />
			<frame tileid="15" duration="300" />
		</animation>
	</tile>
	<tile id="13" terrain=",,0,0">
		<properties>
			<property name="Collision" value="3" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="13" duration="300" />
			<frame tileid="16" duration="300" />
		</animation>
	</tile>
	<tile id="14" terrain=",,0,">
		<properties>
			<property name="Collision" value="2" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="14" duration="300" />
			<frame tileid="17" duration="300" />
		</animation>
	</tile>
	<tile id="18" terrain=",0,,0">
		<properties>
			<property name="Collision" value="5" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="18" duration="300" />
			<frame tileid="21" duration="300" />
		</animation>
	</tile>
	<tile id="19" terrain="0,0,0,0" />
	<tile id="20" terrain="0,,0,">
		<properties>
			<property name="Collision" value="10" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="20" duration="300" />
			<frame tileid="23" duration="300" />
		</animation>
	</tile>
	<tile id="24" terrain=",0,,">
		<properties>
			<property name="Collision" value="4" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="24" duration="300" />
			<frame tileid="27" duration="300" />
		</animation>
	</tile>
	<tile id="25" terrain="0,0,,">
		<properties>
			<property name="Collision" value="12" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="25" duration="300" />
			<frame tileid="28" duration="300" />
		</animation>
	</tile>
	<tile id="26" terrain="0,,,">
		<properties>
			<property name="Collision" value="8" />
			<property name="Relatives" value="1,2,7,8,12,13,14,18,20,24,25,26" />
		</properties>
		<animation>
			<frame tileid="26" duration="300" />
			<frame tileid="29" duration="300" />
		</animation>
	</tile>
</tileset>

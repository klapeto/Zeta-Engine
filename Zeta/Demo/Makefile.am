#######################################
# The list of executables we are building seperated by spaces
# the 'bin_' indicates that these build products will be installed
# in the $(bindir) directory. For example /usr/bin
#bin_PROGRAMS=exampleProgram

# Because a.out is only a sample program we don't want it to be installed.
# The 'noinst_' prefix indicates that the following targets are not to be
# installed.
noinst_PROGRAMS=DemoExample

#######################################
# Build information for each executable. The variable name is derived
# by use the name of the executable with each non alpha-numeric character is
# replaced by '_'. So a.out becomes a_out and the appropriate suffex added.
# '_SOURCES' for example.

# Sources for the a.out 
DemoExample_SOURCES=Demo.cpp

# Linker options for a.out
DemoExample_LDFLAGS = $(top_builddir)/libzeta/libzeta.la $(top_builddir)/libzeta/libzeta-sdk-allegro5.la

# Compiler options for a.out
DemoExample_CPPFLAGS = -I$(top_srcdir)/include $(CXXFLAGS)

EXTRA_DIST = \
Demo/Maps/Tilesets/tileset.png \
Demo/Maps/Tilesets/LPC_terrains.png \
Demo/Maps/Tilesets/Terrains.tsx \
Demo/Maps/Tilesets/AnimatedWater1.png \
Demo/Maps/Tilesets/LPC.tsx \
Demo/Maps/Tilesets/AnimatedWater2.png \
Demo/Maps/Tilesets/LPC.tmx \
Demo/Maps/Tilesets/base_out_atlas.png \
Demo/Maps/Tilesets/Water.tsx \
Demo/Maps/FineForest.lua \
Demo/Maps/rules.txt \
Demo/Maps/TreeRule.tmx \
Demo/Maps/Fine_Forest_1.tmx \
Demo/Maps/BriliosHouse.tmx \
Demo/Maps/init.lua \
Demo/Maps/TreeShadowsRule.tmx \
Demo/Maps/BriliosHouse.lua \
Demo/DroppedItem.lua \
Demo/LifeformClasses/Guard.xml \
Demo/LifeformClasses/Female/people147.mp3 \
Demo/LifeformClasses/Eftihia.xml \
Demo/LifeformClasses/Female_NPC_2.xml \
Demo/Drop.lua \
Demo/Boot.lua \
Demo/DragIcon.lua \
Demo/Quests/ChickensOut.lua \
Demo/Quests/SnakeInvasion.lua \
Demo/Factions.xml \
Demo/EquipableItemClass.lua \
Demo/ItemTextPool.lua \
Demo/Objective.lua \
Demo/Quest.lua \
Demo/NPCS/Guard.xml \
Demo/NPCS/Maria_Briliou/init.lua \
Demo/NPCS/Maria_Briliou/Class.xml \
Demo/NPCS/init.lua \
Demo/NPCS/Female_NPC_2.xml \
Demo/NPCS/Ranger.xml \
Demo/NPCS/Barba_Brilios/init.lua \
Demo/NPCS/Barba_Brilios/Class.xml \
Demo/EventManager.lua \
Demo/AbilityTree.lua \
Demo/Items/SimpleSword.lua \
Demo/EftihiaGUI/xml_schemas/Animation.xsd \
Demo/EftihiaGUI/xml_schemas/GUILayout.xsd \
Demo/EftihiaGUI/xml_schemas/Falagard.xsd \
Demo/EftihiaGUI/xml_schemas/CEGUIConfig.xsd \
Demo/EftihiaGUI/xml_schemas/Font.xsd \
Demo/EftihiaGUI/xml_schemas/GUIScheme.xsd \
Demo/EftihiaGUI/xml_schemas/Imageset.xsd \
Demo/EftihiaGUI/Eftihia.project \
Demo/EftihiaGUI/looknfeel/Eftihia.looknfeel \
Demo/EftihiaGUI/layouts/MarianaSkills.layout \
Demo/EftihiaGUI/layouts/Options.layout \
Demo/EftihiaGUI/layouts/Game.layout \
Demo/EftihiaGUI/layouts/CharSelect.layout \
Demo/EftihiaGUI/layouts/MainMenu.layout \
Demo/EftihiaGUI/layouts/Loading.layout \
Demo/EftihiaGUI/layouts/Cutscene.layout \
Demo/EftihiaGUI/layouts/Console.layout \
Demo/EftihiaGUI/layouts/SCE_Intro.layout \
Demo/EftihiaGUI/schemes/Eftihia.scheme \
Demo/EftihiaGUI/Sounds/interface1.ogg \
Demo/EftihiaGUI/imagesets/Icons.png \
Demo/EftihiaGUI/imagesets/menubuttons.png \
Demo/EftihiaGUI/imagesets/Zeta_BG.png \
Demo/EftihiaGUI/imagesets/Icons.imageset \
Demo/EftihiaGUI/imagesets/Gameplay.imageset \
Demo/EftihiaGUI/imagesets/Abilities.imageset \
Demo/EftihiaGUI/imagesets/Eftihia.imageset \
Demo/EftihiaGUI/imagesets/Inventory.png \
Demo/EftihiaGUI/imagesets/InventorIcons.imageset \
Demo/EftihiaGUI/imagesets/GUI2.png \
Demo/EftihiaGUI/imagesets/MainMenuBack.imageset \
Demo/EftihiaGUI/imagesets/Abilities.png \
Demo/EftihiaGUI/imagesets/MainMenuImages.imageset \
Demo/EftihiaGUI/imagesets/Gameplay.png \
Demo/EftihiaGUI/fonts/Ubuntu-Bold.ttf \
Demo/EftihiaGUI/fonts/Ubuntu-10-Bold.font \
Demo/EftihiaGUI/fonts/Ubuntu-Bold-48.font \
Demo/EftihiaGUI/fonts/TradeWinds-20.font \
Demo/EftihiaGUI/fonts/TradeWinds-Regular.ttf \
Demo/EftihiaGUI/fonts/DejaVuSans-12.font \
Demo/EftihiaGUI/fonts/DejaVuSans-14.font \
Demo/EftihiaGUI/fonts/Ubuntu-48.font \
Demo/EftihiaGUI/fonts/Ubuntu-18.font \
Demo/EftihiaGUI/fonts/DejaVu-14.font \
Demo/EftihiaGUI/fonts/Ubuntu-20.font \
Demo/EftihiaGUI/fonts/Ubuntu-Regular.ttf \
Demo/EftihiaGUI/fonts/Ubuntu-72.font \
Demo/EftihiaGUI/fonts/DejaVuSans-16.font \
Demo/EftihiaGUI/fonts/Ubuntu-12.font \
Demo/EftihiaGUI/fonts/Ubuntu-10.font \
Demo/EftihiaGUI/fonts/DejaVuSans-10.font \
Demo/EftihiaGUI/fonts/Ubuntu-32.font \
Demo/EftihiaGUI/fonts/Ubuntu-14.font \
Demo/EftihiaGUI/fonts/DejaVuSans.ttf \
Demo/EftihiaGUI/fonts/Ubuntu-16.font \
Demo/EftihiaGUI/fonts/DejaVuSans-18.font \
Demo/EftihiaGUI/lua_scripts/Boot.lua \
Demo/AnimationClasses/OrcArcher.xml \
Demo/AnimationClasses/Orc.xml \
Demo/AnimationClasses/Guard.xml \
Demo/AnimationClasses/Chicken.xml \
Demo/AnimationClasses/AuraSphere.xml \
Demo/AnimationClasses/Female_NPC_3.xml \
Demo/AnimationClasses/Female_NPC_1.xml \
Demo/AnimationClasses/Snake.xml \
Demo/AnimationClasses/Captain.xml \
Demo/AnimationClasses/Bee_Normal.xml \
Demo/AnimationClasses/Female_NPC_2.xml \
Demo/AnimationClasses/Ranger.xml \
Demo/AnimationClasses/Elder.xml \
Demo/ListBoxItemPool.lua \
Demo/Music/Aria_2.ogg \
Demo/Music/MainV2.ogg \
Demo/AbilityNode.lua \
Demo/AbilityDragTable.lua \
Demo/UnitFrame.lua \
Demo/XPDrop.lua \
Demo/ItemDragTable.lua \
Demo/EnemyClass.lua \
Demo/PlayableChars/Mariana.lua \
Demo/Item.lua \
Demo/init.lua \
Demo/LevelRequirement.lua \
Demo/QuestState.lua \
Demo/Sprites/QuestTurnIn.lua \
Demo/Sprites/FX1.anim \
Demo/Sprites/Elder/Elder.png \
Demo/Sprites/Elder/Elder.anim \
Demo/Sprites/Elder/Elder.sprites \
Demo/Sprites/Female_NPC_1/Female_NPC_1.png \
Demo/Sprites/Female_NPC_1/Female_NPC_1.anim \
Demo/Sprites/Female_NPC_1/Female_NPC_1.sprites \
Demo/Sprites/Mark/trgPos.sprites \
Demo/Sprites/Mark/Mark.anim \
Demo/Sprites/Mark/trgPos.png \
Demo/Sprites/Mark/trgPos.xml \
Demo/Sprites/Mark/Makr.sprites \
Demo/Sprites/Mark/Mark.xml \
Demo/Sprites/Mark/trgPos.anim \
Demo/Sprites/Mark/Mark.png \
Demo/Sprites/Captain/Captain.png \
Demo/Sprites/Captain/Captain.anim~ \
Demo/Sprites/Captain/Captain.sprites \
Demo/Sprites/Captain/Captain.anim \
Demo/Sprites/FX1.png \
Demo/Sprites/QuestMark.lua \
Demo/Sprites/Bee_Norm/Bee.anim \
Demo/Sprites/Bee_Norm/bee.png \
Demo/Sprites/Bee_Norm/Bee.sprites \
Demo/Sprites/FX1.sprites \
Demo/Sprites/AuraSphere.anim \
Demo/Sprites/Ranger/Ranger.anim \
Demo/Sprites/Ranger/Ranger.png \
Demo/Sprites/Ranger/Ranger.sprites \
Demo/Sprites/Chicken/Chicken.sprites \
Demo/Sprites/Chicken/Chicken.anim \
Demo/Sprites/Chicken/Chicken.png \
Demo/Sprites/Female_NPC_2/Female_NPC_2.anim \
Demo/Sprites/Female_NPC_2/Female_NPC_2.png \
Demo/Sprites/Female_NPC_2/Female_NPC_2.sprites \
Demo/Sprites/Snake/Snake.sprites \
Demo/Sprites/Snake/snake.png \
Demo/Sprites/Snake/Snake.anim \
Demo/Sprites/PurpleDebuff.lua \
Demo/Sprites/Orc/Orc.anim \
Demo/Sprites/Orc/Orc.png \
Demo/Sprites/Orc/Orc.sprites \
Demo/Sprites/AuraSphere.sprites \
Demo/Sprites/OrcArcher/OrcArcher.png \
Demo/Sprites/OrcArcher/OrcArcher.anim \
Demo/Sprites/OrcArcher/OrcArcher.sprites \
Demo/Sprites/Guard/Guard.sprites \
Demo/Sprites/Guard/Guard.png \
Demo/Sprites/Guard/Guard.anim \
Demo/Sprites/ball.png \
Demo/Sprites/Female_NPC_3/Female_NPC_3.sprites \
Demo/Sprites/Female_NPC_3/Female_NPC_3.anim \
Demo/Sprites/Female_NPC_3/Female_NPC_3.png \
Demo/DamageTextPool.lua \
Demo/Enemies/Chicken/init.lua \
Demo/Enemies/Chicken/Class.xml \
Demo/Enemies/Bee/Class.xml \
Demo/Enemies/Snake/init.lua \
Demo/Enemies/Snake/Class.xml \
Demo/Enemies/Orc/init.lua \
Demo/Enemies/Orc/Class.xml \
Demo/ItemClass.lua \
Demo/Fonts/Ubuntu-RI.ttf \
Demo/Fonts/FreeSans.ttf \
Demo/Fonts/Ubuntu-R.ttf \
Demo/Fonts/Ubuntu-MI.ttf \
Demo/Fonts/DejaVuSans.ttf \
Demo/Fonts/Ubuntu-M.ttf \
Demo/Operations.lua \
Demo/QuestClass.lua \
Demo/ItemDrop.lua \
Demo/XMLFiles/System.xml \
Demo/XMLFiles/Settings.xml \
Demo/XMLFiles/Schemas/DarkFunctionAnim.xsd \
Demo/XMLFiles/Schemas/TiledMap.xsd \
Demo/XMLFiles/Schemas/LifeformClasses.xsd \
Demo/XMLFiles/Schemas/System.xsd \
Demo/XMLFiles/Schemas/TiledTileset.xsd \
Demo/XMLFiles/Schemas/Factions.xsd \
Demo/XMLFiles/Schemas/AnimationClasses.xsd \
Demo/XMLFiles/Schemas/DarkFunctionSprites.xsd \
Demo/CEGUI_Settings.xml \
Demo/UnitFramePool.lua \
Demo/ItemSlot.lua \
Demo/QuestTrackPool.lua \
Demo/Characters/Mariana.png \
Demo/Characters/LoadingScreens/Trade.png \
Demo/Characters/LoadingScreens/Ship.png \
Demo/Characters/LoadingScreens/Irene11ALT.png \
Demo/Characters/LoadingScreens/Zoe1080.png \
Demo/Characters/LoadingScreens/topiο4.png \
Demo/Characters/LoadingScreens/mountains.png \
Demo/Characters/LoadingScreens/Lake.png \
Demo/Characters/LoadingScreens/Efi.png \
Demo/Characters/Mariana2.png \
Demo/Characters/MarianaAv.png \
Demo/PlayableCharacter.lua \
Demo/Enemy.lua \
Demo/Npc.lua \
Demo/GUI/MainMenu.lua \
Demo/GUI/GameInterface.lua \
Demo/GUI/Console.lua \
Demo/GUI/CharSelect.lua \
Demo/GUI/init.lua \
Demo/GUI/LoadingScreen.lua \
Demo/GUI/Options.lua \
Demo/Inventory.lua \
Demo/Dialog.lua \
Demo/DragIconPool.lua \
Demo/Abilities/Icons/Melee.png \
Demo/Abilities/AuraSphere.lua \
Demo/Abilities/Strike.lua \
Demo/Abilities/HP5.lua \
Demo/Abilities/Effects/Fear.lua \
Demo/Abilities/Effects/init.lua \
Demo/Abilities/Melee.lua \
Demo/Abilities/Sounds/charge.ogg \
Demo/Abilities/Sounds/shoot.ogg \
Demo/Abilities/Sounds/swing.ogg \
Demo/Abilities/MP5.lua \
Demo/DragTable.lua

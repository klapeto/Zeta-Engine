#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libzeta.la libzeta-sdk-allegro5.la

#######################################
# Build information for each library

# Sources for libzeta
libzeta_la_SOURCES = \
Zeta/Core/Event.cpp \
Zeta/Core/AsynchronousResourceContext.cpp \
Zeta/Core/ResourceReleaseRequest.cpp \
Zeta/Core/ConsoleFunctions.cpp \
Zeta/Core/SaveManager.cpp \
Zeta/Core/ShapeRenderer.cpp \
Zeta/Core/RenderingContext.cpp \
Zeta/Core/SingleInstanced.cpp \
Zeta/Core/System.cpp \
Zeta/Core/Drawable.cpp \
Zeta/Core/ConsoleManager.cpp \
Zeta/Core/RPGClasses/AI/Faction.cpp \
Zeta/Core/RPGClasses/AI/WanderingMovement.cpp \
Zeta/Core/RPGClasses/AI/AggressiveBehaviour.cpp \
Zeta/Core/RPGClasses/AI/IdleMovementClass.cpp \
Zeta/Core/RPGClasses/AI/IdleMovement.cpp \
Zeta/Core/RPGClasses/AI/PassiveBehaviourClass.cpp \
Zeta/Core/RPGClasses/AI/BehaviourClass.cpp \
Zeta/Core/RPGClasses/AI/WanderingMovementClass.cpp \
Zeta/Core/RPGClasses/AI/Behaviour.cpp \
Zeta/Core/RPGClasses/AI/FactionManager.cpp \
Zeta/Core/RPGClasses/AI/AggressiveBehaviourClass.cpp \
Zeta/Core/RPGClasses/AI/PassiveBehaviour.cpp \
Zeta/Core/RPGClasses/LifeformClassContainer.cpp \
Zeta/Core/RPGClasses/PassiveAbilityClass.cpp \
Zeta/Core/RPGClasses/Chance.cpp \
Zeta/Core/RPGClasses/Attribute.cpp \
Zeta/Core/RPGClasses/InteractObject.cpp \
Zeta/Core/RPGClasses/ActiveAbilityClass.cpp \
Zeta/Core/RPGClasses/Modifier.cpp \
Zeta/Core/RPGClasses/LifeformClass.cpp \
Zeta/Core/RPGClasses/Enemy.cpp \
Zeta/Core/RPGClasses/PassiveAbility.cpp \
Zeta/Core/RPGClasses/CEGUIChild.cpp \
Zeta/Core/RPGClasses/FlatModifier.cpp \
Zeta/Core/RPGClasses/Player.cpp \
Zeta/Core/RPGClasses/OverTimeEffect.cpp \
Zeta/Core/RPGClasses/ChildObject.cpp \
Zeta/Core/RPGClasses/EffectClass.cpp \
Zeta/Core/RPGClasses/Object.cpp \
Zeta/Core/RPGClasses/DirectionalProjectile.cpp \
Zeta/Core/RPGClasses/Lifeform.cpp \
Zeta/Core/RPGClasses/WorldListener.cpp \
Zeta/Core/RPGClasses/WorldManager.cpp \
Zeta/Core/RPGClasses/Npc.cpp \
Zeta/Core/RPGClasses/DurableEffect.cpp \
Zeta/Core/RPGClasses/AbilityClass.cpp \
Zeta/Core/RPGClasses/WorldEvent.cpp \
Zeta/Core/RPGClasses/Projectile.cpp \
Zeta/Core/RPGClasses/StickyObject.cpp \
Zeta/Core/RPGClasses/CEGUIObject.cpp \
Zeta/Core/RPGClasses/ProjectileClass.cpp \
Zeta/Core/RPGClasses/RegenerationAbilityClass.cpp \
Zeta/Core/RPGClasses/ClassifiedAbility.cpp \
Zeta/Core/RPGClasses/Regeneration.cpp \
Zeta/Core/RPGClasses/SeekingProjectile.cpp \
Zeta/Core/RPGClasses/ActiveAbility.cpp \
Zeta/Core/RPGClasses/Timer.cpp \
Zeta/Core/RPGClasses/MulModifier.cpp \
Zeta/Core/RPGClasses/Ability.cpp \
Zeta/Core/RPGClasses/LuaListener.cpp \
Zeta/Core/RPGClasses/Effect.cpp \
Zeta/Core/Color.cpp \
Zeta/Core/LuaNumber.cpp \
Zeta/Core/ResourceContext.cpp \
Zeta/Core/SynchronousRenderingContext.cpp \
Zeta/Core/Context.cpp \
Zeta/Core/AudioContext.cpp \
Zeta/Core/MusicManager.cpp \
Zeta/Core/SynchronousResourceContext.cpp \
Zeta/Core/LuaReferenced.cpp \
Zeta/Core/LuaEngine.cpp \
Zeta/Core/Settings.cpp \
Zeta/Core/UtilityClasses/Vector2D.cpp \
Zeta/Core/UtilityClasses/StringOperations.cpp \
Zeta/Core/UtilityClasses/Ellipsis.cpp \
Zeta/Core/UtilityClasses/Vector2.cpp \
Zeta/Core/UtilityClasses/base64.cpp \
Zeta/Core/UtilityClasses/Exception.cpp \
Zeta/Core/UtilityClasses/Rectangle.cpp \
Zeta/Core/UtilityClasses/Visitor.cpp \
Zeta/Core/UtilityClasses/Shape.cpp \
Zeta/Core/AsynchronousWorker.cpp \
Zeta/Core/Updateable.cpp \
Zeta/Core/XMLSchemaValidator.cpp \
Zeta/Core/GUIManager.cpp \
Zeta/Core/LuaPushable.cpp \
Zeta/Core/LuaFunctor.cpp \
Zeta/Core/NonCopyable.cpp \
Zeta/Core/LuaTable.cpp \
Zeta/Core/RenderRequest.cpp \
Zeta/Core/ContextOperation.cpp \
Zeta/Core/MapLoader.cpp \
Zeta/Core/LuaBoolean.cpp \
Zeta/Core/AsynchronousRenderingContext.cpp \
Zeta/Core/MainLoop.cpp \
Zeta/Core/FunctorContextOperation.cpp \
Zeta/Core/ResourceClasses/AnimationPack.cpp \
Zeta/Core/ResourceClasses/Sound.cpp \
Zeta/Core/ResourceClasses/Resource.cpp \
Zeta/Core/ResourceClasses/File.cpp \
Zeta/Core/ResourceClasses/AnimationClass.cpp \
Zeta/Core/ResourceClasses/Bitmap.cpp \
Zeta/Core/ResourceClasses/SharedResource.cpp \
Zeta/Core/ResourceClasses/SoundInstance.cpp \
Zeta/Core/ResourceClasses/SpriteSheet.cpp \
Zeta/Core/Logger.cpp \
Zeta/Core/LuaString.cpp \
Zeta/Core/MapClasses/Tile.cpp \
Zeta/Core/MapClasses/Tileset.cpp \
Zeta/Core/MapClasses/Quadtree.cpp \
Zeta/Core/MapClasses/StaticQuadtree.cpp \
Zeta/Core/MapClasses/InteractField.cpp \
Zeta/Core/MapClasses/Map.cpp \
Zeta/Core/MapClasses/TeleportField.cpp \
Zeta/Core/MapClasses/ExternalObjectRequest.cpp \
Zeta/Core/MapClasses/Layer.cpp \
Zeta/Core/MapClasses/StaticObject.cpp \
Zeta/Core/toLua_Binders/Binder.cpp \
Zeta/Core/LoopRunner.cpp \
Zeta/Core/PropertyList.cpp \
Zeta/Core/AnimationClasses/AnimationHandler.cpp \
Zeta/Core/AnimationClasses/AnimationPlayer.cpp \
Zeta/Core/AnimationClasses/Cell.cpp \
Zeta/Core/AnimationClasses/OffAnimation.cpp \
Zeta/Core/AnimationClasses/AnimationEffectsManager.cpp \
Zeta/Core/AnimationClasses/Animation.cpp \
Zeta/Core/NullReference.cpp \
Zeta/Core/Display.cpp \
Zeta/Core/View.cpp \
Zeta/Core/ResourceCache.cpp \
Zeta/Core/GeneralLoop.cpp \
Zeta/Core/SystemEventListener.cpp \
Zeta/Core/UtilityClasses/Crosshair.cpp \
Zeta/Core/RPGClasses/LifeformState.cpp \
Zeta/Core/LuaNil.cpp \
Zeta/Core/AnimationClasses/Sprite.cpp \
Zeta/Core/MapClasses/MapTileset.cpp \
Zeta/Core/MapClasses/ReferenceRequest.cpp

libzeta_sdk_allegro5_la_SOURCES = \
Zeta/LibraryBinders/Loaders/FileLoader.cpp \
Zeta/LibraryBinders/Allegro5/AllegroSDK.cpp \
Zeta/LibraryBinders/Allegro5/AllegroSound.cpp \
Zeta/LibraryBinders/Allegro5/AllegroRenderer.cpp \
Zeta/LibraryBinders/Allegro5/AllegroLoop.cpp \
Zeta/LibraryBinders/Allegro5/AllegroBitmap.cpp \
Zeta/LibraryBinders/Allegro5/AllegroDisplay.cpp \
Zeta/LibraryBinders/Allegro5/AllegroSoundInstance.cpp \
Zeta/LibraryBinders/Allegro5/AllegroAudioContext.cpp \
Zeta/LibraryBinders/Allegro5/AllegroEvent.cpp

SZLLdir = $(prefix)/share/lua/5.1/SZLL
dist_SZLL_DATA = \
SZLL/ObjectiveClass.lua \
SZLL/Ability.lua \
SZLL/DeQueue.lua \
SZLL/Item.lua \
SZLL/LifeformAbility.lua \
SZLL/ItemClass.lua \
SZLL/Quest.lua \
SZLL/dump.lua \
SZLL/ActiveAbility.lua \
SZLL/Objective.lua \
SZLL/Class.lua \
SZLL/Npc.lua \
SZLL/SaveManager.lua \
SZLL/OffAnimation.lua \
SZLL/Zeta.doclua \
SZLL/Map.lua \
SZLL/DurableEffect.lua \
SZLL/OverTimeEffect.lua \
SZLL/Effect.lua \
SZLL/PassiveAbility.lua \
SZLL/Regeneration.lua \
SZLL/CEGUI.doclua \
SZLL/init.lua \
SZLL/Projectile.lua \
SZLL/QuestClass.lua \
SZLL/QuestState.lua

EXTRA_DIST = \
Zeta/Core/toLua_Binders/WorldManager.pkg \
Zeta/Core/toLua_Binders/Modifier.pkg \
Zeta/Core/toLua_Binders/ConsoleManager.pkg \
Zeta/Core/toLua_Binders/AnimationPlayer.pkg \
Zeta/Core/toLua_Binders/CEGUIObject.pkg \
Zeta/Core/toLua_Binders/Binder.cpp \
Zeta/Core/toLua_Binders/AbilityClass.pkg \
Zeta/Core/toLua_Binders/Npc.pkg \
Zeta/Core/toLua_Binders/InteractObject.pkg \
Zeta/Core/toLua_Binders/tolua++Z \
Zeta/Core/toLua_Binders/InteractField.pkg \
Zeta/Core/toLua_Binders/Animation.pkg \
Zeta/Core/toLua_Binders/LifeformClassContainer.pkg \
Zeta/Core/toLua_Binders/Rectangle.pkg \
Zeta/Core/toLua_Binders/Player.pkg \
Zeta/Core/toLua_Binders/Vector2.pkg \
Zeta/Core/toLua_Binders/ChildObject.pkg \
Zeta/Core/toLua_Binders/LuaListener.pkg \
Zeta/Core/toLua_Binders/View.pkg \
Zeta/Core/toLua_Binders/ActiveAbilityClass.pkg \
Zeta/Core/toLua_Binders/System.pkg \
Zeta/Core/toLua_Binders/PassiveAbility.pkg \
Zeta/Core/toLua_Binders/rebuild.sh \
Zeta/Core/toLua_Binders/Zeta.pkg \
Zeta/Core/toLua_Binders/WorldEvent.pkg \
Zeta/Core/toLua_Binders/AudioContext.pkg \
Zeta/Core/toLua_Binders/ActiveAbility.pkg \
Zeta/Core/toLua_Binders/Logger.pkg \
Zeta/Core/toLua_Binders/AnimationHandler.pkg \
Zeta/Core/toLua_Binders/EffectClass.pkg \
Zeta/Core/toLua_Binders/Object.pkg \
Zeta/Core/toLua_Binders/AnimationEffectsManager.pkg \
Zeta/Core/toLua_Binders/Regeneration.pkg \
Zeta/Core/toLua_Binders/OffAnimation.pkg \
Zeta/Core/toLua_Binders/Timer.pkg \
Zeta/Core/toLua_Binders/PassiveAbilityClass.pkg \
Zeta/Core/toLua_Binders/RegenerationAbilityClass.pkg \
Zeta/Core/toLua_Binders/Enemy.pkg \
Zeta/Core/toLua_Binders/SeekingProjectile.pkg \
Zeta/Core/toLua_Binders/Map.pkg \
Zeta/Core/toLua_Binders/Ability.pkg \
Zeta/Core/toLua_Binders/Lifeform.pkg \
Zeta/Core/toLua_Binders/CEGUIChild.pkg \
Zeta/Core/toLua_Binders/DirectionalProjectile.pkg \
Zeta/Core/toLua_Binders/Projectile.pkg \
Zeta/Core/toLua_Binders/Effect.pkg \
Zeta/Core/toLua_Binders/MainLoop.pkg \
Zeta/Core/toLua_Binders/LifeformClass.pkg \
Zeta/Core/toLua_Binders/Settings.pkg 


pkgcnfdir = $(prefix)/share/pkgconfig
dist_pkgcnf_DATA = \
zeta.pc \
zeta-sdk-allegro5.pc


# Linker options libTestProgram
libzeta_la_LDFLAGS = $(cegui_LIBS) $(lua51_LIBS) $(libxmlpp_LIBS) $(zlib_LIBS)
libzeta_sdk_allegro5_la_LDFLAGS = $(allegro5_LIBS)

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libzeta_la_CPPFLAGS = $(CXXFLAGS) -I$(top_srcdir)/include -I$(top_srcdir)/include/Zeta $(cegui_CFLAGS) $(lua51_CFLAGS) $(libxmlpp_CFLAGS) $(zlib_CFLAGS)
libzeta_sdk_allegro5_la_CPPFLAGS = $(CXXFLAGS) -I$(top_srcdir)/include -I$(top_srcdir)/include/Zeta $(allegro5_CFLAGS)



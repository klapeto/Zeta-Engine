/*
** Lua binding: Zeta
** Generated automatically by tolua++-1.0.93 on Mon Jan  4 18:12:07 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
int tolua_Zeta_open (lua_State* tolua_S);

#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/ConsoleManager.hpp>
#include <Zeta/Core/RPGClasses/DirectionalProjectile.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Enemy.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/MainLoop.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/Npc.hpp>
#include <Zeta/Core/RPGClasses/PassiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/Projectile.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/SaveManager.hpp>
#include <Zeta/Core/RPGClasses/SeekingProjectile.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/Settings.hpp>
#include <string>
#include <vector>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/View.hpp>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/AudioContext.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/PassiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/RegenerationAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/Regeneration.hpp>
#include <Zeta/Core/RPGClasses/InteractObject.hpp>
#include <Zeta/Core/RPGClasses/CEGUIChild.hpp>
#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/AnimationClasses/AnimationPlayer.hpp>
#include <Zeta/Core/AnimationClasses/AnimationEffectsManager.hpp>
#include <Zeta/Core/AnimationClasses/OffAnimation.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/RPGClasses/LifeformClassContainer.hpp>
#include <Zeta/Core/RPGClasses/CEGUIObject.hpp>
#include <Zeta/Core/MapClasses/InteractField.hpp>
#include <Zeta/Core/RPGClasses/LuaListener.hpp>
#include <Zeta/Core/RPGClasses/EffectClass.hpp>
#include <Zeta/Core/RPGClasses/Effect.hpp>
#include <Zeta/Core/RPGClasses/Timer.hpp>
#include <Zeta/Core/ResourceCache.hpp>
#include <Zeta/Core/RPGClasses/LifeformState.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/RPGClasses/DurableEffect.hpp>
#include <Zeta/Core/RPGClasses/OverTimeEffect.hpp>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Zeta__LifeformState (lua_State* tolua_S)
{
 Zeta::LifeformState* self = (Zeta::LifeformState*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__CEGUIObject (lua_State* tolua_S)
{
 Zeta::CEGUIObject* self = (Zeta::CEGUIObject*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Rectangle (lua_State* tolua_S)
{
 Zeta::Rectangle* self = (Zeta::Rectangle*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__LifeformClassContainer (lua_State* tolua_S)
{
 Zeta::LifeformClassContainer* self = (Zeta::LifeformClassContainer*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__AbilityClass (lua_State* tolua_S)
{
 Zeta::AbilityClass* self = (Zeta::AbilityClass*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__WorldEvent (lua_State* tolua_S)
{
 Zeta::WorldEvent* self = (Zeta::WorldEvent*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Object (lua_State* tolua_S)
{
 Zeta::Object* self = (Zeta::Object*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Vector2 (lua_State* tolua_S)
{
 Zeta::Vector2* self = (Zeta::Vector2*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Npc (lua_State* tolua_S)
{
 Zeta::Npc* self = (Zeta::Npc*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Lifeform (lua_State* tolua_S)
{
 Zeta::Lifeform* self = (Zeta::Lifeform*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__LifeformClass (lua_State* tolua_S)
{
 Zeta::LifeformClass* self = (Zeta::LifeformClass*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__InteractObject (lua_State* tolua_S)
{
 Zeta::InteractObject* self = (Zeta::InteractObject*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Timer (lua_State* tolua_S)
{
 Zeta::Timer* self = (Zeta::Timer*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__LuaListener (lua_State* tolua_S)
{
 Zeta::LuaListener* self = (Zeta::LuaListener*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__EffectClass (lua_State* tolua_S)
{
 Zeta::EffectClass* self = (Zeta::EffectClass*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__Enemy (lua_State* tolua_S)
{
 Zeta::Enemy* self = (Zeta::Enemy*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__View (lua_State* tolua_S)
{
 Zeta::View* self = (Zeta::View*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Zeta__CEGUIChild (lua_State* tolua_S)
{
 Zeta::CEGUIChild* self = (Zeta::CEGUIChild*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Zeta::OverTimeEffect");
 tolua_usertype(tolua_S,"Zeta::Ability");
 tolua_usertype(tolua_S,"Zeta::PassiveAbility");
 tolua_usertype(tolua_S,"Zeta::AnimationHandler::QueuePlace");
 tolua_usertype(tolua_S,"Zeta::DurableEffect");
 tolua_usertype(tolua_S,"Zeta::ProjectileClass");
 tolua_usertype(tolua_S,"Zeta::LifeformClassContainer");
 tolua_usertype(tolua_S,"Zeta::Player");
 tolua_usertype(tolua_S,"Zeta::InteractField");
 tolua_usertype(tolua_S,"Zeta::ConsoleManager");
 tolua_usertype(tolua_S,"Zeta::Projectile");
 tolua_usertype(tolua_S,"Zeta::WorldEvent");
 tolua_usertype(tolua_S,"Zeta::Modifier::Type");
 tolua_usertype(tolua_S,"Zeta::Modifier");
 tolua_usertype(tolua_S,"Zeta::LifeformState");
 tolua_usertype(tolua_S,"Zeta::LifeformState::Action");
 tolua_usertype(tolua_S,"Zeta::ResourceCache");
 tolua_usertype(tolua_S,"Zeta::Timer");
 tolua_usertype(tolua_S,"Zeta::Effect");
 tolua_usertype(tolua_S,"Zeta::AudioContext");
 tolua_usertype(tolua_S,"Zeta::Lifeform");
 tolua_usertype(tolua_S,"Zeta::AnimationHandler");
 tolua_usertype(tolua_S,"Zeta::DirectionalProjectile");
 tolua_usertype(tolua_S,"Zeta::Settings");
 tolua_usertype(tolua_S,"Zeta::Logger");
 tolua_usertype(tolua_S,"Zeta::EffectClass");
 tolua_usertype(tolua_S,"Zeta::LuaListener");
 tolua_usertype(tolua_S,"Zeta::LifeformState::Direction");
 tolua_usertype(tolua_S,"Zeta::CEGUIObject");
 tolua_usertype(tolua_S,"Zeta::WorldManager");
 tolua_usertype(tolua_S,"Zeta::WorldEvent::Type");
 tolua_usertype(tolua_S,"Zeta::AnimationPlayer");
 tolua_usertype(tolua_S,"Zeta::MainLoop");
 tolua_usertype(tolua_S,"Zeta::LifeformClass");
 tolua_usertype(tolua_S,"Zeta::SeekingProjectile");
 tolua_usertype(tolua_S,"Zeta::OffAnimation");
 tolua_usertype(tolua_S,"Zeta::AnimationEffectsManager");
 tolua_usertype(tolua_S,"Zeta::Rectangle");
 tolua_usertype(tolua_S,"Zeta::Animation");
 tolua_usertype(tolua_S,"Zeta::AbilityClass");
 tolua_usertype(tolua_S,"CEGUI::Window");
 tolua_usertype(tolua_S,"Zeta::CEGUIChild");
 tolua_usertype(tolua_S,"Zeta::ChildObject");
 tolua_usertype(tolua_S,"Zeta::Ability::Result");
 tolua_usertype(tolua_S,"Zeta::Object");
 tolua_usertype(tolua_S,"Zeta::Vector2");
 tolua_usertype(tolua_S,"Zeta::ProjectileClass::ProjectileType");
 tolua_usertype(tolua_S,"Zeta::InteractObject");
 tolua_usertype(tolua_S,"Zeta::Regeneration");
 tolua_usertype(tolua_S,"Zeta::Npc");
 tolua_usertype(tolua_S,"Zeta::Display");
 tolua_usertype(tolua_S,"Zeta::RegenerationAbilityClass");
 tolua_usertype(tolua_S,"Zeta::View");
 tolua_usertype(tolua_S,"Zeta::AbilityClass::Type");
 tolua_usertype(tolua_S,"Zeta::ActiveAbilityClass");
 tolua_usertype(tolua_S,"Zeta::ActiveAbility");
 tolua_usertype(tolua_S,"Zeta::System");
 tolua_usertype(tolua_S,"Zeta::PassiveAbilityClass");
 tolua_usertype(tolua_S,"Zeta::SaveManager");
 tolua_usertype(tolua_S,"Zeta::Display::Resolution");
 tolua_usertype(tolua_S,"Zeta::Enemy");
 tolua_usertype(tolua_S,"Zeta::WorldManager::Callback");
 tolua_usertype(tolua_S,"Zeta::Map");
}

/* method: getLevel of class  Zeta::Ability */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Ability_getLevel00
static int tolua_Zeta_Zeta_Ability_getLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Ability",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Ability* self = (const Zeta::Ability*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevel'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLevel of class  Zeta::Ability */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Ability_setLevel00
static int tolua_Zeta_Zeta_Ability_setLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Ability",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Ability* self = (Zeta::Ability*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLevel'",NULL);
#endif
 {
  self->setLevel(level);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOwner of class  Zeta::Ability */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Ability_getOwner00
static int tolua_Zeta_Zeta_Ability_getOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Ability",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Ability* self = (Zeta::Ability*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOwner'",NULL);
#endif
 {
  Zeta::Lifeform& tolua_ret = (Zeta::Lifeform&)  self->getOwner();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLevels of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_getLevels00
static int tolua_Zeta_Zeta_AbilityClass_getLevels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevels'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getLevels();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAbilityName of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_getAbilityName00
static int tolua_Zeta_Zeta_AbilityClass_getAbilityName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAbilityName'",NULL);
#endif
 {
  const std::string tolua_ret = (const std::string)  self->getAbilityName();
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAbilityName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPassive of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_isPassive00
static int tolua_Zeta_Zeta_AbilityClass_isPassive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPassive'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isPassive();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPassive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_getType00
static int tolua_Zeta_Zeta_AbilityClass_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'",NULL);
#endif
 {
  Zeta::AbilityClass::Type tolua_ret = (Zeta::AbilityClass::Type)  self->getType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLuaTable of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_getLuaTable00
static int tolua_Zeta_Zeta_AbilityClass_getLuaTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuaTable'",NULL);
#endif
 {
  lua_Object tolua_ret = (lua_Object)  self->getLuaTable();
 tolua_pushvalue(tolua_S,(int)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuaTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onApply of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_onApply00
static int tolua_Zeta_Zeta_AbilityClass_onApply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Ability",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Ability* invoker = ((Zeta::Ability*)  tolua_tousertype(tolua_S,2,0));
  Zeta::Lifeform* caster = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onApply'",NULL);
#endif
 {
  self->onApply(invoker,caster,target);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onApply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onRemove of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_onRemove00
static int tolua_Zeta_Zeta_AbilityClass_onRemove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Ability",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AbilityClass* self = (const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Ability* invoker = ((Zeta::Ability*)  tolua_tousertype(tolua_S,2,0));
  Zeta::Lifeform* caster = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onRemove'",NULL);
#endif
 {
  self->onRemove(invoker,caster,target);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onRemove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_new00
static int tolua_Zeta_Zeta_AbilityClass_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
 {
  Zeta::AbilityClass* tolua_ret = (Zeta::AbilityClass*)  new Zeta::AbilityClass(table);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::AbilityClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_new00_local
static int tolua_Zeta_Zeta_AbilityClass_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
 {
  Zeta::AbilityClass* tolua_ret = (Zeta::AbilityClass*)  new Zeta::AbilityClass(table);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::AbilityClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::AbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AbilityClass_delete00
static int tolua_Zeta_Zeta_AbilityClass_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AbilityClass* self = (Zeta::AbilityClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  Zeta::AnimationHandler */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationHandler_setAnimation00
static int tolua_Zeta_Zeta_AnimationHandler_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationHandler",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationHandler* self = (Zeta::AnimationHandler*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'",NULL);
#endif
 {
  self->setAnimation(name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationClass of class  Zeta::AnimationHandler */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationHandler_setAnimationClass00
static int tolua_Zeta_Zeta_AnimationHandler_setAnimationClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationHandler",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationHandler* self = (Zeta::AnimationHandler*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationClass'",NULL);
#endif
 {
  self->setAnimationClass(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMainAnimationPlayer of class  Zeta::AnimationHandler */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationHandler_getMainAnimationPlayer00
static int tolua_Zeta_Zeta_AnimationHandler_getMainAnimationPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AnimationHandler",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AnimationHandler* self = (const Zeta::AnimationHandler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMainAnimationPlayer'",NULL);
#endif
 {
  Zeta::AnimationPlayer& tolua_ret = (Zeta::AnimationPlayer&)  self->getMainAnimationPlayer();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AnimationPlayer");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMainAnimationPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addOffAnimation of class  Zeta::AnimationHandler */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationHandler_addOffAnimation00
static int tolua_Zeta_Zeta_AnimationHandler_addOffAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationHandler",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Animation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationHandler* self = (Zeta::AnimationHandler*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Animation* animation = ((const Zeta::Animation*)  tolua_tousertype(tolua_S,2,0));
   float dx = ((  float)  tolua_tonumber(tolua_S,3,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,4,0));
  Zeta::AnimationHandler::QueuePlace queue = ((Zeta::AnimationHandler::QueuePlace)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addOffAnimation'",NULL);
#endif
 {
  self->addOffAnimation(*animation,dx,dy,queue);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addOffAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffAnimation of class  Zeta::AnimationHandler */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationHandler_getOffAnimation00
static int tolua_Zeta_Zeta_AnimationHandler_getOffAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationHandler",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationHandler* self = (Zeta::AnimationHandler*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Zeta::AnimationHandler::QueuePlace queue = ((Zeta::AnimationHandler::QueuePlace)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffAnimation'",NULL);
#endif
 {
  Zeta::OffAnimation& tolua_ret = (Zeta::OffAnimation&)  self->getOffAnimation(name,queue);
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::OffAnimation");
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationHandler of class  Zeta::ChildObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ChildObject_getAnimationHandler00
static int tolua_Zeta_Zeta_ChildObject_getAnimationHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ChildObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ChildObject* self = (Zeta::ChildObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationHandler'",NULL);
#endif
 {
  Zeta::AnimationHandler& tolua_ret = (Zeta::AnimationHandler&)  self->getAnimationHandler();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AnimationHandler");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParent of class  Zeta::ChildObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ChildObject_getParent00
static int tolua_Zeta_Zeta_ChildObject_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ChildObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ChildObject* self = (Zeta::ChildObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'",NULL);
#endif
 {
  Zeta::Object* tolua_ret = (Zeta::Object*)  self->getParent();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Object");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasParent of class  Zeta::ChildObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ChildObject_hasParent00
static int tolua_Zeta_Zeta_ChildObject_hasParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ChildObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ChildObject* self = (const Zeta::ChildObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasParent'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasParent();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParent of class  Zeta::ChildObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ChildObject_setParent00
static int tolua_Zeta_Zeta_ChildObject_setParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ChildObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ChildObject* self = (Zeta::ChildObject*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Object* parent = ((Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParent'",NULL);
#endif
 {
  self->setParent(parent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: excecuteLine of class  Zeta::ConsoleManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ConsoleManager_excecuteLine00
static int tolua_Zeta_Zeta_ConsoleManager_excecuteLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ConsoleManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ConsoleManager* self = (Zeta::ConsoleManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string line = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'excecuteLine'",NULL);
#endif
 {
  std::string tolua_ret = (std::string)  self->excecuteLine(line);
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 tolua_pushcppstring(tolua_S,(const char*)line);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'excecuteLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::ConsoleManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ConsoleManager_getInstance00
static int tolua_Zeta_Zeta_ConsoleManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::ConsoleManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::ConsoleManager& tolua_ret = (Zeta::ConsoleManager&)  Zeta::ConsoleManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::ConsoleManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBounding of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getBounding00
static int tolua_Zeta_Zeta_Object_getBounding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBounding'",NULL);
#endif
 {
  const Zeta::Rectangle& tolua_ret = (const Zeta::Rectangle&)  self->getBounding();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::Rectangle");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBounding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBounding of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getBounding01
static int tolua_Zeta_Zeta_Object_getBounding01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBounding'",NULL);
#endif
 {
  Zeta::Rectangle& tolua_ret = (Zeta::Rectangle&)  self->getBounding();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Object_getBounding00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBounding of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setBounding00
static int tolua_Zeta_Zeta_Object_setBounding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Rectangle* bounding = ((const Zeta::Rectangle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBounding'",NULL);
#endif
 {
  self->setBounding(*bounding);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBounding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTargetArea of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getTargetArea00
static int tolua_Zeta_Zeta_Object_getTargetArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTargetArea'",NULL);
#endif
 {
  const Zeta::Rectangle& tolua_ret = (const Zeta::Rectangle&)  self->getTargetArea();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::Rectangle");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTargetArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTargetArea of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getTargetArea01
static int tolua_Zeta_Zeta_Object_getTargetArea01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTargetArea'",NULL);
#endif
 {
  Zeta::Rectangle& tolua_ret = (Zeta::Rectangle&)  self->getTargetArea();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Object_getTargetArea00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getPosition00
static int tolua_Zeta_Zeta_Object_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
 {
  const Zeta::Vector2& tolua_ret = (const Zeta::Vector2&)  self->getPosition();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setPosition00
static int tolua_Zeta_Zeta_Object_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* position = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setPosition01
static int tolua_Zeta_Zeta_Object_setPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_Object_setPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getName00
static int tolua_Zeta_Zeta_Object_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
 {
  const std::string tolua_ret = (const std::string)  self->getName();
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setName00
static int tolua_Zeta_Zeta_Object_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'",NULL);
#endif
 {
  self->setName(name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistance of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getDistance00
static int tolua_Zeta_Zeta_Object_getDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Object* other = ((const Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistance'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getDistance(*other);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChildObject of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_addChildObject00
static int tolua_Zeta_Zeta_Object_addChildObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::ChildObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Zeta::ChildObject* child = ((Zeta::ChildObject*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChildObject'",NULL);
#endif
 {
  self->addChildObject(name,child);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChildObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChildObject of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_addChildObject01
static int tolua_Zeta_Zeta_Object_addChildObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string classPath = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string animName = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChildObject'",NULL);
#endif
 {
  self->addChildObject(x,y,name,classPath,animName);
 tolua_pushcppstring(tolua_S,(const char*)name);
 tolua_pushcppstring(tolua_S,(const char*)classPath);
 tolua_pushcppstring(tolua_S,(const char*)animName);
 }
 }
 return 3;
tolua_lerror:
 return tolua_Zeta_Zeta_Object_addChildObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChildObject of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_removeChildObject00
static int tolua_Zeta_Zeta_Object_removeChildObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChildObject'",NULL);
#endif
 {
  self->removeChildObject(name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChildObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRenderPosition of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getRenderPosition00
static int tolua_Zeta_Zeta_Object_getRenderPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRenderPosition'",NULL);
#endif
 {
  Zeta::Vector2 tolua_ret = (Zeta::Vector2)  self->getRenderPosition();
 {
#ifdef __cplusplus
 void* tolua_obj = new Zeta::Vector2(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Zeta::Vector2));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRenderPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCollideAble of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_isCollideAble00
static int tolua_Zeta_Zeta_Object_isCollideAble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCollideAble'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isCollideAble();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCollideAble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCoolideAble of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setCoolideAble00
static int tolua_Zeta_Zeta_Object_setCoolideAble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCoolideAble'",NULL);
#endif
 {
  self->setCoolideAble(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCoolideAble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTriggeringCollisionEvents of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_isTriggeringCollisionEvents00
static int tolua_Zeta_Zeta_Object_isTriggeringCollisionEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTriggeringCollisionEvents'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isTriggeringCollisionEvents();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTriggeringCollisionEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTriggeringCollisionEvents of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setTriggeringCollisionEvents00
static int tolua_Zeta_Zeta_Object_setTriggeringCollisionEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTriggeringCollisionEvents'",NULL);
#endif
 {
  self->setTriggeringCollisionEvents(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTriggeringCollisionEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_isVisible00
static int tolua_Zeta_Zeta_Object_isVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Object* self = (const Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_setVisible00
static int tolua_Zeta_Zeta_Object_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'",NULL);
#endif
 {
  self->setVisible(visible);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_show00
static int tolua_Zeta_Zeta_Object_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
 {
  self->show();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_hide00
static int tolua_Zeta_Zeta_Object_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
 {
  self->hide();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChildObject of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_getChildObject00
static int tolua_Zeta_Zeta_Object_getChildObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChildObject'",NULL);
#endif
 {
  Zeta::ChildObject* tolua_ret = (Zeta::ChildObject*)  self->getChildObject(name);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::ChildObject");
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChildObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Object */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Object_delete00
static int tolua_Zeta_Zeta_Object_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Object* self = (Zeta::Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveToPosition of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_moveToPosition00
static int tolua_Zeta_Zeta_Lifeform_moveToPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveToPosition'",NULL);
#endif
 {
  self->moveToPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveToPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveToPosition of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_moveToPosition01
static int tolua_Zeta_Zeta_Lifeform_moveToPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* pos = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveToPosition'",NULL);
#endif
 {
  self->moveToPosition(*pos);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_moveToPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getState of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getState00
static int tolua_Zeta_Zeta_Lifeform_getState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getState'",NULL);
#endif
 {
  Zeta::LifeformState tolua_ret = (Zeta::LifeformState)  self->getState();
 {
#ifdef __cplusplus
 void* tolua_obj = new Zeta::LifeformState(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::LifeformState");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Zeta::LifeformState));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::LifeformState");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopMoving of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_stopMoving00
static int tolua_Zeta_Zeta_Lifeform_stopMoving00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopMoving'",NULL);
#endif
 {
  self->stopMoving();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopMoving'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClass of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setClass00
static int tolua_Zeta_Zeta_Lifeform_setClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClass'",NULL);
#endif
 {
  self->setClass(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationClass of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setAnimationClass00
static int tolua_Zeta_Zeta_Lifeform_setAnimationClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationClass'",NULL);
#endif
 {
  self->setAnimationClass(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActionAnimation of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setActionAnimation00
static int tolua_Zeta_Zeta_Lifeform_setActionAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActionAnimation'",NULL);
#endif
 {
  self->setActionAnimation(name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActionAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addOffAnimation of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_addOffAnimation00
static int tolua_Zeta_Zeta_Lifeform_addOffAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Animation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Animation* animation = ((const Zeta::Animation*)  tolua_tousertype(tolua_S,2,0));
   float dx = ((  float)  tolua_tonumber(tolua_S,3,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,4,0));
  Zeta::AnimationHandler::QueuePlace queue = ((Zeta::AnimationHandler::QueuePlace)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addOffAnimation'",NULL);
#endif
 {
  self->addOffAnimation(*animation,dx,dy,queue);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addOffAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttributeValue of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getAttributeValue00
static int tolua_Zeta_Zeta_Lifeform_getAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributeValue'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getAttributeValue(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributeValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAttributeBaseValue of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setAttributeBaseValue00
static int tolua_Zeta_Zeta_Lifeform_setAttributeBaseValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float value = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAttributeBaseValue'",NULL);
#endif
 {
  self->setAttributeBaseValue(name,value);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAttributeBaseValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttributesLuaTable of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getAttributesLuaTable00
static int tolua_Zeta_Zeta_Lifeform_getAttributesLuaTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributesLuaTable'",NULL);
#endif
 {
  self->getAttributesLuaTable();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributesLuaTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAttributeModifier of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_addAttributeModifier00
static int tolua_Zeta_Zeta_Lifeform_addAttributeModifier00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string attributeName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string modifierName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float value = ((  float)  tolua_tonumber(tolua_S,4,0));
  Zeta::Modifier::Type type = ((Zeta::Modifier::Type)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAttributeModifier'",NULL);
#endif
 {
  self->addAttributeModifier(attributeName,modifierName,value,type);
 tolua_pushcppstring(tolua_S,(const char*)attributeName);
 tolua_pushcppstring(tolua_S,(const char*)modifierName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAttributeModifier'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationHandler of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getAnimationHandler00
static int tolua_Zeta_Zeta_Lifeform_getAnimationHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationHandler'",NULL);
#endif
 {
  Zeta::AnimationHandler& tolua_ret = (Zeta::AnimationHandler&)  self->getAnimationHandler();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AnimationHandler");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAttributeModifier of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_removeAttributeModifier00
static int tolua_Zeta_Zeta_Lifeform_removeAttributeModifier00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string attributeName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string modifierName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAttributeModifier'",NULL);
#endif
 {
  self->removeAttributeModifier(attributeName,modifierName);
 tolua_pushcppstring(tolua_S,(const char*)attributeName);
 tolua_pushcppstring(tolua_S,(const char*)modifierName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAttributeModifier'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetMana of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_offsetMana00
static int tolua_Zeta_Zeta_Lifeform_offsetMana00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetMana'",NULL);
#endif
 {
  self->offsetMana(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetMana'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetHP of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_offsetHP00
static int tolua_Zeta_Zeta_Lifeform_offsetHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetHP'",NULL);
#endif
 {
  self->offsetHP(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHP of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setHP00
static int tolua_Zeta_Zeta_Lifeform_setHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'",NULL);
#endif
 {
  self->setHP(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMana of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setMana00
static int tolua_Zeta_Zeta_Lifeform_setMana00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMana'",NULL);
#endif
 {
  self->setMana(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMana'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHostileWith of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_isHostileWith00
static int tolua_Zeta_Zeta_Lifeform_isHostileWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* other = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHostileWith'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isHostileWith(other);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHostileWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addEffect of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_addEffect00
static int tolua_Zeta_Zeta_Lifeform_addEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Effect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Effect* eff = ((Zeta::Effect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEffect'",NULL);
#endif
 {
  self->addEffect(eff);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: canReceiveEffect of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_canReceiveEffect00
static int tolua_Zeta_Zeta_Lifeform_canReceiveEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::EffectClass* effClass = ((const Zeta::EffectClass*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'canReceiveEffect'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->canReceiveEffect(*effClass);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'canReceiveEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInCombat of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_isInCombat00
static int tolua_Zeta_Zeta_Lifeform_isInCombat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isInCombat'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isInCombat();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInCombat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInCombat of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setInCombat00
static int tolua_Zeta_Zeta_Lifeform_setInCombat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  bool combat = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInCombat'",NULL);
#endif
 {
  self->setInCombat(combat);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInCombat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetState of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_resetState00
static int tolua_Zeta_Zeta_Lifeform_resetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetState'",NULL);
#endif
 {
  self->resetState();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDirty of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_isDirty00
static int tolua_Zeta_Zeta_Lifeform_isDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDirty'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isDirty();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAlive of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_isAlive00
static int tolua_Zeta_Zeta_Lifeform_isAlive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAlive'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isAlive();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAlive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLevel of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getLevel00
static int tolua_Zeta_Zeta_Lifeform_getLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevel'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasTarget of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_hasTarget00
static int tolua_Zeta_Zeta_Lifeform_hasTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasTarget'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasTarget();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLuaTable of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getLuaTable00
static int tolua_Zeta_Zeta_Lifeform_getLuaTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuaTable'",NULL);
#endif
 {
  lua_Object tolua_ret = (lua_Object)  self->getLuaTable();
 tolua_pushvalue(tolua_S,(int)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuaTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLuaTable of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setLuaTable00
static int tolua_Zeta_Zeta_Lifeform_setLuaTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLuaTable'",NULL);
#endif
 {
  self->setLuaTable(table);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLuaTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAbility of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_addAbility00
static int tolua_Zeta_Zeta_Lifeform_addAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::AbilityClass* abilityClass = ((const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAbility'",NULL);
#endif
 {
  self->addAbility(*abilityClass,level);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTarget of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_setTarget00
static int tolua_Zeta_Zeta_Lifeform_setTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* trg = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTarget'",NULL);
#endif
 {
  self->setTarget(trg);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActiveAbility of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getActiveAbility00
static int tolua_Zeta_Zeta_Lifeform_getActiveAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string abilityName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActiveAbility'",NULL);
#endif
 {
  Zeta::ActiveAbility* tolua_ret = (Zeta::ActiveAbility*)  self->getActiveAbility(abilityName);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::ActiveAbility");
 tolua_pushcppstring(tolua_S,(const char*)abilityName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActiveAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPassiveAbility of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getPassiveAbility00
static int tolua_Zeta_Zeta_Lifeform_getPassiveAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string abilityName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPassiveAbility'",NULL);
#endif
 {
  Zeta::PassiveAbility* tolua_ret = (Zeta::PassiveAbility*)  self->getPassiveAbility(abilityName);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::PassiveAbility");
 tolua_pushcppstring(tolua_S,(const char*)abilityName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPassiveAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRegeneration of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getRegeneration00
static int tolua_Zeta_Zeta_Lifeform_getRegeneration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string regenerationName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRegeneration'",NULL);
#endif
 {
  Zeta::Regeneration* tolua_ret = (Zeta::Regeneration*)  self->getRegeneration(regenerationName);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Regeneration");
 tolua_pushcppstring(tolua_S,(const char*)regenerationName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRegeneration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAbility of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getAbility00
static int tolua_Zeta_Zeta_Lifeform_getAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const std::string abilityName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAbility'",NULL);
#endif
 {
  Zeta::Ability* tolua_ret = (Zeta::Ability*)  self->getAbility(abilityName);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Ability");
 tolua_pushcppstring(tolua_S,(const char*)abilityName);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_getTarget00
static int tolua_Zeta_Zeta_Lifeform_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'",NULL);
#endif
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  self->getTarget();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInMeleeRange of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_isInMeleeRange00
static int tolua_Zeta_Zeta_Lifeform_isInMeleeRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Lifeform* self = (const Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Lifeform* lf = ((const Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isInMeleeRange'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isInMeleeRange(lf);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInMeleeRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: teleportToCordinates of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_teleportToCordinates00
static int tolua_Zeta_Zeta_Lifeform_teleportToCordinates00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'teleportToCordinates'",NULL);
#endif
 {
  self->teleportToCordinates(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'teleportToCordinates'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: die of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_die00
static int tolua_Zeta_Zeta_Lifeform_die00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'die'",NULL);
#endif
 {
  self->die();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'die'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: face of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_face00
static int tolua_Zeta_Zeta_Lifeform_face00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* postion = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'face'",NULL);
#endif
 {
  self->face(*postion);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'face'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: face of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_face01
static int tolua_Zeta_Zeta_Lifeform_face01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'face'",NULL);
#endif
 {
  self->face(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_face00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: face of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_face02
static int tolua_Zeta_Zeta_Lifeform_face02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Object* other = ((Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'face'",NULL);
#endif
 {
  self->face(other);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_face01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new00
static int tolua_Zeta_Zeta_Lifeform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new00_local
static int tolua_Zeta_Zeta_Lifeform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new01
static int tolua_Zeta_Zeta_Lifeform_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string lifeClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform(lifeClass,x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Lifeform");
 tolua_pushcppstring(tolua_S,(const char*)lifeClass);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new01_local
static int tolua_Zeta_Zeta_Lifeform_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string lifeClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform(lifeClass,x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Lifeform");
 tolua_pushcppstring(tolua_S,(const char*)lifeClass);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new02
static int tolua_Zeta_Zeta_Lifeform_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::LifeformClass* lifeClass = ((const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform(*lifeClass,x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_new02_local
static int tolua_Zeta_Zeta_Lifeform_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::LifeformClass* lifeClass = ((const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Lifeform* tolua_ret = (Zeta::Lifeform*)  new Zeta::Lifeform(*lifeClass,x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Lifeform");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Lifeform_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Lifeform */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Lifeform_delete00
static int tolua_Zeta_Zeta_Lifeform_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Lifeform* self = (Zeta::Lifeform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Enemy */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Enemy_new00
static int tolua_Zeta_Zeta_Enemy_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Enemy",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string lifeClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Enemy* tolua_ret = (Zeta::Enemy*)  new Zeta::Enemy(lifeClass,x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Enemy");
 tolua_pushcppstring(tolua_S,(const char*)lifeClass);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Enemy */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Enemy_new00_local
static int tolua_Zeta_Zeta_Enemy_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Enemy",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string lifeClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Enemy* tolua_ret = (Zeta::Enemy*)  new Zeta::Enemy(lifeClass,x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Enemy");
 tolua_pushcppstring(tolua_S,(const char*)lifeClass);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Enemy */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Enemy_new01
static int tolua_Zeta_Zeta_Enemy_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Enemy",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::LifeformClass* lifeClass = ((const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
   float respawnTime = ((  float)  tolua_tonumber(tolua_S,5,30));
   float vanishTime = ((  float)  tolua_tonumber(tolua_S,6,10));
 {
  Zeta::Enemy* tolua_ret = (Zeta::Enemy*)  new Zeta::Enemy(*lifeClass,x,y,respawnTime,vanishTime);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Enemy");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Enemy_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Enemy */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Enemy_new01_local
static int tolua_Zeta_Zeta_Enemy_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Enemy",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::LifeformClass* lifeClass = ((const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
   float respawnTime = ((  float)  tolua_tonumber(tolua_S,5,30));
   float vanishTime = ((  float)  tolua_tonumber(tolua_S,6,10));
 {
  Zeta::Enemy* tolua_ret = (Zeta::Enemy*)  new Zeta::Enemy(*lifeClass,x,y,respawnTime,vanishTime);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Enemy");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Enemy_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Enemy */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Enemy_delete00
static int tolua_Zeta_Zeta_Enemy_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Enemy",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Enemy* self = (Zeta::Enemy*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::Logger */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Logger_getInstance00
static int tolua_Zeta_Zeta_Logger_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Logger",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Logger& tolua_ret = (Zeta::Logger&)  Zeta::Logger::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Logger");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  Zeta::Logger */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Logger_write00
static int tolua_Zeta_Zeta_Logger_write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Logger",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Logger* self = (Zeta::Logger*)  tolua_tousertype(tolua_S,1,0);
  const std::string message = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'",NULL);
#endif
 {
  self->write(message);
 tolua_pushcppstring(tolua_S,(const char*)message);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentFPS of class  Zeta::MainLoop */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_MainLoop_getCurrentFPS00
static int tolua_Zeta_Zeta_MainLoop_getCurrentFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::MainLoop",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::MainLoop* self = (const Zeta::MainLoop*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentFPS'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getCurrentFPS();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::MainLoop */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_MainLoop_getInstance00
static int tolua_Zeta_Zeta_MainLoop_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::MainLoop",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::MainLoop& tolua_ret = (Zeta::MainLoop&)  Zeta::MainLoop::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::MainLoop");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addObject of class  Zeta::Map */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Map_addObject00
static int tolua_Zeta_Zeta_Map_addObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Map",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Map* self = (Zeta::Map*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Object* obj = ((Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
  bool toBeDeleted = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addObject'",NULL);
#endif
 {
  self->addObject(obj,toBeDeleted);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertObject of class  Zeta::Map */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Map_insertObject00
static int tolua_Zeta_Zeta_Map_insertObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Map",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Map* self = (Zeta::Map*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Object* obj = ((Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
  bool toBeDeleted = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertObject'",NULL);
#endif
 {
  self->insertObject(obj,toBeDeleted);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeObject of class  Zeta::Map */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Map_removeObject00
static int tolua_Zeta_Zeta_Map_removeObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Map",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Map* self = (Zeta::Map*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Object* obj = ((Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeObject'",NULL);
#endif
 {
  self->removeObject(obj);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Npc */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Npc_new00
static int tolua_Zeta_Zeta_Npc_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Npc",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string classPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,5,0));
 {
  Zeta::Npc* tolua_ret = (Zeta::Npc*)  new Zeta::Npc(classPath,x,y,table);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Npc");
 tolua_pushcppstring(tolua_S,(const char*)classPath);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Npc */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Npc_new00_local
static int tolua_Zeta_Zeta_Npc_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Npc",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string classPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,5,0));
 {
  Zeta::Npc* tolua_ret = (Zeta::Npc*)  new Zeta::Npc(classPath,x,y,table);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Npc");
 tolua_pushcppstring(tolua_S,(const char*)classPath);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Npc */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Npc_delete00
static int tolua_Zeta_Zeta_Npc_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Npc",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Npc* self = (Zeta::Npc*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClass of class  Zeta::PassiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_PassiveAbility_getClass00
static int tolua_Zeta_Zeta_PassiveAbility_getClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::PassiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::PassiveAbility* self = (const Zeta::PassiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClass'",NULL);
#endif
 {
  const Zeta::PassiveAbilityClass& tolua_ret = (const Zeta::PassiveAbilityClass&)  self->getClass();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::PassiveAbilityClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setView of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_setView00
static int tolua_Zeta_Zeta_Player_setView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  Zeta::View* camera = ((Zeta::View*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setView'",NULL);
#endif
 {
  self->setView(*camera);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveToWorldPosition of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_moveToWorldPosition00
static int tolua_Zeta_Zeta_Player_moveToWorldPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveToWorldPosition'",NULL);
#endif
 {
  self->moveToWorldPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveToWorldPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: targetLifeformPosition of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_targetLifeformPosition00
static int tolua_Zeta_Zeta_Player_targetLifeformPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'targetLifeformPosition'",NULL);
#endif
 {
  self->targetLifeformPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'targetLifeformPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLevelUpCallback of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_setLevelUpCallback00
static int tolua_Zeta_Zeta_Player_setLevelUpCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLevelUpCallback'",NULL);
#endif
 {
  self->setLevelUpCallback(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLevelUpCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invokeAbility of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_invokeAbility00
static int tolua_Zeta_Zeta_Player_invokeAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Player",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Player* self = (const Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invokeAbility'",NULL);
#endif
 {
  Zeta::Ability::Result tolua_ret = (Zeta::Ability::Result)  self->invokeAbility(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invokeAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTargetIndicator of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_setTargetIndicator00
static int tolua_Zeta_Zeta_Player_setTargetIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
  const std::string childName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTargetIndicator'",NULL);
#endif
 {
  self->setTargetIndicator(childName);
 tolua_pushcppstring(tolua_S,(const char*)childName);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTargetIndicator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getXp of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_getXp00
static int tolua_Zeta_Zeta_Player_getXp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Player",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Player* self = (const Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getXp'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getXp();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getXp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setXp of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_setXp00
static int tolua_Zeta_Zeta_Player_setXp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setXp'",NULL);
#endif
 {
  self->setXp(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setXp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetXp of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_offsetXp00
static int tolua_Zeta_Zeta_Player_offsetXp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetXp'",NULL);
#endif
 {
  self->offsetXp(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetXp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setXpToNextLevel of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_setXpToNextLevel00
static int tolua_Zeta_Zeta_Player_setXpToNextLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Player",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Player* self = (Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setXpToNextLevel'",NULL);
#endif
 {
  self->setXpToNextLevel(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setXpToNextLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getXpToNextLevel of class  Zeta::Player */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Player_getXpToNextLevel00
static int tolua_Zeta_Zeta_Player_getXpToNextLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Player",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Player* self = (const Zeta::Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getXpToNextLevel'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getXpToNextLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getXpToNextLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearCollidedObjects of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_clearCollidedObjects00
static int tolua_Zeta_Zeta_Projectile_clearCollidedObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearCollidedObjects'",NULL);
#endif
 {
  self->clearCollidedObjects();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearCollidedObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_show00
static int tolua_Zeta_Zeta_Projectile_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
 {
  self->show();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_hide00
static int tolua_Zeta_Zeta_Projectile_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
 {
  self->hide();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_destroy00
static int tolua_Zeta_Zeta_Projectile_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
#endif
 {
  self->destroy();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTargetLocation of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_setTargetLocation00
static int tolua_Zeta_Zeta_Projectile_setTargetLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTargetLocation'",NULL);
#endif
 {
  self->setTargetLocation(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTargetLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentAbility of class  Zeta::Projectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Projectile_getParentAbility00
static int tolua_Zeta_Zeta_Projectile_getParentAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Projectile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Projectile* self = (Zeta::Projectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParentAbility'",NULL);
#endif
 {
  Zeta::ActiveAbility* tolua_ret = (Zeta::ActiveAbility*)  self->getParentAbility();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::ActiveAbility");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getX of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_getX00
static int tolua_Zeta_Zeta_Rectangle_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Rectangle* self = (const Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getY of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_getY00
static int tolua_Zeta_Zeta_Rectangle_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Rectangle* self = (const Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_setPosition00
static int tolua_Zeta_Zeta_Rectangle_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetPosition of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_offsetPosition00
static int tolua_Zeta_Zeta_Rectangle_offsetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetPosition'",NULL);
#endif
 {
  self->offsetPosition(dx,dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_getWidth00
static int tolua_Zeta_Zeta_Rectangle_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Rectangle* self = (const Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_getHeight00
static int tolua_Zeta_Zeta_Rectangle_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Rectangle* self = (const Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHeight of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_setHeight00
static int tolua_Zeta_Zeta_Rectangle_setHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHeight'",NULL);
#endif
 {
  self->setHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWidth of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_setWidth00
static int tolua_Zeta_Zeta_Rectangle_setWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWidth'",NULL);
#endif
 {
  self->setWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_setSize00
static int tolua_Zeta_Zeta_Rectangle_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
 {
  self->setSize(width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: overlapsPoint of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_overlapsPoint00
static int tolua_Zeta_Zeta_Rectangle_overlapsPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'overlapsPoint'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->overlapsPoint(x,y);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'overlapsPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: overlapsPoint of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_overlapsPoint01
static int tolua_Zeta_Zeta_Rectangle_overlapsPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* point = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'overlapsPoint'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->overlapsPoint(*point);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Rectangle_overlapsPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: overlapsRectangle of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_overlapsRectangle00
static int tolua_Zeta_Zeta_Rectangle_overlapsRectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Rectangle* self = (const Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Rectangle* other = ((const Zeta::Rectangle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'overlapsRectangle'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->overlapsRectangle(*other);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'overlapsRectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new00
static int tolua_Zeta_Zeta_Rectangle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new00_local
static int tolua_Zeta_Zeta_Rectangle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new01
static int tolua_Zeta_Zeta_Rectangle_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::Vector2* location = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle(*location,width,height);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Rectangle_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new01_local
static int tolua_Zeta_Zeta_Rectangle_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Zeta::Vector2* location = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle(*location,width,height);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Rectangle_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new02
static int tolua_Zeta_Zeta_Rectangle_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle(x,y,width,height);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Rectangle_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_new02_local
static int tolua_Zeta_Zeta_Rectangle_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  Zeta::Rectangle* tolua_ret = (Zeta::Rectangle*)  new Zeta::Rectangle(x,y,width,height);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Rectangle");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Rectangle_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Rectangle */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Rectangle_delete00
static int tolua_Zeta_Zeta_Rectangle_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Rectangle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Rectangle* self = (Zeta::Rectangle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFile of class  Zeta::SaveManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_SaveManager_setFile00
static int tolua_Zeta_Zeta_SaveManager_setFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::SaveManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::SaveManager* self = (Zeta::SaveManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFile'",NULL);
#endif
 {
  self->setFile(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: save of class  Zeta::SaveManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_SaveManager_save00
static int tolua_Zeta_Zeta_SaveManager_save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::SaveManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::SaveManager* self = (Zeta::SaveManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'save'",NULL);
#endif
 {
  self->save();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  Zeta::SaveManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_SaveManager_load00
static int tolua_Zeta_Zeta_SaveManager_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::SaveManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::SaveManager* self = (Zeta::SaveManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'",NULL);
#endif
 {
  self->load();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::SaveManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_SaveManager_getInstance00
static int tolua_Zeta_Zeta_SaveManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::SaveManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::SaveManager& tolua_ret = (Zeta::SaveManager&)  Zeta::SaveManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::SaveManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTarget of class  Zeta::SeekingProjectile */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_SeekingProjectile_setTarget00
static int tolua_Zeta_Zeta_SeekingProjectile_setTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::SeekingProjectile",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::SeekingProjectile* self = (Zeta::SeekingProjectile*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTarget'",NULL);
#endif
 {
  self->setTarget(target);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  Resolution */
#ifndef TOLUA_DISABLE_tolua_get_Zeta__Display__Resolution_height
static int tolua_get_Zeta__Display__Resolution_height(lua_State* tolua_S)
{
  Zeta::Display::Resolution* self = (Zeta::Display::Resolution*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  Resolution */
#ifndef TOLUA_DISABLE_tolua_set_Zeta__Display__Resolution_height
static int tolua_set_Zeta__Display__Resolution_height(lua_State* tolua_S)
{
  Zeta::Display::Resolution* self = (Zeta::Display::Resolution*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  Resolution */
#ifndef TOLUA_DISABLE_tolua_get_Zeta__Display__Resolution_width
static int tolua_get_Zeta__Display__Resolution_width(lua_State* tolua_S)
{
  Zeta::Display::Resolution* self = (Zeta::Display::Resolution*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  Resolution */
#ifndef TOLUA_DISABLE_tolua_set_Zeta__Display__Resolution_width
static int tolua_set_Zeta__Display__Resolution_width(lua_State* tolua_S)
{
  Zeta::Display::Resolution* self = (Zeta::Display::Resolution*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_getInstance00
static int tolua_Zeta_Zeta_Settings_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Settings& tolua_ret = (Zeta::Settings&)  Zeta::Settings::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Settings");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentResolution of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_getCurrentResolution00
static int tolua_Zeta_Zeta_Settings_getCurrentResolution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Settings* self = (const Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentResolution'",NULL);
#endif
 {
  const Zeta::Display::Resolution& tolua_ret = (const Zeta::Display::Resolution&)  self->getCurrentResolution();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::Display::Resolution");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentResolution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFullscreen of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_getFullscreen00
static int tolua_Zeta_Zeta_Settings_getFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Settings* self = (const Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFullscreen'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getFullscreen();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFullscreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFullscreen of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_setFullscreen00
static int tolua_Zeta_Zeta_Settings_setFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
  bool val = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFullscreen'",NULL);
#endif
 {
  self->setFullscreen(val);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFullscreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setResolution of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_setResolution00
static int tolua_Zeta_Zeta_Settings_setResolution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Display::Resolution",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Display::Resolution* res = ((const Zeta::Display::Resolution*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setResolution'",NULL);
#endif
 {
  self->setResolution(*res);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResolution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResolutionsTable of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_getResolutionsTable00
static int tolua_Zeta_Zeta_Settings_getResolutionsTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResolutionsTable'",NULL);
#endif
 {
  lua_Object tolua_ret = (lua_Object)  self->getResolutionsTable();
 tolua_pushvalue(tolua_S,(int)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResolutionsTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFile of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_loadFile00
static int tolua_Zeta_Zeta_Settings_loadFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadFile'",NULL);
#endif
 {
  self->loadFile();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFile of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_loadFile01
static int tolua_Zeta_Zeta_Settings_loadFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadFile'",NULL);
#endif
 {
  self->loadFile(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Settings_loadFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveSettings of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_saveSettings00
static int tolua_Zeta_Zeta_Settings_saveSettings00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveSettings'",NULL);
#endif
 {
  self->saveSettings();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveSettings'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveSettings of class  Zeta::Settings */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Settings_saveSettings01
static int tolua_Zeta_Zeta_Settings_saveSettings01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Settings",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::Settings* self = (Zeta::Settings*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveSettings'",NULL);
#endif
 {
  self->saveSettings(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Settings_saveSettings00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getX of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_getX00
static int tolua_Zeta_Zeta_Vector2_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setX of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_setX00
static int tolua_Zeta_Zeta_Vector2_setX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setX'",NULL);
#endif
 {
  self->setX(x);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getY of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_getY00
static int tolua_Zeta_Zeta_Vector2_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setY of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_setY00
static int tolua_Zeta_Zeta_Vector2_setY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
   float y = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setY'",NULL);
#endif
 {
  self->setY(y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_set00
static int tolua_Zeta_Zeta_Vector2_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offset of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_offset00
static int tolua_Zeta_Zeta_Vector2_offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offset'",NULL);
#endif
 {
  self->offset(dx,dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2__add00
static int tolua_Zeta_Zeta_Vector2__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* other = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'",NULL);
#endif
 {
  Zeta::Vector2 tolua_ret = (Zeta::Vector2)  self->operator+(*other);
 {
#ifdef __cplusplus
 void* tolua_obj = new Zeta::Vector2(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Zeta::Vector2));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2__sub00
static int tolua_Zeta_Zeta_Vector2__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* other = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'",NULL);
#endif
 {
  Zeta::Vector2 tolua_ret = (Zeta::Vector2)  self->operator-(*other);
 {
#ifdef __cplusplus
 void* tolua_obj = new Zeta::Vector2(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Zeta::Vector2));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2__mul00
static int tolua_Zeta_Zeta_Vector2__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
   float m = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'",NULL);
#endif
 {
  Zeta::Vector2 tolua_ret = (Zeta::Vector2)  self->operator*(m);
 {
#ifdef __cplusplus
 void* tolua_obj = new Zeta::Vector2(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Zeta::Vector2));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"Zeta::Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_getLength00
static int tolua_Zeta_Zeta_Vector2_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Vector2* self = (const Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistance of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_getDistance00
static int tolua_Zeta_Zeta_Vector2_getDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Vector2* other = ((const Zeta::Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistance'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getDistance(*other);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_normalize00
static int tolua_Zeta_Zeta_Vector2_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'",NULL);
#endif
 {
  self->normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_new00
static int tolua_Zeta_Zeta_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Vector2* tolua_ret = (Zeta::Vector2*)  new Zeta::Vector2();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_new00_local
static int tolua_Zeta_Zeta_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::Vector2* tolua_ret = (Zeta::Vector2*)  new Zeta::Vector2();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_new01
static int tolua_Zeta_Zeta_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
 {
  Zeta::Vector2* tolua_ret = (Zeta::Vector2*)  new Zeta::Vector2(x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_new01_local
static int tolua_Zeta_Zeta_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
 {
  Zeta::Vector2* tolua_ret = (Zeta::Vector2*)  new Zeta::Vector2(x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Vector2_delete00
static int tolua_Zeta_Zeta_Vector2_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Vector2",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Vector2* self = (Zeta::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_setPosition00
static int tolua_Zeta_Zeta_View_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::View* self = (Zeta::View*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetPosition of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_offsetPosition00
static int tolua_Zeta_Zeta_View_offsetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::View* self = (Zeta::View*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
  float dy = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetPosition'",NULL);
#endif
 {
  self->offsetPosition(dx,dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_resize00
static int tolua_Zeta_Zeta_View_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::View* self = (Zeta::View*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
#endif
 {
  self->resize(width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getX of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_getX00
static int tolua_Zeta_Zeta_View_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::View* self = (const Zeta::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getY of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_getY00
static int tolua_Zeta_Zeta_View_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::View* self = (const Zeta::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_getWidth00
static int tolua_Zeta_Zeta_View_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::View* self = (const Zeta::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_getHeight00
static int tolua_Zeta_Zeta_View_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::View* self = (const Zeta::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInView of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_isInView00
static int tolua_Zeta_Zeta_View_isInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::View",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::View* self = (const Zeta::View*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::Object* obj = ((const Zeta::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isInView'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isInView(*obj);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_new00
static int tolua_Zeta_Zeta_View_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::View* tolua_ret = (Zeta::View*)  new Zeta::View();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::View");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_new00_local
static int tolua_Zeta_Zeta_View_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::View* tolua_ret = (Zeta::View*)  new Zeta::View();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::View");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::View */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_View_delete00
static int tolua_Zeta_Zeta_View_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::View",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::View* self = (Zeta::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsDamageEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsDamageEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsDamageEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* victim = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
  Zeta::Lifeform* dealer = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
  unsigned amount = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsDamageEvent'",NULL);
#endif
 {
  self->setAsDamageEvent(victim,dealer,amount);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsDamageEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsDeathEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsDeathEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsDeathEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* victim = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsDeathEvent'",NULL);
#endif
 {
  self->setAsDeathEvent(victim);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsDeathEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsInteractEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsInteractEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsInteractEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* user1 = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
  Zeta::Lifeform* user2 = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsInteractEvent'",NULL);
#endif
 {
  self->setAsInteractEvent(user1,user2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsInteractEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsAbilityUseEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsAbilityUseEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsAbilityUseEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Ability",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* user = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
  Zeta::Ability* ability = ((Zeta::Ability*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsAbilityUseEvent'",NULL);
#endif
 {
  self->setAsAbilityUseEvent(user,ability);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsAbilityUseEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsWorldExitEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsWorldExitEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsWorldExitEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* invoker = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsWorldExitEvent'",NULL);
#endif
 {
  self->setAsWorldExitEvent(invoker);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsWorldExitEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAsCustomEvent of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_setAsCustomEvent00
static int tolua_Zeta_Zeta_WorldEvent_setAsCustomEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
  const std::string channel = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAsCustomEvent'",NULL);
#endif
 {
  self->setAsCustomEvent(channel,table);
 tolua_pushcppstring(tolua_S,(const char*)channel);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAsCustomEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: broadcast of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_broadcast00
static int tolua_Zeta_Zeta_WorldEvent_broadcast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'broadcast'",NULL);
#endif
 {
  self->broadcast();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'broadcast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toEventType of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_toEventType00
static int tolua_Zeta_Zeta_WorldEvent_toEventType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  Zeta::WorldEvent::Type tolua_ret = (Zeta::WorldEvent::Type)  Zeta::WorldEvent::toEventType(num);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toEventType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_getType00
static int tolua_Zeta_Zeta_WorldEvent_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::WorldEvent* self = (const Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'",NULL);
#endif
 {
  Zeta::WorldEvent::Type tolua_ret = (Zeta::WorldEvent::Type)  self->getType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_new00
static int tolua_Zeta_Zeta_WorldEvent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::WorldEvent* tolua_ret = (Zeta::WorldEvent*)  new Zeta::WorldEvent();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::WorldEvent");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_new00_local
static int tolua_Zeta_Zeta_WorldEvent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::WorldEvent* tolua_ret = (Zeta::WorldEvent*)  new Zeta::WorldEvent();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::WorldEvent");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::WorldEvent */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldEvent_delete00
static int tolua_Zeta_Zeta_WorldEvent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldEvent* self = (Zeta::WorldEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_getInstance00
static int tolua_Zeta_Zeta_WorldManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::WorldManager& tolua_ret = (Zeta::WorldManager&)  Zeta::WorldManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::WorldManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeMap of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_changeMap00
static int tolua_Zeta_Zeta_WorldManager_changeMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeMap'",NULL);
#endif
 {
  self->changeMap(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeMapWithCallback of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_changeMapWithCallback00
static int tolua_Zeta_Zeta_WorldManager_changeMapWithCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeMapWithCallback'",NULL);
#endif
 {
  self->changeMapWithCallback(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeMapWithCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallback of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_setCallback00
static int tolua_Zeta_Zeta_WorldManager_setCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
  Zeta::WorldManager::Callback call = ((Zeta::WorldManager::Callback)  tolua_tonumber(tolua_S,2,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallback'",NULL);
#endif
 {
  self->setCallback(call,name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallback of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_setCallback01
static int tolua_Zeta_Zeta_WorldManager_setCallback01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
  Zeta::WorldManager::Callback call = ((Zeta::WorldManager::Callback)  tolua_tonumber(tolua_S,2,0));
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallback'",NULL);
#endif
 {
  self->setCallback(call,func);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_WorldManager_setCallback00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: raiseEvent of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_raiseEvent00
static int tolua_Zeta_Zeta_WorldManager_raiseEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::WorldEvent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::WorldEvent* event = ((const Zeta::WorldEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'raiseEvent'",NULL);
#endif
 {
  self->raiseEvent(*event);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'raiseEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getView of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_getView00
static int tolua_Zeta_Zeta_WorldManager_getView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getView'",NULL);
#endif
 {
  Zeta::View& tolua_ret = (Zeta::View&)  self->getView();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::View");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_show00
static int tolua_Zeta_Zeta_WorldManager_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
 {
  self->show();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_hide00
static int tolua_Zeta_Zeta_WorldManager_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
 {
  self->hide();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_pause00
static int tolua_Zeta_Zeta_WorldManager_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'",NULL);
#endif
 {
  self->pause();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resume of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_resume00
static int tolua_Zeta_Zeta_WorldManager_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resume'",NULL);
#endif
 {
  self->resume();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentMap of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_getCurrentMap00
static int tolua_Zeta_Zeta_WorldManager_getCurrentMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentMap'",NULL);
#endif
 {
  Zeta::Map& tolua_ret = (Zeta::Map&)  self->getCurrentMap();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Map");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlayer of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_getPlayer00
static int tolua_Zeta_Zeta_WorldManager_getPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::WorldManager* self = (Zeta::WorldManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayer'",NULL);
#endif
 {
  Zeta::Player& tolua_ret = (Zeta::Player&)  self->getPlayer();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::Player");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::WorldManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_WorldManager_getInstance01
static int tolua_Zeta_Zeta_WorldManager_getInstance01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::WorldManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  Zeta::WorldManager& tolua_ret = (Zeta::WorldManager&)  Zeta::WorldManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::WorldManager");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_WorldManager_getInstance00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::System */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_System_getInstance00
static int tolua_Zeta_Zeta_System_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::System",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::System& tolua_ret = (Zeta::System&)  Zeta::System::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::System");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAudioContext of class  Zeta::System */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_System_getAudioContext00
static int tolua_Zeta_Zeta_System_getAudioContext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::System",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::System* self = (Zeta::System*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAudioContext'",NULL);
#endif
 {
  Zeta::AudioContext& tolua_ret = (Zeta::AudioContext&)  self->getAudioContext();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AudioContext");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAudioContext'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: shutdown of class  Zeta::System */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_System_shutdown00
static int tolua_Zeta_Zeta_System_shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::System",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::System* self = (Zeta::System*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'shutdown'",NULL);
#endif
 {
  self->shutdown();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: abort of class  Zeta::System */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_System_abort00
static int tolua_Zeta_Zeta_System_abort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::System",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::System* self = (Zeta::System*)  tolua_tousertype(tolua_S,1,0);
  const std::string error = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'abort'",NULL);
#endif
 {
  self->abort(error);
 tolua_pushcppstring(tolua_S,(const char*)error);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClass of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getClass00
static int tolua_Zeta_Zeta_ActiveAbility_getClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClass'",NULL);
#endif
 {
  const Zeta::ActiveAbilityClass& tolua_ret = (const Zeta::ActiveAbilityClass&)  self->getClass();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::ActiveAbilityClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invokeProjectile of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_invokeProjectile00
static int tolua_Zeta_Zeta_ActiveAbility_invokeProjectile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invokeProjectile'",NULL);
#endif
 {
  self->invokeProjectile(name,x,y);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invokeProjectile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRemainingCooldown of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getRemainingCooldown00
static int tolua_Zeta_Zeta_ActiveAbility_getRemainingCooldown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRemainingCooldown'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getRemainingCooldown();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRemainingCooldown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCastTime of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getCastTime00
static int tolua_Zeta_Zeta_ActiveAbility_getCastTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCastTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getCastTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCastTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCastTime of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_setCastTime00
static int tolua_Zeta_Zeta_ActiveAbility_setCastTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
   float castTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCastTime'",NULL);
#endif
 {
  self->setCastTime(castTime);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCastTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCoolDown of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getCoolDown00
static int tolua_Zeta_Zeta_ActiveAbility_getCoolDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCoolDown'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getCoolDown();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCoolDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCoolDown of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_setCoolDown00
static int tolua_Zeta_Zeta_ActiveAbility_setCoolDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
   float coolDown = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCoolDown'",NULL);
#endif
 {
  self->setCoolDown(coolDown);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCoolDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getManaCost of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getManaCost00
static int tolua_Zeta_Zeta_ActiveAbility_getManaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getManaCost'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getManaCost();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getManaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setManaCost of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_setManaCost00
static int tolua_Zeta_Zeta_ActiveAbility_setManaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
   float manaCost = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setManaCost'",NULL);
#endif
 {
  self->setManaCost(manaCost);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setManaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRange of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_getRange00
static int tolua_Zeta_Zeta_ActiveAbility_getRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbility* self = (const Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRange'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getRange();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRange of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_setRange00
static int tolua_Zeta_Zeta_ActiveAbility_setRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
   float range = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRange'",NULL);
#endif
 {
  self->setRange(range);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyEffect of class  Zeta::ActiveAbility */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbility_applyEffect00
static int tolua_Zeta_Zeta_ActiveAbility_applyEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ActiveAbility* self = (Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyEffect'",NULL);
#endif
 {
  self->applyEffect(name,target,level);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMainGain of class  Zeta::AudioContext */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AudioContext_getMainGain00
static int tolua_Zeta_Zeta_AudioContext_getMainGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AudioContext",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AudioContext* self = (const Zeta::AudioContext*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMainGain'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getMainGain();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMainGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMainGain of class  Zeta::AudioContext */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AudioContext_setMainGain00
static int tolua_Zeta_Zeta_AudioContext_setMainGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AudioContext",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AudioContext* self = (Zeta::AudioContext*)  tolua_tousertype(tolua_S,1,0);
  float mainGain = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMainGain'",NULL);
#endif
 {
  self->setMainGain(mainGain);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMainGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMusic of class  Zeta::AudioContext */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AudioContext_setMusic00
static int tolua_Zeta_Zeta_AudioContext_setMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AudioContext",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AudioContext* self = (Zeta::AudioContext*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMusic'",NULL);
#endif
 {
  self->setMusic(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Zeta::AudioContext */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AudioContext_start00
static int tolua_Zeta_Zeta_AudioContext_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AudioContext",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AudioContext* self = (Zeta::AudioContext*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'",NULL);
#endif
 {
  self->start();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Zeta::AudioContext */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AudioContext_stop00
static int tolua_Zeta_Zeta_AudioContext_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AudioContext",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AudioContext* self = (Zeta::AudioContext*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'",NULL);
#endif
 {
  self->stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applyEffect of class  Zeta::ActiveAbilityClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ActiveAbilityClass_applyEffect00
static int tolua_Zeta_Zeta_ActiveAbilityClass_applyEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::ActiveAbilityClass",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Zeta::ActiveAbility",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::ActiveAbilityClass* self = (const Zeta::ActiveAbilityClass*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
  Zeta::ActiveAbility* ability = ((Zeta::ActiveAbility*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applyEffect'",NULL);
#endif
 {
  self->applyEffect(name,target,level,ability);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applyEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClass of class  Zeta::Regeneration */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Regeneration_getClass00
static int tolua_Zeta_Zeta_Regeneration_getClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Regeneration",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Regeneration* self = (const Zeta::Regeneration*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClass'",NULL);
#endif
 {
  const Zeta::RegenerationAbilityClass& tolua_ret = (const Zeta::RegenerationAbilityClass&)  self->getClass();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::RegenerationAbilityClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnClick of class  Zeta::InteractObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_InteractObject_setOnClick00
static int tolua_Zeta_Zeta_InteractObject_setOnClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::InteractObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::InteractObject* self = (Zeta::InteractObject*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnClick'",NULL);
#endif
 {
  self->setOnClick(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnCollide of class  Zeta::InteractObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_InteractObject_setOnCollide00
static int tolua_Zeta_Zeta_InteractObject_setOnCollide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::InteractObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::InteractObject* self = (Zeta::InteractObject*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnCollide'",NULL);
#endif
 {
  self->setOnCollide(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnCollide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  Zeta::InteractObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_InteractObject_setAnimation00
static int tolua_Zeta_Zeta_InteractObject_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::InteractObject",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::InteractObject* self = (Zeta::InteractObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'",NULL);
#endif
 {
  self->setAnimation(name);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::InteractObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_InteractObject_new00
static int tolua_Zeta_Zeta_InteractObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::InteractObject",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string animationClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::InteractObject* tolua_ret = (Zeta::InteractObject*)  new Zeta::InteractObject(animationClass,x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::InteractObject");
 tolua_pushcppstring(tolua_S,(const char*)animationClass);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::InteractObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_InteractObject_new00_local
static int tolua_Zeta_Zeta_InteractObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::InteractObject",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string animationClass = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::InteractObject* tolua_ret = (Zeta::InteractObject*)  new Zeta::InteractObject(animationClass,x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::InteractObject");
 tolua_pushcppstring(tolua_S,(const char*)animationClass);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffesets of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_setOffesets00
static int tolua_Zeta_Zeta_CEGUIChild_setOffesets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIChild* self = (Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
   float offX = ((  float)  tolua_tonumber(tolua_S,2,0));
   float offY = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffesets'",NULL);
#endif
 {
  self->setOffesets(offX,offY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffesets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDestroy of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_isDestroy00
static int tolua_Zeta_Zeta_CEGUIChild_isDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIChild* self = (const Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDestroy'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isDestroy();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDestroy of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_setDestroy00
static int tolua_Zeta_Zeta_CEGUIChild_setDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIChild* self = (Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
  bool destroy = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDestroy'",NULL);
#endif
 {
  self->setDestroy(destroy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetX of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_getOffsetX00
static int tolua_Zeta_Zeta_CEGUIChild_getOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIChild* self = (const Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetX'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getOffsetX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetX of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_setOffsetX00
static int tolua_Zeta_Zeta_CEGUIChild_setOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIChild* self = (Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
   float offX = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetX'",NULL);
#endif
 {
  self->setOffsetX(offX);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetY of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_getOffsetY00
static int tolua_Zeta_Zeta_CEGUIChild_getOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIChild* self = (const Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetY'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getOffsetY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetY of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_setOffsetY00
static int tolua_Zeta_Zeta_CEGUIChild_setOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIChild* self = (Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
   float offY = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetY'",NULL);
#endif
 {
  self->setOffsetY(offY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindow of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_getWindow00
static int tolua_Zeta_Zeta_CEGUIChild_getWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIChild* self = (const Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindow'",NULL);
#endif
 {
  CEGUI::Window* tolua_ret = (CEGUI::Window*)  self->getWindow();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEGUI::Window");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWindow of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_setWindow00
static int tolua_Zeta_Zeta_CEGUIChild_setWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIChild* self = (Zeta::CEGUIChild*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWindow'",NULL);
#endif
 {
  self->setWindow(window);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_new00
static int tolua_Zeta_Zeta_CEGUIChild_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  bool destroy = ((bool)  tolua_toboolean(tolua_S,3,false));
 {
  Zeta::CEGUIChild* tolua_ret = (Zeta::CEGUIChild*)  new Zeta::CEGUIChild(window,destroy);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::CEGUIChild");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::CEGUIChild */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIChild_new00_local
static int tolua_Zeta_Zeta_CEGUIChild_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIChild",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  bool destroy = ((bool)  tolua_toboolean(tolua_S,3,false));
 {
  Zeta::CEGUIChild* tolua_ret = (Zeta::CEGUIChild*)  new Zeta::CEGUIChild(window,destroy);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::CEGUIChild");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Zeta::Animation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Animation_getName00
static int tolua_Zeta_Zeta_Animation_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Animation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Animation* self = (const Zeta::Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
 {
  const std::string tolua_ret = (const std::string)  self->getName();
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLooping of class  Zeta::Animation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Animation_isLooping00
static int tolua_Zeta_Zeta_Animation_isLooping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Animation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Animation* self = (const Zeta::Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLooping'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isLooping();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLooping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumFrames of class  Zeta::Animation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Animation_getNumFrames00
static int tolua_Zeta_Zeta_Animation_getNumFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Animation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Animation* self = (const Zeta::Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumFrames'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getNumFrames();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPlaying of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_isPlaying00
static int tolua_Zeta_Zeta_AnimationPlayer_isPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AnimationPlayer* self = (const Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPlaying'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isPlaying();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_isVisible00
static int tolua_Zeta_Zeta_AnimationPlayer_isVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AnimationPlayer* self = (const Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_setVisible00
static int tolua_Zeta_Zeta_AnimationPlayer_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'",NULL);
#endif
 {
  self->setVisible(visible);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_hide00
static int tolua_Zeta_Zeta_AnimationPlayer_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
 {
  self->hide();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_show00
static int tolua_Zeta_Zeta_AnimationPlayer_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
 {
  self->show();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_play00
static int tolua_Zeta_Zeta_AnimationPlayer_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'",NULL);
#endif
 {
  self->play();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_stop00
static int tolua_Zeta_Zeta_AnimationPlayer_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'",NULL);
#endif
 {
  self->stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_pause00
static int tolua_Zeta_Zeta_AnimationPlayer_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'",NULL);
#endif
 {
  self->pause();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  Zeta::AnimationPlayer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationPlayer_reset00
static int tolua_Zeta_Zeta_AnimationPlayer_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationPlayer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationPlayer* self = (Zeta::AnimationPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
 {
  self->reset();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationFX of class  Zeta::AnimationEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationEffectsManager_getAnimationFX00
static int tolua_Zeta_Zeta_AnimationEffectsManager_getAnimationFX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::AnimationEffectsManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::AnimationEffectsManager* self = (const Zeta::AnimationEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string animationPack = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationFX'",NULL);
#endif
 {
  const Zeta::Animation& tolua_ret = (const Zeta::Animation&)  self->getAnimationFX(name,animationPack);
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::Animation");
 tolua_pushcppstring(tolua_S,(const char*)name);
 tolua_pushcppstring(tolua_S,(const char*)animationPack);
 }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationFX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimationPack of class  Zeta::AnimationEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack00
static int tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationEffectsManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::AnimationEffectsManager* self = (Zeta::AnimationEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimationPack'",NULL);
#endif
 {
  self->addAnimationPack(path);
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimationPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimationPack of class  Zeta::AnimationEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack01
static int tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::AnimationEffectsManager",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::AnimationEffectsManager* self = (Zeta::AnimationEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimationPack'",NULL);
#endif
 {
  self->addAnimationPack(path,name);
 tolua_pushcppstring(tolua_S,(const char*)path);
 tolua_pushcppstring(tolua_S,(const char*)name);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::AnimationEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_AnimationEffectsManager_getInstance00
static int tolua_Zeta_Zeta_AnimationEffectsManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::AnimationEffectsManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::AnimationEffectsManager& tolua_ret = (Zeta::AnimationEffectsManager&)  Zeta::AnimationEffectsManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AnimationEffectsManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDx of class  Zeta::OffAnimation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OffAnimation_getDx00
static int tolua_Zeta_Zeta_OffAnimation_getDx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::OffAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::OffAnimation* self = (const Zeta::OffAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDx'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getDx();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDx of class  Zeta::OffAnimation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OffAnimation_setDx00
static int tolua_Zeta_Zeta_OffAnimation_setDx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::OffAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::OffAnimation* self = (Zeta::OffAnimation*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDx'",NULL);
#endif
 {
  self->setDx(dx);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDy of class  Zeta::OffAnimation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OffAnimation_getDy00
static int tolua_Zeta_Zeta_OffAnimation_getDy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::OffAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::OffAnimation* self = (const Zeta::OffAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDy'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getDy();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDy of class  Zeta::OffAnimation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OffAnimation_setDy00
static int tolua_Zeta_Zeta_OffAnimation_setDy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::OffAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::OffAnimation* self = (Zeta::OffAnimation*)  tolua_tousertype(tolua_S,1,0);
   float dy = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDy'",NULL);
#endif
 {
  self->setDy(dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsets of class  Zeta::OffAnimation */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OffAnimation_setOffsets00
static int tolua_Zeta_Zeta_OffAnimation_setOffsets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::OffAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::OffAnimation* self = (Zeta::OffAnimation*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsets'",NULL);
#endif
 {
  self->setOffsets(dx,dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLifeformName of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_getLifeformName00
static int tolua_Zeta_Zeta_LifeformClass_getLifeformName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformClass* self = (const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLifeformName'",NULL);
#endif
 {
  const std::string tolua_ret = (const std::string)  self->getLifeformName();
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLifeformName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationClassName of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_getAnimationClassName00
static int tolua_Zeta_Zeta_LifeformClass_getAnimationClassName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformClass* self = (const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationClassName'",NULL);
#endif
 {
  const std::string tolua_ret = (const std::string)  self->getAnimationClassName();
 tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationClassName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLevel of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_getLevel00
static int tolua_Zeta_Zeta_LifeformClass_getLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformClass* self = (const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevel'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTable of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_setTable00
static int tolua_Zeta_Zeta_LifeformClass_setTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTable'",NULL);
#endif
 {
  self->setTable(table);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnClick of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_setOnClick00
static int tolua_Zeta_Zeta_LifeformClass_setOnClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnClick'",NULL);
#endif
 {
  self->setOnClick(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnCollision of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_setOnCollision00
static int tolua_Zeta_Zeta_LifeformClass_setOnCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnCollision'",NULL);
#endif
 {
  self->setOnCollision(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: levelizeStats of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_levelizeStats00
static int tolua_Zeta_Zeta_LifeformClass_levelizeStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  float levelMultiplier = ((float)  tolua_tonumber(tolua_S,2,1.0f));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'levelizeStats'",NULL);
#endif
 {
  self->levelizeStats(levelMultiplier);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'levelizeStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: levelizeStats of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_levelizeStats01
static int tolua_Zeta_Zeta_LifeformClass_levelizeStats01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  float multiplier = ((float)  tolua_tonumber(tolua_S,2,0));
  int lowerBound = ((int)  tolua_tonumber(tolua_S,3,0));
  int upperBound = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'levelizeStats'",NULL);
#endif
 {
  self->levelizeStats(multiplier,lowerBound,upperBound);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_LifeformClass_levelizeStats00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAbility of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_addAbility00
static int tolua_Zeta_Zeta_LifeformClass_addAbility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::AbilityClass* abClass = ((const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAbility'",NULL);
#endif
 {
  self->addAbility(*abClass,level);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAbility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_new00
static int tolua_Zeta_Zeta_LifeformClass_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::LifeformClass* tolua_ret = (Zeta::LifeformClass*)  new Zeta::LifeformClass();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LifeformClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_new00_local
static int tolua_Zeta_Zeta_LifeformClass_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::LifeformClass* tolua_ret = (Zeta::LifeformClass*)  new Zeta::LifeformClass();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LifeformClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_new01
static int tolua_Zeta_Zeta_LifeformClass_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
 {
  Zeta::LifeformClass* tolua_ret = (Zeta::LifeformClass*)  new Zeta::LifeformClass(path);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LifeformClass");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_LifeformClass_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_new01_local
static int tolua_Zeta_Zeta_LifeformClass_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
 {
  Zeta::LifeformClass* tolua_ret = (Zeta::LifeformClass*)  new Zeta::LifeformClass(path);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LifeformClass");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_LifeformClass_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::LifeformClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClass_delete00
static int tolua_Zeta_Zeta_LifeformClass_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClass* self = (Zeta::LifeformClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  Zeta::LifeformClassContainer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClassContainer_get00
static int tolua_Zeta_Zeta_LifeformClassContainer_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClassContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClassContainer* self = (Zeta::LifeformClassContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  Zeta::LifeformClass& tolua_ret = (Zeta::LifeformClass&)  self->get();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::LifeformClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LifeformClassContainer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClassContainer_new00
static int tolua_Zeta_Zeta_LifeformClassContainer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClassContainer",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
 {
  Zeta::LifeformClassContainer* tolua_ret = (Zeta::LifeformClassContainer*)  new Zeta::LifeformClassContainer(path);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LifeformClassContainer");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LifeformClassContainer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClassContainer_new00_local
static int tolua_Zeta_Zeta_LifeformClassContainer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformClassContainer",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
 {
  Zeta::LifeformClassContainer* tolua_ret = (Zeta::LifeformClassContainer*)  new Zeta::LifeformClassContainer(path);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LifeformClassContainer");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::LifeformClassContainer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformClassContainer_delete00
static int tolua_Zeta_Zeta_LifeformClassContainer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformClassContainer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformClassContainer* self = (Zeta::LifeformClassContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffesets of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setOffesets00
static int tolua_Zeta_Zeta_CEGUIObject_setOffesets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
   float offX = ((  float)  tolua_tonumber(tolua_S,2,0));
   float offY = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffesets'",NULL);
#endif
 {
  self->setOffesets(offX,offY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffesets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDestroy of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_isDestroy00
static int tolua_Zeta_Zeta_CEGUIObject_isDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIObject* self = (const Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDestroy'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isDestroy();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDestroy of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setDestroy00
static int tolua_Zeta_Zeta_CEGUIObject_setDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
  bool destroy = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDestroy'",NULL);
#endif
 {
  self->setDestroy(destroy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetX of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_getOffsetX00
static int tolua_Zeta_Zeta_CEGUIObject_getOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIObject* self = (const Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetX'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getOffsetX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetX of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setOffsetX00
static int tolua_Zeta_Zeta_CEGUIObject_setOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
   float offX = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetX'",NULL);
#endif
 {
  self->setOffsetX(offX);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffsetY of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_getOffsetY00
static int tolua_Zeta_Zeta_CEGUIObject_getOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIObject* self = (const Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffsetY'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getOffsetY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffsetY of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setOffsetY00
static int tolua_Zeta_Zeta_CEGUIObject_setOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
   float offY = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffsetY'",NULL);
#endif
 {
  self->setOffsetY(offY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindow of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_getWindow00
static int tolua_Zeta_Zeta_CEGUIObject_getWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::CEGUIObject* self = (const Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindow'",NULL);
#endif
 {
  CEGUI::Window* tolua_ret = (CEGUI::Window*)  self->getWindow();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEGUI::Window");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWindow of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setWindow00
static int tolua_Zeta_Zeta_CEGUIObject_setWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWindow'",NULL);
#endif
 {
  self->setWindow(window);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLuaTable of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setLuaTable00
static int tolua_Zeta_Zeta_CEGUIObject_setLuaTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLuaTable'",NULL);
#endif
 {
  self->setLuaTable(table);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLuaTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnClick of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setOnClick00
static int tolua_Zeta_Zeta_CEGUIObject_setOnClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnClick'",NULL);
#endif
 {
  self->setOnClick(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationHandler of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_getAnimationHandler00
static int tolua_Zeta_Zeta_CEGUIObject_getAnimationHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationHandler'",NULL);
#endif
 {
  Zeta::AnimationHandler& tolua_ret = (Zeta::AnimationHandler&)  self->getAnimationHandler();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::AnimationHandler");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_setPosition00
static int tolua_Zeta_Zeta_CEGUIObject_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offsetPosition of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_offsetPosition00
static int tolua_Zeta_Zeta_CEGUIObject_offsetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
   float dx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float dy = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offsetPosition'",NULL);
#endif
 {
  self->offsetPosition(dx,dy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offsetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_new00
static int tolua_Zeta_Zeta_CEGUIObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::CEGUIObject* tolua_ret = (Zeta::CEGUIObject*)  new Zeta::CEGUIObject(window,x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::CEGUIObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_new00_local
static int tolua_Zeta_Zeta_CEGUIObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
 {
  Zeta::CEGUIObject* tolua_ret = (Zeta::CEGUIObject*)  new Zeta::CEGUIObject(window,x,y);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::CEGUIObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_new01
static int tolua_Zeta_Zeta_CEGUIObject_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
  const std::string animationClass = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
 {
  Zeta::CEGUIObject* tolua_ret = (Zeta::CEGUIObject*)  new Zeta::CEGUIObject(window,x,y,animationClass);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::CEGUIObject");
 tolua_pushcppstring(tolua_S,(const char*)animationClass);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_CEGUIObject_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_new01_local
static int tolua_Zeta_Zeta_CEGUIObject_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CEGUI::Window* window = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
  const std::string animationClass = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
 {
  Zeta::CEGUIObject* tolua_ret = (Zeta::CEGUIObject*)  new Zeta::CEGUIObject(window,x,y,animationClass);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::CEGUIObject");
 tolua_pushcppstring(tolua_S,(const char*)animationClass);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_CEGUIObject_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::CEGUIObject */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_CEGUIObject_delete00
static int tolua_Zeta_Zeta_CEGUIObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::CEGUIObject",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::CEGUIObject* self = (Zeta::CEGUIObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deactivate of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_deactivate00
static int tolua_Zeta_Zeta_LuaListener_deactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LuaListener* self = (Zeta::LuaListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deactivate'",NULL);
#endif
 {
  self->deactivate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: activate of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_activate00
static int tolua_Zeta_Zeta_LuaListener_activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LuaListener* self = (Zeta::LuaListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'activate'",NULL);
#endif
 {
  self->activate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_new00
static int tolua_Zeta_Zeta_LuaListener_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
  Zeta::WorldEvent::Type type = ((Zeta::WorldEvent::Type)  tolua_tonumber(tolua_S,3,0));
 {
  Zeta::LuaListener* tolua_ret = (Zeta::LuaListener*)  new Zeta::LuaListener(func,type);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LuaListener");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_new00_local
static int tolua_Zeta_Zeta_LuaListener_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
  Zeta::WorldEvent::Type type = ((Zeta::WorldEvent::Type)  tolua_tonumber(tolua_S,3,0));
 {
  Zeta::LuaListener* tolua_ret = (Zeta::LuaListener*)  new Zeta::LuaListener(func,type);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LuaListener");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_new01
static int tolua_Zeta_Zeta_LuaListener_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string channel = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
 {
  Zeta::LuaListener* tolua_ret = (Zeta::LuaListener*)  new Zeta::LuaListener(channel,func);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LuaListener");
 tolua_pushcppstring(tolua_S,(const char*)channel);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_LuaListener_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_new01_local
static int tolua_Zeta_Zeta_LuaListener_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const std::string channel = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
 {
  Zeta::LuaListener* tolua_ret = (Zeta::LuaListener*)  new Zeta::LuaListener(channel,func);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LuaListener");
 tolua_pushcppstring(tolua_S,(const char*)channel);
 }
 }
 return 2;
tolua_lerror:
 return tolua_Zeta_Zeta_LuaListener_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::LuaListener */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LuaListener_delete00
static int tolua_Zeta_Zeta_LuaListener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LuaListener",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LuaListener* self = (Zeta::LuaListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpTime of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_getUpTime00
static int tolua_Zeta_Zeta_EffectClass_getUpTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::EffectClass* self = (const Zeta::EffectClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUpTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getUpTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUpTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTickEvery of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_getTickEvery00
static int tolua_Zeta_Zeta_EffectClass_getTickEvery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::EffectClass* self = (const Zeta::EffectClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTickEvery'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getTickEvery();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTickEvery'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNewEffect of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_getNewEffect00
static int tolua_Zeta_Zeta_EffectClass_getNewEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Zeta::Lifeform",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::EffectClass* self = (const Zeta::EffectClass*)  tolua_tousertype(tolua_S,1,0);
  Zeta::Lifeform* target = ((Zeta::Lifeform*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNewEffect'",NULL);
#endif
 {
  Zeta::Effect* tolua_ret = (Zeta::Effect*)  self->getNewEffect(target,level);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Effect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNewEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_new00
static int tolua_Zeta_Zeta_EffectClass_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::EffectClass* tolua_ret = (Zeta::EffectClass*)  new Zeta::EffectClass();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::EffectClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_new00_local
static int tolua_Zeta_Zeta_EffectClass_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::EffectClass* tolua_ret = (Zeta::EffectClass*)  new Zeta::EffectClass();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::EffectClass");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_new01
static int tolua_Zeta_Zeta_EffectClass_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
 {
  Zeta::EffectClass* tolua_ret = (Zeta::EffectClass*)  new Zeta::EffectClass(table);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::EffectClass");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_EffectClass_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_new01_local
static int tolua_Zeta_Zeta_EffectClass_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  lua_Object table = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
 {
  Zeta::EffectClass* tolua_ret = (Zeta::EffectClass*)  new Zeta::EffectClass(table);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::EffectClass");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Zeta_Zeta_EffectClass_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::EffectClass */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_EffectClass_delete00
static int tolua_Zeta_Zeta_EffectClass_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::EffectClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::EffectClass* self = (Zeta::EffectClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSource of class  Zeta::Effect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Effect_getSource00
static int tolua_Zeta_Zeta_Effect_getSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Effect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Effect* self = (Zeta::Effect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSource'",NULL);
#endif
 {
  Zeta::ActiveAbility* tolua_ret = (Zeta::ActiveAbility*)  self->getSource();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::ActiveAbility");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFinished of class  Zeta::Effect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Effect_isFinished00
static int tolua_Zeta_Zeta_Effect_isFinished00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Effect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Effect* self = (const Zeta::Effect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFinished'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isFinished();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFinished'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: end of class  Zeta::Effect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Effect_end00
static int tolua_Zeta_Zeta_Effect_end00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Effect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Effect* self = (Zeta::Effect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'end'",NULL);
#endif
 {
  self->end();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'end'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxTime of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_getMaxTime00
static int tolua_Zeta_Zeta_Timer_getMaxTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Timer* self = (const Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getMaxTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaxTime of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_setMaxTime00
static int tolua_Zeta_Zeta_Timer_setMaxTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
   float maxTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxTime'",NULL);
#endif
 {
  self->setMaxTime(maxTime);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRemainingTime of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_getRemainingTime00
static int tolua_Zeta_Zeta_Timer_getRemainingTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Timer* self = (const Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRemainingTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getRemainingTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRemainingTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRemainingTime of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_setRemainingTime00
static int tolua_Zeta_Zeta_Timer_setRemainingTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
   float remainingTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRemainingTime'",NULL);
#endif
 {
  self->setRemainingTime(remainingTime);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRemainingTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOver of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_isOver00
static int tolua_Zeta_Zeta_Timer_isOver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Timer* self = (const Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOver'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isOver();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunning of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_isRunning00
static int tolua_Zeta_Zeta_Timer_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::Timer* self = (const Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isRunning();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_start00
static int tolua_Zeta_Zeta_Timer_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'",NULL);
#endif
 {
  self->start();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_pause00
static int tolua_Zeta_Zeta_Timer_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'",NULL);
#endif
 {
  self->pause();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_reset00
static int tolua_Zeta_Zeta_Timer_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
 {
  self->reset();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallback of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_setCallback00
static int tolua_Zeta_Zeta_Timer_setCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
  lua_Object func = ((lua_Object)  tolua_tovalue(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallback'",NULL);
#endif
 {
  self->setCallback(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_new00
static int tolua_Zeta_Zeta_Timer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
   float maxTime = ((  float)  tolua_tonumber(tolua_S,2,0));
 {
  Zeta::Timer* tolua_ret = (Zeta::Timer*)  new Zeta::Timer(maxTime);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::Timer");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_new00_local
static int tolua_Zeta_Zeta_Timer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
   float maxTime = ((  float)  tolua_tonumber(tolua_S,2,0));
 {
  Zeta::Timer* tolua_ret = (Zeta::Timer*)  new Zeta::Timer(maxTime);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::Timer");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::Timer */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_Timer_delete00
static int tolua_Zeta_Zeta_Timer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::Timer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::Timer* self = (Zeta::Timer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAbilityClass of class  Zeta::ResourceCache */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ResourceCache_getAbilityClass00
static int tolua_Zeta_Zeta_ResourceCache_getAbilityClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ResourceCache",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ResourceCache* self = (Zeta::ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAbilityClass'",NULL);
#endif
 {
  const Zeta::AbilityClass& tolua_ret = (const Zeta::AbilityClass&)  self->getAbilityClass(path);
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::AbilityClass");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAbilityClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLifeformClass of class  Zeta::ResourceCache */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ResourceCache_getLifeformClass00
static int tolua_Zeta_Zeta_ResourceCache_getLifeformClass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ResourceCache",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ResourceCache* self = (Zeta::ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLifeformClass'",NULL);
#endif
 {
  const Zeta::LifeformClass& tolua_ret = (const Zeta::LifeformClass&)  self->getLifeformClass(path);
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Zeta::LifeformClass");
 tolua_pushcppstring(tolua_S,(const char*)path);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLifeformClass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: releaseResource of class  Zeta::ResourceCache */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ResourceCache_releaseResource00
static int tolua_Zeta_Zeta_ResourceCache_releaseResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ResourceCache",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::AbilityClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::ResourceCache* self = (Zeta::ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::AbilityClass* value = ((const Zeta::AbilityClass*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'releaseResource'",NULL);
#endif
 {
  self->releaseResource(*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: releaseResource of class  Zeta::ResourceCache */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ResourceCache_releaseResource01
static int tolua_Zeta_Zeta_ResourceCache_releaseResource01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::ResourceCache",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Zeta::LifeformClass",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Zeta::ResourceCache* self = (Zeta::ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const Zeta::LifeformClass* value = ((const Zeta::LifeformClass*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'releaseResource'",NULL);
#endif
 {
  self->releaseResource(*value);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Zeta_Zeta_ResourceCache_releaseResource00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Zeta::ResourceCache */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_ResourceCache_getInstance00
static int tolua_Zeta_Zeta_ResourceCache_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::ResourceCache& tolua_ret = (Zeta::ResourceCache&)  Zeta::ResourceCache::getInstance();
 tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Zeta::ResourceCache");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_set00
static int tolua_Zeta_Zeta_LifeformState_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformState* self = (Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
  int combinedState = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(combinedState);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCombinedState of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_getCombinedState00
static int tolua_Zeta_Zeta_LifeformState_getCombinedState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformState* self = (const Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCombinedState'",NULL);
#endif
 {
   int tolua_ret = (  int)  self->getCombinedState();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCombinedState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAction of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_setAction00
static int tolua_Zeta_Zeta_LifeformState_setAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformState* self = (Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
  Zeta::LifeformState::Action action = ((Zeta::LifeformState::Action)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAction'",NULL);
#endif
 {
  self->setAction(action);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_setDirection00
static int tolua_Zeta_Zeta_LifeformState_setDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformState* self = (Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
  Zeta::LifeformState::Direction direction = ((Zeta::LifeformState::Direction)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
 {
  self->setDirection(direction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAction of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_getAction00
static int tolua_Zeta_Zeta_LifeformState_getAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformState* self = (const Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAction'",NULL);
#endif
 {
  Zeta::LifeformState::Action tolua_ret = (Zeta::LifeformState::Action)  self->getAction();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDirection of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_getDirection00
static int tolua_Zeta_Zeta_LifeformState_getDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::LifeformState* self = (const Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDirection'",NULL);
#endif
 {
  Zeta::LifeformState::Direction tolua_ret = (Zeta::LifeformState::Direction)  self->getDirection();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_new00
static int tolua_Zeta_Zeta_LifeformState_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::LifeformState* tolua_ret = (Zeta::LifeformState*)  new Zeta::LifeformState();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Zeta::LifeformState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_new00_local
static int tolua_Zeta_Zeta_LifeformState_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Zeta::LifeformState* tolua_ret = (Zeta::LifeformState*)  new Zeta::LifeformState();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Zeta::LifeformState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Zeta::LifeformState */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_LifeformState_delete00
static int tolua_Zeta_Zeta_LifeformState_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::LifeformState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::LifeformState* self = (Zeta::LifeformState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRemainingTime of class  Zeta::DurableEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_DurableEffect_getRemainingTime00
static int tolua_Zeta_Zeta_DurableEffect_getRemainingTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::DurableEffect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::DurableEffect* self = (const Zeta::DurableEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRemainingTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getRemainingTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRemainingTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpTime of class  Zeta::DurableEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_DurableEffect_getUpTime00
static int tolua_Zeta_Zeta_DurableEffect_getUpTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::DurableEffect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::DurableEffect* self = (const Zeta::DurableEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUpTime'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getUpTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUpTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUpTime of class  Zeta::DurableEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_DurableEffect_setUpTime00
static int tolua_Zeta_Zeta_DurableEffect_setUpTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::DurableEffect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::DurableEffect* self = (Zeta::DurableEffect*)  tolua_tousertype(tolua_S,1,0);
   float upTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUpTime'",NULL);
#endif
 {
  self->setUpTime(upTime);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUpTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  Zeta::DurableEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_DurableEffect_reset00
static int tolua_Zeta_Zeta_DurableEffect_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::DurableEffect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::DurableEffect* self = (Zeta::DurableEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
 {
  self->reset();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTickEvery of class  Zeta::OverTimeEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OverTimeEffect_getTickEvery00
static int tolua_Zeta_Zeta_OverTimeEffect_getTickEvery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Zeta::OverTimeEffect",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Zeta::OverTimeEffect* self = (const Zeta::OverTimeEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTickEvery'",NULL);
#endif
 {
   float tolua_ret = (  float)  self->getTickEvery();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTickEvery'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTickEvery of class  Zeta::OverTimeEffect */
#ifndef TOLUA_DISABLE_tolua_Zeta_Zeta_OverTimeEffect_setTickEvery00
static int tolua_Zeta_Zeta_OverTimeEffect_setTickEvery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Zeta::OverTimeEffect",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Zeta::OverTimeEffect* self = (Zeta::OverTimeEffect*)  tolua_tousertype(tolua_S,1,0);
   float tickEvery = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTickEvery'",NULL);
#endif
 {
  self->setTickEvery(tickEvery);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTickEvery'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
int tolua_Zeta_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"Zeta",0);
 tolua_beginmodule(tolua_S,"Zeta");
  tolua_cclass(tolua_S,"Ability","Zeta::Ability","",NULL);
  tolua_beginmodule(tolua_S,"Ability");
   tolua_cclass(tolua_S,"Result","Zeta::Ability::Result","",NULL);
   tolua_beginmodule(tolua_S,"Result");
    tolua_constant(tolua_S,"Success",(lua_Number)Zeta::Ability::Result::Success);
    tolua_constant(tolua_S,"onCooldown",(lua_Number)Zeta::Ability::Result::onCooldown);
    tolua_constant(tolua_S,"NoTarget",(lua_Number)Zeta::Ability::Result::NoTarget);
    tolua_constant(tolua_S,"NoMana",(lua_Number)Zeta::Ability::Result::NoMana);
    tolua_constant(tolua_S,"OutOfRange",(lua_Number)Zeta::Ability::Result::OutOfRange);
    tolua_constant(tolua_S,"TargetIsDead",(lua_Number)Zeta::Ability::Result::TargetIsDead);
    tolua_constant(tolua_S,"TargetIsNotHostile",(lua_Number)Zeta::Ability::Result::TargetIsNotHostile);
    tolua_constant(tolua_S,"InvalidAbility",(lua_Number)Zeta::Ability::Result::InvalidAbility);
    tolua_constant(tolua_S,"Other",(lua_Number)Zeta::Ability::Result::Other);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"getLevel",tolua_Zeta_Zeta_Ability_getLevel00);
   tolua_function(tolua_S,"setLevel",tolua_Zeta_Zeta_Ability_setLevel00);
   tolua_function(tolua_S,"getOwner",tolua_Zeta_Zeta_Ability_getOwner00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"AbilityClass","Zeta::AbilityClass","",tolua_collect_Zeta__AbilityClass);
  #else
  tolua_cclass(tolua_S,"AbilityClass","Zeta::AbilityClass","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"AbilityClass");
   tolua_cclass(tolua_S,"Type","Zeta::AbilityClass::Type","",NULL);
   tolua_beginmodule(tolua_S,"Type");
    tolua_constant(tolua_S,"Active",(lua_Number)Zeta::AbilityClass::Type::Active);
    tolua_constant(tolua_S,"Passive",(lua_Number)Zeta::AbilityClass::Type::Passive);
    tolua_constant(tolua_S,"Regeneration",(lua_Number)Zeta::AbilityClass::Type::Regeneration);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"getLevels",tolua_Zeta_Zeta_AbilityClass_getLevels00);
   tolua_function(tolua_S,"getAbilityName",tolua_Zeta_Zeta_AbilityClass_getAbilityName00);
   tolua_function(tolua_S,"isPassive",tolua_Zeta_Zeta_AbilityClass_isPassive00);
   tolua_function(tolua_S,"getType",tolua_Zeta_Zeta_AbilityClass_getType00);
   tolua_function(tolua_S,"getLuaTable",tolua_Zeta_Zeta_AbilityClass_getLuaTable00);
   tolua_function(tolua_S,"onApply",tolua_Zeta_Zeta_AbilityClass_onApply00);
   tolua_function(tolua_S,"onRemove",tolua_Zeta_Zeta_AbilityClass_onRemove00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_AbilityClass_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_AbilityClass_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_AbilityClass_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_AbilityClass_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AnimationHandler","Zeta::AnimationHandler","",NULL);
  tolua_beginmodule(tolua_S,"AnimationHandler");
   tolua_cclass(tolua_S,"QueuePlace","Zeta::AnimationHandler::QueuePlace","",NULL);
   tolua_beginmodule(tolua_S,"QueuePlace");
    tolua_constant(tolua_S,"Front",(lua_Number)Zeta::AnimationHandler::QueuePlace::Front);
    tolua_constant(tolua_S,"Back",(lua_Number)Zeta::AnimationHandler::QueuePlace::Back);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"setAnimation",tolua_Zeta_Zeta_AnimationHandler_setAnimation00);
   tolua_function(tolua_S,"setAnimationClass",tolua_Zeta_Zeta_AnimationHandler_setAnimationClass00);
   tolua_function(tolua_S,"getMainAnimationPlayer",tolua_Zeta_Zeta_AnimationHandler_getMainAnimationPlayer00);
   tolua_function(tolua_S,"addOffAnimation",tolua_Zeta_Zeta_AnimationHandler_addOffAnimation00);
   tolua_function(tolua_S,"getOffAnimation",tolua_Zeta_Zeta_AnimationHandler_getOffAnimation00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ChildObject","Zeta::ChildObject","Zeta::Object",NULL);
  tolua_beginmodule(tolua_S,"ChildObject");
   tolua_function(tolua_S,"getAnimationHandler",tolua_Zeta_Zeta_ChildObject_getAnimationHandler00);
   tolua_function(tolua_S,"getParent",tolua_Zeta_Zeta_ChildObject_getParent00);
   tolua_function(tolua_S,"hasParent",tolua_Zeta_Zeta_ChildObject_hasParent00);
   tolua_function(tolua_S,"setParent",tolua_Zeta_Zeta_ChildObject_setParent00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ConsoleManager","Zeta::ConsoleManager","",NULL);
  tolua_beginmodule(tolua_S,"ConsoleManager");
   tolua_function(tolua_S,"excecuteLine",tolua_Zeta_Zeta_ConsoleManager_excecuteLine00);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_ConsoleManager_getInstance00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"DirectionalProjectile","Zeta::DirectionalProjectile","Zeta::Projectile",NULL);
  tolua_beginmodule(tolua_S,"DirectionalProjectile");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Object","Zeta::Object","",tolua_collect_Zeta__Object);
  #else
  tolua_cclass(tolua_S,"Object","Zeta::Object","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Object");
   tolua_function(tolua_S,"getBounding",tolua_Zeta_Zeta_Object_getBounding00);
   tolua_function(tolua_S,"getBounding",tolua_Zeta_Zeta_Object_getBounding01);
   tolua_function(tolua_S,"setBounding",tolua_Zeta_Zeta_Object_setBounding00);
   tolua_function(tolua_S,"getTargetArea",tolua_Zeta_Zeta_Object_getTargetArea00);
   tolua_function(tolua_S,"getTargetArea",tolua_Zeta_Zeta_Object_getTargetArea01);
   tolua_function(tolua_S,"getPosition",tolua_Zeta_Zeta_Object_getPosition00);
   tolua_function(tolua_S,"setPosition",tolua_Zeta_Zeta_Object_setPosition00);
   tolua_function(tolua_S,"setPosition",tolua_Zeta_Zeta_Object_setPosition01);
   tolua_function(tolua_S,"getName",tolua_Zeta_Zeta_Object_getName00);
   tolua_function(tolua_S,"setName",tolua_Zeta_Zeta_Object_setName00);
   tolua_function(tolua_S,"getDistance",tolua_Zeta_Zeta_Object_getDistance00);
   tolua_function(tolua_S,"addChildObject",tolua_Zeta_Zeta_Object_addChildObject00);
   tolua_function(tolua_S,"addChildObject",tolua_Zeta_Zeta_Object_addChildObject01);
   tolua_function(tolua_S,"removeChildObject",tolua_Zeta_Zeta_Object_removeChildObject00);
   tolua_function(tolua_S,"getRenderPosition",tolua_Zeta_Zeta_Object_getRenderPosition00);
   tolua_function(tolua_S,"isCollideAble",tolua_Zeta_Zeta_Object_isCollideAble00);
   tolua_function(tolua_S,"setCoolideAble",tolua_Zeta_Zeta_Object_setCoolideAble00);
   tolua_function(tolua_S,"isTriggeringCollisionEvents",tolua_Zeta_Zeta_Object_isTriggeringCollisionEvents00);
   tolua_function(tolua_S,"setTriggeringCollisionEvents",tolua_Zeta_Zeta_Object_setTriggeringCollisionEvents00);
   tolua_function(tolua_S,"isVisible",tolua_Zeta_Zeta_Object_isVisible00);
   tolua_function(tolua_S,"setVisible",tolua_Zeta_Zeta_Object_setVisible00);
   tolua_function(tolua_S,"show",tolua_Zeta_Zeta_Object_show00);
   tolua_function(tolua_S,"hide",tolua_Zeta_Zeta_Object_hide00);
   tolua_function(tolua_S,"getChildObject",tolua_Zeta_Zeta_Object_getChildObject00);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Object_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Lifeform","Zeta::Lifeform","Zeta::Object",tolua_collect_Zeta__Lifeform);
  #else
  tolua_cclass(tolua_S,"Lifeform","Zeta::Lifeform","Zeta::Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Lifeform");
   tolua_function(tolua_S,"moveToPosition",tolua_Zeta_Zeta_Lifeform_moveToPosition00);
   tolua_function(tolua_S,"moveToPosition",tolua_Zeta_Zeta_Lifeform_moveToPosition01);
   tolua_function(tolua_S,"getState",tolua_Zeta_Zeta_Lifeform_getState00);
   tolua_function(tolua_S,"stopMoving",tolua_Zeta_Zeta_Lifeform_stopMoving00);
   tolua_function(tolua_S,"setClass",tolua_Zeta_Zeta_Lifeform_setClass00);
   tolua_function(tolua_S,"setAnimationClass",tolua_Zeta_Zeta_Lifeform_setAnimationClass00);
   tolua_function(tolua_S,"setActionAnimation",tolua_Zeta_Zeta_Lifeform_setActionAnimation00);
   tolua_function(tolua_S,"addOffAnimation",tolua_Zeta_Zeta_Lifeform_addOffAnimation00);
   tolua_function(tolua_S,"getAttributeValue",tolua_Zeta_Zeta_Lifeform_getAttributeValue00);
   tolua_function(tolua_S,"setAttributeBaseValue",tolua_Zeta_Zeta_Lifeform_setAttributeBaseValue00);
   tolua_function(tolua_S,"getAttributesLuaTable",tolua_Zeta_Zeta_Lifeform_getAttributesLuaTable00);
   tolua_function(tolua_S,"addAttributeModifier",tolua_Zeta_Zeta_Lifeform_addAttributeModifier00);
   tolua_function(tolua_S,"getAnimationHandler",tolua_Zeta_Zeta_Lifeform_getAnimationHandler00);
   tolua_function(tolua_S,"removeAttributeModifier",tolua_Zeta_Zeta_Lifeform_removeAttributeModifier00);
   tolua_function(tolua_S,"offsetMana",tolua_Zeta_Zeta_Lifeform_offsetMana00);
   tolua_function(tolua_S,"offsetHP",tolua_Zeta_Zeta_Lifeform_offsetHP00);
   tolua_function(tolua_S,"setHP",tolua_Zeta_Zeta_Lifeform_setHP00);
   tolua_function(tolua_S,"setMana",tolua_Zeta_Zeta_Lifeform_setMana00);
   tolua_function(tolua_S,"isHostileWith",tolua_Zeta_Zeta_Lifeform_isHostileWith00);
   tolua_function(tolua_S,"addEffect",tolua_Zeta_Zeta_Lifeform_addEffect00);
   tolua_function(tolua_S,"canReceiveEffect",tolua_Zeta_Zeta_Lifeform_canReceiveEffect00);
   tolua_function(tolua_S,"isInCombat",tolua_Zeta_Zeta_Lifeform_isInCombat00);
   tolua_function(tolua_S,"setInCombat",tolua_Zeta_Zeta_Lifeform_setInCombat00);
   tolua_function(tolua_S,"resetState",tolua_Zeta_Zeta_Lifeform_resetState00);
   tolua_function(tolua_S,"isDirty",tolua_Zeta_Zeta_Lifeform_isDirty00);
   tolua_function(tolua_S,"isAlive",tolua_Zeta_Zeta_Lifeform_isAlive00);
   tolua_function(tolua_S,"getLevel",tolua_Zeta_Zeta_Lifeform_getLevel00);
   tolua_function(tolua_S,"hasTarget",tolua_Zeta_Zeta_Lifeform_hasTarget00);
   tolua_function(tolua_S,"getLuaTable",tolua_Zeta_Zeta_Lifeform_getLuaTable00);
   tolua_function(tolua_S,"setLuaTable",tolua_Zeta_Zeta_Lifeform_setLuaTable00);
   tolua_function(tolua_S,"addAbility",tolua_Zeta_Zeta_Lifeform_addAbility00);
   tolua_function(tolua_S,"setTarget",tolua_Zeta_Zeta_Lifeform_setTarget00);
   tolua_function(tolua_S,"getActiveAbility",tolua_Zeta_Zeta_Lifeform_getActiveAbility00);
   tolua_function(tolua_S,"getPassiveAbility",tolua_Zeta_Zeta_Lifeform_getPassiveAbility00);
   tolua_function(tolua_S,"getRegeneration",tolua_Zeta_Zeta_Lifeform_getRegeneration00);
   tolua_function(tolua_S,"getAbility",tolua_Zeta_Zeta_Lifeform_getAbility00);
   tolua_function(tolua_S,"getTarget",tolua_Zeta_Zeta_Lifeform_getTarget00);
   tolua_function(tolua_S,"isInMeleeRange",tolua_Zeta_Zeta_Lifeform_isInMeleeRange00);
   tolua_function(tolua_S,"teleportToCordinates",tolua_Zeta_Zeta_Lifeform_teleportToCordinates00);
   tolua_function(tolua_S,"die",tolua_Zeta_Zeta_Lifeform_die00);
   tolua_function(tolua_S,"face",tolua_Zeta_Zeta_Lifeform_face00);
   tolua_function(tolua_S,"face",tolua_Zeta_Zeta_Lifeform_face01);
   tolua_function(tolua_S,"face",tolua_Zeta_Zeta_Lifeform_face02);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Lifeform_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Lifeform_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Lifeform_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Lifeform_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Lifeform_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Lifeform_new01_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Lifeform_new02);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Lifeform_new02_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Lifeform_new02_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Lifeform_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Enemy","Zeta::Enemy","Zeta::Lifeform",tolua_collect_Zeta__Enemy);
  #else
  tolua_cclass(tolua_S,"Enemy","Zeta::Enemy","Zeta::Lifeform",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Enemy");
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Enemy_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Enemy_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Enemy_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Enemy_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Enemy_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Enemy_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Enemy_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Logger","Zeta::Logger","",NULL);
  tolua_beginmodule(tolua_S,"Logger");
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_Logger_getInstance00);
   tolua_function(tolua_S,"write",tolua_Zeta_Zeta_Logger_write00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MainLoop","Zeta::MainLoop","",NULL);
  tolua_beginmodule(tolua_S,"MainLoop");
   tolua_function(tolua_S,"getCurrentFPS",tolua_Zeta_Zeta_MainLoop_getCurrentFPS00);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_MainLoop_getInstance00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Map","Zeta::Map","",NULL);
  tolua_beginmodule(tolua_S,"Map");
   tolua_function(tolua_S,"addObject",tolua_Zeta_Zeta_Map_addObject00);
   tolua_function(tolua_S,"insertObject",tolua_Zeta_Zeta_Map_insertObject00);
   tolua_function(tolua_S,"removeObject",tolua_Zeta_Zeta_Map_removeObject00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Modifier","Zeta::Modifier","",NULL);
  tolua_beginmodule(tolua_S,"Modifier");
   tolua_cclass(tolua_S,"Type","Zeta::Modifier::Type","",NULL);
   tolua_beginmodule(tolua_S,"Type");
    tolua_constant(tolua_S,"Flat",(lua_Number)Zeta::Modifier::Type::Flat);
    tolua_constant(tolua_S,"Scalar",(lua_Number)Zeta::Modifier::Type::Scalar);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Npc","Zeta::Npc","Zeta::Lifeform",tolua_collect_Zeta__Npc);
  #else
  tolua_cclass(tolua_S,"Npc","Zeta::Npc","Zeta::Lifeform",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Npc");
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Npc_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Npc_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Npc_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Npc_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"PassiveAbility","Zeta::PassiveAbility","Zeta::Ability",NULL);
  tolua_beginmodule(tolua_S,"PassiveAbility");
   tolua_function(tolua_S,"getClass",tolua_Zeta_Zeta_PassiveAbility_getClass00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Player","Zeta::Player","Zeta::Lifeform",NULL);
  tolua_beginmodule(tolua_S,"Player");
   tolua_function(tolua_S,"setView",tolua_Zeta_Zeta_Player_setView00);
   tolua_function(tolua_S,"moveToWorldPosition",tolua_Zeta_Zeta_Player_moveToWorldPosition00);
   tolua_function(tolua_S,"targetLifeformPosition",tolua_Zeta_Zeta_Player_targetLifeformPosition00);
   tolua_function(tolua_S,"setLevelUpCallback",tolua_Zeta_Zeta_Player_setLevelUpCallback00);
   tolua_function(tolua_S,"invokeAbility",tolua_Zeta_Zeta_Player_invokeAbility00);
   tolua_function(tolua_S,"setTargetIndicator",tolua_Zeta_Zeta_Player_setTargetIndicator00);
   tolua_function(tolua_S,"getXp",tolua_Zeta_Zeta_Player_getXp00);
   tolua_function(tolua_S,"setXp",tolua_Zeta_Zeta_Player_setXp00);
   tolua_function(tolua_S,"offsetXp",tolua_Zeta_Zeta_Player_offsetXp00);
   tolua_function(tolua_S,"setXpToNextLevel",tolua_Zeta_Zeta_Player_setXpToNextLevel00);
   tolua_function(tolua_S,"getXpToNextLevel",tolua_Zeta_Zeta_Player_getXpToNextLevel00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Projectile","Zeta::Projectile","Zeta::Object",NULL);
  tolua_beginmodule(tolua_S,"Projectile");
   tolua_function(tolua_S,"clearCollidedObjects",tolua_Zeta_Zeta_Projectile_clearCollidedObjects00);
   tolua_function(tolua_S,"show",tolua_Zeta_Zeta_Projectile_show00);
   tolua_function(tolua_S,"hide",tolua_Zeta_Zeta_Projectile_hide00);
   tolua_function(tolua_S,"destroy",tolua_Zeta_Zeta_Projectile_destroy00);
   tolua_function(tolua_S,"setTargetLocation",tolua_Zeta_Zeta_Projectile_setTargetLocation00);
   tolua_function(tolua_S,"getParentAbility",tolua_Zeta_Zeta_Projectile_getParentAbility00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Rectangle","Zeta::Rectangle","",tolua_collect_Zeta__Rectangle);
  #else
  tolua_cclass(tolua_S,"Rectangle","Zeta::Rectangle","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Rectangle");
   tolua_function(tolua_S,"getX",tolua_Zeta_Zeta_Rectangle_getX00);
   tolua_function(tolua_S,"getY",tolua_Zeta_Zeta_Rectangle_getY00);
   tolua_function(tolua_S,"setPosition",tolua_Zeta_Zeta_Rectangle_setPosition00);
   tolua_function(tolua_S,"offsetPosition",tolua_Zeta_Zeta_Rectangle_offsetPosition00);
   tolua_function(tolua_S,"getWidth",tolua_Zeta_Zeta_Rectangle_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_Zeta_Zeta_Rectangle_getHeight00);
   tolua_function(tolua_S,"setHeight",tolua_Zeta_Zeta_Rectangle_setHeight00);
   tolua_function(tolua_S,"setWidth",tolua_Zeta_Zeta_Rectangle_setWidth00);
   tolua_function(tolua_S,"setSize",tolua_Zeta_Zeta_Rectangle_setSize00);
   tolua_function(tolua_S,"overlapsPoint",tolua_Zeta_Zeta_Rectangle_overlapsPoint00);
   tolua_function(tolua_S,"overlapsPoint",tolua_Zeta_Zeta_Rectangle_overlapsPoint01);
   tolua_function(tolua_S,"overlapsRectangle",tolua_Zeta_Zeta_Rectangle_overlapsRectangle00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Rectangle_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Rectangle_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Rectangle_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Rectangle_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Rectangle_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Rectangle_new01_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Rectangle_new02);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Rectangle_new02_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Rectangle_new02_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Rectangle_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SaveManager","Zeta::SaveManager","",NULL);
  tolua_beginmodule(tolua_S,"SaveManager");
   tolua_function(tolua_S,"setFile",tolua_Zeta_Zeta_SaveManager_setFile00);
   tolua_function(tolua_S,"save",tolua_Zeta_Zeta_SaveManager_save00);
   tolua_function(tolua_S,"load",tolua_Zeta_Zeta_SaveManager_load00);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_SaveManager_getInstance00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SeekingProjectile","Zeta::SeekingProjectile","Zeta::Projectile",NULL);
  tolua_beginmodule(tolua_S,"SeekingProjectile");
   tolua_function(tolua_S,"setTarget",tolua_Zeta_Zeta_SeekingProjectile_setTarget00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Display","Zeta::Display","",NULL);
  tolua_beginmodule(tolua_S,"Display");
   tolua_cclass(tolua_S,"Resolution","Zeta::Display::Resolution","",NULL);
   tolua_beginmodule(tolua_S,"Resolution");
    tolua_variable(tolua_S,"height",tolua_get_Zeta__Display__Resolution_height,tolua_set_Zeta__Display__Resolution_height);
    tolua_variable(tolua_S,"width",tolua_get_Zeta__Display__Resolution_width,tolua_set_Zeta__Display__Resolution_width);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Settings","Zeta::Settings","",NULL);
  tolua_beginmodule(tolua_S,"Settings");
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_Settings_getInstance00);
   tolua_function(tolua_S,"getCurrentResolution",tolua_Zeta_Zeta_Settings_getCurrentResolution00);
   tolua_function(tolua_S,"getFullscreen",tolua_Zeta_Zeta_Settings_getFullscreen00);
   tolua_function(tolua_S,"setFullscreen",tolua_Zeta_Zeta_Settings_setFullscreen00);
   tolua_function(tolua_S,"setResolution",tolua_Zeta_Zeta_Settings_setResolution00);
   tolua_function(tolua_S,"getResolutionsTable",tolua_Zeta_Zeta_Settings_getResolutionsTable00);
   tolua_function(tolua_S,"loadFile",tolua_Zeta_Zeta_Settings_loadFile00);
   tolua_function(tolua_S,"loadFile",tolua_Zeta_Zeta_Settings_loadFile01);
   tolua_function(tolua_S,"saveSettings",tolua_Zeta_Zeta_Settings_saveSettings00);
   tolua_function(tolua_S,"saveSettings",tolua_Zeta_Zeta_Settings_saveSettings01);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector2","Zeta::Vector2","",tolua_collect_Zeta__Vector2);
  #else
  tolua_cclass(tolua_S,"Vector2","Zeta::Vector2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector2");
   tolua_function(tolua_S,"getX",tolua_Zeta_Zeta_Vector2_getX00);
   tolua_function(tolua_S,"setX",tolua_Zeta_Zeta_Vector2_setX00);
   tolua_function(tolua_S,"getY",tolua_Zeta_Zeta_Vector2_getY00);
   tolua_function(tolua_S,"setY",tolua_Zeta_Zeta_Vector2_setY00);
   tolua_function(tolua_S,"set",tolua_Zeta_Zeta_Vector2_set00);
   tolua_function(tolua_S,"offset",tolua_Zeta_Zeta_Vector2_offset00);
   tolua_function(tolua_S,".add",tolua_Zeta_Zeta_Vector2__add00);
   tolua_function(tolua_S,".sub",tolua_Zeta_Zeta_Vector2__sub00);
   tolua_function(tolua_S,".mul",tolua_Zeta_Zeta_Vector2__mul00);
   tolua_function(tolua_S,"getLength",tolua_Zeta_Zeta_Vector2_getLength00);
   tolua_function(tolua_S,"getDistance",tolua_Zeta_Zeta_Vector2_getDistance00);
   tolua_function(tolua_S,"normalize",tolua_Zeta_Zeta_Vector2_normalize00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Vector2_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Vector2_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Vector2_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Vector2_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Vector2_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Vector2_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Vector2_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"View","Zeta::View","",tolua_collect_Zeta__View);
  #else
  tolua_cclass(tolua_S,"View","Zeta::View","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"View");
   tolua_function(tolua_S,"setPosition",tolua_Zeta_Zeta_View_setPosition00);
   tolua_function(tolua_S,"offsetPosition",tolua_Zeta_Zeta_View_offsetPosition00);
   tolua_function(tolua_S,"resize",tolua_Zeta_Zeta_View_resize00);
   tolua_function(tolua_S,"getX",tolua_Zeta_Zeta_View_getX00);
   tolua_function(tolua_S,"getY",tolua_Zeta_Zeta_View_getY00);
   tolua_function(tolua_S,"getWidth",tolua_Zeta_Zeta_View_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_Zeta_Zeta_View_getHeight00);
   tolua_function(tolua_S,"isInView",tolua_Zeta_Zeta_View_isInView00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_View_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_View_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_View_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_View_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"WorldEvent","Zeta::WorldEvent","",tolua_collect_Zeta__WorldEvent);
  #else
  tolua_cclass(tolua_S,"WorldEvent","Zeta::WorldEvent","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"WorldEvent");
   tolua_cclass(tolua_S,"Type","Zeta::WorldEvent::Type","",NULL);
   tolua_beginmodule(tolua_S,"Type");
    tolua_constant(tolua_S,"Damage",(lua_Number)Zeta::WorldEvent::Type::Damage);
    tolua_constant(tolua_S,"Death",(lua_Number)Zeta::WorldEvent::Type::Death);
    tolua_constant(tolua_S,"Interact",(lua_Number)Zeta::WorldEvent::Type::Interact);
    tolua_constant(tolua_S,"AbilityUse",(lua_Number)Zeta::WorldEvent::Type::AbilityUse);
    tolua_constant(tolua_S,"WorldExit",(lua_Number)Zeta::WorldEvent::Type::WorldExit);
    tolua_constant(tolua_S,"Collision",(lua_Number)Zeta::WorldEvent::Type::Collision);
    tolua_constant(tolua_S,"Custom",(lua_Number)Zeta::WorldEvent::Type::Custom);
    tolua_constant(tolua_S,"Nothing",(lua_Number)Zeta::WorldEvent::Type::Nothing);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"setAsDamageEvent",tolua_Zeta_Zeta_WorldEvent_setAsDamageEvent00);
   tolua_function(tolua_S,"setAsDeathEvent",tolua_Zeta_Zeta_WorldEvent_setAsDeathEvent00);
   tolua_function(tolua_S,"setAsInteractEvent",tolua_Zeta_Zeta_WorldEvent_setAsInteractEvent00);
   tolua_function(tolua_S,"setAsAbilityUseEvent",tolua_Zeta_Zeta_WorldEvent_setAsAbilityUseEvent00);
   tolua_function(tolua_S,"setAsWorldExitEvent",tolua_Zeta_Zeta_WorldEvent_setAsWorldExitEvent00);
   tolua_function(tolua_S,"setAsCustomEvent",tolua_Zeta_Zeta_WorldEvent_setAsCustomEvent00);
   tolua_function(tolua_S,"broadcast",tolua_Zeta_Zeta_WorldEvent_broadcast00);
   tolua_function(tolua_S,"toEventType",tolua_Zeta_Zeta_WorldEvent_toEventType00);
   tolua_function(tolua_S,"getType",tolua_Zeta_Zeta_WorldEvent_getType00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_WorldEvent_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_WorldEvent_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_WorldEvent_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_WorldEvent_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"WorldManager","Zeta::WorldManager","",NULL);
  tolua_beginmodule(tolua_S,"WorldManager");
   tolua_cclass(tolua_S,"Callback","Zeta::WorldManager::Callback","",NULL);
   tolua_beginmodule(tolua_S,"Callback");
    tolua_constant(tolua_S,"ChangeMap",(lua_Number)Zeta::WorldManager::Callback::ChangeMap);
    tolua_constant(tolua_S,"LoadBegin",(lua_Number)Zeta::WorldManager::Callback::LoadBegin);
    tolua_constant(tolua_S,"LoadEnd",(lua_Number)Zeta::WorldManager::Callback::LoadEnd);
    tolua_constant(tolua_S,"FrameBegin",(lua_Number)Zeta::WorldManager::Callback::FrameBegin);
    tolua_constant(tolua_S,"FrameEnd",(lua_Number)Zeta::WorldManager::Callback::FrameEnd);
    tolua_constant(tolua_S,"LifeformDeath",(lua_Number)Zeta::WorldManager::Callback::LifeformDeath);
    tolua_constant(tolua_S,"LifeformShow",(lua_Number)Zeta::WorldManager::Callback::LifeformShow);
    tolua_constant(tolua_S,"LifeformHide",(lua_Number)Zeta::WorldManager::Callback::LifeformHide);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_WorldManager_getInstance00);
   tolua_function(tolua_S,"changeMap",tolua_Zeta_Zeta_WorldManager_changeMap00);
   tolua_function(tolua_S,"changeMapWithCallback",tolua_Zeta_Zeta_WorldManager_changeMapWithCallback00);
   tolua_function(tolua_S,"setCallback",tolua_Zeta_Zeta_WorldManager_setCallback00);
   tolua_function(tolua_S,"setCallback",tolua_Zeta_Zeta_WorldManager_setCallback01);
   tolua_function(tolua_S,"raiseEvent",tolua_Zeta_Zeta_WorldManager_raiseEvent00);
   tolua_function(tolua_S,"getView",tolua_Zeta_Zeta_WorldManager_getView00);
   tolua_function(tolua_S,"show",tolua_Zeta_Zeta_WorldManager_show00);
   tolua_function(tolua_S,"hide",tolua_Zeta_Zeta_WorldManager_hide00);
   tolua_function(tolua_S,"pause",tolua_Zeta_Zeta_WorldManager_pause00);
   tolua_function(tolua_S,"resume",tolua_Zeta_Zeta_WorldManager_resume00);
   tolua_function(tolua_S,"getCurrentMap",tolua_Zeta_Zeta_WorldManager_getCurrentMap00);
   tolua_function(tolua_S,"getPlayer",tolua_Zeta_Zeta_WorldManager_getPlayer00);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_WorldManager_getInstance01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"System","Zeta::System","",NULL);
  tolua_beginmodule(tolua_S,"System");
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_System_getInstance00);
   tolua_function(tolua_S,"getAudioContext",tolua_Zeta_Zeta_System_getAudioContext00);
   tolua_function(tolua_S,"shutdown",tolua_Zeta_Zeta_System_shutdown00);
   tolua_function(tolua_S,"abort",tolua_Zeta_Zeta_System_abort00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ActiveAbility","Zeta::ActiveAbility","Zeta::Ability",NULL);
  tolua_beginmodule(tolua_S,"ActiveAbility");
   tolua_function(tolua_S,"getClass",tolua_Zeta_Zeta_ActiveAbility_getClass00);
   tolua_function(tolua_S,"invokeProjectile",tolua_Zeta_Zeta_ActiveAbility_invokeProjectile00);
   tolua_function(tolua_S,"getRemainingCooldown",tolua_Zeta_Zeta_ActiveAbility_getRemainingCooldown00);
   tolua_function(tolua_S,"getCastTime",tolua_Zeta_Zeta_ActiveAbility_getCastTime00);
   tolua_function(tolua_S,"setCastTime",tolua_Zeta_Zeta_ActiveAbility_setCastTime00);
   tolua_function(tolua_S,"getCoolDown",tolua_Zeta_Zeta_ActiveAbility_getCoolDown00);
   tolua_function(tolua_S,"setCoolDown",tolua_Zeta_Zeta_ActiveAbility_setCoolDown00);
   tolua_function(tolua_S,"getManaCost",tolua_Zeta_Zeta_ActiveAbility_getManaCost00);
   tolua_function(tolua_S,"setManaCost",tolua_Zeta_Zeta_ActiveAbility_setManaCost00);
   tolua_function(tolua_S,"getRange",tolua_Zeta_Zeta_ActiveAbility_getRange00);
   tolua_function(tolua_S,"setRange",tolua_Zeta_Zeta_ActiveAbility_setRange00);
   tolua_function(tolua_S,"applyEffect",tolua_Zeta_Zeta_ActiveAbility_applyEffect00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AudioContext","Zeta::AudioContext","",NULL);
  tolua_beginmodule(tolua_S,"AudioContext");
   tolua_function(tolua_S,"getMainGain",tolua_Zeta_Zeta_AudioContext_getMainGain00);
   tolua_function(tolua_S,"setMainGain",tolua_Zeta_Zeta_AudioContext_setMainGain00);
   tolua_function(tolua_S,"setMusic",tolua_Zeta_Zeta_AudioContext_setMusic00);
   tolua_function(tolua_S,"start",tolua_Zeta_Zeta_AudioContext_start00);
   tolua_function(tolua_S,"stop",tolua_Zeta_Zeta_AudioContext_stop00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ActiveAbilityClass","Zeta::ActiveAbilityClass","Zeta::AbilityClass",NULL);
  tolua_beginmodule(tolua_S,"ActiveAbilityClass");
   tolua_function(tolua_S,"applyEffect",tolua_Zeta_Zeta_ActiveAbilityClass_applyEffect00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"PassiveAbilityClass","Zeta::PassiveAbilityClass","Zeta::AbilityClass",NULL);
  tolua_beginmodule(tolua_S,"PassiveAbilityClass");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"RegenerationAbilityClass","Zeta::RegenerationAbilityClass","Zeta::AbilityClass",NULL);
  tolua_beginmodule(tolua_S,"RegenerationAbilityClass");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Regeneration","Zeta::Regeneration","Zeta::Ability",NULL);
  tolua_beginmodule(tolua_S,"Regeneration");
   tolua_function(tolua_S,"getClass",tolua_Zeta_Zeta_Regeneration_getClass00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"InteractObject","Zeta::InteractObject","Zeta::Object",tolua_collect_Zeta__InteractObject);
  #else
  tolua_cclass(tolua_S,"InteractObject","Zeta::InteractObject","Zeta::Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"InteractObject");
   tolua_function(tolua_S,"setOnClick",tolua_Zeta_Zeta_InteractObject_setOnClick00);
   tolua_function(tolua_S,"setOnCollide",tolua_Zeta_Zeta_InteractObject_setOnCollide00);
   tolua_function(tolua_S,"setAnimation",tolua_Zeta_Zeta_InteractObject_setAnimation00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_InteractObject_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_InteractObject_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_InteractObject_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CEGUIChild","Zeta::CEGUIChild","Zeta::ChildObject",tolua_collect_Zeta__CEGUIChild);
  #else
  tolua_cclass(tolua_S,"CEGUIChild","Zeta::CEGUIChild","Zeta::ChildObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CEGUIChild");
   tolua_function(tolua_S,"setOffesets",tolua_Zeta_Zeta_CEGUIChild_setOffesets00);
   tolua_function(tolua_S,"isDestroy",tolua_Zeta_Zeta_CEGUIChild_isDestroy00);
   tolua_function(tolua_S,"setDestroy",tolua_Zeta_Zeta_CEGUIChild_setDestroy00);
   tolua_function(tolua_S,"getOffsetX",tolua_Zeta_Zeta_CEGUIChild_getOffsetX00);
   tolua_function(tolua_S,"setOffsetX",tolua_Zeta_Zeta_CEGUIChild_setOffsetX00);
   tolua_function(tolua_S,"getOffsetY",tolua_Zeta_Zeta_CEGUIChild_getOffsetY00);
   tolua_function(tolua_S,"setOffsetY",tolua_Zeta_Zeta_CEGUIChild_setOffsetY00);
   tolua_function(tolua_S,"getWindow",tolua_Zeta_Zeta_CEGUIChild_getWindow00);
   tolua_function(tolua_S,"setWindow",tolua_Zeta_Zeta_CEGUIChild_setWindow00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_CEGUIChild_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_CEGUIChild_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_CEGUIChild_new00_local);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Animation","Zeta::Animation","",NULL);
  tolua_beginmodule(tolua_S,"Animation");
   tolua_function(tolua_S,"getName",tolua_Zeta_Zeta_Animation_getName00);
   tolua_function(tolua_S,"isLooping",tolua_Zeta_Zeta_Animation_isLooping00);
   tolua_function(tolua_S,"getNumFrames",tolua_Zeta_Zeta_Animation_getNumFrames00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AnimationPlayer","Zeta::AnimationPlayer","",NULL);
  tolua_beginmodule(tolua_S,"AnimationPlayer");
   tolua_function(tolua_S,"isPlaying",tolua_Zeta_Zeta_AnimationPlayer_isPlaying00);
   tolua_function(tolua_S,"isVisible",tolua_Zeta_Zeta_AnimationPlayer_isVisible00);
   tolua_function(tolua_S,"setVisible",tolua_Zeta_Zeta_AnimationPlayer_setVisible00);
   tolua_function(tolua_S,"hide",tolua_Zeta_Zeta_AnimationPlayer_hide00);
   tolua_function(tolua_S,"show",tolua_Zeta_Zeta_AnimationPlayer_show00);
   tolua_function(tolua_S,"play",tolua_Zeta_Zeta_AnimationPlayer_play00);
   tolua_function(tolua_S,"stop",tolua_Zeta_Zeta_AnimationPlayer_stop00);
   tolua_function(tolua_S,"pause",tolua_Zeta_Zeta_AnimationPlayer_pause00);
   tolua_function(tolua_S,"reset",tolua_Zeta_Zeta_AnimationPlayer_reset00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AnimationEffectsManager","Zeta::AnimationEffectsManager","",NULL);
  tolua_beginmodule(tolua_S,"AnimationEffectsManager");
   tolua_function(tolua_S,"getAnimationFX",tolua_Zeta_Zeta_AnimationEffectsManager_getAnimationFX00);
   tolua_function(tolua_S,"addAnimationPack",tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack00);
   tolua_function(tolua_S,"addAnimationPack",tolua_Zeta_Zeta_AnimationEffectsManager_addAnimationPack01);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_AnimationEffectsManager_getInstance00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"OffAnimation","Zeta::OffAnimation","Zeta::AnimationPlayer",NULL);
  tolua_beginmodule(tolua_S,"OffAnimation");
   tolua_function(tolua_S,"getDx",tolua_Zeta_Zeta_OffAnimation_getDx00);
   tolua_function(tolua_S,"setDx",tolua_Zeta_Zeta_OffAnimation_setDx00);
   tolua_function(tolua_S,"getDy",tolua_Zeta_Zeta_OffAnimation_getDy00);
   tolua_function(tolua_S,"setDy",tolua_Zeta_Zeta_OffAnimation_setDy00);
   tolua_function(tolua_S,"setOffsets",tolua_Zeta_Zeta_OffAnimation_setOffsets00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LifeformClass","Zeta::LifeformClass","",tolua_collect_Zeta__LifeformClass);
  #else
  tolua_cclass(tolua_S,"LifeformClass","Zeta::LifeformClass","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LifeformClass");
   tolua_function(tolua_S,"getLifeformName",tolua_Zeta_Zeta_LifeformClass_getLifeformName00);
   tolua_function(tolua_S,"getAnimationClassName",tolua_Zeta_Zeta_LifeformClass_getAnimationClassName00);
   tolua_function(tolua_S,"getLevel",tolua_Zeta_Zeta_LifeformClass_getLevel00);
   tolua_function(tolua_S,"setTable",tolua_Zeta_Zeta_LifeformClass_setTable00);
   tolua_function(tolua_S,"setOnClick",tolua_Zeta_Zeta_LifeformClass_setOnClick00);
   tolua_function(tolua_S,"setOnCollision",tolua_Zeta_Zeta_LifeformClass_setOnCollision00);
   tolua_function(tolua_S,"levelizeStats",tolua_Zeta_Zeta_LifeformClass_levelizeStats00);
   tolua_function(tolua_S,"levelizeStats",tolua_Zeta_Zeta_LifeformClass_levelizeStats01);
   tolua_function(tolua_S,"addAbility",tolua_Zeta_Zeta_LifeformClass_addAbility00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LifeformClass_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LifeformClass_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LifeformClass_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LifeformClass_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LifeformClass_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LifeformClass_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_LifeformClass_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LifeformClassContainer","Zeta::LifeformClassContainer","",tolua_collect_Zeta__LifeformClassContainer);
  #else
  tolua_cclass(tolua_S,"LifeformClassContainer","Zeta::LifeformClassContainer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LifeformClassContainer");
   tolua_function(tolua_S,"get",tolua_Zeta_Zeta_LifeformClassContainer_get00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LifeformClassContainer_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LifeformClassContainer_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LifeformClassContainer_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_LifeformClassContainer_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CEGUIObject","Zeta::CEGUIObject","Zeta::Object",tolua_collect_Zeta__CEGUIObject);
  #else
  tolua_cclass(tolua_S,"CEGUIObject","Zeta::CEGUIObject","Zeta::Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CEGUIObject");
   tolua_function(tolua_S,"setOffesets",tolua_Zeta_Zeta_CEGUIObject_setOffesets00);
   tolua_function(tolua_S,"isDestroy",tolua_Zeta_Zeta_CEGUIObject_isDestroy00);
   tolua_function(tolua_S,"setDestroy",tolua_Zeta_Zeta_CEGUIObject_setDestroy00);
   tolua_function(tolua_S,"getOffsetX",tolua_Zeta_Zeta_CEGUIObject_getOffsetX00);
   tolua_function(tolua_S,"setOffsetX",tolua_Zeta_Zeta_CEGUIObject_setOffsetX00);
   tolua_function(tolua_S,"getOffsetY",tolua_Zeta_Zeta_CEGUIObject_getOffsetY00);
   tolua_function(tolua_S,"setOffsetY",tolua_Zeta_Zeta_CEGUIObject_setOffsetY00);
   tolua_function(tolua_S,"getWindow",tolua_Zeta_Zeta_CEGUIObject_getWindow00);
   tolua_function(tolua_S,"setWindow",tolua_Zeta_Zeta_CEGUIObject_setWindow00);
   tolua_function(tolua_S,"setLuaTable",tolua_Zeta_Zeta_CEGUIObject_setLuaTable00);
   tolua_function(tolua_S,"setOnClick",tolua_Zeta_Zeta_CEGUIObject_setOnClick00);
   tolua_function(tolua_S,"getAnimationHandler",tolua_Zeta_Zeta_CEGUIObject_getAnimationHandler00);
   tolua_function(tolua_S,"setPosition",tolua_Zeta_Zeta_CEGUIObject_setPosition00);
   tolua_function(tolua_S,"offsetPosition",tolua_Zeta_Zeta_CEGUIObject_offsetPosition00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_CEGUIObject_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_CEGUIObject_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_CEGUIObject_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_CEGUIObject_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_CEGUIObject_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_CEGUIObject_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_CEGUIObject_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"InteractField","Zeta::InteractField","Zeta::Object",NULL);
  tolua_beginmodule(tolua_S,"InteractField");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaListener","Zeta::LuaListener","",tolua_collect_Zeta__LuaListener);
  #else
  tolua_cclass(tolua_S,"LuaListener","Zeta::LuaListener","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaListener");
   tolua_function(tolua_S,"deactivate",tolua_Zeta_Zeta_LuaListener_deactivate00);
   tolua_function(tolua_S,"activate",tolua_Zeta_Zeta_LuaListener_activate00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LuaListener_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LuaListener_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LuaListener_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LuaListener_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LuaListener_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LuaListener_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_LuaListener_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EffectClass","Zeta::EffectClass","",tolua_collect_Zeta__EffectClass);
  #else
  tolua_cclass(tolua_S,"EffectClass","Zeta::EffectClass","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EffectClass");
   tolua_function(tolua_S,"getUpTime",tolua_Zeta_Zeta_EffectClass_getUpTime00);
   tolua_function(tolua_S,"getTickEvery",tolua_Zeta_Zeta_EffectClass_getTickEvery00);
   tolua_function(tolua_S,"getNewEffect",tolua_Zeta_Zeta_EffectClass_getNewEffect00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_EffectClass_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_EffectClass_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_EffectClass_new00_local);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_EffectClass_new01);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_EffectClass_new01_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_EffectClass_new01_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_EffectClass_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Effect","Zeta::Effect","",NULL);
  tolua_beginmodule(tolua_S,"Effect");
   tolua_function(tolua_S,"getSource",tolua_Zeta_Zeta_Effect_getSource00);
   tolua_function(tolua_S,"isFinished",tolua_Zeta_Zeta_Effect_isFinished00);
   tolua_function(tolua_S,"end",tolua_Zeta_Zeta_Effect_end00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Timer","Zeta::Timer","",tolua_collect_Zeta__Timer);
  #else
  tolua_cclass(tolua_S,"Timer","Zeta::Timer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Timer");
   tolua_function(tolua_S,"getMaxTime",tolua_Zeta_Zeta_Timer_getMaxTime00);
   tolua_function(tolua_S,"setMaxTime",tolua_Zeta_Zeta_Timer_setMaxTime00);
   tolua_function(tolua_S,"getRemainingTime",tolua_Zeta_Zeta_Timer_getRemainingTime00);
   tolua_function(tolua_S,"setRemainingTime",tolua_Zeta_Zeta_Timer_setRemainingTime00);
   tolua_function(tolua_S,"isOver",tolua_Zeta_Zeta_Timer_isOver00);
   tolua_function(tolua_S,"isRunning",tolua_Zeta_Zeta_Timer_isRunning00);
   tolua_function(tolua_S,"start",tolua_Zeta_Zeta_Timer_start00);
   tolua_function(tolua_S,"pause",tolua_Zeta_Zeta_Timer_pause00);
   tolua_function(tolua_S,"reset",tolua_Zeta_Zeta_Timer_reset00);
   tolua_function(tolua_S,"setCallback",tolua_Zeta_Zeta_Timer_setCallback00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_Timer_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_Timer_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_Timer_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_Timer_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ResourceCache","Zeta::ResourceCache","",NULL);
  tolua_beginmodule(tolua_S,"ResourceCache");
   tolua_function(tolua_S,"getAbilityClass",tolua_Zeta_Zeta_ResourceCache_getAbilityClass00);
   tolua_function(tolua_S,"getLifeformClass",tolua_Zeta_Zeta_ResourceCache_getLifeformClass00);
   tolua_function(tolua_S,"releaseResource",tolua_Zeta_Zeta_ResourceCache_releaseResource00);
   tolua_function(tolua_S,"releaseResource",tolua_Zeta_Zeta_ResourceCache_releaseResource01);
   tolua_function(tolua_S,"getInstance",tolua_Zeta_Zeta_ResourceCache_getInstance00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LifeformState","Zeta::LifeformState","",tolua_collect_Zeta__LifeformState);
  #else
  tolua_cclass(tolua_S,"LifeformState","Zeta::LifeformState","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LifeformState");
   tolua_cclass(tolua_S,"Direction","Zeta::LifeformState::Direction","",NULL);
   tolua_beginmodule(tolua_S,"Direction");
    tolua_constant(tolua_S,"Down",(lua_Number)Zeta::LifeformState::Direction::Down);
    tolua_constant(tolua_S,"Up",(lua_Number)Zeta::LifeformState::Direction::Up);
    tolua_constant(tolua_S,"Left",(lua_Number)Zeta::LifeformState::Direction::Left);
    tolua_constant(tolua_S,"Right",(lua_Number)Zeta::LifeformState::Direction::Right);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Action","Zeta::LifeformState::Action","",NULL);
   tolua_beginmodule(tolua_S,"Action");
    tolua_constant(tolua_S,"Idle",(lua_Number)Zeta::LifeformState::Action::Idle);
    tolua_constant(tolua_S,"Moving",(lua_Number)Zeta::LifeformState::Action::Moving);
    tolua_constant(tolua_S,"Dying",(lua_Number)Zeta::LifeformState::Action::Dying);
    tolua_constant(tolua_S,"Dead",(lua_Number)Zeta::LifeformState::Action::Dead);
    tolua_constant(tolua_S,"Casting",(lua_Number)Zeta::LifeformState::Action::Casting);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"set",tolua_Zeta_Zeta_LifeformState_set00);
   tolua_function(tolua_S,"getCombinedState",tolua_Zeta_Zeta_LifeformState_getCombinedState00);
   tolua_function(tolua_S,"setAction",tolua_Zeta_Zeta_LifeformState_setAction00);
   tolua_function(tolua_S,"setDirection",tolua_Zeta_Zeta_LifeformState_setDirection00);
   tolua_function(tolua_S,"getAction",tolua_Zeta_Zeta_LifeformState_getAction00);
   tolua_function(tolua_S,"getDirection",tolua_Zeta_Zeta_LifeformState_getDirection00);
   tolua_function(tolua_S,"new",tolua_Zeta_Zeta_LifeformState_new00);
   tolua_function(tolua_S,"new_local",tolua_Zeta_Zeta_LifeformState_new00_local);
   tolua_function(tolua_S,".call",tolua_Zeta_Zeta_LifeformState_new00_local);
   tolua_function(tolua_S,"delete",tolua_Zeta_Zeta_LifeformState_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ProjectileClass","Zeta::ProjectileClass","",NULL);
  tolua_beginmodule(tolua_S,"ProjectileClass");
   tolua_cclass(tolua_S,"ProjectileType","Zeta::ProjectileClass::ProjectileType","",NULL);
   tolua_beginmodule(tolua_S,"ProjectileType");
    tolua_constant(tolua_S,"Normal",(lua_Number)Zeta::ProjectileClass::ProjectileType::Normal);
    tolua_constant(tolua_S,"Directional",(lua_Number)Zeta::ProjectileClass::ProjectileType::Directional);
    tolua_constant(tolua_S,"Seeking",(lua_Number)Zeta::ProjectileClass::ProjectileType::Seeking);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"DurableEffect","Zeta::DurableEffect","Zeta::Effect",NULL);
  tolua_beginmodule(tolua_S,"DurableEffect");
   tolua_function(tolua_S,"getRemainingTime",tolua_Zeta_Zeta_DurableEffect_getRemainingTime00);
   tolua_function(tolua_S,"getUpTime",tolua_Zeta_Zeta_DurableEffect_getUpTime00);
   tolua_function(tolua_S,"setUpTime",tolua_Zeta_Zeta_DurableEffect_setUpTime00);
   tolua_function(tolua_S,"reset",tolua_Zeta_Zeta_DurableEffect_reset00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"OverTimeEffect","Zeta::OverTimeEffect","Zeta::DurableEffect",NULL);
  tolua_beginmodule(tolua_S,"OverTimeEffect");
   tolua_function(tolua_S,"getTickEvery",tolua_Zeta_Zeta_OverTimeEffect_getTickEvery00);
   tolua_function(tolua_S,"setTickEvery",tolua_Zeta_Zeta_OverTimeEffect_setTickEvery00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 int luaopen_Zeta (lua_State* tolua_S) {
 return tolua_Zeta_open(tolua_S);
};
#endif


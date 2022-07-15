/*
** Lua binding: interface
** Generated automatically by tolua++-1.0.93.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_interface_open (lua_State* tolua_S);

#include "dmlua_typeid.h"
#include "dmlua_luaresult.h"
#include "dmtypes.h"
#include "../common/macros.h"
#include "../common/enum.h"
#include "../common/struct.h"
#include "../role/role.h"
#include "../role/rolemgr.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_STaskInfo (lua_State* tolua_S)
{
 STaskInfo* self = (STaskInfo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__vector_int64_t_ (lua_State* tolua_S)
{
 std::vector<int64_t>* self = (std::vector<int64_t>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CRole (lua_State* tolua_S)
{
 CRole* self = (CRole*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaResult_double_ (lua_State* tolua_S)
{
 LuaResult<double>* self = (LuaResult<double>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaResult_int_ (lua_State* tolua_S)
{
 LuaResult<int>* self = (LuaResult<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaResult_int64_t_ (lua_State* tolua_S)
{
 LuaResult<int64_t>* self = (LuaResult<int64_t>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CObj (lua_State* tolua_S)
{
 CObj* self = (CObj*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__vector_int_ (lua_State* tolua_S)
{
 std::vector<int>* self = (std::vector<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaResult_std__string_ (lua_State* tolua_S)
{
 LuaResult<std::string>* self = (LuaResult<std::string>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__vector_std__string_ (lua_State* tolua_S)
{
 std::vector<std::string>* self = (std::vector<std::string>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaResult_uint64_t_ (lua_State* tolua_S)
{
 LuaResult<uint64_t>* self = (LuaResult<uint64_t>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__vector_double_ (lua_State* tolua_S)
{
 std::vector<double>* self = (std::vector<double>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__vector_uint64_t_ (lua_State* tolua_S)
{
 std::vector<uint64_t>* self = (std::vector<uint64_t>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SPos (lua_State* tolua_S)
{
 SPos* self = (SPos*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"STaskInfo");
 Mtolua_typeid< STaskInfo >(tolua_S, "STaskInfo");
 tolua_usertype(tolua_S,"std::vector<int64_t>");
 Mtolua_typeid< std::vector<int64_t> >(tolua_S, "std::vector<int64_t>");
 tolua_usertype(tolua_S,"CRole");
 Mtolua_typeid< CRole >(tolua_S, "CRole");
 tolua_usertype(tolua_S,"LuaResult<double>");
 Mtolua_typeid< LuaResult<double> >(tolua_S, "LuaResult<double>");
 tolua_usertype(tolua_S,"LuaResult<int>");
 Mtolua_typeid< LuaResult<int> >(tolua_S, "LuaResult<int>");
 tolua_usertype(tolua_S,"LuaResult<int64_t>");
 Mtolua_typeid< LuaResult<int64_t> >(tolua_S, "LuaResult<int64_t>");
 tolua_usertype(tolua_S,"CObj");
 Mtolua_typeid< CObj >(tolua_S, "CObj");
 tolua_usertype(tolua_S,"std::vector<int>");
 Mtolua_typeid< std::vector<int> >(tolua_S, "std::vector<int>");
 tolua_usertype(tolua_S,"LuaResult<std::string>");
 Mtolua_typeid< LuaResult<std::string> >(tolua_S, "LuaResult<std::string>");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 Mtolua_typeid< std::vector<std::string> >(tolua_S, "std::vector<std::string>");
 tolua_usertype(tolua_S,"LuaResult<uint64_t>");
 Mtolua_typeid< LuaResult<uint64_t> >(tolua_S, "LuaResult<uint64_t>");
 tolua_usertype(tolua_S,"std::vector<double>");
 Mtolua_typeid< std::vector<double> >(tolua_S, "std::vector<double>");
 tolua_usertype(tolua_S,"std::vector<uint64_t>");
 Mtolua_typeid< std::vector<uint64_t> >(tolua_S, "std::vector<uint64_t>");
 tolua_usertype(tolua_S,"SPos");
 Mtolua_typeid< SPos >(tolua_S, "SPos");
}

/* get function: value of class  LuaResult<int> */
#ifndef TOLUA_DISABLE_tolua_get_LuaResult_int__value
static int tolua_get_LuaResult_int__value(lua_State* tolua_S)
{
  LuaResult<int>* self = (LuaResult<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  LuaResult<int> */
#ifndef TOLUA_DISABLE_tolua_set_LuaResult_int__value
static int tolua_set_LuaResult_int__value(lua_State* tolua_S)
{
  LuaResult<int>* self = (LuaResult<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaResult<int> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int__new00
static int tolua_interface_LuaResult_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<int>* tolua_ret = (LuaResult<int>*)  Mtolua_new((LuaResult<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<int>");
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

/* method: new_local of class  LuaResult<int> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int__new00_local
static int tolua_interface_LuaResult_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<int>* tolua_ret = (LuaResult<int>*)  Mtolua_new((LuaResult<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  LuaResult<int> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int__delete00
static int tolua_interface_LuaResult_int__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaResult<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaResult<int>* self = (LuaResult<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  LuaResult<int64_t> */
#ifndef TOLUA_DISABLE_tolua_get_LuaResult_int64_t__value
static int tolua_get_LuaResult_int64_t__value(lua_State* tolua_S)
{
  LuaResult<int64_t>* self = (LuaResult<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  LuaResult<int64_t> */
#ifndef TOLUA_DISABLE_tolua_set_LuaResult_int64_t__value
static int tolua_set_LuaResult_int64_t__value(lua_State* tolua_S)
{
  LuaResult<int64_t>* self = (LuaResult<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int64_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaResult<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int64_t__new00
static int tolua_interface_LuaResult_int64_t__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<int64_t>* tolua_ret = (LuaResult<int64_t>*)  Mtolua_new((LuaResult<int64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<int64_t>");
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

/* method: new_local of class  LuaResult<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int64_t__new00_local
static int tolua_interface_LuaResult_int64_t__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<int64_t>* tolua_ret = (LuaResult<int64_t>*)  Mtolua_new((LuaResult<int64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<int64_t>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  LuaResult<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_int64_t__delete00
static int tolua_interface_LuaResult_int64_t__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaResult<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaResult<int64_t>* self = (LuaResult<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  LuaResult<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_get_LuaResult_uint64_t__value
static int tolua_get_LuaResult_uint64_t__value(lua_State* tolua_S)
{
  LuaResult<uint64_t>* self = (LuaResult<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  LuaResult<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_set_LuaResult_uint64_t__value
static int tolua_set_LuaResult_uint64_t__value(lua_State* tolua_S)
{
  LuaResult<uint64_t>* self = (LuaResult<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((uint64_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaResult<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_uint64_t__new00
static int tolua_interface_LuaResult_uint64_t__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<uint64_t>* tolua_ret = (LuaResult<uint64_t>*)  Mtolua_new((LuaResult<uint64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<uint64_t>");
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

/* method: new_local of class  LuaResult<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_uint64_t__new00_local
static int tolua_interface_LuaResult_uint64_t__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<uint64_t>* tolua_ret = (LuaResult<uint64_t>*)  Mtolua_new((LuaResult<uint64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<uint64_t>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  LuaResult<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_uint64_t__delete00
static int tolua_interface_LuaResult_uint64_t__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaResult<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaResult<uint64_t>* self = (LuaResult<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  LuaResult<double> */
#ifndef TOLUA_DISABLE_tolua_get_LuaResult_double__value
static int tolua_get_LuaResult_double__value(lua_State* tolua_S)
{
  LuaResult<double>* self = (LuaResult<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  LuaResult<double> */
#ifndef TOLUA_DISABLE_tolua_set_LuaResult_double__value
static int tolua_set_LuaResult_double__value(lua_State* tolua_S)
{
  LuaResult<double>* self = (LuaResult<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaResult<double> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_double__new00
static int tolua_interface_LuaResult_double__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<double>* tolua_ret = (LuaResult<double>*)  Mtolua_new((LuaResult<double>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<double>");
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

/* method: new_local of class  LuaResult<double> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_double__new00_local
static int tolua_interface_LuaResult_double__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<double>* tolua_ret = (LuaResult<double>*)  Mtolua_new((LuaResult<double>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<double>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  LuaResult<double> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_double__delete00
static int tolua_interface_LuaResult_double__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaResult<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaResult<double>* self = (LuaResult<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  LuaResult<std::string> */
#ifndef TOLUA_DISABLE_tolua_get_LuaResult_std__string__value
static int tolua_get_LuaResult_std__string__value(lua_State* tolua_S)
{
  LuaResult<std::string>* self = (LuaResult<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  LuaResult<std::string> */
#ifndef TOLUA_DISABLE_tolua_set_LuaResult_std__string__value
static int tolua_set_LuaResult_std__string__value(lua_State* tolua_S)
{
  LuaResult<std::string>* self = (LuaResult<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaResult<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_std__string__new00
static int tolua_interface_LuaResult_std__string__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<std::string>* tolua_ret = (LuaResult<std::string>*)  Mtolua_new((LuaResult<std::string>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<std::string>");
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

/* method: new_local of class  LuaResult<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_std__string__new00_local
static int tolua_interface_LuaResult_std__string__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaResult<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaResult<std::string>* tolua_ret = (LuaResult<std::string>*)  Mtolua_new((LuaResult<std::string>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaResult<std::string>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  LuaResult<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_LuaResult_std__string__delete00
static int tolua_interface_LuaResult_std__string__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaResult<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaResult<std::string>* self = (LuaResult<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__clear00
static int tolua_interface_std_vector_int__clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int>* self = (std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__size00
static int tolua_interface_std_vector_int__size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<int>* self = (const std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int___geti00
static int tolua_interface_std_vector_int___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<int>* self = (const std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int___seti00
static int tolua_interface_std_vector_int___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int>* self = (std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int tolua_value = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int___geti01
static int tolua_interface_std_vector_int___geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::vector<int>* self = (std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   int tolua_ret = (int)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_std_vector_int___geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__push_back00
static int tolua_interface_std_vector_int__push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int>* self = (std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
  int val = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__new00
static int tolua_interface_std_vector_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<int>* tolua_ret = (std::vector<int>*)  Mtolua_new((std::vector<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<int>");
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

/* method: new_local of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__new00_local
static int tolua_interface_std_vector_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<int>* tolua_ret = (std::vector<int>*)  Mtolua_new((std::vector<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  std::vector<int> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int__delete00
static int tolua_interface_std_vector_int__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int>* self = (std::vector<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__clear00
static int tolua_interface_std_vector_int64_t__clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int64_t>* self = (std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__size00
static int tolua_interface_std_vector_int64_t__size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<int64_t>* self = (const std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t___geti00
static int tolua_interface_std_vector_int64_t___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<int64_t>* self = (const std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const int64_t tolua_ret = (const int64_t)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t___seti00
static int tolua_interface_std_vector_int64_t___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int64_t>* self = (std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int64_t tolua_value = ((int64_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t___geti01
static int tolua_interface_std_vector_int64_t___geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::vector<int64_t>* self = (std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_std_vector_int64_t___geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__push_back00
static int tolua_interface_std_vector_int64_t__push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int64_t>* self = (std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
  int64_t val = ((int64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__new00
static int tolua_interface_std_vector_int64_t__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<int64_t>* tolua_ret = (std::vector<int64_t>*)  Mtolua_new((std::vector<int64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<int64_t>");
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

/* method: new_local of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__new00_local
static int tolua_interface_std_vector_int64_t__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<int64_t>* tolua_ret = (std::vector<int64_t>*)  Mtolua_new((std::vector<int64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<int64_t>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  std::vector<int64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_int64_t__delete00
static int tolua_interface_std_vector_int64_t__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<int64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<int64_t>* self = (std::vector<int64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__clear00
static int tolua_interface_std_vector_uint64_t__clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<uint64_t>* self = (std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__size00
static int tolua_interface_std_vector_uint64_t__size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<uint64_t>* self = (const std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t___geti00
static int tolua_interface_std_vector_uint64_t___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<uint64_t>* self = (const std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const uint64_t tolua_ret = (const uint64_t)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t___seti00
static int tolua_interface_std_vector_uint64_t___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<uint64_t>* self = (std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  uint64_t tolua_value = ((uint64_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t___geti01
static int tolua_interface_std_vector_uint64_t___geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::vector<uint64_t>* self = (std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   uint64_t tolua_ret = (uint64_t)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_std_vector_uint64_t___geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__push_back00
static int tolua_interface_std_vector_uint64_t__push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<uint64_t>* self = (std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
  uint64_t val = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__new00
static int tolua_interface_std_vector_uint64_t__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<uint64_t>* tolua_ret = (std::vector<uint64_t>*)  Mtolua_new((std::vector<uint64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<uint64_t>");
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

/* method: new_local of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__new00_local
static int tolua_interface_std_vector_uint64_t__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<uint64_t>* tolua_ret = (std::vector<uint64_t>*)  Mtolua_new((std::vector<uint64_t>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<uint64_t>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  std::vector<uint64_t> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_uint64_t__delete00
static int tolua_interface_std_vector_uint64_t__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<uint64_t>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<uint64_t>* self = (std::vector<uint64_t>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__clear00
static int tolua_interface_std_vector_double__clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<double>* self = (std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__size00
static int tolua_interface_std_vector_double__size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<double>* self = (const std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double___geti00
static int tolua_interface_std_vector_double___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<double>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<double>* self = (const std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const double tolua_ret = (const double)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double___seti00
static int tolua_interface_std_vector_double___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<double>* self = (std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  double tolua_value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double___geti01
static int tolua_interface_std_vector_double___geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::vector<double>* self = (std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   double tolua_ret = (double)  self->operator[](index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_std_vector_double___geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__push_back00
static int tolua_interface_std_vector_double__push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<double>* self = (std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
  double val = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__new00
static int tolua_interface_std_vector_double__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<double>* tolua_ret = (std::vector<double>*)  Mtolua_new((std::vector<double>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<double>");
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

/* method: new_local of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__new00_local
static int tolua_interface_std_vector_double__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<double>* tolua_ret = (std::vector<double>*)  Mtolua_new((std::vector<double>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<double>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  std::vector<double> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_double__delete00
static int tolua_interface_std_vector_double__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<double>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<double>* self = (std::vector<double>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__clear00
static int tolua_interface_std_vector_std__string__clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<std::string>* self = (std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__size00
static int tolua_interface_std_vector_std__string__size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<std::string>* self = (const std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string___geti00
static int tolua_interface_std_vector_std__string___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::vector<std::string>* self = (const std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->operator[](index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string___seti00
static int tolua_interface_std_vector_std__string___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<std::string>* self = (std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  std::string tolua_value = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string___geti01
static int tolua_interface_std_vector_std__string___geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::vector<std::string>* self = (std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->operator[](index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_std_vector_std__string___geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__push_back00
static int tolua_interface_std_vector_std__string__push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<std::string>* self = (std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
  std::string val = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__new00
static int tolua_interface_std_vector_std__string__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<std::string>* tolua_ret = (std::vector<std::string>*)  Mtolua_new((std::vector<std::string>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<std::string>");
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

/* method: new_local of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__new00_local
static int tolua_interface_std_vector_std__string__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<std::string>* tolua_ret = (std::vector<std::string>*)  Mtolua_new((std::vector<std::string>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"std::vector<std::string>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  std::vector<std::string> */
#ifndef TOLUA_DISABLE_tolua_interface_std_vector_std__string__delete00
static int tolua_interface_std_vector_std__string__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"std::vector<std::string>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::vector<std::string>* self = (std::vector<std::string>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_interface_STaskInfo_new00
static int tolua_interface_STaskInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"STaskInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   STaskInfo* tolua_ret = (STaskInfo*)  Mtolua_new((STaskInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"STaskInfo");
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

/* method: new_local of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_interface_STaskInfo_new00_local
static int tolua_interface_STaskInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"STaskInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   STaskInfo* tolua_ret = (STaskInfo*)  Mtolua_new((STaskInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"STaskInfo");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_interface_STaskInfo_delete00
static int tolua_interface_STaskInfo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"STaskInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nTaskID of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_get_STaskInfo_nTaskID
static int tolua_get_STaskInfo_nTaskID(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->nTaskID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nTaskID of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_set_STaskInfo_nTaskID
static int tolua_set_STaskInfo_nTaskID(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nTaskID = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nTaskState of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_get_STaskInfo_nTaskState
static int tolua_get_STaskInfo_nTaskState(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskState'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->nTaskState);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nTaskState of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_set_STaskInfo_nTaskState
static int tolua_set_STaskInfo_nTaskState(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskState'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nTaskState = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nTaskCondition of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_get_STaskInfo_nTaskCondition
static int tolua_get_STaskInfo_nTaskCondition(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskCondition'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->nTaskCondition);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nTaskCondition of class  STaskInfo */
#ifndef TOLUA_DISABLE_tolua_set_STaskInfo_nTaskCondition
static int tolua_set_STaskInfo_nTaskCondition(lua_State* tolua_S)
{
  STaskInfo* self = (STaskInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nTaskCondition'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nTaskCondition = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SPos */
#ifndef TOLUA_DISABLE_tolua_interface_SPos_new00
static int tolua_interface_SPos_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SPos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SPos* tolua_ret = (SPos*)  Mtolua_new((SPos)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SPos");
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

/* method: new_local of class  SPos */
#ifndef TOLUA_DISABLE_tolua_interface_SPos_new00_local
static int tolua_interface_SPos_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SPos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SPos* tolua_ret = (SPos*)  Mtolua_new((SPos)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SPos");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: new of class  SPos */
#ifndef TOLUA_DISABLE_tolua_interface_SPos_new01
static int tolua_interface_SPos_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SPos",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int _x = ((int)  tolua_tonumber(tolua_S,2,0));
  int _y = ((int)  tolua_tonumber(tolua_S,3,0));
  int _z = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   SPos* tolua_ret = (SPos*)  Mtolua_new((SPos)(_x,_y,_z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SPos");
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_SPos_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SPos */
#ifndef TOLUA_DISABLE_tolua_interface_SPos_new01_local
static int tolua_interface_SPos_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SPos",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int _x = ((int)  tolua_tonumber(tolua_S,2,0));
  int _y = ((int)  tolua_tonumber(tolua_S,3,0));
  int _z = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   SPos* tolua_ret = (SPos*)  Mtolua_new((SPos)(_x,_y,_z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SPos");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_SPos_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SPos */
#ifndef TOLUA_DISABLE_tolua_interface_SPos_delete00
static int tolua_interface_SPos_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SPos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  SPos */
#ifndef TOLUA_DISABLE_tolua_get_SPos_x
static int tolua_get_SPos_x(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  SPos */
#ifndef TOLUA_DISABLE_tolua_set_SPos_x
static int tolua_set_SPos_x(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  SPos */
#ifndef TOLUA_DISABLE_tolua_get_SPos_y
static int tolua_get_SPos_y(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  SPos */
#ifndef TOLUA_DISABLE_tolua_set_SPos_y
static int tolua_set_SPos_y(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  SPos */
#ifndef TOLUA_DISABLE_tolua_get_SPos_z
static int tolua_get_SPos_z(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  SPos */
#ifndef TOLUA_DISABLE_tolua_set_SPos_z
static int tolua_set_SPos_z(lua_State* tolua_S)
{
  SPos* self = (SPos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_new00
static int tolua_interface_CObj_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CObj* tolua_ret = (CObj*)  Mtolua_new((CObj)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CObj");
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

/* method: new_local of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_new00_local
static int tolua_interface_CObj_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CObj* tolua_ret = (CObj*)  Mtolua_new((CObj)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CObj");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_delete00
static int tolua_interface_CObj_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObjID of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_SetObjID00
static int tolua_interface_CObj_SetObjID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
  uint64_t qwObjID = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObjID'", NULL);
#endif
  {
   self->SetObjID(qwObjID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObjID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjID of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_GetObjID00
static int tolua_interface_CObj_GetObjID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjID'", NULL);
#endif
  {
   uint64_t tolua_ret = (uint64_t)  self->GetObjID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjID of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_GetObjID01
static int tolua_interface_CObj_GetObjID01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
  uint64_t qwObjID = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjID'", NULL);
#endif
  {
   self->GetObjID(qwObjID);
   tolua_pushnumber(tolua_S,(lua_Number)qwObjID);
  }
 }
 return 1;
tolua_lerror:
 return tolua_interface_CObj_GetObjID00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_SetName00
static int tolua_interface_CObj_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
  const char* szName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   self->SetName(szName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  CObj */
#ifndef TOLUA_DISABLE_tolua_interface_CObj_GetName00
static int tolua_interface_CObj_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CObj* self = (CObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_new00
static int tolua_interface_CRole_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CRole* tolua_ret = (CRole*)  Mtolua_new((CRole)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CRole");
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

/* method: new_local of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_new00_local
static int tolua_interface_CRole_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CRole* tolua_ret = (CRole*)  Mtolua_new((CRole)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CRole");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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

/* method: delete of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_delete00
static int tolua_interface_CRole_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMp of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_SetMp00
static int tolua_interface_CRole_SetMp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nMp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMp'", NULL);
#endif
  {
   self->SetMp(nMp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMp of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_GetMp00
static int tolua_interface_CRole_GetMp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMp'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHp of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_SetHp00
static int tolua_interface_CRole_SetHp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nHp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHp'", NULL);
#endif
  {
   self->SetHp(nHp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHp of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_GetHp00
static int tolua_interface_CRole_GetHp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHp'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetHp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMP of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_AddMP00
static int tolua_interface_CRole_AddMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nMp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMP'", NULL);
#endif
  {
   self->AddMP(nMp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddHP of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_AddHP00
static int tolua_interface_CRole_AddHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nHp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddHP'", NULL);
#endif
  {
   self->AddHP(nHp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPos of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_SetPos00
static int tolua_interface_CRole_SetPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SPos",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  const SPos* stPos = ((const SPos*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPos'", NULL);
#endif
  {
   self->SetPos(*stPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPos of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_GetPos00
static int tolua_interface_CRole_GetPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPos'", NULL);
#endif
  {
   SPos& tolua_ret = (SPos&)  self->GetPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"SPos");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AcceptTask of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_AcceptTask00
static int tolua_interface_CRole_AcceptTask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nTaskID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AcceptTask'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AcceptTask(nTaskID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AcceptTask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FinishTask of class  CRole */
#ifndef TOLUA_DISABLE_tolua_interface_CRole_FinishTask00
static int tolua_interface_CRole_FinishTask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* self = (CRole*)  tolua_tousertype(tolua_S,1,0);
  int nTaskID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FinishTask'", NULL);
#endif
  {
   self->FinishTask(nTaskID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FinishTask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: FindRole */
#ifndef TOLUA_DISABLE_tolua_interface_FindRole00
static int tolua_interface_FindRole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  uint64_t qwID = ((uint64_t)  tolua_tonumber(tolua_S,1,0));
  {
   CRole* tolua_ret = (CRole*)  FindRole(qwID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CRole");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindRole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: CreateRole */
#ifndef TOLUA_DISABLE_tolua_interface_CreateRole00
static int tolua_interface_CreateRole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CRole* tolua_ret = (CRole*)  CreateRole();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CRole");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ReleaseRole */
#ifndef TOLUA_DISABLE_tolua_interface_ReleaseRole00
static int tolua_interface_ReleaseRole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRole* poRole = ((CRole*)  tolua_tousertype(tolua_S,1,0));
  {
   ReleaseRole(poRole);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseRole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_interface_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaResult_int_","LuaResult<int>","",tolua_collect_LuaResult_int_);
  #else
  tolua_cclass(tolua_S,"LuaResult_int_","LuaResult<int>","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaResult_int_");
   tolua_variable(tolua_S,"value",tolua_get_LuaResult_int__value,tolua_set_LuaResult_int__value);
   tolua_function(tolua_S,"new",tolua_interface_LuaResult_int__new00);
   tolua_function(tolua_S,"new_local",tolua_interface_LuaResult_int__new00_local);
   tolua_function(tolua_S,".call",tolua_interface_LuaResult_int__new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_LuaResult_int__delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaResult_int64_t_","LuaResult<int64_t>","",tolua_collect_LuaResult_int64_t_);
  #else
  tolua_cclass(tolua_S,"LuaResult_int64_t_","LuaResult<int64_t>","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaResult_int64_t_");
   tolua_variable(tolua_S,"value",tolua_get_LuaResult_int64_t__value,tolua_set_LuaResult_int64_t__value);
   tolua_function(tolua_S,"new",tolua_interface_LuaResult_int64_t__new00);
   tolua_function(tolua_S,"new_local",tolua_interface_LuaResult_int64_t__new00_local);
   tolua_function(tolua_S,".call",tolua_interface_LuaResult_int64_t__new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_LuaResult_int64_t__delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaResult_uint64_t_","LuaResult<uint64_t>","",tolua_collect_LuaResult_uint64_t_);
  #else
  tolua_cclass(tolua_S,"LuaResult_uint64_t_","LuaResult<uint64_t>","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaResult_uint64_t_");
   tolua_variable(tolua_S,"value",tolua_get_LuaResult_uint64_t__value,tolua_set_LuaResult_uint64_t__value);
   tolua_function(tolua_S,"new",tolua_interface_LuaResult_uint64_t__new00);
   tolua_function(tolua_S,"new_local",tolua_interface_LuaResult_uint64_t__new00_local);
   tolua_function(tolua_S,".call",tolua_interface_LuaResult_uint64_t__new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_LuaResult_uint64_t__delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaResult_double_","LuaResult<double>","",tolua_collect_LuaResult_double_);
  #else
  tolua_cclass(tolua_S,"LuaResult_double_","LuaResult<double>","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaResult_double_");
   tolua_variable(tolua_S,"value",tolua_get_LuaResult_double__value,tolua_set_LuaResult_double__value);
   tolua_function(tolua_S,"new",tolua_interface_LuaResult_double__new00);
   tolua_function(tolua_S,"new_local",tolua_interface_LuaResult_double__new00_local);
   tolua_function(tolua_S,".call",tolua_interface_LuaResult_double__new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_LuaResult_double__delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaResult_std__string_","LuaResult<std::string>","",tolua_collect_LuaResult_std__string_);
  #else
  tolua_cclass(tolua_S,"LuaResult_std__string_","LuaResult<std::string>","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaResult_std__string_");
   tolua_variable(tolua_S,"value",tolua_get_LuaResult_std__string__value,tolua_set_LuaResult_std__string__value);
   tolua_function(tolua_S,"new",tolua_interface_LuaResult_std__string__new00);
   tolua_function(tolua_S,"new_local",tolua_interface_LuaResult_std__string__new00_local);
   tolua_function(tolua_S,".call",tolua_interface_LuaResult_std__string__new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_LuaResult_std__string__delete00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"std",0);
  tolua_beginmodule(tolua_S,"std");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"vector_int_","std::vector<int>","",tolua_collect_std__vector_int_);
   #else
   tolua_cclass(tolua_S,"vector_int_","std::vector<int>","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"vector_int_");
    tolua_function(tolua_S,"clear",tolua_interface_std_vector_int__clear00);
    tolua_function(tolua_S,"size",tolua_interface_std_vector_int__size00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_int___geti00);
    tolua_function(tolua_S,".seti",tolua_interface_std_vector_int___seti00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_int___geti01);
    tolua_function(tolua_S,"push_back",tolua_interface_std_vector_int__push_back00);
    tolua_function(tolua_S,"new",tolua_interface_std_vector_int__new00);
    tolua_function(tolua_S,"new_local",tolua_interface_std_vector_int__new00_local);
    tolua_function(tolua_S,".call",tolua_interface_std_vector_int__new00_local);
    tolua_function(tolua_S,"delete",tolua_interface_std_vector_int__delete00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"vector_int64_t_","std::vector<int64_t>","",tolua_collect_std__vector_int64_t_);
   #else
   tolua_cclass(tolua_S,"vector_int64_t_","std::vector<int64_t>","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"vector_int64_t_");
    tolua_function(tolua_S,"clear",tolua_interface_std_vector_int64_t__clear00);
    tolua_function(tolua_S,"size",tolua_interface_std_vector_int64_t__size00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_int64_t___geti00);
    tolua_function(tolua_S,".seti",tolua_interface_std_vector_int64_t___seti00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_int64_t___geti01);
    tolua_function(tolua_S,"push_back",tolua_interface_std_vector_int64_t__push_back00);
    tolua_function(tolua_S,"new",tolua_interface_std_vector_int64_t__new00);
    tolua_function(tolua_S,"new_local",tolua_interface_std_vector_int64_t__new00_local);
    tolua_function(tolua_S,".call",tolua_interface_std_vector_int64_t__new00_local);
    tolua_function(tolua_S,"delete",tolua_interface_std_vector_int64_t__delete00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"vector_uint64_t_","std::vector<uint64_t>","",tolua_collect_std__vector_uint64_t_);
   #else
   tolua_cclass(tolua_S,"vector_uint64_t_","std::vector<uint64_t>","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"vector_uint64_t_");
    tolua_function(tolua_S,"clear",tolua_interface_std_vector_uint64_t__clear00);
    tolua_function(tolua_S,"size",tolua_interface_std_vector_uint64_t__size00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_uint64_t___geti00);
    tolua_function(tolua_S,".seti",tolua_interface_std_vector_uint64_t___seti00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_uint64_t___geti01);
    tolua_function(tolua_S,"push_back",tolua_interface_std_vector_uint64_t__push_back00);
    tolua_function(tolua_S,"new",tolua_interface_std_vector_uint64_t__new00);
    tolua_function(tolua_S,"new_local",tolua_interface_std_vector_uint64_t__new00_local);
    tolua_function(tolua_S,".call",tolua_interface_std_vector_uint64_t__new00_local);
    tolua_function(tolua_S,"delete",tolua_interface_std_vector_uint64_t__delete00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"vector_double_","std::vector<double>","",tolua_collect_std__vector_double_);
   #else
   tolua_cclass(tolua_S,"vector_double_","std::vector<double>","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"vector_double_");
    tolua_function(tolua_S,"clear",tolua_interface_std_vector_double__clear00);
    tolua_function(tolua_S,"size",tolua_interface_std_vector_double__size00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_double___geti00);
    tolua_function(tolua_S,".seti",tolua_interface_std_vector_double___seti00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_double___geti01);
    tolua_function(tolua_S,"push_back",tolua_interface_std_vector_double__push_back00);
    tolua_function(tolua_S,"new",tolua_interface_std_vector_double__new00);
    tolua_function(tolua_S,"new_local",tolua_interface_std_vector_double__new00_local);
    tolua_function(tolua_S,".call",tolua_interface_std_vector_double__new00_local);
    tolua_function(tolua_S,"delete",tolua_interface_std_vector_double__delete00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"vector_std__string_","std::vector<std::string>","",tolua_collect_std__vector_std__string_);
   #else
   tolua_cclass(tolua_S,"vector_std__string_","std::vector<std::string>","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"vector_std__string_");
    tolua_function(tolua_S,"clear",tolua_interface_std_vector_std__string__clear00);
    tolua_function(tolua_S,"size",tolua_interface_std_vector_std__string__size00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_std__string___geti00);
    tolua_function(tolua_S,".seti",tolua_interface_std_vector_std__string___seti00);
    tolua_function(tolua_S,".geti",tolua_interface_std_vector_std__string___geti01);
    tolua_function(tolua_S,"push_back",tolua_interface_std_vector_std__string__push_back00);
    tolua_function(tolua_S,"new",tolua_interface_std_vector_std__string__new00);
    tolua_function(tolua_S,"new_local",tolua_interface_std_vector_std__string__new00_local);
    tolua_function(tolua_S,".call",tolua_interface_std_vector_std__string__new00_local);
    tolua_function(tolua_S,"delete",tolua_interface_std_vector_std__string__delete00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"MAX_HP",MAX_HP);
  tolua_constant(tolua_S,"MAX_MP",MAX_MP);
  tolua_constant(tolua_S,"MAX_ROLE_COUNT",MAX_ROLE_COUNT);
  tolua_constant(tolua_S,"MAX_NAME_LEN",MAX_NAME_LEN);
  tolua_constant(tolua_S,"eTaskStateStart",eTaskStateStart);
  tolua_constant(tolua_S,"eTaskStateEnd",eTaskStateEnd);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"STaskInfo","STaskInfo","",tolua_collect_STaskInfo);
  #else
  tolua_cclass(tolua_S,"STaskInfo","STaskInfo","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"STaskInfo");
   tolua_function(tolua_S,"new",tolua_interface_STaskInfo_new00);
   tolua_function(tolua_S,"new_local",tolua_interface_STaskInfo_new00_local);
   tolua_function(tolua_S,".call",tolua_interface_STaskInfo_new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_STaskInfo_delete00);
   tolua_variable(tolua_S,"nTaskID",tolua_get_STaskInfo_nTaskID,tolua_set_STaskInfo_nTaskID);
   tolua_variable(tolua_S,"nTaskState",tolua_get_STaskInfo_nTaskState,tolua_set_STaskInfo_nTaskState);
   tolua_variable(tolua_S,"nTaskCondition",tolua_get_STaskInfo_nTaskCondition,tolua_set_STaskInfo_nTaskCondition);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SPos","SPos","",tolua_collect_SPos);
  #else
  tolua_cclass(tolua_S,"SPos","SPos","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SPos");
   tolua_function(tolua_S,"new",tolua_interface_SPos_new00);
   tolua_function(tolua_S,"new_local",tolua_interface_SPos_new00_local);
   tolua_function(tolua_S,".call",tolua_interface_SPos_new00_local);
   tolua_function(tolua_S,"new",tolua_interface_SPos_new01);
   tolua_function(tolua_S,"new_local",tolua_interface_SPos_new01_local);
   tolua_function(tolua_S,".call",tolua_interface_SPos_new01_local);
   tolua_function(tolua_S,"delete",tolua_interface_SPos_delete00);
   tolua_variable(tolua_S,"x",tolua_get_SPos_x,tolua_set_SPos_x);
   tolua_variable(tolua_S,"y",tolua_get_SPos_y,tolua_set_SPos_y);
   tolua_variable(tolua_S,"z",tolua_get_SPos_z,tolua_set_SPos_z);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CObj","CObj","",tolua_collect_CObj);
  #else
  tolua_cclass(tolua_S,"CObj","CObj","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CObj");
   tolua_function(tolua_S,"new",tolua_interface_CObj_new00);
   tolua_function(tolua_S,"new_local",tolua_interface_CObj_new00_local);
   tolua_function(tolua_S,".call",tolua_interface_CObj_new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_CObj_delete00);
   tolua_function(tolua_S,"SetObjID",tolua_interface_CObj_SetObjID00);
   tolua_function(tolua_S,"GetObjID",tolua_interface_CObj_GetObjID00);
   tolua_function(tolua_S,"GetObjID",tolua_interface_CObj_GetObjID01);
   tolua_function(tolua_S,"SetName",tolua_interface_CObj_SetName00);
   tolua_function(tolua_S,"GetName",tolua_interface_CObj_GetName00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CRole","CRole","CObj",tolua_collect_CRole);
  #else
  tolua_cclass(tolua_S,"CRole","CRole","CObj",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CRole");
   tolua_function(tolua_S,"new",tolua_interface_CRole_new00);
   tolua_function(tolua_S,"new_local",tolua_interface_CRole_new00_local);
   tolua_function(tolua_S,".call",tolua_interface_CRole_new00_local);
   tolua_function(tolua_S,"delete",tolua_interface_CRole_delete00);
   tolua_function(tolua_S,"SetMp",tolua_interface_CRole_SetMp00);
   tolua_function(tolua_S,"GetMp",tolua_interface_CRole_GetMp00);
   tolua_function(tolua_S,"SetHp",tolua_interface_CRole_SetHp00);
   tolua_function(tolua_S,"GetHp",tolua_interface_CRole_GetHp00);
   tolua_function(tolua_S,"AddMP",tolua_interface_CRole_AddMP00);
   tolua_function(tolua_S,"AddHP",tolua_interface_CRole_AddHP00);
   tolua_function(tolua_S,"SetPos",tolua_interface_CRole_SetPos00);
   tolua_function(tolua_S,"GetPos",tolua_interface_CRole_GetPos00);
   tolua_function(tolua_S,"AcceptTask",tolua_interface_CRole_AcceptTask00);
   tolua_function(tolua_S,"FinishTask",tolua_interface_CRole_FinishTask00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"FindRole",tolua_interface_FindRole00);
  tolua_function(tolua_S,"CreateRole",tolua_interface_CreateRole00);
  tolua_function(tolua_S,"ReleaseRole",tolua_interface_ReleaseRole00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_interface (lua_State* tolua_S) {
 return tolua_interface_open(tolua_S);
};
#endif


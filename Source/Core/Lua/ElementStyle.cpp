/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
 
#include "precompiled.h"
#include <Rocket/Core/Lua/LuaType.h>
#include <Rocket/Core/Lua/lua.hpp>
#include "ElementStyle.h"
#include <ElementStyle.h>

namespace Rocket {
namespace Core {
namespace Lua {


int ElementStyle__index(lua_State* L)
{
    /*the table obj and the missing key are currently on the stack(index 1 & 2) as defined by the Lua language*/
    int keytype = lua_type(L,2);
    if(keytype == LUA_TSTRING) //if we are trying to access a string, then we will assume that it is a property
    {
        ElementStyle* es = LuaType<ElementStyle>::check(L,1);
        if(es == NULL)
        {
            lua_pushnil(L);
            return 1;
        }
        const Property* prop = es->GetProperty(lua_tostring(L,2));
        if(prop == NULL)
        {
            lua_pushnil(L);
            return 1;
        }
        else
        {
            lua_pushstring(L,prop->ToString().CString());
            return 1;
        }
    }
    else //if it wasn't trying to get a string
    {
        lua_settop(L,2);
        return LuaType<ElementStyle>::index(L);
    }
}

int ElementStyle__newindex(lua_State* L)
{
    //[1] = obj, [2] = key, [3] = value
    ElementStyle* es = LuaType<ElementStyle>::check(L,1);
    if(es == NULL)
    {
        lua_pushnil(L);
        return 1;
    }
    int keytype = lua_type(L,2);
    int valuetype = lua_type(L,3);
    if(keytype == LUA_TSTRING )
    {
        const char* key = lua_tostring(L,2);
        if(valuetype == LUA_TSTRING)
        {
            const char* value = lua_tostring(L,3);
            lua_pushboolean(L,es->SetProperty(key,value));
            return 1; 
        }
        else if (valuetype == LUA_TNIL)
        {
            es->RemoveProperty(key);
            return 0;
        }
    }
    //everything else returns when it needs to, so we are safe to pass it
    //on if needed

    lua_settop(L,3);
    return LuaType<ElementStyle>::newindex(L);

}


int ElementStyleGetTable(lua_State* L, ElementStyle* obj)
{
    int index = 0;
    String key,sval;
    const Property* value;
    PseudoClassList pseudo;
    lua_newtable(L);
    while(obj->IterateProperties(index,pseudo,key,value))
    {
        lua_pushstring(L,key.CString());
        value->definition->GetValue(sval,*value);
        lua_pushstring(L,sval.CString());
        lua_settable(L,-3);
    }
    return 1;
}


RegType<ElementStyle> ElementStyleMethods[] = 
{
    LUAMETHOD(ElementStyle,GetTable)
    { NULL, NULL },
};

luaL_reg ElementStyleGetters[] = 
{
    { NULL, NULL },
};

luaL_reg ElementStyleSetters[] = 
{
    { NULL, NULL },
};

/*
template<> const char* GetTClassName<ElementStyle>() { return "ElementStyle"; }
template<> RegType<ElementStyle>* GetMethodTable<ElementStyle>() { return ElementStyleMethods; }
template<> luaL_reg* GetAttrTable<ElementStyle>() { return ElementStyleGetters; }
template<> luaL_reg* SetAttrTable<ElementStyle>() { return ElementStyleSetters; }
*/
}
}
}
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
 
#ifndef ROCKETCORELUAEVENT_H
#define ROCKETCORELUAEVENT_H
/*
    This defines an Event type name in the global Lua namespace

    Generally, you won't create an event yourself, just receive it.

    //method
    noreturn Event:StopPropagation()
    
    //getters
    Element Event.current_element
    string Event.type
    Element Event.target_element
    {}key=string,value=int,float,Colourb/f,string,Vector2f,userdata Event.parameters
*/

#include <Rocket/Core/Lua/LuaType.h>
#include <Rocket/Core/Lua/lua.hpp>

namespace Rocket {
namespace Core {
namespace Lua {
template<> bool LuaType<Event>::is_reference_counted();

//method
int EventStopPropagation(lua_State* L, Event* obj);

//getters
int EventGetAttrcurrent_element(lua_State* L);
int EventGetAttrtype(lua_State* L);
int EventGetAttrtarget_element(lua_State* L);
int EventGetAttrparameters(lua_State* L);

RegType<Event> EventMethods[];
luaL_reg EventGetters[];
luaL_reg EventSetters[];

/*
template<> const char* GetTClassName<Event>();
template<> RegType<Event>* GetMethodTable<Event>();
template<> luaL_reg* GetAttrTable<Event>();
template<> luaL_reg* SetAttrTable<Event>();
*/
}
}
}
#endif

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
 
#ifndef ROCKETCORELUAELEMENTDATAGRID_H
#define ROCKETCORELUAELEMENTDATAGRID_H
/*
    This defines the ElementDataGrid type in the Lua global namespace
    
    inherits from Element

    //methods
    noreturn ElementDataGrid:AddColumn(string fields, string formatter, float initial_width, string header_rml)
    noreturn ElementDataGrid:SetDataSource(string data_source_name)

    //getter
    {}key=int,value=ElementDataGridRow ElementDataGrid.rows
    --it returns a table, so you can acess it just like any other table. 
*/

#include <Rocket/Core/Lua/LuaType.h>
#include <Rocket/Core/Lua/lua.hpp>
#include <Rocket/Controls/ElementDataGrid.h>

using Rocket::Controls::ElementDataGrid;
namespace Rocket {
namespace Core {
namespace Lua {
//this will be used to "inherit" from Element
template<> void LuaType<ElementDataGrid>::extra_init(lua_State* L, int metatable_index);
template<> bool LuaType<ElementDataGrid>::is_reference_counted();

//methods
int ElementDataGridAddColumn(lua_State* L, ElementDataGrid* obj);
int ElementDataGridSetDataSource(lua_State* L, ElementDataGrid* obj);

//getter
int ElementDataGridGetAttrrows(lua_State* L);


RegType<ElementDataGrid> ElementDataGridMethods[];
luaL_reg ElementDataGridGetters[];
luaL_reg ElementDataGridSetters[];

/*
template<> const char* GetTClassName<ElementDataGrid>();
template<> RegType<ElementDataGrid>* GetMethodTable<ElementDataGrid>();
template<> luaL_reg* GetAttrTable<ElementDataGrid>();
template<> luaL_reg* SetAttrTable<ElementDataGrid>();
*/
}
}
}
#endif

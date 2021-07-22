#include "gtest.h"

#include "interface.sol.h"
#include "sol/sol.hpp"
#include "player.h"

TEST(DoSol, DoSol)
{
    sol::state lua;

    lua.open_libraries();
    lua.require("interface", sol::c_call<decltype(&luaopen_interface), &luaopen_interface>);

    auto script_result = lua.safe_script(R"(
        module("interface", package.seeall)
        local p = CPlayer.new()
        p:Init()
        p:NotChange()
        p:OnChange()
        print("[1]" .. GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(GNextID())
        print("[3]" .. p:GetObjID())
        print("[4]" .. p:GetHP())
        print("[5]" .. CPlayer.NextID())
        )", sol::script_throw_on_error);
    ASSERT_TRUE(script_result.valid());
}

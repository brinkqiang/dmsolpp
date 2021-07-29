#include "gtest.h"

#include "interface.sol.h"
#include "player.h"
#include "dmlua.h"

TEST(DoSol, DoSol)
{
    CDMLuaEngine oDMLuaEngine;

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR);
    auto state = oDMLuaEngine.GetSol();
    state.require("interface", sol::c_call<decltype(&luaopen_interface), &luaopen_interface>);

    //if (!oDMLuaEngine.ReloadScript())
    //{
    //    ASSERT_TRUE(0);
    //    return;
    //}

    auto script_result = state.safe_script(R"(
        module("interface", package.seeall)
        local p = CPlayer.new()
        p:Init()
        p:NotChange()
        p:OnChange()
        print("[1]" .. GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. CPlayer.NextID())
        )", sol::script_throw_on_error);
    ASSERT_TRUE(script_result.valid());
}

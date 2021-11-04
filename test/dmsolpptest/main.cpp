#include "gtest.h"
#include <cstddef>
#include "interface.sol.h"
#include "player.h"
#include "dmsolpp.h"

TEST(DoSolModule, DoSolModule)
{
    auto module = dmsolppGetModule();
    if (nullptr == module)
    {
        return;
    }

    CDMLuaEngine& oDMLuaEngine = module->GetDMLuaEngine();

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    oDMLuaEngine.AddModule(require_interface);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    oDMLuaEngine.DoString(R"(
        module("interface", package.seeall)
        local p = CPlayer.new()
        p:Init()
        p:NotChange()
        p.OnChange = function (self) print("OnChange in lua") end
        p:OnChange()
        print(MAX_NAME_LEN)
        print("[1]" .. GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. CPlayer.NextID())
        )");

    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    auto state = oDMLuaEngine.GetSol();

    int num = state["add"](1, 2);

    int num2 = oDMLuaEngine.CallT<int>("add", 1, 2);

    CPlayer oPlayer;
    int num3 = state["test"]["main"]["dowork"](&oPlayer);

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

TEST(DoSol, DoSol)
{
    CDMLuaEngine oDMLuaEngine;

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    oDMLuaEngine.AddModule(require_interface);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    oDMLuaEngine.DoString(R"(
        module("interface", package.seeall)
        local p = CPlayer.new()
        p:Init()
        p:NotChange()
        p:OnChange()
        print(MAX_NAME_LEN)
        print("[1]" .. GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. CPlayer.NextID())
        )");

    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    auto state = oDMLuaEngine.GetSol();

    int num = state["add"](1, 2);

    int num2 = oDMLuaEngine.CallT<int>("add", 1 , 2);

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

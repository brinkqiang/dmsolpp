#include "gtest.h"
#include <cstddef>
#include "interface.sol.h"
#include "player.h"
#include "dmsolpp.h"

TEST(DoSolpp, DoSolpp)
{
    CDMLuaEngine oDMLuaEngine;

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    // �����Զ������ɴ��� ģ�飬 ������ж��ģ�飬��Ҫ��������Ӷ��
    oDMLuaEngine.AddModule(require_interface);

    // ʹ��dmlua��load ��Ҫ���������Զ�loadָ��Ŀ¼�������ļ�. sol���汾��û��ʵ���������.
    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    oDMLuaEngine.DoString(R"(
        function addplayer(player)
            print("[addplayer]: " .. player:GetName())
            return 1
        end
        )");

    // ��ȡsol����
    auto state = oDMLuaEngine.GetSol();

    int num = state["add"](1, 2);

    CPlayer oPlayer(5, "zhangsan");
    int ret = state["test"]["main"]["dowork"](&oPlayer);

    int ret2 = state["addplayer"](oPlayer);

    auto script_result = state.safe_script(R"(
        local interface = require("interface")

        local p = interface.CPlayer.new()
        p:Init()
        p:NotChange()
        p:OnChange()
        print("[1]" .. interface.GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(interface.GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(interface.GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. interface.CPlayer.NextID())
        )", sol::script_throw_on_error);
    ASSERT_TRUE(script_result.valid());
}


TEST(DoluaEngine, DoluaEngine)
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
        local interface = require("interface")
        local p = interface.CPlayer.new()
        p:Init()
        p:NotChange()
        p.OnChange = function (self) print("OnChange in lua") end
        p:OnChange()
        print(MAX_NAME_LEN)
        print("[1]" .. interface.GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(interface.GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(interface.GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. interface.CPlayer.NextID())
        )");

    oDMLuaEngine.DoString(R"(
        local interface = require("interface")
        local p = interface.create_player();

        local p2 = interface.find_player(p:GetObjID());
        p2:Init()
        p2:NotChange()
        p2.OnChange = function (self) print("OnChange in lua") end
        p2:OnChange()

        interface.release_player(p:GetObjID())
        )");

    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    int num = oDMLuaEngine.CallT<int>("add", 1, 2);

    oDMLuaEngine.DoString(R"(
        local interface = require("interface")

        local p = interface.CPlayer.new()
        p:Init()
        p:NotChange()
        p:OnChange()
        print("[1]" .. interface.GNextID())
        print("[2]" .. p.NextID())
        p:SetObjID(interface.GNextID())
        print("[3]" .. p:GetObjID())
        p:SetHP(interface.GNextID())
        print("[4]" .. p:GetHP())
        print("[5]" .. interface.CPlayer.NextID())
        )");
}

#include "gtest.h"
#include <cstddef>
#include "interface.sol.h"
#include "player.h"
#include "dmsolpp.h"
#include "dmformat.h"

TEST(dmluatest_solpp, dmluatest_solpp)
{
    CDMLuaEngine oDMLuaEngine;

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    // 加载自动化生成代码 模块， 如果你有多个模块，需要在这里添加多个
    oDMLuaEngine.AddModule(require_interface);

    // 使用dmlua来load 主要是他可以自动load指定目录的所有文件. sol引擎本身没有实现这个功能.
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

    // 获取sol引擎
    auto state = oDMLuaEngine.GetSol();

    int num = state["add"](1, 2);

    CPlayer oPlayer(5, "zhangsan");
    int ret = state["test"]["main"]["dowork"](&oPlayer);

    int ret2 = state["addplayer"](oPlayer);

    // 通过lua脚本实现的对象管理器进行对象创建 对象生命周期由lua负责 reload 之后数据丢失
    auto script_result = state.safe_script(R"(
        local interface = require("interface")
        local player_mgr = require("player")
        local player = player_mgr.create_player()
        local p = player_mgr.find_player(player:GetObjID())

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
        player_mgr.release_player(p)
        print("in sol2.lua player_mgr.create_player");
        )", sol::script_throw_on_error);
    ASSERT_TRUE(script_result.valid());

    // 通过导入的C++对象管理器进行对象创建 对象生命周期由C++负责 reload 之后数据还在
    auto script_result2 = state.safe_script(R"(
        local interface = require("interface")
        local player = interface.create_player();

        local p = interface.find_player(player:GetObjID());
        p:Init()
        p:NotChange()
        p.OnChange = function (self) print("OnChange in lua") end
        p:OnChange()

        interface.release_player(player:GetObjID())
        print("in sol2.cpp player_mgr.create_player");
        )", sol::script_throw_on_error);
    ASSERT_TRUE(script_result2.valid());
}


TEST(dmluatest_engine, dmluatest_engine)
{
    // 使用接口的方式提供所有功能。
    auto module = dmsolppGetModule();
    if (nullptr == module)
    {
        return;
    }

    CDMLuaEngine& oDMLuaEngine = *module->GetDMLuaEngine();

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    oDMLuaEngine.AddModule(require_interface);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    // 通过lua脚本实现的对象管理器进行对象创建 对象生命周期由lua负责 reload 之后数据丢失
    oDMLuaEngine.DoString(R"(
        local interface = require("interface")
        local player_mgr = require("player")
        local player = player_mgr.create_player()
        local p = player_mgr.find_player(player:GetObjID())

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
        player_mgr.release_player(p)
        print("in oDMLuaEngine.lua player_mgr.create_player");
        )");


    // 通过导入的C++对象管理器进行对象创建 对象生命周期由C++负责 reload 之后数据还在.
    oDMLuaEngine.DoString(R"(
        local interface = require("interface")
        local player = interface.create_player();

        local p = interface.find_player(player:GetObjID());
        p:Init()
        p:NotChange()
        p.OnChange = function (self) print("OnChange in lua") end
        p:OnChange()

        interface.release_player(player:GetObjID())
        print("in oDMLuaEngine.cpp player_mgr.create_player");
        )");

    // 测试普通lua全局函数
    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    int num = oDMLuaEngine.CallT<int>("add", 1, 2);
}

const int PERF_COUNT = 1 * 10000;

TEST(dmluatest_tolua_perf, dmluatest_tolua_perf)
{
    // 使用接口的方式提供所有功能。
    auto module = dmsolppGetModule();
    if (nullptr == module)
    {
        return;
    }

    CDMLuaEngine& oDMLuaEngine = *module->GetDMLuaEngine();

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    oDMLuaEngine.AddModule(require_interface);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    // 测试普通lua全局函数
    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");
    uint64_t total = 0;
    for (int i=0; i < PERF_COUNT; i++)
    {
        int num = oDMLuaEngine.CallT<int>("add", 1, 2);
        total += num;
    }

    fmt::print("total = {}\n", total);
}

TEST(dmluatest_sol_perf, dmluatest_sol_perf)
{
    // 使用接口的方式提供所有功能。
    auto module = dmsolppGetModule();
    if (nullptr == module)
    {
        return;
    }

    CDMLuaEngine& oDMLuaEngine = *module->GetDMLuaEngine();

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    oDMLuaEngine.AddModule(require_interface);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    // 测试普通lua全局函数
    oDMLuaEngine.DoString(R"(
        function add(a , b)
            return a + b
        end
        )");

    auto state = oDMLuaEngine.GetSol();
    auto add = state["add"];

    uint64_t total = 0;
    for (int i = 0; i < PERF_COUNT; i++)
    {
        int num = add(1, 2);
        total += num;
    }

    fmt::print("total = {}\n", total);

}

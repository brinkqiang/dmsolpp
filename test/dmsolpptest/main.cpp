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

#include <string>

struct EventData {
    std::string category;
    int severity;
    std::string eventName;
    std::string resultCode;
};

class ILuaEventFilterRunner {
public:
    virtual ~ILuaEventFilterRunner() = default;
    virtual bool runFilter(sol::state_view lua_State, const EventData& event_data, const std::string& lua_function_name) const = 0;
};

class LuaScriptEventFilterRunner : public ILuaEventFilterRunner {
public:
    bool runFilter(sol::state_view lua_State, const EventData& event_data, const std::string& lua_function_name) const override {
        sol::protected_function lua_filter_func = lua_State[lua_function_name];

        if (!lua_filter_func.valid()) {
            std::cerr << "Error: Lua function '" << lua_function_name << "' not found." << std::endl;
            return false;
        }

        sol::table event_table = lua_State.create_table_with(
            "category", event_data.category,
            "severity", event_data.severity,
            "eventName", event_data.eventName,
            "resultCode", event_data.resultCode
        );

        sol::protected_function_result result = lua_filter_func(event_table);

        if (result.valid()) {
            if (result.get_type() == sol::type::boolean) {
                return result.get<bool>();
            }
            else {
                std::cerr << "Error: Lua function '" << lua_function_name << "' did not return a boolean." << std::endl;
                return false;
            }
        }
        else {
            sol::error err = result;
            std::cerr << "Error executing Lua function '" << lua_function_name << "': " << err.what() << std::endl;
            return false;
        }
    }
};

TEST(EventData, event)
{
    // 使用接口的方式提供所有功能。
    auto module = dmsolppGetModule();
    if (nullptr == module)
    {
        return;
    }

    CDMLuaEngine& oDMLuaEngine = *module->GetDMLuaEngine();

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }
    auto state = oDMLuaEngine.GetSol();
    state["count"] = 0;

    oDMLuaEngine.DoString(R"(
    -- event_filter.lua

    local function string_contains_ci(text, pattern)
        if type(text) ~= "string" or type(pattern) ~= "string" then
            return false
        end
        if pattern == "" then return true end
        if text == "" and pattern ~= "" then return false end
        return string.find(string.lower(text), string.lower(pattern), 1, true) ~= nil
    end

    local function string_contains_cs(text, pattern)
        if type(text) ~= "string" or type(pattern) ~= "string" then
            return false
        end
        if pattern == "" then return true end
        if text == "" and pattern ~= "" then return false end
        return string.find(text, pattern, 1, true) ~= nil
    end

    function evaluate_event(event)
        if type(event) ~= "table" then
            -- print("Error: event data is not a table")
            return false
        end

        local category = event.category
        local severity = event.severity
        local eventName = event.eventName
        local resultCode = event.resultCode

        local categoryMatch = (category == "有害程序" or category == "网络攻击" or category == "信息破坏")
        local severityMatch = (severity == 2 or severity == 3 or severity == 4)

        local eventNameCond1 = not string_contains_cs(eventName, "畸形漏洞")
        local eventNameCond2 = string_contains_ci(eventName, "DNs")
        local eventNameCond3 = string_contains_ci(eventName, "恶意爬虫")
        local eventNameCond4 = string_contains_ci(eventName, "工具扫描")
        local eventNameCond5 = not string_contains_cs(eventName, "扫描工具")
        local eventNameCond6 = (eventName ~= "服务器敏感目录访问")
        local eventNameCond7 = (eventName ~= "Dos攻击日志")
        local eventNameCond8 = (eventName ~= "SNMP使用默认的社区串")

        local part1ConditionsMet = categoryMatch and
                                  severityMatch and
                                  eventNameCond1 and
                                  eventNameCond2 and
                                  eventNameCond3 and
                                  eventNameCond4 and
                                  eventNameCond5 and
                                  eventNameCond6 and
                                  eventNameCond7 and
                                  eventNameCond8
    
        local part2ConditionsMet = (eventName == "服务器敏感目录访问" and resultCode ~= "200")

        count = count + 1
        return part1ConditionsMet or part2ConditionsMet
    end
        )");

    LuaScriptEventFilterRunner runner;

    // 示例事件1 (预期通过 Part1)
    EventData event1 = {"有害程序", 3, "Contains DNs and 恶意爬虫 with 工具扫描", "500"};

    for (int i=0; i < 100 * 10000; i++)
    {
        bool result1 = runner.runFilter(oDMLuaEngine.GetSol(), event1, "evaluate_event");
    }
    int count = state["count"];

    std::cout << count << std::endl;
}
#include "role/rolemgr.h"
#include "role/role.h"
#include "gtest/gtest.h"
#include "dmlua.h"
#include "dmutil.h"
#include "script/interface.h"

#define DMLUA_TEST_COUNT 10000

TEST(luabasetest, luabasetest)
{
    CDMLuaEngine oDMLuaEngine;
    /// The default search path is to search the root directory with the exe program /../ relative path (because cmake will add the $BUILD_TYPE directory to the generated bin directory.)
    /// If you need to modify to other paths, please set your own search path

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR);

    oDMLuaEngine.AddModule(tolua_interface_open);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    oDMLuaEngine.DoString(R"(
        function addtest()
           local a = 100000000
           local b = 100000000
           local c = a * b
           print(c)
        end
        )");
    {
        for (int i = 0; i < 1; ++i)
        {
            int r = oDMLuaEngine.Call("addtest");
        }
    }

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }

    oDMLuaEngine.DoString(R"(
        function addex(first, second)
            print("overflow -> " .. first * second)
            return first * second
        end
        )");
    {
        for (int i = 0; i < 1; ++i)
        {
            uint64_t r = oDMLuaEngine.CallT<uint64_t>("addex", 4294967295,
                4294967295);

            if (r >= 0)
            {
                std::cout << r << std::endl;
                EXPECT_TRUE(r == 4294967295ULL * 4294967295ULL);
            }
        }
    }
    {
        oDMLuaEngine.DoString(R"(
            function script.task.taskinfo()
               local task = STaskInfo:new()
               task.nTaskID = 1002
               task.nTaskState = 2
               task.nTaskCondition = 2
               return task
            end
            )");

        STaskInfo sInfo = oDMLuaEngine.CallT<STaskInfo>("script.task.taskinfo");

        std::cout << sInfo.nTaskID << std::endl;
    }
    {
        oDMLuaEngine.DoString(R"(
            function script.task.taskinfo(task)
               task.nTaskID = 1003
               task.nTaskState = 1
               task.nTaskCondition = 0
            end
            )");
        STaskInfo sInfo;
        int r = oDMLuaEngine.Call("script.task.taskinfo", &sInfo);

        if (r >= 0)
        {
            std::cout << sInfo.nTaskID << std::endl;
        }
    }
    {
        oDMLuaEngine.DoString(R"(
            function bintest(data)
               print(string.len(data))
            print(data)
            end
            )");
        std::string strData = "12345";
        strData.append("\0", 1);
        strData.append("ABCDE", 5);
        int r = oDMLuaEngine.Call("bintest", strData);

        if (r >= 0)
        {
            ;
        }
    }

    CRole* poRole = CRoleMgr::Instance()->CreateRole();
    poRole->SetName("andy");
    poRole->SetHp(9999);
    poRole->SetMp(9999);
    unsigned int dwTaskID = 100;

    LResultINT oResult(-1);
    oDMLuaEngine.Call("script.task.task.AcceptTask", poRole->GetObjID(), dwTaskID, &oResult);

    oDMLuaEngine.Call("script.task.task.FinishTask", poRole->GetObjID(), dwTaskID);
    std::vector<std::string> vecData;
    vecData.push_back("hello");
    oDMLuaEngine.Call("script.common.test.main_vector", &vecData);
    oDMLuaEngine.Call("script.common.test.main");
    oDMLuaEngine.Call("script.common.clone.main");
    CRoleMgr::Instance()->ReleaseRole(poRole);
}


TEST(luatype, luatype) {
    CDMLuaEngine oDMLuaEngine;
    /// The default search path is to search the root directory with the exe program /../ relative path (because cmake will add the $BUILD_TYPE directory to the generated bin directory.)
    /// If you need to modify to other paths, please set your own search path

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR);

    oDMLuaEngine.AddModule(tolua_interface_open);

    if (!oDMLuaEngine.ReloadScript())
    {
        ASSERT_TRUE(0);
        return;
    }
    char chData = 1;
    uint16_t wData = 2;
    uint32_t dwData = 3;
    uint64_t qwData = 12345678987654321;
    int16_t sData = 5;
    int32_t nData = 6;
    int64_t llData = 7;
    float fData = 8;
    double dbData = 12345678987654321;

    oDMLuaEngine.Call("script.type.type.TypeTest", chData, wData, dwData, qwData, sData, nData, llData, fData, dbData);
}
//
//TEST(luaload, luaload) {
//    if (!CDMLuaEngine::Instance()->ReloadScript()) {
//        ASSERT_TRUE(0);
//        return;
//    }
//
//    CDMLuaEngine::Instance()->DoString(
//        "function Sqrt(x\n)"
//        "MAX_LOOP = 100000000\n"
//        "z = 1.0\n"
//        "for i = 1, MAX_LOOP do\n"
//        "z = z - (z*z - x) / (2 * z)\n"
//        "end\n"
//        "return z\n"
//        "end\n");
//}
//
//TEST(lua_empty_call, lua_empty_call) {
//    CDMLuaEngine oDMLuaEngine;
//    if (!oDMLuaEngine.ReloadScript()) {
//        ASSERT_TRUE(0);
//        return;
//    }
//    oDMLuaEngine.DoString(
//        "function performancetest()\n"
//        "end\n");
//
//    for (int i = 0; i < DMLUA_TEST_COUNT; ++i) {
//        oDMLuaEngine.Call("performancetest");
//    }
//}

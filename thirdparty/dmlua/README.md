# dmlua

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmlua](https://img.shields.io/badge/brinkqiang-dmlua-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmlua)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmlua/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmlua.svg?label=Stars)](https://github.com/brinkqiang/dmlua) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmlua.svg?label=Fork)](https://github.com/brinkqiang/dmlua)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmlua/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmlua/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmlua/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmlua/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmlua/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmlua/actions/workflows/win.yml "win build status"

## Intro
Lua fully automated engine, based on tolua++, support lua 5.1-5.4
```cpp
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
            uint64_t r = oDMLuaEngine.CallT<uint64_t>("addex", 4294967295ULL,
                         4294967295ULL);

            if (r >= 0)
            {
                std::cout << r << std::endl;
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
    oDMLuaEngine.Call("script.task.task.AcceptTask", poRole, dwTaskID, &oResult);

    oDMLuaEngine.Call("script.task.task.FinishTask", poRole, dwTaskID);
    std::vector<std::string> vecData;
    vecData.push_back("hello");
    oDMLuaEngine.Call("script.common.test.main_vector", &vecData);
    oDMLuaEngine.Call("script.common.test.main");
    CRoleMgr::Instance()->ReleaseRole(poRole);
}
```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmlua/Lobby.svg)](https://gitter.im/brinkqiang/dmlua)

## Thanks
gavingqf@126.com

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
#include "test/role/rolemgr.h"
#include "test/role/role.h"
#include "dmlua.h"
#include "gtest/gtest.h"

TEST( luatest, luatest ) {
    CDMLuaEngine oDMLuaEngine;

    if ( !oDMLuaEngine.ReloadScript() ) {
        return;
    }

    oDMLuaEngine.DoString(
        "function addtest()\n"
        "   local a = 100000000\n"
        "   local b = 100000000\n"
        "   local c = a * b\n"
        "   print(c)\n"
        "end\n" );
    {
        for ( int i = 0; i < 1; ++i ) {
            int r = oDMLuaEngine.Call( "addtest" );
        }
    }

    if ( !oDMLuaEngine.ReloadScript() ) {
        return;
    }
    
    oDMLuaEngine.DoString(
        "function addex(first, second)\n"
        "   return first * second\n"
        "end\n" );
    {
        for ( int i = 0; i < 1; ++i ) {
            uint64_t r = oDMLuaEngine.CallT<uint64_t>("addex", 100000000LL, 100000000LL);

            if ( r >= 0 ) {
                std::cout << r << std::endl;
            }
        }
    }
    
    oDMLuaEngine.DoString(
        "function addex(first, second, res)\n"
        "   res.value = first * second\n"
        "end\n" );
    {
        LResultINT64 resAdd( -1 );

        for ( int i = 0; i < 1; ++i ) {
            int r = oDMLuaEngine.Call( "addex", 100000000LL, 100000000LL, &resAdd );

            if ( r >= 0 ) {
                std::cout << resAdd.value << std::endl;
            }
        }
    }
    {
        oDMLuaEngine.DoString(
            "function script.task.taskinfo(task)\n"
            "   task.nTaskID = 1002\n"
            "   task.nTaskState = 2\n"
            "   task.nTaskCondition = 2\n"
            "end\n" );
        STaskInfo sInfo;
        int r = oDMLuaEngine.Call( "script.task.taskinfo", &sInfo );

        if ( r >= 0 ) {
            std::cout << sInfo.nTaskID << std::endl;
        }
    }
    {
        oDMLuaEngine.DoString(
            "function script.task.taskinfo(task)\n"
            "   task.nTaskID = 1003\n"
            "   task.nTaskState = 1\n"
            "   task.nTaskCondition = 0\n"
            "end\n" );
        STaskInfo sInfo;
        int r = oDMLuaEngine.Call( "script.task.taskinfo", &sInfo );

        if ( r >= 0 ) {
            std::cout << sInfo.nTaskID << std::endl;
        }
    }
    CRole* poRole = CRoleMgr::Instance()->CreateRole();
    poRole->SetName( "andy" );
    poRole->SetHp( 9999 );
    poRole->SetMp( 9999 );
    unsigned int dwTaskID = 100;
    LResultINT oResult( -1 );
    oDMLuaEngine.Call( "script.task.task.AcceptTask", poRole, dwTaskID, &oResult );
    oDMLuaEngine.Call( "script.task.task.FinishTask", poRole, dwTaskID );
    std::vector<std::string> vecData;
    vecData.push_back( "hello" );
    oDMLuaEngine.Call( "script.common.test.main", &vecData );
    oDMLuaEngine.Call( "script.config.loadcsv.main" );
    CRoleMgr::Instance()->ReleaseRole( poRole );
}
```
## lua modules

[![lua53](https://img.shields.io/badge/lua53-7AD6FD.svg)](https://github.com/brinkqiang/lua53)

[![luapb](https://img.shields.io/badge/luapb-7AD6FD.svg)](https://github.com/brinkqiang/luapb)

[![luacrypto](https://img.shields.io/badge/luacrypto-7AD6FD.svg)](https://github.com/brinkqiang/luacrypto)

[![luahttpclient](https://img.shields.io/badge/luahttpclient-7AD6FD.svg)](https://github.com/brinkqiang/luahttpclient)

[![luamysql](https://img.shields.io/badge/luamysql-7AD6FD.svg)](https://github.com/brinkqiang/luamysql)

[![luaredis](https://img.shields.io/badge/luaredis-7AD6FD.svg)](https://github.com/brinkqiang/luaredis)

[![luatimer](https://img.shields.io/badge/luatimer-7AD6FD.svg)](https://github.com/brinkqiang/luatimer)

[![luacsv](https://img.shields.io/badge/luacsv-7AD6FD.svg)](https://github.com/brinkqiang/luacsv)

[![luautf8](https://img.shields.io/badge/luautf8-7AD6FD.svg)](https://github.com/brinkqiang/luautf8)

[![luaprofiler](https://img.shields.io/badge/luaprofiler-7AD6FD.svg)](https://github.com/brinkqiang/luaprofiler)

[![luatime](https://img.shields.io/badge/luatime-7AD6FD.svg)](https://github.com/brinkqiang/luatime)

[![luajson](https://img.shields.io/badge/luajson-7AD6FD.svg)](https://github.com/brinkqiang/luajson)

[![luaxml](https://img.shields.io/badge/luaxml-7AD6FD.svg)](https://github.com/brinkqiang/luaxml)
```lua
-- lua script
module (..., package.seeall)

local pb = require("luapb")
pb.import("net.proto")

print("ID2Name: " .. pb.id2name(8345))
print("Name2ID: " .. pb.name2id("net.tb_Person"))

function tbcreate()
    local msg = pb.new("net.tb_Person")
    msg.number = "13615632545
    msg.email = "13615632545@163.com"
    msg.age = 28
    msg.ptype = 2
    msg.desc:add("first")
    msg.desc:add("second")
    msg.desc:add("three")
end

function pbtest()
    local msg = pb.new("net.tb_Person")
    msg.number = "13615632545"
    msg.email = "13615632545@163.com"
    msg.age = 28
    msg.ptype = 2
    msg.desc:add("first")
    msg.desc:add("second")
    msg.desc:add("three")

    local binstr = pb.serializeToString(msg)
    local msg2 = pb.new("net.tb_Person")
    pb.parseFromString(msg2, binstr)

    print("pbtest " .. binstr)
end

function pbtest2()
    local msg = pb.new("net.tb_Person")
    msg.number = "13615632545"
    msg.email = "13615632545@163.com"
    msg.age = 28
    msg.ptype = 2
    msg.desc:add("first")
    msg.desc:add("second")
    msg.desc:add("three")

    for i = 1,1000000 do
        local binstr = pb.serializeToString(msg)
        local msg2 = pb.new("net.tb_Person")
        pb.parseFromString(msg2, binstr)
    end
end

function pbtest3() 
    local message = {
        number = "13615632545",
        email = "13615632545@163.com",
        age = 28,
        ptype = "WORK",
        desc = {"first", "second", "three"}
    }
    for k, v in pairs(message) do
        print(type(v))
        print(k)
    end

    local buffer = pb.encode("net.tb_Person", message)
    local msg = pb.decode("net.tb_Person", buffer)

    assert(msg.number == "13615632545")
    assert(msg.email == "13615632545@163.com")
    assert(msg.age == 28)
    assert(msg.ptype == "WORK")
    assert(msg.desc[1] == "first")
    assert(msg.desc[2] == "second")
    assert(msg.desc[3] == "three")

    print("pbtest3 " .. buffer)
end

pbtest()
```


## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmlua/Lobby.svg)](https://gitter.im/brinkqiang/dmlua)

## Thanks
gavingqf@126.com

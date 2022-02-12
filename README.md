# dmsolpp

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmsolpp](https://img.shields.io/badge/brinkqiang-dmsolpp-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmsolpp)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmsolpp/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmsolpp.svg?label=Stars)](https://github.com/brinkqiang/dmsolpp) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmsolpp.svg?label=Fork)](https://github.com/brinkqiang/dmsolpp)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmsolpp/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmsolpp/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmsolpp/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmsolpp/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmsolpp/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmsolpp/actions/workflows/win.yml "win build status"

## Intro
dmsolpp

command
```
dmsolpp --PKG=interface.pkg
```
output
```
interface.sol.cc
interface.sol.h
```


```cpp
#include "gtest.h"
#include <cstddef>
#include "interface.sol.h"
#include "player.h"
#include "dmsolpp.h"

TEST(DoSolModule, DoSolModule)
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
```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmsolpp/Lobby.svg)](https://gitter.im/brinkqiang/dmsolpp)

## Thanks

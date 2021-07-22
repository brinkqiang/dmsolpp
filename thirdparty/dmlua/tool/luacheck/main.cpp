
#include "dmlua.h"

TOLUA_API int  tolua_interface_open(lua_State* tolua_S) {
    return 0;
}

int main(int argc, char** argv) {

    CDMLuaEngine oDMLuaEngine;

    if (!oDMLuaEngine.ReloadScript()) {
        return -1;
    }

    return 0;
}

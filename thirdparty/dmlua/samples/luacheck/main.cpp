
#include "dmlua.h"


int main(int argc, char** argv) {

    CDMLuaEngine oDMLuaEngine;

    std::string strScriptRootPath = DMGetRootPath();
    oDMLuaEngine.SetRootPath(strScriptRootPath + PATH_DELIMITER_STR + ".." + PATH_DELIMITER_STR + "script");

    if (!oDMLuaEngine.ReloadScript()) {
        return -1;
    }

    return 0;
}

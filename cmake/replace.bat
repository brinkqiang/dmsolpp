dmreplacefile --SRCFILE="ModuleImport.cmake" --TPLFILE="ModuleImport.cmake" --PATH="..\thirdparty"

dmreplacefile --SRCFILE="ModuleImport.cmake" --TPLFILE="ModuleImport.cmake" --PATH="..\src"

dmreplacefile --SRCFILE="ModuleCompileOptions.cmake" --TPLFILE="ModuleCompileOptions.cmake" --PATH="..\thirdparty"
dmreplacefile --SRCFILE="ModuleCompileOptions.cmake" --TPLFILE="ModuleCompileOptions.cmake" --PATH="..\src"

dmreplacefile --SRCFILE="cmake_uninstall.cmake.in" --TPLFILE="cmake_uninstall.cmake.in" --PATH="..\thirdparty"
dmreplacefile --SRCFILE="cmake_uninstall.cmake.in" --TPLFILE="cmake_uninstall.cmake.in" --PATH="..\src"

PAUSE
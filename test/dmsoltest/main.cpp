#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <iostream>

int main() {
    std::cout << "=== override-able member functions ===" << std::endl;

    struct thingy {
        thingy(){
        }

        virtual void paint() {
            std::cout << "paint in cpp" << std::endl;
        }
    };

    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.new_usertype<thingy>("thingy",
        sol::constructors<thingy()>(),
        "paint", &thingy::paint);

    sol::string_view code = R"(
    obj = thingy.new()
    obj:paint()
    obj.paint = function (self) print("paint in lua") end
    obj:paint()
    function obj:paint () print("paint in lua2") end
    obj:paint()
    )";

    lua.safe_script(code);

    std::cout << std::endl;

    return 0;
}
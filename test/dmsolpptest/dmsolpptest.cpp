
#include "dmsolpp.h"

int main( int argc, char* argv[] ) {

    Idmsolpp* module = dmsolppGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}

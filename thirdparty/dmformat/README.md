# dmformat

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

## Intro
C++11 string format lib, based on fmt.
```cpp

#include "dmformat.h"
#include "dmtime.h"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

int main()
{
    std::cout << fmt::format("{0},{1},{2}", "a", "b", "c") << std::endl;
    std::cout << fmt::format("{2},{1},{0}", "a", "b", "c") << std::endl;
    std::cout << fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(time(NULL))) << std::endl;

    std::cout << fmt::lexical_cast<float>(fmt::to_string(std::numeric_limits<float>::max())) << std::endl;
    std::cout << fmt::lexical_cast<double>(fmt::to_string(std::numeric_limits<double>::max())) << std::endl;
    std::cout << fmt::lexical_cast<long double>(fmt::to_string(std::numeric_limits<long double>::max())) << std::endl;
    std::cout << fmt::lexical_cast<int>(fmt::to_string(std::numeric_limits<int>::max())) << std::endl;
    std::cout << fmt::lexical_cast<int>(fmt::to_string(std::numeric_limits<int>::min())) << std::endl;

    std::cout << fmt::lexical_cast<long long>(fmt::to_string(std::numeric_limits<long long>::max())) << std::endl;
    std::cout << fmt::lexical_cast<unsigned long long>(fmt::to_string(std::numeric_limits<unsigned long long>::max())) << std::endl;

    std::cout << fmt::format("{}{}{}{}{}{}{}{}{}{}{}{}",
        1, 2, 3, 4, 5, 6, 'a', 'b', 'c', 'd', 'e', 'f') << std::endl;

    std::cout << fmt::format("{_1}/{a_}/{A_}", fmt::arg("a_", 'a'),
        fmt::arg("A_", "A"), fmt::arg("_1", 1)) << std::endl;

    char name[] = "fmt";
    std::string strName = "{}";
    strName = fmt::format(strName, name);

    return 0;
}

```

## Thanks

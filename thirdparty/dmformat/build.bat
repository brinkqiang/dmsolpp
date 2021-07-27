rmdir /S /Q build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=relwithdebinfo ..
cmake --build . --config relwithdebinfo
cd ..

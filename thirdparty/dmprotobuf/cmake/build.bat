rmdir /S /Q build
mkdir build
pushd build
cmake -DCMAKE_BUILD_TYPE=relwithdebinfo -Dprotobuf_BUILD_TESTS=OFF ..
cmake --build . --config relwithdebinfo
popd
#!/bin/sh

# - install depends tools
# yum -y install git
# yum -y install gcc gcc-c++ autoconf libtool automake make
#

# - clone code
# git clone https://github.com/brinkqiang/dmformat.git
# pushd dmformat
# git submodule update --init --recursive
#

# pushd depends_path
# libtoolize && aclocal && autoheader && autoconf && automake --add-missing
# sh configure
# popd

rm -rf build
mkdir build
pushd build
cmake -DCMAKE_BUILD_TYPE=relwithdebinfo ..
cmake --build . --config relwithdebinfo
popd

# popd
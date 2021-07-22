#!/bin/bash

for file in ./*.pkg
do
    if test -f $file
    then
        echo checking $file
        ./dmsolpp --PKG=$file
    fi
done
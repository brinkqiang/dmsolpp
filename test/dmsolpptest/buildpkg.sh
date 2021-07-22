#!/bin/bash

for file in ./*.pkg
do
    if test -f $file
    then
        echo checking $file
        ./dmgen4cpp --PKG=$file
    fi
done
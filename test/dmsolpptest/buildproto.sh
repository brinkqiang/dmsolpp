#!/bin/bash

for file in ./*.proto
do
    if test -f $file
    then
        echo checking $file
        ./protoc --cpp_out=. $file
    fi
done
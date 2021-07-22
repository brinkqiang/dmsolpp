#!/bin/bash

for file in ./*.proto
do
    if test -f $file
    then
        echo checking $file
        ./dmgen4pbmerge --PROTONAME=$file
        ./protoc --cpp_out=. $file
    fi
done
#!/bin/bash

set -e

IFS=$'\n'
SUC=0

for file in `find . -regextype posix-basic -regex  ".*_test.cc.*" | sed -e 's/\.\///g' -e 's/.cc//g'`
do
    echo -n "compiling $file ..."
    ORG=`echo $file | sed -e 's/_test//'`

    if [ $ORG == "cc2" ]
    then
        g++ -o $file $file.cc
    else
        g++ -o $file $file.cc $ORG.cc
    fi
    echo "done"
done

set +e
for file in `find . -regextype posix-basic -regex  ".*_test.cc.*" | sed -e 's/\.\///g' -e 's/.cc//g'`
do
    ./$file > /dev/null
    if [ $? -ne 0 ]; then
        echo "test $file  ...  failed❌"
        SUC=1
        continue
    fi
    echo "test $file  ...  passed✨"
done

if [ $SUC -eq 0 ]; then
    echo "=== All tests passed!✅ ==="
fi

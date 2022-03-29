#!/bin/bash 

set -e

make cc2
SUC=0

test() {
    input=$1
    expect=$2

    ./cc2 "$input"
    gcc -o gen gen.s

    ./gen

    result=$?
    if [ $result -eq $expect ]
    then
        echo "$input -> $result ... OK✨"
    else
        SUC=1
        echo "Fail, expect $expect, got $result❌"
    fi
}

test "" 0


if [ $SUC eq 0 ]; then
    echo "=== All tests passed!✅ ==="
fi

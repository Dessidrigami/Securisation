#!/bin/bash

make
if [ ! -f libcypher.a ]
then
    echo "No \"libcypher.a\" file found. Can't start program"
    exit 23
fi
if [ ! -f main.c ]
then
    echo "No \"main.c\" file. Can't start program."
    exit 23
fi
gcc main.c -o securize -L. -lcypher
if [ ! -f securize ]
then
    echo "Binary \"securize\" not found. Can't start program."
    exit 23
fi
if [ ! -x securize ]
then
    echo "Binary \"securize\" found but can't be executed."
    echo "Can't start program."
    echo "Use command \"chmod +x securize\" to give it execute rights."
    exit 23
fi
./securize

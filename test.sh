#!/bin/bash

EXEC=./matrix
TEST_DIR=./tests
TEMP_DIR=/tmp

for OP in s p t l
do
    for TYPE in i r c
	do
        $EXEC -t $TYPE -o $OP -s < $TEST_DIR/$OP.$TYPE.in > $TEMP_DIR/$OP.$TYPE.out
        diff $TEST_DIR/$OP.$TYPE.out $TEMP_DIR/$OP.$TYPE.out &>/dev/null
        if [ $? -ne 0 ]; then
            echo "Test for type $TYPE operation $OP failed!"
            exit 1
        fi
    done
done

echo "All tests passed!"

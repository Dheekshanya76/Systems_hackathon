#!/bin/bash

WORLD="test_invalid.world"

rm -f $WORLD

OUTPUT=$(printf "SPAWN PLAYER -1 alice a@a.gg\n.quit\n" | ./chronicle $WORLD)

echo "===== Test 8: Invalid ID ====="

PASS=true

echo "$OUTPUT" | grep -qi "error" || PASS=false
echo "$OUTPUT" | grep -qi "positive" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f $WORLD
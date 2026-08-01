#!/bin/bash

WORLD="test_duplicate.world"

rm -f $WORLD

OUTPUT=$(printf "SPAWN PLAYER 1 alice a@a.gg\nSPAWN PLAYER 1 bob b@b.gg\nLIST PLAYERS\n.quit\n" | ./chronicle $WORLD)

echo "===== Test 9: Duplicate ID ====="

PASS=true

echo "$OUTPUT" | grep -qi "already exists" || PASS=false
echo "$OUTPUT" | grep -q "alice" || PASS=false
echo "$OUTPUT" | grep -q "1 entities" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f $WORLD
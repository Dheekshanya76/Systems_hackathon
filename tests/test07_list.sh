#!/bin/bash

WORLD="test_list.world"

rm -f $WORLD

OUTPUT=$(printf "SPAWN PLAYER 1 alice alice@ironhold.gg\nSPAWN PLAYER 2 bob bob@ironhold.gg\nLIST PLAYERS\n.quit\n" | ./chronicle $WORLD)

echo "===== Test 7: List Players ====="

PASS=true

echo "$OUTPUT" | grep -q "\[1\] alice" || PASS=false
echo "$OUTPUT" | grep -q "\[2\] bob" || PASS=false
echo "$OUTPUT" | grep -q "2 entities" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f $WORLD
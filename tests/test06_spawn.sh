#!/bin/bash

WORLD="test_spawn.world"

rm -f $WORLD

OUTPUT=$(printf "SPAWN PLAYER 1 alice alice@ironhold.gg\n.quit\n" | ./chronicle $WORLD)

echo "===== Test 6: Spawn Player ====="

PASS=true

echo "$OUTPUT" | grep -qi "Spawned" || PASS=false
echo "$OUTPUT" | grep -qi "Error" && PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f $WORLD
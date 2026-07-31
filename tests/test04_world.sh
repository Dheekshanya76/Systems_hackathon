#!/bin/bash

OUTPUT=$(printf "SPAWN PLAYER 1 alice\nLIST PLAYERS\n.quit\n" | ./chronicle)

echo "===== Test 4: World Commands ====="

PASS=true

echo "$OUTPUT" | grep -q "\[World command queued: SPAWN PLAYER 1 alice\]" || PASS=false
echo "$OUTPUT" | grep -q "\[World command queued: LIST PLAYERS\]" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi
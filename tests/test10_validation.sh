#!/bin/bash

WORLD="test_validation.world"

rm -f $WORLD

LONG_NAME=$(python3 -c "print('a'*33)")
LONG_EMAIL=$(python3 -c "print('a'*256 + '@x.gg')")

OUTPUT=$(printf "SPAWN PLAYER 1 $LONG_NAME a@a.gg\n.quit\n" | ./chronicle $WORLD)

echo "===== Test 10: Validation ====="

PASS=true

echo "$OUTPUT" | grep -qi "error" || PASS=false


OUTPUT2=$(printf "SPAWN PLAYER 2 alice $LONG_EMAIL\n.quit\n" | ./chronicle $WORLD)

echo "$OUTPUT2" | grep -qi "error" || PASS=false


if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f $WORLD
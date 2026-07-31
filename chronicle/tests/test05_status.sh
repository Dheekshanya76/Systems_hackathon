#!/bin/bash

OUTPUT=$(printf "\n\n.status\n\n.version\n.quit\n" | ./chronicle)

echo "===== Test 5: Status ====="

PASS=true

echo "$OUTPUT" | grep -qi "World: offline" || PASS=false
echo "$OUTPUT" | grep -qi "Chronicle" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi
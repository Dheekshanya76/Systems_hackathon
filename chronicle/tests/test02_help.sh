#!/bin/bash

OUTPUT=$(printf ".help\n.quit\n" | ./chronicle)

echo "===== Test 2: Help ====="

PASS=true

echo "$OUTPUT" | grep -qi ".quit" || PASS=false
echo "$OUTPUT" | grep -qi ".help" || PASS=false
echo "$OUTPUT" | grep -qi ".version" || PASS=false
echo "$OUTPUT" | grep -qi ".status" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi
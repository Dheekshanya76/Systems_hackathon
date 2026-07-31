#!/bin/bash

OUTPUT=$(printf ".xyzzy\n.version\n.quit\n" | ./chronicle)

echo "===== Test 3: Unknown Command ====="

PASS=true

echo "$OUTPUT" | grep -qi "Unknown" || PASS=false
echo "$OUTPUT" | grep -qi "Chronicle" || PASS=false

if $PASS
then
    echo "PASS"
else
    echo "FAIL"
fi
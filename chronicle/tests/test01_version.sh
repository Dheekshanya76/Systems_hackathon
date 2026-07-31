#!/bin/bash

OUTPUT=$(printf ".version\n.quit\n" | ./chronicle)

echo "===== Test 1: Version ====="

if echo "$OUTPUT" | grep -qi "Chronicle" &&
   echo "$OUTPUT" | grep -qi "v0"
then
    echo "PASS"
else
    echo "FAIL"
fi
#!/bin/bash

echo "=============================="
echo " Running Chronicle Tests"
echo "=============================="

bash tests/test01_version.sh
bash tests/test02_help.sh
bash tests/test03_unknown.sh
bash tests/test04_world.sh
bash tests/test05_status.sh

echo "=============================="
echo " Tests Complete"
echo "=============================="
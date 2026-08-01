#!/bin/bash

echo "=============================="
echo " Running Chronicle Tests"
echo "=============================="

bash tests/test01_version.sh
bash tests/test02_help.sh
bash tests/test03_unknown.sh
bash tests/test04_world.sh
bash tests/test05_status.sh

bash tests/test06_spawn.sh
bash tests/test07_list.sh
bash tests/test08_invalid_id.sh
bash tests/test09_duplicate.sh
bash tests/test10_validation.sh

echo "=============================="
echo " Tests Complete"
echo "=============================="
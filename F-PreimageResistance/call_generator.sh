#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "1 1" "1 1" "10000 1" "1 10000"

    "100 10" "3000 10" "10000 10"
    "10 100" "10 3000" "10 10000"

    "-50 0" "-100 0" "-500 0" "-1000 0" "-10000 0" "-100000 0"
    "0 -50" "0 -100" "0 -500" "0 -1000" "0 -10000" "0 -100000"

    "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0" "0 0"

    "-10000 -10000" "-10000 -10000" "-10000 -10000" "-10000 -10000" "-10000 -10000"

    "200000 200000" "200000 200000" "200000 200000"
  )

i=1;
for m in "${M[@]}"; do
    j="$i"
    if [ $j -lt 10 ]; then
        j="0$j"
    fi

    tmpfile1=$(mktemp --tmpdir=.)
    echo "$m" > "$tmpfile1"
    pypy3 ./generator.py < "$tmpfile1" > "testcases/in/testcase-$j"
    rm "$tmpfile1"

    i=$((i + 1))
    echo $j
done

./call_solver.sh "./solver.exe"
./call_verifier.sh

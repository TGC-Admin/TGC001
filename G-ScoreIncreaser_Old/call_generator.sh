#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "10 \n -10 10" "10 \n 0 10" "10 \n -10 0"
    "10 \n 1 -1"

    "100 \n -100 100" "100 \n 0 100" "100 \n -100 0"
    "100 \n -10 10" "100 \n 0 10" "100 \n -10 0"
    "100 \n 1 -1"

    "100 \n 0 0" "100 \n 1000000000 1000000000"

    "500 \n -10 10" "500 \n -100 100"
    "500 \n -100 100" "500 \n 0 100" "500 \n -100 0"
    "500 \n -1000 1000" "500 \n -1000000 1000000"
    "500 \n 1 -1"

    "1000 \n -1000 1000" "1000 \n 1 -1"
  )

i=1;
for m in "${M[@]}"; do
    j="$i"
    if [ $j -lt 10 ]; then
        j="0$j"
    fi

    tmpfile1=$(mktemp --tmpdir=.)
    echo -e "$m" > "$tmpfile1"
    pypy3 ./generator.py < "$tmpfile1" > "testcases/in/testcase-$j"
    rm "$tmpfile1"

    i=$((i + 1))
    echo $j
done

./call_verifier.sh
./call_solver.sh ./solver.exe

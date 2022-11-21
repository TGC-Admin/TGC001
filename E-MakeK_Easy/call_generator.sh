#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "1 \n 1" "1 \n 1" "1 \n 1" "1 \n 1" "1 \n 1"
    "1 \n 10" "1 \n 10" "1 \n 10" "1 \n 10" "1 \n 10"
    "1 \n 100" "1 \n 100" "1 \n 100" "1 \n 100" "1 \n 100"
    "1 \n 1000" "1 \n 1000" "1 \n 1000" "1 \n 1000" "1 \n 1000"
    "1 \n 10000" "1 \n 10000" "1 \n 10000" "1 \n 10000" "1 \n 10000"

    "0 \n 2 10002" "0 \n 10002 20002" "0 \n 20002 30002" "0 \n 30002 40002" "0 \n 40002 50002" "0 \n 50002 60002" "0 \n 60002 70001"
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

#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "10000 0 -1 -1" "10000 1 -1 -1" "10000 2 -1 -1" "10000 3 -1 -1" "10000 4 -1 -1" "10000 5 -1 -1"
    "1000 0 -1 -1" "1000 1 -1 -1" "1000 2 -1 -1" "1000 3 -1 -1" "1000 4 -1 -1" "1000 5 -1 -1"
    "100 0 -1 -1" "100 1 -1 -1" "100 2 -1 -1" "100 3 -1 -1" "100 4 -1 -1" "100 5 -1 -1"
    "10 0 -1 -1" "10 1 -1 -1" "10 2 -1 -1" "10 3 -1 -1" "10 4 -1 -1" "10 5 -1 -1"
    "1 0 -1 -1" "1 1 -1 -1" "1 2 -1 -1" "1 3 -1 -1" "1 4 -1 -1" "1 5 -1 -1"

    "10000 -1 -1 -1"
    "1000 -1 -1 -1"
    "100 -1 -1 -1"
    "50 -1 -1 -1"

    "10000 0 1 10"
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

./call_verifier.sh
./call_solver.sh "pypy3 ./solver.py"

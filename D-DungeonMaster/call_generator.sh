#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "1 1 0"
    "1 1 1"

    "1 10 0"
    "1 10 -1"
    "10 1 0"
    "10 1 -1"

    "2 2 0"
    "2 2 -1"
    "2 2 -1"
    "5 5 -1"

    "5 5 -1"
    "5 5 -1"

    "10 10 -1"
    "50 50 -1"
    "100 100 -1"
    "500 500 -1"

    "1000 1000 -1"
    "1000 1000 -1"
    "1000 1000 -1"
    "1000 1000 -1"
    "1000 1000 -1"
    "1000 1000 -1"

    "1000 1000 0"
    "1000 1000 1"
    "1000 1000 2"
    "1000 1000 10"

    "2500 2500 -1"
    "2500 2500 -1"
    "2500 2500 -1"

    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
    "-1 -1 -1"
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
./call_solver.sh "pypy3 ./solver-dsu.py"

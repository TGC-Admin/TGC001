#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(
    "-1 0"
    "-1 1"
    "-1 2"
    "-1 3"
    "-1 4"
    "-1 5"
    "-1 6"
    "-1 7"
    "-1 8"
    "-1 9"
    "-1 10"
    "-1 11"
    "-1 12"
    "-1 14"
    "-1 15"
    "-1 16"
    "-1 17"
    "-1 -1"
    "-1 -1"
    "-1 -1"
    "-1 -1"
    "-1 -1"
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

#!/bin/bash

echo "INPUT"
while read -rd $'\0' file; do
    echo "$file"
    pypy3 ./input_verifier.py < "$file" || exit 1
done < <(find testcases/in/ -mindepth 1 -maxdepth 1 -print0)

echo "OUTPUT"
while read -rd $'\0' file; do
    echo "$file"
    pypy3 ./output_verifier.py < "$file" || exit 1
done < <(find testcases/out/ -mindepth 1 -maxdepth 1 -print0)

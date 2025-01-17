#!/bin/bash
echo "If code: Checksum 12 Numbers write it like this: 1 2 3 4 5 6 7 8 9 10 11 12 Checksum"
E1=$(($1 + $3 + $5 + $7 + $9 + ${11}))
E2=$((($2 + $4 + $6 + $8 + ${10} + ${12}) * 3))
E3=$(($E1 + $E2))
echo "Sum: $E3"
E4=$(( (10 - ($E3 % 10)) % 10 ))
echo "Checksum: $E4"
echo "Expected Checksum: ${13}"

#! /bin/bash
# coding: utf-8
# vim:softtabstop=4:ts=4:sw=4:expandtab:tw=120

set -e

if [ -z $1 ]; then
    echo "Usage: $0 <path-to-binary>"
    exit 1
fi

export TIMEFORMAT=%R

path="/home/jasonivey/dev/testcpp"
max_iterations=(100 1000 10000 100000 1000000)

echo "Building Binaries"

for iteration in ${max_iterations[@]}; do
    echo "iterating on $1 $iteration times"
    total_time=0.0
    executed_times=()
    for i in $(seq 1 4); do
        executed_time=$( { time $1 $iteration > /dev/null; } 2>&1 )
        echo "iteration on $1 for $iteration took $executed_time seconds"
        executed_times+=("$executed_time")
        total_time=`echo "$total_time + $executed_time" | bc -l`
    done
    echo "executed times: ${executed_times[@]}, total time: $total_time"
    sum=`echo "$total_time / 4.0" | bc -l`
    echo "average time for $1 name for $iteration: $sum"
done

exit

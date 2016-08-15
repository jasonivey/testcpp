#! /bin/bash
# coding: utf-8
# vim:softtabstop=4:ts=4:sw=4:expandtab:tw=120

set -e

export TIMEFORMAT=%R

path="/home/jasonivey/dev/testcpp"
max_iterations=(100 1000 10000 100000 1000000)
names=(test-new-map-clang \
       test-new-map-str-clang \
       test-new-dict-clang \
       test-new-dict-str-clang \
       test-new-vector-clang \
       test-new-vector-sorted-clang \
       test-new-vector-str-clang \
       test-new-vector-str-sorted-clang \
       test-old-gperf-clang \
       test-new-map-gcc \
       test-new-map-str-gcc \
       test-new-dict-gcc \
       test-new-dict-str-gcc \
       test-new-vector-gcc \
       test-new-vector-sorted-gcc \
       test-new-vector-str-gcc \
       test-new-vector-str-sorted-gcc \
       test-old-gperf-gcc)

echo "Running Binaries"

for name in ${names[@]}; do
    for iteration in ${max_iterations[@]}; do
        echo "iterating on $name $iteration times"
        total_time=0.0
        executed_times=()
        for i in $(seq 1 4); do
            executed_time=$( { time $path/tmp/$name $iteration > /dev/null; } 2>&1 )
            echo "iteration on $name for $iteration took $executed_time seconds"
            executed_times+=("$executed_time")
            total_time=`echo "$total_time + $executed_time" | bc -l`
        done
        echo "executed times: ${executed_times[@]}, total time: $total_time"
        sum=`echo "$total_time / 4.0" | bc -l`
        echo "average time for $name for $iteration: $sum"
    done
done

exit

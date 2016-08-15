#! /bin/bash
# coding: utf-8
# vim:softtabstop=4:ts=4:sw=4:expandtab:tw=120

set -e

path="/home/jasonivey/dev/testcpp"
options="-DNDEBUG -xc++ -O3 -std=c++14 -Wall -Werror -Wno-unused-function"
compilers=("clang++-3.8" "g++-5")
sources=("$path/main.cpp" "$path/langcode-new.cpp" "$path/langcode-old.cpp")
versions=(USING_MAP \
          USING_MAP_STR \
          USING_DICT \
          USING_DICT_STR \
          USING_VECTOR \
          USING_VECTOR_SORTED \
          USING_VECTOR_STR \
          USING_VECTOR_STR_SORTED)
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

echo "Building Binaries"
index=0
for compiler in ${compilers[@]}; do
    #echo "using compiler $compiler"
    for version in ${versions[@]}; do
        #echo "using version $version"
        command_line="$compiler -D$version -DTEST_NEW=1 $options ${sources[@]} -I$path -o $path/tmp/${names[index]}"
        #echo "$command_line"
        echo "Building $version using $compiler into ${names[index]}"
        $command_line
        index=$((index + 1))
    done
    command_line="$compiler -DTEST_OLD=1 $options ${sources[@]} -I$path -o $path/tmp/${names[index]}"
    #echo "$command_line"
    echo "Building gperf using $compiler into ${names[index]}"
    $command_line
    index=$((index + 1))
done


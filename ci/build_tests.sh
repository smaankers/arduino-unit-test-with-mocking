#!/bin/bash

script_name=$0
script_path=$(dirname "$0")

pushd $script_path/..                       && \
rm -rf ./target/export                      && \
mkdir -p ./target/export                    && \
cd ./target/export                          && \
cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja "../.." && cmake --build "." && \
./test/arduino-unit-test-with-mocking_gtest

if [ ${?} -ne 0 ]; then echo "error!"; exit 1; fi

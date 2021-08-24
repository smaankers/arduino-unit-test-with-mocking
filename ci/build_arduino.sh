#!/bin/bash

script_name=$0
script_path=$(dirname "$0")

pushd $script_path/../arduino-unit-test-with-mocking/ && \
arduino --verify arduino-unit-test-with-mocking.ino

if [ ${?} -ne 0 ]; then echo "error!"; exit 1; fi

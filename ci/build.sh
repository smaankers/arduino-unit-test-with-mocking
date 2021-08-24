#!/bin/bash

script_name=$0
script_path=$(dirname "$0")

pushd $script_path/.. && \
git submodule update --init --recursive

if [ ${?} -ne 0 ]; then echo "error!"; exit 1; fi

ci/build_arduino.sh    && \
ci/build_googletest.sh && \
ci/build_tests.sh      && \
ci/package.sh          && \
echo "OK"

if [ ${?} -ne 0 ]; then echo "error!"; exit 1; fi

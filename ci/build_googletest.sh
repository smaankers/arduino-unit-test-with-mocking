#!/bin/bash

script_name=$0
project_root_dir=$(dirname "$0")/../target/dependencies/googletest

pushd $project_root_dir
project_root_dir_absolute=$(pwd)

if [ -d "$project_root_dir_absolute/target/export" ]; then
  echo "Note: googletest already built, skipping..."
  exit 0
fi

# git clean
git clean -fdx
git reset --hard

# cleanup
rm -rf target
mkdir -p target/export

# calculate number of cores
cores=$(nproc --all)
max_jobs=$(($cores * 2))

# override number of cores on low memory machines to prevent out of memory
memory_kb=$(cat /proc/meminfo | grep MemTotal | awk '{ print $2 }')

memory_kb_5gb=$((5 * 1024 * 1024))
memory_kb_9gb=$((9 * 1024 * 1024))

if [ $memory_kb -le $memory_kb_5gb ]
then
  max_jobs=4
elif [ $memory_kb -le $memory_kb_9gb ]
then
  max_jobs=6
fi

echo total memory: $memory_kb kb
echo using $max_jobs jobs to build

# build
pushd target

  cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:PATH=$project_root_dir_absolute/target/export -G Ninja ".."
  rc=$?; if [[ $rc != 0 ]]; then exit $rc; fi

  ninja -j$max_jobs all
  rc=$?; if [[ $rc != 0 ]]; then exit $rc; fi

  ninja install
  rc=$?; if [[ $rc != 0 ]]; then exit $rc; fi

popd

popd

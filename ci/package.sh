#!/bin/bash

#--- Version
version="1.0.0"

#--- Variables, no need to change
script_path=$(dirname "$0")
project_root=${script_path}/..

package_base_name=package-src
package_name=${package_base_name}-v${version}
package_dir=${package_name}
package_file=${package_name}.zip

#--- Create the package
pushd  "${project_root}"            && \
rm -rf "${package_dir}"*            && \
mkdir  "${package_dir}"             && \
rsync -arvq --progress \
    * \
    "${package_dir}" \
    --exclude "${package_base_name}*" \
    --exclude "${package_name}" \
    --exclude "target" \
    --exclude "cmake-build-*"       && \
cd "${package_dir}"                 && \
echo "creating ${package_file}"     && \
zip -rq "../${package_file}" *      && \
cd ".."                             && \
rm -rf "${package_dir}"

if [ ${?} -ne 0 ]; then echo "ERROR"; exit 1; fi

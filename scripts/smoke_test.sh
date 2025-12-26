#!/bin/bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
build_dir="${repo_root}/build"

mkdir -p "${build_dir}"
cd "${build_dir}"

cmake ..
make

ctest --output-on-failure

cd "${repo_root}"
./scripts/run_simulation.sh

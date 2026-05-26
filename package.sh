#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"

if ! command -v geode >/dev/null 2>&1; then
    echo "Error: Geode CLI is not installed or not on PATH."
    echo "Install it from https://github.com/geode-sdk/cli/releases/latest"
    exit 1
fi

mkdir -p build
cd build
cmake ..
cmake --build .

LIB_FILE=$(find . -maxdepth 1 -type f -name 'HideComments.*' | head -n 1)
if [ -z "$LIB_FILE" ]; then
    echo "Error: Build did not produce a HideComments library."
    exit 1
fi

cd ..
geode package new . --binary "build/${LIB_FILE##*/}" --output "HideComments.geode"

echo "Created HideComments.geode"

#!/usr/bin/env bash
set -euo pipefail

REPO_URL="https://github.com/apple/metal-cpp.git"
DEST="${1:-metal-cpp-cmake}"

if [[ -e "$DEST" ]]; then
    echo "Error: destination already exists: $DEST" >&2
    echo "Choose another directory or remove it first." >&2
    exit 1
fi

git clone "$REPO_URL" "$DEST"

# Add a CMake-based sample target to Apple's header-only repository.
cp "$(dirname "$0")/CMakeLists.txt" "$DEST/CMakeLists.txt"
mkdir -p "$DEST/src"
cp "$(dirname "$0")/src/main.cpp" "$DEST/src/main.cpp"
cp "$(dirname "$0")/src/mtl_implementation.cpp" "$DEST/src/mtl_implementation.cpp"

echo
echo "Apple metal-cpp cloned and CMake files installed in: $DEST"
echo "Build with:"
echo "  cmake -S \"$DEST\" -B \"$DEST/build\" -G Ninja -DCMAKE_BUILD_TYPE=Debug"
echo "  cmake --build \"$DEST/build\""
echo "  \"$DEST/build/bin/metal_cpp_hello\""

#!/usr/bin/env bash
set -euo pipefail

SOURCE_ROOT="$1"
CLANG_FORMAT="$2"

while IFS= read -r file; do
    echo "  formatting $file"
    "$CLANG_FORMAT" -i "$file"
done < <(find "$SOURCE_ROOT" \
    -path "$SOURCE_ROOT/build" -prune \
    -o \( -name "*.cpp" -o -name "*.hpp" \) -print)

echo "Done."

#!/bin/bash

# Define ANSI color
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
RESET='\033[0m'

# Determine the script's directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the path to the executable
EXECUTABLE="$SCRIPT_DIR/../bank_account"


file1="$SCRIPT_DIR/expected.log"
file2="$SCRIPT_DIR/output.txt"
file1_timestamp_removed="$SCRIPT_DIR/expected_timestamp_removed.txt"
file2_timestamp_removed="$SCRIPT_DIR/output_timestamp_removed.txt"
file3_test_result="$SCRIPT_DIR/test_result.txt"

# Start a subshell
(
    exec 2>&1 > >(tee "$file2")
    "$EXECUTABLE"
)
# Back to the main shell

# Remove timestamp
cut -f2- -d' ' "$file1" > "$file1_timestamp_removed"
cut -f2- -d' ' "$file2" > "$file2_timestamp_removed"

# Compare results
echo -e "\n${YELLOW}Comparing output with expected:${RESET}"
if diff "$file1_timestamp_removed" "$file2_timestamp_removed" >/dev/null; then
    echo -e "${GREEN}Success${RESET}"
else
    {
        echo -e "${RED}Fail${RESET}"
        awk -v yellow="$YELLOW" -v green="$GREEN" -v red="$RED" -v reset="$RESET" '
            NR==FNR {
                a[NR]=$0
                next
            } {
                if (a[FNR] != $0) {
                    print yellow "Difference at line", reset, FNR
                    print green "Correct:", reset, a[FNR]
                    print red "Wrong  :", reset, $0
                }
            }
        ' "$file1_timestamp_removed" "$file2_timestamp_removed" > "$file3_test_result"
        cat "$file3_test_result"
    }
fi

# Clean up
rm "$file1_timestamp_removed"
rm "$file2_timestamp_removed"

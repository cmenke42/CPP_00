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

# Start a subshell
(
    exec 2>&1 > >(tee "$file2")
    "$EXECUTABLE" | cat -e
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
        {
            if (FILENAME == ARGV[1]) {
                # Process the first file to store expected lines
                expected_lines[FNR] = $0
                length_file_1 = FNR
            } else {
                # Process the second file to compare expected and actual lines
                if (FNR <= length_file_1 && expected_lines[FNR] != $0) {
                    print yellow "Difference at line", reset, FNR
                    print green "Expected:", reset, expected_lines[FNR]
                    print red "Actual  :", reset, $0
                } else if ((FNR == length_file_1 && expected_lines[FNR] != $0) || FNR > length_file_1) {
                    # Print extra lines in the output
                    print yellow "Difference at line", reset, FNR
                    print green "Expected:", reset
                    print red "Actual  :", reset, $0
                }
                length_file_2 = FNR  # Store the length of file 2
            }
        }
        END {
                if (length_file_2 < length_file_1) {
                    #Print lines that are missing in the output
                    for (i = length_file_2 + 1; i <= length_file_1; i++) {
                        print yellow "Difference at line", reset, i
                        print green "Expected:", reset, expected_lines[i]
                        print red "Actual  :", reset
                    }
            }
        }
        ' "$file1_timestamp_removed" "$file2_timestamp_removed"
}
fi

# Clean up
rm "$file1_timestamp_removed"
rm "$file2_timestamp_removed"
rm "$file2"

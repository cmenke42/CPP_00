#!/bin/bash

# Define ANSI color
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
RESET='\033[0m'

# Determine the script's directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the path to the "megaphone" executable
MEGAPHONE_EXECUTABLE="$SCRIPT_DIR/../megaphone"

file1="$SCRIPT_DIR/expected.txt"
file2="$SCRIPT_DIR/output.txt"

# Open test
exec > >(tee "$file2")

# Run tests
"$MEGAPHONE_EXECUTABLE" "shhhhh... I think the students are asleep..."
"$MEGAPHONE_EXECUTABLE" Damnit " ! " "Sorry students, I thought this thing was off."
"$MEGAPHONE_EXECUTABLE"

# Close test
exec >/dev/tty

# Compare results
echo -e "\n${YELLOW}Comparing output with expected:${RESET}"
if diff "$file1" "$file2" >/dev/null; then
    echo -e "${GREEN}Success${RESET}"
else
{
    echo -e "${RED}Fail${RESET}"
    awk 'NR==FNR{a[NR]=$0;next} {if(a[FNR]!=$0) print "Difference at line",FNR,"\nFile1:",a[FNR],"\nFile2:",$0}' $file1 $file2

}
fi

# Clean up
rm "$file2"
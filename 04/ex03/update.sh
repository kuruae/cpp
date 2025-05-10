#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color
BOLD='\033[1m'

# Function to update Makefile in a directory
update_makefile() {
    local dir=$1
    local makefile="$dir/Makefile"
    
    # Check if Makefile exists
    if [ ! -f "$makefile" ]; then
        echo -e "${RED}Error: Makefile not found in $dir${NC}"
        return 1
    fi
    
    # Find all .cpp files in the srcs directory
    local srcs_dir="$dir/srcs"
    if [ ! -d "$srcs_dir" ]; then
        echo -e "${RED}Error: srcs directory not found in $dir${NC}"
        return 1
    fi
    
    # Get list of cpp files
    local cpp_files=$(find "$srcs_dir" -name "*.cpp" | sort)
    if [ -z "$cpp_files" ]; then
        echo -e "${YELLOW}Warning: No .cpp files found in $srcs_dir${NC}"
        return 0
    fi
    
    # Format the files for SRC_FILES variable (SRC_DIR)/file.cpp format
    local formatted_files=""
    for file in $cpp_files; do
        # Get the relative path from the project directory
        local relative_file=${file#$dir/}
        formatted_files+="$(echo '$')\(SRC_DIR\)/$(basename "$relative_file") "
    done
    formatted_files=${formatted_files% } # Remove trailing space
    
    # Backup the original Makefile
    cp "$makefile" "${makefile}.bak"
    
    # Update the SRC_FILES line in the Makefile
    if grep -q "SRC_FILES :=" "$makefile"; then
        # Create temporary file
        local temp_file=$(mktemp)
        
        # Replace the SRC_FILES line while preserving formatting
        awk -v files="$formatted_files" '
        /SRC_FILES :=/ {
            print "SRC_FILES := " files;
            next;
        }
        { print }
        ' "$makefile" > "$temp_file"
        
        # Replace original file with updated content
        mv "$temp_file" "$makefile"
        echo -e "${GREEN}${BOLD}[✓] Updated SRC_FILES in $makefile${NC}"
        echo -e "${BLUE}New SRC_FILES:${NC} $formatted_files"
    else
        echo -e "${RED}Error: SRC_FILES variable not found in $makefile${NC}"
        # Restore backup
        mv "${makefile}.bak" "$makefile"
        return 1
    fi
}

# Main script
if [ $# -eq 0 ]; then
    # No arguments, search for directories with Makefile
    echo -e "${YELLOW}No directories specified, searching for Makefiles...${NC}"
    
    makefiles=$(find . -name "Makefile" -not -path "*/\.*")
    
    if [ -z "$makefiles" ]; then
        echo -e "${RED}No Makefiles found!${NC}"
        exit 1
    fi
    
    for makefile in $makefiles; do
        dir=$(dirname "$makefile")
        echo -e "\n${BOLD}Processing directory: $dir${NC}"
        update_makefile "$dir"
    done
else
    # Process specified directories
    for dir in "$@"; do
        if [ -d "$dir" ]; then
            echo -e "\n${BOLD}Processing directory: $dir${NC}"
            update_makefile "$dir"
        else
            echo -e "${RED}Error: $dir is not a directory${NC}"
        fi
    done
fi

echo -e "\n${GREEN}${BOLD}Done!${NC}"

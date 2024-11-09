# PDF Organiser Script

A simple bash script that helps organize PDF (more options coming soon) files in Downloads folder.

## What it does:
- Creates a Documents folder in Downloads if it doesn't exist
- Finds all PDF files in Downloads
- Moves them to the Documents folder
- Shows how many files were moved


## What i learned:
- Basic bash scripting
- Linux file handling
- Working with conditionals
- Counting using wc
- Error handling for missing files

## How to use:
```bash
# ensure that you replace the DIRECTORY variable with your relevant home directory
DIRECTORY = <path-to-Downloads-folder>
# Make script executable (first time only)
chmod +x organize.sh

# Run the script
./organize.sh

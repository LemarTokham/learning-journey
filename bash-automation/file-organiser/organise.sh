#!/bin/bash     # tells system we are running a bash script

DIRECTORY="/Users/lemartokham/Downloads"

# Create a Documents folder if it doesnt exist
mkdir -p "$DIRECTORY/Documents"

if ls "$DIRECTORY"/*.pdf >/dev/null 2>&1; then
    # list every pdf file
    echo "All PDF files"
    ls "$DIRECTORY"/*.pdf


    # move all pdf files to doc folder
    echo "Moving PDF files to Document folder..."
    count=$(ls "$DIRECTORY"/*.pdf | wc -l) # count how many files were moved
    mv "$DIRECTORY"/*.pdf "$DIRECTORY/Documents"
    echo "✅Done"
    echo "Moved $count PDF files"
else
    echo "No PDF files found in the Downloads folder!"
fi
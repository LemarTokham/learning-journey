#!/bin/bash 
# quicker way of updating the README
DEFAULT_MESSAGE="Update README"

# Allows us to type in a custmer commit message
# $# is the number of arguments passed on to the script
# -eq is the quality operator for numbers
if [ $# -eq 0 ]; then
    # If no arguments are passed, use default message
    COMMIT_MESSAGE="$DEFAULT_MESSAGE"
else 
    # $* combines all arguments into one string so they aren't treated as seperate arguments
    # e.g "script hello world" will commit the message "hello world"
    COMMIT_MESSAGE="$*"
fi

# print what we are about to do
echo "Running git commands..."
echo "Commit message: $COMMIT_MESSAGE" 

# run git commands
git add .
git commit -m "$COMMIT_MESSAGE"
git push

# check if succesful
# $? i the exit status, where 0 is everything went well and 1 is an error occured
if [$? -eq 0 ]; then
    echo "Successfully pushed to Github!"
else
    echo "Something went wrong, please check error messagees!"
fi



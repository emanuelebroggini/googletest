#!/bin/bash
for file in ./googletest/samples/*.exe; do
    if [ -f $file ]; then    # Check if the file exists
        "$file"              # Run the executable
        exit_code=$?         # Store the exit code in a variable

        if [ $exit_code -ne 0 ]; then
            echo "Error: $file returned a non-zero exit code: $exit_code"
            exit 1
        fi
    fi
done


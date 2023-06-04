#!/bin/bash
for file in ./googletest/samples/*.exe; do
    if [ -f $file ]; then    # Check if the file exists
        $file              # Run the executable
        
    fi
done


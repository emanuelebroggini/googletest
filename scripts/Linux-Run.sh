#!/bin/bash
for file in ./googletest/samples/sample*.exe; do
    if [ -x "$file" ]; then  # Check if the file is executable
        "$file"              # Run the executable
    fi
done


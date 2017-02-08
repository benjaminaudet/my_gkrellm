#!/bin/bash

# Launch them all
for i in $(ls); do
    if [[ $i == cli.exe ]]; then
        echo -e "\n<*** ! === TESTING $i ==== ! ***>\n"
        ./$i ;
    fi
done

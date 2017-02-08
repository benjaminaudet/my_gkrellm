#!/bin/bash

# Build Docker image
if which docker > /dev/null; then
    (docker build -t cpp_gkrellm . -f .Dockerfile)
fi

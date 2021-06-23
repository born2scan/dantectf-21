#!/bin/bash
docker rm -f dante_web_challs
docker build -t dante_web_challs . && \
docker run --name=dante_web_challs --rm -p4001:4001 -p4002:4002 -p4003:4003 -it dante_web_challs
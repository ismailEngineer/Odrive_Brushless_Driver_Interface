# Download base image ubuntu 20.04
FROM ubuntu:20.04

# LABEL about the custom image
LABEL maintainer="ismailhamrouni97@gmail.com"
LABEL version="0.1"
LABEL description="This is custom Docker Image for GUI APP ODrive."

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update Ubuntu Software repository
RUN apt update
RUN apt-get install -y \ 
    python3


WORKDIR /workspace/
COPY ./ ./

CMD [ "./src/test_docker_script.py" ]
#!/bin/bash
# ==============================
# INSTALL PACKAGES TO RUN 32-BIT
# NASM PROGRAMS ON 64-BIT LINUX
# ==============================
sudo dpkg --add-architecture i386
sudo apt-get update
sudo apt-get install nasm
sudo apt-get install gcc-multilib
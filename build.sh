#!/bin/bash
gcc main.c -o Game -Werror -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./Game
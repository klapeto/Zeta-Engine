#!/bin/bash
LD_LIBRARY_PATH=../libzeta/.libs valgrind --leak-check=full --show-leak-kinds=all --log-file=%p ./.libs/DemoExample

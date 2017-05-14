#!/bin/bash
LD_LIBRARY_PATH=../libzeta/.libs valgrind --tool=callgrind --log-file=%p ./.libs/lt-DemoExample

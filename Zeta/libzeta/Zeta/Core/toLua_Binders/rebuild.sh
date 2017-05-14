#!/bin/bash
./tolua++Z -o Binder.cpp Zeta.pkg
./tolua++Z -k Zeta.pkg > ../../../SZLL/Zeta.doclua

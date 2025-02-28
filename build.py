#!/usr/bin/env python3

from sys import platform
from os import system, path


def run(cmd: str) -> int:
    print('$', cmd)
    return system(cmd)

if platform.startswith("win"):
    run('cmd.exe /c cd Quake')
    if not path.isfile("sh.exe"):
        run('gcc sh.c -o sh')
    run('make -f Makefile.w64')

elif platform.startswith("darwin"):
    run("meson build")
    run("ninja -C build")
else: # Linux/unix
    raise NotImplementedError("No linux yet")


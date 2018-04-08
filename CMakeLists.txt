cmake_minimum_required(VERSION 3.9)
project(pa1)

set(CMAKE_CXX_STANDARD 11)

add_executable(pa1
        cs221util/lodepng/lodepng.cpp
        cs221util/lodepng/lodepng.h
        cs221util/HSLAPixel.cpp
        cs221util/HSLAPixel.h
        cs221util/PNG.cpp
        cs221util/PNG.h
        cs221util/RGB_HSL.h
        images/given-blocktest.png
        images/given-moveToBack.png
        images/given-swapEasy.png
        images/given-twistSame1.png
        images/given-twistSame2.png
        images/given-ubcRose.png
        images/rosegarden.png
        block.cpp
        block.h
        block.o
        chain.cpp
        chain.h
        chain.o
        chain_given.cpp
        HSLAPixel.o
        lodepng.o
        main.cpp
        main.o
        Makefile
        PNG.o
        PNGutil.cpp
        PNGutil.h
        PNGutil.o)

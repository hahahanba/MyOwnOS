cmake_minimum_required(VERSION 3.20)
project(MyOwnOS)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyOwnOS main.cpp include/common/color.h include/common/types.h include/common/coordinates.h include/common/pair.h include/common/string.h include/common/time.h include/common/vector.h include/common/rectangle.h include/common/map.h include/common/factory.h include/common/graphicscontext.h include/common/font.h include/common/inputstream.h include/common/outputstream.h)

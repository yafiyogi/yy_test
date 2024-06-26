#
#
#  MIT License
#
#  Copyright (c) 2024 Yafiyogi
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#
#

# cmake --fresh -DCMAKE_INSTALL_PREFIX=${HOME}/code/cpp/build .

cmake_minimum_required(VERSION 3.24)

project(yy_test LANGUAGES CXX)

set(YY_ROOT "${PROJECT_SOURCE_DIR}/..")
set(YY_CMAKE "${YY_ROOT}/yy_cmake")

include(${YY_CMAKE}/cmake_common.txt)

add_library(yy_test STATIC)

target_sources(yy_test
  PRIVATE
    yy_test_count.cpp)

set(YY_TEST_HEADERS
  yy_test_count.h )

install(TARGETS yy_test )
install(FILES ${YY_TEST_HEADERS} DESTINATION include/yy_test )

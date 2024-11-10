# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ubuntu/esp/esp-idf/components/bootloader/subproject"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/tmp"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/src/bootloader-stamp"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/src"
  "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ubuntu/CLionProjects/template_project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()

# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Verifying that IDF_PATH environment variable is set
if (NOT DEFINED ENV{IDF_PATH})
    message(FATAL_ERROR "Environment variable IDF_PATH is not set")
endif()

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Attempt to determine PROJECT_VER from `git describe`
execute_process(
        COMMAND git describe --tags --always
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE PROJECT_VER
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE GIT_DESCRIBE_RESULT
)

# Check if git describe was successful
if (NOT GIT_DESCRIBE_RESULT EQUAL 0)
    message(WARNING "git describe failed, setting PROJECT_VER to 0.0.0")
    set(PROJECT_VER "0.0.0")
endif()

project(main VERSION ${PROJECT_VER})

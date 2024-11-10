# Set the project name and version from variables in Menu
#project(Display VERSION ${PROJECT_VER})

# Set project name and version explicitly
project(my_project VERSION 1.2.3)

set(srcs

)

set(dependencies
        esp_common
        mqtt
        log
        driver
        nvs_flash
        freertos
        esp_timer
        app_update

)

set(private_dependencies

)

idf_component_register(SRCS "main.cpp" ${srcs}
        INCLUDE_DIRS "."
        REQUIRES ${dependencies}
        PRIV_REQUIRES ${private_dependencies})

# Automatically Set PROJECT_VER Using Git Tags
# Attempt to determine PROJECT_VER from `git describe`
execute_process(
        COMMAND git describe --tags --always
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE PROJECT_VER
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include ESP-IDF components in the build, may be thought as an equivalent of
# add_subdirectory() but with some additional procesing and magic for ESP-IDF build
# specific build processes.
#idf_build_process(esp32)
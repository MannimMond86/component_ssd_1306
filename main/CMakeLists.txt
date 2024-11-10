# Set the project name and version from variables in Menu
#project(Display VERSION ${PROJECT_VER})

# Set project name and version explicitly

set(srcs

)

set(dependencies
        esp_common
        esp_netif
        esp_wifi
        mqtt
        log
        driver
        nvs_flash
        freertos
)

set(private_dependencies

)

idf_component_register(SRCS "main.cpp" ${srcs}
        INCLUDE_DIRS "."
        REQUIRES ${dependencies}
        PRIV_REQUIRES ${private_dependencies}
        )


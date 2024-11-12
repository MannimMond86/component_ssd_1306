# Set the project name and version from variables in Menu
#project(Display VERSION ${PROJECT_VER})

# Set project name and version explicitly


set(srcs
        #../display_api/display_ssd1306/display_ssd1306.cpp
)

set(dependencies
        log
        driver
        display_ssd1306
)

set(private_dependencies

)

#set(EXTRA_COMPONENT_DIRS ../display_api/display_ssd1306/ssd1306)

idf_component_register(SRCS "main.cpp" ${srcs}
        INCLUDE_DIRS "."
        REQUIRES ${dependencies}
        PRIV_REQUIRES ${private_dependencies})


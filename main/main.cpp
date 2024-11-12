/***********************************************************************************************
* FILENAME       : main.cpp
 * VERSION        : 0.0.1
 * DESCRIPTION    : This code defines an ESP32 application that manages modem operations and facilitates UART communication between a terminal and the modem using FreeRTOS tasks.
 *
 * PUBLIC FUNCTIONS:
 *    - mode_task()
 *    - uart_task()
 *    - app_main()
 *
 * NOTES:
 *    Prefixes denote variable or return types:
 *    - "c" for char, "s" for short, "v" for void, "u" for unsigned, and "x" for non-standard types.
 *
 * AUTHOR         : Tjark Ziehm
 * START DATE     : July 6, 2024
 * COPYRIGHT      : © 2024 Tjark Ziehm
 * LICENCE        : CC BY-NC-ND 4.0
 * VERSION FORMAT : <major>.<minor>.<patch>
 *
 * Contributors   :
 *
 * CHANGE LOG:
 *    - v0.0.1:
 *    - v0.0.2:
 *    - v0.1.0:
 *    - v1.0.0:
 ***********************************************************************************************/
// TODO: implement the PROJECT_VER from build and git process
//#ifndef PROJECT_VER
//#define PROJECT_VER "99.99.99" // Definieren der Projektversion, falls nicht definiert
//#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_system.h"
#include "sdkconfig.h"

#include "display_ssd1306.h"

static const char *TAG = "example";

void display_task(void *pvParameters)
{
    while (1) {
        activate_display();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


extern "C" void app_main() {
    //ESP_LOGI("App", "Project Version: %s", PROJECT_VER);
    //ESP_LOGI("App", "Project Version: %s", PROJECT_VER);
    xTaskCreatePinnedToCore(display_task, "display_task", 4096, NULL, 5, NULL, 0);
}

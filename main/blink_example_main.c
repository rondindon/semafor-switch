/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#define    FIRST            5 
#define    SECOND           18
#define    THIRD            19
#define    FOURTH           21
#define    FIFTH            22
#define    SIXTH            23

// variables will change:
int led_state = 0;    // the current state of LED
int button_state;       // the current state of button
int last_button_state;  // the previous state of button


static const char *TAG = "log :";


void app_main(void)
{
    gpio_reset_pin(FIRST);
    gpio_reset_pin(SECOND);
    gpio_reset_pin(THIRD);
    gpio_reset_pin(FOURTH);
    gpio_reset_pin(FIFTH);
    gpio_reset_pin(SIXTH);
    gpio_set_direction(FIRST, GPIO_MODE_OUTPUT);
    gpio_set_direction(SECOND, GPIO_MODE_OUTPUT);
    gpio_set_direction(THIRD, GPIO_MODE_OUTPUT);
    gpio_set_direction(FOURTH, GPIO_MODE_OUTPUT);
    gpio_set_direction(FIFTH, GPIO_MODE_OUTPUT);
    gpio_set_direction(SIXTH, GPIO_MODE_OUTPUT);

    while (1) {

        gpio_set_level(FIRST,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(FIRST,0);
        gpio_set_level(SECOND,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(SECOND,0);
        gpio_set_level(THIRD,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(THIRD,0);
        gpio_set_level(FOURTH,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(FOURTH,0);
        gpio_set_level(FIFTH,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(FIFTH,0);    
        gpio_set_level(SIXTH,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(SIXTH,0);
        gpio_set_level(FIFTH,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(FIFTH,0);
        gpio_set_level(FOURTH,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(FOURTH,0);
        gpio_set_level(THIRD,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(THIRD,0);
        gpio_set_level(SECOND,1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(SECOND,0);  

        }

    }

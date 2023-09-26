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

#define BUTTON_PIN              18
#define GREEN_PIN               21 
#define ORANGE_PIN              22
#define RED_PIN                 23
#define PEDESTRIAN_GREEN_PIN    4
#define PEDESTRIAN_RED_PIN      15
#define TRAFFIC_LIGHT           2

// variables will change:
int led_state = 0;    // the current state of LED
int button_state;       // the current state of button
int last_button_state;  // the previous state of button


static const char *TAG = "log :";


void app_main(void)
{
    gpio_reset_pin(BUTTON_PIN);
    gpio_reset_pin(GREEN_PIN);
    gpio_reset_pin(ORANGE_PIN);
    gpio_reset_pin(RED_PIN);
    gpio_reset_pin(PEDESTRIAN_GREEN_PIN);
    gpio_reset_pin(PEDESTRIAN_RED_PIN);
    gpio_reset_pin(TRAFFIC_LIGHT);
    gpio_set_direction(BUTTON_PIN, GPIO_PULLDOWN_ENABLE);
    gpio_set_direction(GREEN_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(ORANGE_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(RED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(PEDESTRIAN_GREEN_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(PEDESTRIAN_RED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(TRAFFIC_LIGHT, GPIO_MODE_OUTPUT);

    while (1) {


        last_button_state = button_state;
        button_state = gpio_get_level(BUTTON_PIN);
        
        if (last_button_state == 1 && button_state == 0) {
            
            ESP_LOGI(TAG, "The button is pressed");

            // toggle state of LED
            
            led_state = 1;
            gpio_set_direction(TRAFFIC_LIGHT, 1);

            if(led_state == 1){

                gpio_set_level(GREEN_PIN,1);
                gpio_set_level(PEDESTRIAN_RED_PIN,1);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                gpio_set_level(GREEN_PIN,0);
                gpio_set_level(PEDESTRIAN_RED_PIN,0);

                gpio_set_level(ORANGE_PIN,1);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                gpio_set_level(ORANGE_PIN,0);

                gpio_set_level(RED_PIN,1);
                gpio_set_level(PEDESTRIAN_GREEN_PIN,1);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                gpio_set_level(RED_PIN,0);
                gpio_set_level(PEDESTRIAN_GREEN_PIN,0);

                gpio_set_level(ORANGE_PIN,1);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                gpio_set_level(ORANGE_PIN,0);

                gpio_set_level(GREEN_PIN,1);
                gpio_set_level(PEDESTRIAN_RED_PIN,1);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                gpio_set_level(GREEN_PIN,0);
                gpio_set_level(PEDESTRIAN_RED_PIN,0);

            }

        }

    }
}

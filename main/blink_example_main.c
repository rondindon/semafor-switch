/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "esp_log.h"
// #include "led_strip.h"
// #include "sdkconfig.h"

// #define    FIRST            5 
// #define    SECOND           18
// #define    THIRD            19
// #define    FOURTH           21
// #define    FIFTH            22
// #define    SIXTH            23

// // variables will change:
// int led_state = 0;    // the current state of LED
// int button_state;       // the current state of button
// int last_button_state;  // the previous state of button


// static const char *TAG = "log :";


// void app_main(void)
// {
//     gpio_reset_pin(FIRST);
//     gpio_reset_pin(SECOND);
//     gpio_reset_pin(THIRD);
//     gpio_reset_pin(FOURTH);
//     gpio_reset_pin(FIFTH);
//     gpio_reset_pin(SIXTH);
//     gpio_set_direction(FIRST, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SECOND, GPIO_MODE_OUTPUT);
//     gpio_set_direction(THIRD, GPIO_MODE_OUTPUT);
//     gpio_set_direction(FOURTH, GPIO_MODE_OUTPUT);
//     gpio_set_direction(FIFTH, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SIXTH, GPIO_MODE_OUTPUT);

//     while (1) {

//         gpio_set_level(FIRST,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(FIRST,0);
//         gpio_set_level(SECOND,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(SECOND,0);
//         gpio_set_level(THIRD,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(THIRD,0);
//         gpio_set_level(FOURTH,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(FOURTH,0);
//         gpio_set_level(FIFTH,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(FIFTH,0);    
//         gpio_set_level(SIXTH,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(SIXTH,0);
//         gpio_set_level(FIFTH,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(FIFTH,0);
//         gpio_set_level(FOURTH,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(FOURTH,0);
//         gpio_set_level(THIRD,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(THIRD,0);
//         gpio_set_level(SECOND,1);
//         vTaskDelay(100 / portTICK_PERIOD_MS);
//         gpio_set_level(SECOND,0);  

//         }

//     }

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#define    cPin             5 
#define    dPin             18
#define    ePin             19
#define    bPin             21
#define    aPin             22
#define    fPin             23
#define    gPin             4
#define    buttonPin        15

// variables will change:
// int led_state = 0;    // the current state of LED
// int button_state;       // the current state of button
// int last_button_state;  // the previous state of button


// static const char *TAG = "log :";

// int pins[7] = {dPin,cPin,ePin,gPin,fPin,aPin,bPin};
// int hex[16][7] =    {{1,1,1,0,1,1,1}, //0
//                      {0,1,0,0,0,0,1}, //1
//                      {1,0,1,1,0,1,1}, //2
//                      {1,1,0,1,0,1,1}, //3
//                      {0,1,0,1,1,0,1}, //4
//                      {1,1,0,1,1,1,0}, //5
//                      {1,1,1,1,1,1,0}, //6
//                      {0,1,0,0,0,1,1}, //7
//                      {1,1,1,1,1,1,1}, //8
//                      {1,1,0,1,1,1,1}, //9
//                      {0,1,1,1,1,1,1}, //a
//                      {1,1,1,1,1,0,0}, //b
//                      {1,0,1,0,1,1,0}, //c
//                      {1,1,1,1,0,0,1}, //d
//                      {1,0,1,1,1,1,0}, //e
//                      {0,0,1,1,1,1,0}, //f
//                      };

// unsigned char count = 0;

// void board_config(){
//     gpio_reset_pin(cPin);
//     gpio_reset_pin(dPin);
//     gpio_reset_pin(ePin);
//     gpio_reset_pin(bPin);
//     gpio_reset_pin(aPin);
//     gpio_reset_pin(fPin);
//     gpio_reset_pin(gPin);
//     gpio_reset_pin(buttonPin);
    
//     gpio_set_direction(cPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(dPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(ePin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(bPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(aPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(fPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(gPin, GPIO_MODE_OUTPUT);
//     gpio_set_direction(buttonPin, GPIO_MODE_INPUT);
//     gpio_set_pull_mode(buttonPin, GPIO_PULLUP_ONLY);
// }

// bool is_button_pressed()
// {
//     return (gpio_get_level(buttonPin) == 0);
// }

// void app_main(void)
// {
//     board_config();
//     while (1) {
//         for (int i = 0; i < 7; i++)
//         {
//             gpio_set_level(pins[i], hex[count][i]);
//         }
//         if(is_button_pressed())
//         {
//              ESP_LOGI(TAG, "Turning the LED OFF!");
//             if (count == 15)
//             {
//                 count = 0;
//             }else
//             {
//                 count +=1;
//             }
//             for (int i = 0; i < 7; i++)
//             {
//                 gpio_set_level(pins[i], hex[count][i]);
//             }
//             while (is_button_pressed())
//             {
//                 vTaskDelay(1); 
//             }
            
//         }
        
        
//     }
// }


int pins[7] = {dPin,cPin,ePin,gPin,fPin,aPin,bPin};
int dice_number[6][7] =   {
                    {0,1,0,0,0,0,1}, //1
                    {1,0,1,1,0,1,1}, //2
                    {1,1,0,1,0,1,1}, //3
                    {0,1,0,1,1,0,1}, //4
                    {1,1,0,1,1,1,0}, //5
                    {1,1,1,1,1,1,0}, //6
                    };
void board_config()
{
    gpio_reset_pin(dPin);    //d
    gpio_reset_pin(cPin);    //c
    gpio_reset_pin(ePin);   //e
    gpio_reset_pin(gPin);   //g
    gpio_reset_pin(fPin);   //f
    gpio_reset_pin(aPin);   //a
    gpio_reset_pin(bPin);   //b
    gpio_reset_pin(buttonPin);   //button

    gpio_set_direction(dPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(cPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(ePin, GPIO_MODE_OUTPUT);
    gpio_set_direction(gPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(fPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(aPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(bPin, GPIO_MODE_OUTPUT);
    gpio_set_direction(buttonPin, GPIO_MODE_INPUT);
    gpio_set_pull_mode(buttonPin, GPIO_PULLUP_ONLY);
}

bool is_button_pressed()
{
    return (gpio_get_level(buttonPin) == 0);
}


void app_main(void)
{
    board_config();
    int dice_state = rand() % 6 ;
    while (1) {
        for (int i = 0; i < 7; i++)
        {
            gpio_set_level(pins[i], dice_number[dice_state][i]);
        }
        if(is_button_pressed())
        {
            dice_state = rand() % 6;
            
            for (int i = 0; i < 7; i++)
            {
                gpio_set_level(pins[i], dice_number[dice_state][i]);
            }
            while (is_button_pressed())
            {
                vTaskDelay(1); 
            }
            
        }
        
        
    }
}
/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "esp_log.h"
#include "bsp/esp32_s3_lcd_ev_board.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/portmacro.h"
#include "freertos/projdefs.h"
#include "mysleep.h"
// #include "ctrl.h"
/**other*/


// #define TAG "ESP-EXAMPLE"

/*******************************************************************************
* Private functions
*******************************************************************************/

TaskHandle_t sleep_mode_handle;
// *INDENT-OFF*
void app_lvgl_display(void)
{
    bsp_display_lock(0);

    ui_init();

    bsp_display_unlock();
}

void app_main(void)
{
    /* Initialize I2C (for touch and audio) */
    bsp_i2c_init();

    /* Initialize display and LVGL */
    bsp_display_start();

    /* Turn on display backlight */
    bsp_display_backlight_on();

    /* Add and show objects on display */
    app_lvgl_display();

    printf("Hello world!\n");
    xTaskCreate(sleep_mode_task, "sleep_mode_task", 4096 * 4, NULL, 3,&sleep_mode_handle);  //kxcj91008_test

}
// *INDENT-ON*


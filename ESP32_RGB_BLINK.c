#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define RED 2
#define GREEN 4
#define BLUE 5

void app_main(void)
{
	char* ourTaskName = pcTaskGetName(NULL);

	ESP_LOGI(ourTaskName, "Hello, look at the pretty colors\n");

	gpio_reset_pin(RED);
	gpio_reset_pin(GREEN);
	gpio_reset_pin(BLUE);

	gpio_set_direction(RED, GPIO_MODE_OUTPUT);
	gpio_set_direction(GREEN, GPIO_MODE_OUTPUT);
	gpio_set_direction(BLUE, GPIO_MODE_OUTPUT);

	while (1)
	{
		gpio_set_level(RED, 1);
		ESP_LOGI(ourTaskName, "Red on\n");
		vTaskDelay(500 / portTICK_PERIOD_MS);
		gpio_set_level(RED, 0);
		gpio_set_level(GREEN, 1);
		ESP_LOGI(ourTaskName, "Green on\n");
		vTaskDelay(500 / portTICK_PERIOD_MS);
		gpio_set_level(GREEN, 0);
		gpio_set_level(BLUE, 1);
		ESP_LOGI(ourTaskName, "Blue on\n");
		vTaskDelay(500 / portTICK_PERIOD_MS);
		gpio_set_level(BLUE, 0);
	}
}

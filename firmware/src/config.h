#pragma once

#include <freertos/FreeRTOS.h>
#include <driver/i2s.h>

// network config
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASS"
#define MDNS_DOMAIN "microphone1"

// save to SPIFFS instead of SD Card?
// #define USE_SPIFFS 1

// sample rate for the system
#define SAMPLE_RATE 44100
#define BUFFER_LEN 1024

// are you using an I2S microphone - comment this out if you want to use an analog mic and ADC input
#define USE_I2S_MIC_INPUT

// I2S Microphone Settings
// Which channel is the I2S microphone on? I2S_CHANNEL_FMT_ONLY_LEFT or I2S_CHANNEL_FMT_ONLY_RIGHT
// Generally they will default to LEFT - but you may need to attach the L/R pin to GND
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT

/* ESP32 (DevKitV1-30Pins)

INMP441         ESP32
GND             GND
VDD             3.3v
SD              D21
SCK             D26
WS              D22
L/R             GND
*/
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_26
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_22
#define I2S_MIC_SERIAL_DATA GPIO_NUM_21

/* ESP32-C3 

SCK (INMP441) → GPIO4   Serial Clock (I2S Bit Clock, BCLK)
WS (INMP441) → GPIO5    Word Select (I2S Left/Right Clock, LRCLK)
SD (INMP441) → GPIO6    Serial Data (I2S Data Out) 
VDD (INMP441) → 3.3V
GND (INMP441) → GND
L/R (INMP441) → GND (for mono audio on the left channel)

// #define I2S_MIC_SERIAL_CLOCK GPIO_NUM_4
// #define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_5
// #define I2S_MIC_SERIAL_DATA GPIO_NUM_6
*/

// Analog Microphone Settings - ADC1_CHANNEL_7 is GPIO35
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7

// i2s config for using the internal ADC
extern i2s_config_t i2s_adc_config;
// i2s config for reading from of I2S
extern i2s_config_t i2s_mic_Config;
// i2s microphone pins
extern i2s_pin_config_t i2s_mic_pins;

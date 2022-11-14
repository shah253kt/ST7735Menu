#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_ST7735.h>

#ifndef ON
#define ON	true
#define OFF	!ON
#endif

#define TFT_INVALID_BLACKLIGHT_PIN	255

// Dimensions
#define DIMENSIONS_COUNT	4
#define START_X				0
#define START_Y				1
#define WIDTH				2
#define HEIGHT				3

typedef void (*FunctionPointer)();

class ST7735Menu
{
private:
	Adafruit_ST7735 *mTft;
	uint8_t mBacklightPin;
	uint16_t mDimensions[DIMENSIONS_COUNT];

public:
	ST7735Menu(Adafruit_ST7735 *tft, uint8_t backlightPin = TFT_INVALID_BLACKLIGHT_PIN);
	~ST7735Menu();

	void setBacklight(bool state);
	void setDimension(uint8_t dimension, uint8_t value);
};

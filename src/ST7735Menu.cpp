#include "ST7735Menu.h"

ST7735Menu::ST7735Menu(Adafruit_ST7735 *tft, uint8_t backlightPin)
{
	pinMode(mBacklightPin, OUTPUT);
	setBacklight(ON);
	tft->initR(INITR_GREENTAB);
	tft->setRotation(1);

	setDimension(START_X, 0);
	setDimension(START_Y, 0);
	setDimension(WIDTH, tft->width());
	setDimension(HEIGHT, tft->height());
}

ST7735Menu::~ST7735Menu()
{
	delete mTft;
}

void ST7735Menu::setBacklight(bool state)
{
	digitalWrite(mBacklightPin, state);
}

void ST7735Menu::setDimension(uint8_t dimension, uint8_t value)
{
	mDimensions[dimension] = value;
}
#include "library.h"
#include "images.h"

Library::Library(int timeout) {
  this->timeout = timeout;
}

void Library::connectionOled(String text, int16_t imageWidth, int16_t imageHeight, const uint8_t *imageBits)
{
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawXbm(52, 10, imageWidth, imageHeight, imageBits);
  Heltec.display->drawString(64, 48, text);
  Heltec.display->display();
}

void Library::displayProgressBar(float maximum, float value, String prefix, String suffix, int16_t imageWidth, int16_t imageHeight, const uint8_t *imageBits, bool integer){
    String v = "";
    if (integer == true)
    {
        v = int(value);
    }
    else
    {
        v = value;
    }

    String info = prefix + v + suffix;

    Heltec.display->clear();

    if (value > maximum && timeout >= 200 && timeout <= 400)
    {
        Heltec.display->setContrast(0);
    }
    else
    {
        Heltec.display->setContrast(100);
    }

    Heltec.display->setFont(ArialMT_Plain_24);
    Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
    Heltec.display->drawXbm(0, 10, imageWidth, imageHeight, imageBits);
    Heltec.display->drawString(70, 10, info);
    Heltec.display->drawProgressBar(0, 48, 127, 15, (value * 100) / maximum);
    Heltec.display->display();

    if (timeout > 400)
    {
        timeout = 0;
    }
    else
    {
        timeout++;
    }
}

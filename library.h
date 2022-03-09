#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <Arduino.h>
#include "heltec.h"

class Library {
  
  private:
    int timeout;
    
  public:
    Library(int timeout);
    void displayProgressBar(float maximum, float value, String prefix, String suffix);
    void connectionOled(String text, int16_t imageWidth, int16_t imageHeight, const uint8_t *imageBits);
};

#endif
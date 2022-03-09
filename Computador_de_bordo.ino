#include "BluetoothSerial.h"
#include "ELMduino.h"
#include "heltec.h"
#include "images.h"

BluetoothSerial SerialBT;
#define ELM_PORT   SerialBT
#define DEBUG_PORT Serial
#define oled Heltec.display

ELM327 myELM327;

uint32_t coolant = 0;
int timeout = 0;

void setup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  pinMode(25, OUTPUT);
  digitalWrite(25, LOW);

  //SerialBT.setPin("1234");
  ELM_PORT.begin("ArduHUD", true);

  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "OBDII Scanner");
  Heltec.display->drawString(0, 15, "CONNECTING...");
  Heltec.display->display();



  if (!ELM_PORT.connect("OBDII"))
  {
    Heltec.display->clear();
    Heltec.display->drawString(0, 0, "OBDII Scanner");
    Heltec.display->drawString(0, 15, "NOT CONNECTED");
    Heltec.display->display();
    while (1);
  }

  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "OBDII Scanner");
  Heltec.display->drawString(0, 15, "CONNECTED");
  Heltec.display->display();
  delay(3000);

  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "ECU");
  Heltec.display->drawString(0, 15, "CONNECTING...");
  Heltec.display->display();

  if (!myELM327.begin(ELM_PORT, true, 2000))
  {
    Heltec.display->clear();
    Heltec.display->drawString(0, 0, "ECU");
    Heltec.display->drawString(0, 15, "NOT CONNECTED");
    Heltec.display->display();
    while (1);
  }

  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "ECU");
  Heltec.display->drawString(0, 15, "CONNECTED");
  Heltec.display->display();
  delay(3000);
}


void loop()
{
  coolant = (uint32_t)myELM327.engineCoolantTemp();
  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    displayProgressBar(100, coolant, "", " °C");
  }
  else if (myELM327.nb_rx_state != ELM_GETTING_MSG) {
    Heltec.display->clear();
    Heltec.display->drawString(0, 0, "ELM Disconnected");
    Heltec.display->display();
    myELM327.printError();
  }
}

void displayProgressBar(float maximum, float value, String prefix, String suffix) {
  String v = "";
  if (value == int(value) )
  {
    v = int(value);
  }
  else {
    v = value;
  }

  String info = prefix + v + suffix;
  int alignCenter = 65 - (oled->getStringWidth(info) / 2);

  oled->clear();

  if (value > maximum && timeout >= 200 && timeout <= 400) {
    oled->setContrast(0);
  }
  else {
    oled->setContrast(100);
  }

  oled->setFont(ArialMT_Plain_24);
  oled->setTextAlignment(TEXT_ALIGN_CENTER);
  oled->drawXbm(0, 10, coolant_width, coolant_height, coolant_bits);
  oled->drawString(70, 10, info);
  oled->drawProgressBar(0, 48, 127, 15, (value * 100) / maximum);
  oled->display();

  if (timeout > 400) {
    timeout = 0;
  }
  else {
    timeout++;
  }
}

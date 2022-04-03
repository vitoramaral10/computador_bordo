#include "BluetoothSerial.h"
#include "ELMduino.h"
#include "heltec.h"
#include "images.h"
#include "library.h"

BluetoothSerial SerialBT;
#define ELM_PORT SerialBT

int buttonPin = 0;
int ledPin = 25;
int buttonState = 0;
int menu = 0;

ELM327 myELM327;

Library util(0);

void setup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // SerialBT.setPin("1234");
  ELM_PORT.begin("ArduHUD", true);

  util.connectionOled("CONNECTING...", obd2_width, obd2_height, obd2_bits);

  if (!ELM_PORT.connect("OBDII"))
  {
    util.connectionOled("NOT CONNECTED", obd2_width, obd2_height, obd2_bits);
    while (1)
      ;
  }

  util.connectionOled("CONNECTED", obd2_width, obd2_height, obd2_bits);
  delay(3000);

  util.connectionOled("CONNECTING...", engine_width, engine_height, engine_bits);

  if (!myELM327.begin(ELM_PORT, false, 2000))
  {
    util.connectionOled("NOT CONNECTED", engine_width, engine_height, engine_bits);
    while (1)
      ;
  }

  util.connectionOled("CONNECTED", engine_width, engine_height, engine_bits);
  delay(3000);
}

void loop()
{
  menuControl();

  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    switch (menu)
    {
    case 0:
      util.displayProgressBar(100, myELM327.engineCoolantTemp(), "", " °C");
      break;
    case 1:
      util.displayProgressBar(15, myELM327.batteryVoltage(), "", " V");
      break;
    default:
      Heltec.display->clear();
      Heltec.display->setFont(ArialMT_Plain_24);
      Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
      Heltec.display->drawString(70, 10, "ERRO");
      Heltec.display->display();
      break;
    }
  }
  else if (myELM327.nb_rx_state != ELM_GETTING_MSG)
  {
    util.connectionOled("ELM Disconnected", disconnected_width, disconnected_height, disconnected_bits);
    myELM327.printError();
  }
}

void menuControl()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {
    if (menu < 1)
    {
      menu++;
    }
    else
    {
      menu--;
    }
    delay(300);
  }
}
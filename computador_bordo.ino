#include "BluetoothSerial.h"
#include "ELMduino.h"
#include "heltec.h"
#include "images.h"
#include "library.h"

BluetoothSerial SerialBT;
#define ELM_PORT SerialBT
#define DEBUG_PORT Serial
#define oled Heltec.display

ELM327 myELM327;

uint32_t value = 0;

Library util(0);

int inPin = 0; // pushbutton connected to digital pin 7
int menu = 0;

void setup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  pinMode(inPin, INPUT); // sets the digital pin 7 as input

  ELM_PORT.begin("ArduHUD", true);

  connectOBD();

  connectECU();
}

void loop()
{

  if (digitalRead(inPin) == LOW)
  {
    menu++;
    if (menu > 2)
    {
      menu = 0;
    }
    delay(200);
  }

  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    switch (menu)
    {
    case 0:
      value = (uint32_t)myELM327.engineCoolantTemp();
      util.displayProgressBar(100, value, "", " °C", coolant_width, coolant_height, coolant_bits, true);
      break;
    case 1:
      value = (uint32_t)myELM327.batteryVoltage();
      util.displayProgressBar(12.7, value, "", " V", battery_width, battery_height, battery_bits, false);
      break;
    case 2:
      value = (uint32_t)myELM327.fuelLevel();
      util.displayProgressBar(100, value, "", " %", fuel_width, fuel_height, fuel_bits, false);
      break;
    default:
      break;
    }
  }
  else if (myELM327.nb_rx_state != ELM_GETTING_MSG)
  {
    util.connectionOled("ELM Disconnected", disconnected_width, disconnected_height, disconnected_bits);
    myELM327.printError();
  }
}

void connectOBD()
{

  util.connectionOled("CONNECTING...", obd2_width, obd2_height, obd2_bits);

  if (!ELM_PORT.connect("OBDII"))
  {
    util.connectionOled("NOT CONNECTED", obd2_width, obd2_height, obd2_bits);
    while (1)
      ;
  }

  util.connectionOled("CONNECTED", obd2_width, obd2_height, obd2_bits);
  delay(3000);
}

void connectECU()
{
  util.connectionOled("CONNECTING...", engine_width, engine_height, engine_bits);

  if (!myELM327.begin(ELM_PORT, true, 2000))
  {
    util.connectionOled("NOT CONNECTED", engine_width, engine_height, engine_bits);
    while (1)
      ;
  }

  util.connectionOled("NOT CONNECTED", engine_width, engine_height, engine_bits);
  delay(3000);
}

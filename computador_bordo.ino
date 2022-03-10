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

uint32_t coolant = 0;

Library util(0);

void setup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  pinMode(0, INPUT);
  SerialBT.setPin("1234");
  ELM_PORT.begin("ArduHUD", true);

  connectOBD();

  connectECU();
}

void loop()
{
  coolant = (uint32_t)myELM327.engineCoolantTemp();
  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    util.displayProgressBar(100, coolant, "", " °C");
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

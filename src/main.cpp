#include <Dynamixel2Arduino.h>

#define DXL_SERIAL     Serial1
#define DXL_DIR_PIN    2
#define DXL1_ID         3
#define DXL2_ID         1
#define DXL_BAUDRATE   1000000

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  DXL_SERIAL.begin(DXL_BAUDRATE);
  dxl.begin();
  dxl.setPortProtocolVersion(2.0);

  if (!dxl.ping(DXL1_ID)) {
    Serial.println("Servo 1 non détecté !");
    while (1);
  } else {
    Serial.println("Servo 1 détecté !");
  }

  if (!dxl.ping(DXL2_ID)) {
    Serial.println("Servo 2 non détecté !");
    while (1);
  } else {
    Serial.println("Servo 2 détecté !");
  }

  dxl.torqueOff(DXL1_ID);
  dxl.setOperatingMode(DXL1_ID, OP_POSITION);
  dxl.torqueOn(DXL1_ID);

  dxl.torqueOff(DXL2_ID);
  dxl.setOperatingMode(DXL2_ID, OP_POSITION);
  dxl.torqueOn(DXL2_ID);

  delay(100);
}

void loop() {
  dxl.setGoalPosition(DXL1_ID, 1025);
  dxl.setGoalPosition(DXL2_ID, 1025);
  delay(3000);
  dxl.setGoalPosition(DXL1_ID, 2000);
  dxl.setGoalPosition(DXL2_ID, 2000);
  delay(3000);
}

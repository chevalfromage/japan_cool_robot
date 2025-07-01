#include <Dynamixel2Arduino.h>

#define DXL_SERIAL     Serial1
#define DXL_DIR_PIN    2
#define DXL0_ID         10
#define DXL1_ID         11
#define DXL2_ID         12
#define DXL_BAUDRATE   1000000

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void deplacement(int debut0, int fin0,int debut1, int fin1){
  float etapes = 200.0;
  float pas0= ((float)(fin0-debut0))/etapes;
  float pas1= ((float)(fin1-debut1))/etapes;
  for(int i=0; i<etapes; i++){
    dxl.setGoalPosition(DXL0_ID, debut0 + pas0*i);
    dxl.setGoalPosition(DXL1_ID, debut1 + pas1*i);
    delay(10);
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  DXL_SERIAL.begin(DXL_BAUDRATE);
  dxl.begin();
  dxl.setPortProtocolVersion(2.0);

  if (!dxl.ping(DXL0_ID)) {
    Serial.println("Servo 0 non détecté !");
    while (1);
  } else {
    Serial.println("Servo 0 détecté !");
  }

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

  dxl.torqueOff(DXL0_ID);
  dxl.setOperatingMode(DXL0_ID, OP_POSITION);
  dxl.torqueOn(DXL0_ID);

  dxl.torqueOff(DXL1_ID);
  dxl.setOperatingMode(DXL1_ID, OP_POSITION);
  dxl.torqueOn(DXL1_ID);

  dxl.torqueOff(DXL2_ID);
  dxl.setOperatingMode(DXL2_ID, OP_POSITION);
  dxl.torqueOn(DXL2_ID);

  delay(100);
}

void loop() {
  deplacement(2048, 2600, 1535, 3200);
  deplacement(2600, 2048, 3200, 1535);
}

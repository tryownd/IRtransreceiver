#include <Arduino.h>
#include <IRremote.hpp>
#include <BluetoothSerial.h>
BluetoothSerial ESP_BT;
String incomingData;
// Define pin for IR transmitter
const int IR_SEND_PIN = 15; // Adjust this pin according to your connection

void setup() {
  Serial.begin(115200);
  ESP_BT.begin("LED_CONTROLLER");
  IrSender.begin(IR_SEND_PIN); // Initialize IR sender
  Serial.println("IR Transmitter is ready");
}
void loop() {
  if (ESP_BT.available()) {
    incomingData = ESP_BT.readStringUntil('\n');
    incomingData.trim();
    incomingData.toLowerCase();

    Serial.println(incomingData);
    if (incomingData.equalsIgnoreCase("nyalakan lampu")) {
      ON();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("matikan lampu")) {
      OFF();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("nyalakan merah")) {
      RED();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("nyalakan hijau")) {
      GREEN();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("nyalakan biru")) {
      BLUE();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("nyalakan putih")) {
      WHITE();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("tambah intensitas")) {
      for (int i = 0; i < 3; i++) {
        UP();
        delay(250);
      }
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("kurangi intensitas")) {
      for (int i = 0; i < 3; i++) {
        DOWN();
        delay(250);
      }
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("mode flash")) {
      FLASH();
      Serial.println("OK");
    } else if (incomingData.equalsIgnoreCase("mode smooth")) {
      SMOOTH();
      Serial.println("OK");
    }
    /*
      if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');
      command.trim();

      if (command.equalsIgnoreCase("on")) {
        ON();
        Serial.println("OK");
      } else if (command.equalsIgnoreCase("off")) {
        OFF();
        Serial.println("OK");
      } else {
        Serial.println("Unknown command. Use 'on' or 'off'.");
      }
    */
  }
}
void UP() {
  IrSender.sendNEC(0xEF00, 0x0, 0);
}
void DOWN() {
  IrSender.sendNEC(0xEF00, 0x1, 0);
}
void OFF() {
  IrSender.sendNEC(0xEF00, 0x2, 0);
}
void ON() {
  IrSender.sendNEC(0xEF00, 0x3, 0);
}
void RED() {
  IrSender.sendNEC(0xEF00, 0x4, 0);
}
void GREEN() {
  IrSender.sendNEC(0xEF00, 0x5, 0);
}
void BLUE() {
  IrSender.sendNEC(0xEF00, 0x6, 0);
}
void WHITE() {
  IrSender.sendNEC(0xEF00, 0x7, 0);
}
void RED1() {
  IrSender.sendNEC(0xEF00, 0x8, 0);
}
void GREEN1() {
  IrSender.sendNEC(0xEF00, 0x9, 0);
}
void BLUE1() {
  IrSender.sendNEC(0xEF00, 0xA, 0);
}
void FLASH() {
  IrSender.sendNEC(0xEF00, 0xB, 0);
}
void RED2() {
  IrSender.sendNEC(0xEF00, 0xC, 0);
}
void GREEN2() {
  IrSender.sendNEC(0xEF00, 0xD, 0);
}
void BLUE2() {
  IrSender.sendNEC(0xEF00, 0xE, 0);
}
void STROBE() {
  IrSender.sendNEC(0xEF00, 0xF, 0);
}
void RED3() {
  IrSender.sendNEC(0xEF00, 0x10, 0);
}
void GREEN3() {
  IrSender.sendNEC(0xEF00, 0x11, 0);
}
void BLUE3() {
  IrSender.sendNEC(0xEF00, 0x12, 0);
}
void FADE() {
  IrSender.sendNEC(0xEF00, 0x13, 0);
}
void RED4() {
  IrSender.sendNEC(0xEF00, 0x14, 0);
}
void GREEN4() {
  IrSender.sendNEC(0xEF00, 0x15, 0);
}
void BLUE4() {
  IrSender.sendNEC(0xEF00, 0x16, 0);
}
void SMOOTH() {
  IrSender.sendNEC(0xEF00, 0x17, 0);
}

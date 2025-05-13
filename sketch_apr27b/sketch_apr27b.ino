#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define GREEN_LED_PIN 6
#define RED_LED_PIN 7

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define MAX_LINES 40
String statusLines[MAX_LINES];
int statusCount = 0;
int currentIndex = 0;
bool receivingStatuses = false;
bool showStatuses = false;
unsigned long lastDisplayTime = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);  // Red LED always on

  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("Scan RFID...");
}

void loop() {
  // 1. RFID scan
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }

    Serial.println("UID:" + uid);

    // Reset for new data
    statusCount = 0;
    currentIndex = 0;
    receivingStatuses = true;
    showStatuses = false;
    lcd.clear();
    lcd.print("Waiting status...");

    // Blink green LED for 3 seconds
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(3000);
    digitalWrite(GREEN_LED_PIN, LOW);
  }

  // 2. Read serial data from Qt
  static String line = "";
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      line.trim();
      if (line == "END") {
        receivingStatuses = false;
        showStatuses = true;
        lastDisplayTime = millis();
        lcd.clear();
        lcd.print("Statuses ready!");
        delay(1000);
        lcd.clear();
      } else if (line.length() > 0 && statusCount < MAX_LINES) {
        // If line is too long, split it
        if (line.length() > 16) {
          statusLines[statusCount++] = line.substring(0, 16);
          statusLines[statusCount++] = line.substring(16);
        } else {
          statusLines[statusCount++] = line;
        }
      }
      line = "";
    } else {
      line += c;
    }
  }

  // 3. Display received status lines
  if (showStatuses && millis() - lastDisplayTime > 2000 && statusCount > 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(statusLines[currentIndex]);

    if (currentIndex + 1 < statusCount) {
      lcd.setCursor(0, 1);
      lcd.print(statusLines[currentIndex + 1]);
    }

    currentIndex += 2;
    if (currentIndex >= statusCount) {
      currentIndex = 0;
    }

    lastDisplayTime = millis();
  }
}

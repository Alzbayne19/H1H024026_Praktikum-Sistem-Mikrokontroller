#include <Wire.h>                   // Library komunikasi I2C
#include <LiquidCrystal_I2C.h>     // Library LCD I2C
#include <Arduino.h>               // Library utama Arduino

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi LCD (alamat 0x27, 16x2)

const int pinPot = A0;             // Pin analog untuk potentiometer

void setup() {
  Serial.begin(9600);             // Memulai komunikasi serial (UART)
  lcd.init();                     // Inisialisasi LCD
  lcd.backlight();                // Menyalakan backlight LCD
}

void loop() {
  int nilai = analogRead(pinPot); // Membaca nilai ADC (0 - 1023)

  float volt = nilai * (5.0 / 1023.0);   // Konversi ke tegangan (Volt)
  float persen = nilai * (100.0 / 1023.0); // Konversi ke persen

  int bar = map(nilai, 0, 1023, 0, 16); // Mapping untuk panjang bar LCD

  // ===== OUTPUT SERIAL MONITOR =====
  Serial.print("ADC: ");
  Serial.print(nilai);
  Serial.print(" | Volt: ");
  Serial.print(volt, 2);          // 2 angka di belakang koma
  Serial.print(" V | Persen: ");
  Serial.print(persen, 0);        // tanpa desimal
  Serial.println("%");

  // ===== OUTPUT LCD =====
  lcd.setCursor(0, 0);            // Baris 1 kolom 0
  lcd.print("ADC:");
  lcd.print(nilai);
  lcd.print("    ");              // Clear sisa karakter

  lcd.setCursor(0, 1);            // Baris 2 kolom 0
  for (int i = 0; i < 16; i++) {  // Loop 16 kolom LCD
    if (i < bar) {
      lcd.print((char)255);       // Karakter blok penuh
    } else {
      lcd.print(" ");             // Kosongkan
    }
  }

  delay(200);                     // Delay agar stabil
}
#include <Arduino.h>              // Library utama Arduino

const int PIN_LED = 12;           // Menentukan pin digital 12 untuk LED

char mode = '0';                  // Menyimpan mode LED (default mati)

void setup() {
  Serial.begin(9600);             // Memulai komunikasi serial dengan baudrate 9600
  Serial.println("Ketik '1' (ON), '0' (OFF), '2' (BLINK)"); // Instruksi ke user
  pinMode(PIN_LED, OUTPUT);       // Mengatur pin LED sebagai output
}

void loop() {

  if (Serial.available() > 0) {   // Mengecek apakah ada data masuk dari serial
    char data = Serial.read();    // Membaca 1 karakter dari serial

    if (data == '1') {            // Jika input '1'
      mode = '1';                 // Set mode menjadi ON
      Serial.println("LED ON");   // Tampilkan status ke serial monitor
    }
    else if (data == '0') {       // Jika input '0'
      mode = '0';                 // Set mode menjadi OFF
      Serial.println("LED OFF");  // Tampilkan status
    }
    else if (data == '2') {       // Jika input '2'
      mode = '2';                 // Set mode menjadi BLINK
      Serial.println("LED BLINK");// Tampilkan status
    }
    else if (data != '\n' && data != '\r') { // Jika bukan input valid
      Serial.println("Perintah tidak dikenal"); // Tampilkan error
    }
  }

  // Eksekusi berdasarkan mode
  if (mode == '1') {              // Jika mode ON
    digitalWrite(PIN_LED, HIGH); // LED menyala terus
  }
  else if (mode == '0') {         // Jika mode OFF
    digitalWrite(PIN_LED, LOW);  // LED mati
  }
  else if (mode == '2') {         // Jika mode BLINK
    digitalWrite(PIN_LED, HIGH); // LED menyala
    delay(500);                  // Tunggu 500 ms
    digitalWrite(PIN_LED, LOW);  // LED mati
    delay(500);                  // Tunggu 500 ms
  }
}
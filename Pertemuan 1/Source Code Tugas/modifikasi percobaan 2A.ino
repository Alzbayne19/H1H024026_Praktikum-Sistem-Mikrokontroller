void loop() {
  // Menyalakan 3 LED Kiri (Pin 2, 3, 4) secara bersamaan
  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, HIGH);
  }
  delay(500); // Jeda nyala
  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, LOW);
  }

  // Menyalakan 3 LED Kanan (Pin 5, 6, 7) secara bersamaan
  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, HIGH);
  }
  delay(500); // Jeda nyala
  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
}
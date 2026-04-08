// Logika untuk transisi Cepat -> Sedang -> Mati (Lambat)
if (timeDelay == 100) {
  timeDelay = 500;   // Berubah dari cepat ke sedang
} else if (timeDelay == 500) {
  timeDelay = 1000;  // Berubah dari sedang ke lambat (mati)
} else {
  timeDelay = 100;   // Reset kembali ke fase cepat
}
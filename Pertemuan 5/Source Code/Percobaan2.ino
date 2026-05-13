#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

// --- Konfigurasi Sensor DHT ---
#define DHTPIN 2       // Tentukan pin Arduino yang terhubung ke pin Data DHT
#define DHTTYPE DHT11  // Ganti menjadi DHT22 jika kamu menggunakan tipe DHT22
DHT dht(DHTPIN, DHTTYPE);

// Struct untuk menyimpan data sensor
// (Diubah menjadi float karena DHT menghasilkan nilai desimal)
struct readings {
  float temp;
  float h;
};

QueueHandle_t my_queue;

// Deklarasi fungsi task
void read_data(void *pvParameters);
void display(void *pvParameters);

void setup() {
  Serial.begin(9600);

  // Inisialisasi sensor DHT
  dht.begin();

  // Membuat queue untuk 1 elemen sebesar ukuran struct readings
  my_queue = xQueueCreate(1, sizeof(struct readings));

  if (my_queue != NULL) {
    xTaskCreate(read_data, "read sensors", 256, NULL, 1, NULL);
    xTaskCreate(display, "display", 256, NULL, 1, NULL);

    // Memulai scheduler FreeRTOS
    vTaskStartScheduler();
  }
}

void loop() {
  // Biarkan kosong, FreeRTOS mengambil alih eksekusi
}

void read_data(void *pvParameters) {
  struct readings x;

  for (;;) {
    // Membaca kelembaban dan suhu dari sensor asli
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Memastikan pembacaan tidak gagal (NaN = Not a Number)
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Gagal membaca data dari sensor DHT!");
    } else {
      x.temp = temperature;
      x.h = humidity;

      // Mengirim struktur data ke Queue
      xQueueSend(my_queue, &x, portMAX_DELAY);
    }

    // PENTING: Sensor DHT butuh jeda minimal 2 detik (2000 ms)
    // agar pembacaan berikutnya berhasil dan stabil
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void display(void *pvParameters) {
  struct readings x;

  for (;;) {
    // Menerima struktur data dari Queue
    if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {
      Serial.print("Temperature = ");
      Serial.print(x.temp);
      Serial.println(" *C");

      Serial.print("Humidity    = ");
      Serial.print(x.h);
      Serial.println(" %");
      Serial.println("----------------------");
    }
  }
}
#include <MQUnifiedsensor.h>

// Tentukan pin sensor
#define MQ135_PIN 23  // Pin analog ESP32 yang terhubung ke AO MQ135

MQUnifiedsensor MQ135("ESP32", 3.3, 4095, MQ135_PIN, "MQ-135");

// Tentukan nilai rasio udara bersih, bisa bervariasi tergantung kalibrasi sensor
#define RatioMQ135CleanAir 3.6

void setup() {
  Serial.begin(115200); // Mulai serial komunikasi
  MQ135.setRegressionMethod(1); // Untuk metode regresi
  MQ135.init(); // Inisialisasi sensor

  // Jika sensor baru, perlu kalibrasi
  Serial.print("Kalibrasi...");
  MQ135.calibrate(RatioMQ135CleanAir);
  Serial.println(" selesai!");
}

void loop() {
  // Membaca nilai analog dari sensor
  MQ135.update(); // Perbarui pembacaan
  float kualitasUdara = MQ135.readSensor(); // Membaca nilai sensor dalam PPM

  // Menampilkan nilai di serial monitor
  Serial.print("Kualitas Udara (PPM): ");
  Serial.println(kualitasUdara);

  delay(1000); // Delay 1 detik sebelum pembacaan berikutnya
}
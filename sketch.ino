#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 14       // Menggunakan GPIO 14 (sesuai rangkaian di Wokwi)
#define DHTTYPE DHT22

// Konfigurasi WiFi dan Broker HiveMQ
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "sistel/iot/dht2"; // Topik baru

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;

void setup_wifi() {
  delay(10);
  Serial.print("Konek ke WiFi ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi udah terkoneksi!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Konek ke HiveMQ...");
    String clientId = "ESP32Client-" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("Berhasil konek!");
    } else {
      Serial.print("Gagal, rc=");
      Serial.print(client.state());
      Serial.println(" Coba lagi 5 detik...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) { // Kirim data tiap 2 detik
    lastMsg = now;

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h)) {
      Serial.println("Gagal baca sensor DHT!");
      return;
    }

    // Format JSON dengan tambahan field nama "satria"
    char payload[128];
    snprintf(payload, sizeof(payload), "{\"nama\": \"satria\", \"suhu\": %.1f, \"kelembapan\": %.1f}", t, h);

    Serial.print("Kirim data ke topik ");
    Serial.print(mqtt_topic);
    Serial.print(": ");
    Serial.println(payload);

    client.publish(mqtt_topic, payload);
  }
}
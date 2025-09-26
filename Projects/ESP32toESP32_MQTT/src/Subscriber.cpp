#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "HUAWEI P30 Pro";
const char* password = "1234567890";

// MQTT Broker
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient); // espClient để gửi/nhận message


void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

// Callback khi nhận dữ liệu
// Message arrived [esp32/data] Hello from Minh Anh
void mqttCallback(char* topic, byte* message, unsigned int length) { // truyền địa chỉ thông qua con trỏ
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] "); 
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)message[i];
  }
  Serial.println(msg);
}

void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Subscriber")) { // đăng nhập vào broker với ID "ESP32Subscriber"
      Serial.println("connected!");
      client.subscribe("esp32/data"); // subscribe topic "esp32/data"
      Serial.println("Subscribed to topic: esp32/data");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  connectWiFi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback); // có tin nhắn từ MQTT Broker gửi về (ESP32 nhận tin) thì callback
}

void loop() {
  if (!client.connected()) connectMQTT();
  client.loop();
}
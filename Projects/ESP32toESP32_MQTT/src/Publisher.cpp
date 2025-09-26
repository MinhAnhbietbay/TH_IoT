// #include <WiFi.h>
// #include <PubSubClient.h>

// const char* ssid = "HUAWEI P30 Pro";
// const char* password = "1234567890";

// // MQTT Broker
// const char* mqtt_server = "test.mosquitto.org";

// WiFiClient espClient; //client TCP/IP nói chuyện qua WiFi
// PubSubClient client(espClient); // espClient để gửi/nhận message

// void connectWiFi() {
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi"); 
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWiFi connected!");
// }

// // Kết nối đến MQTT Broker
// void connectMQTT() { 
//   while (!client.connected()) {
//     Serial.print("Connecting to MQTT...");
//     if (client.connect("ESP32Publisher")) {  // đăng nhập vào broker với tên (ID) là "ESP32Publisher"
//       Serial.println("connected!");
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 2 seconds");
//       delay(2000);
//     }
//   }
// }

// void publishData() {
//   String message = "Hello from Minh Anh";
//   //chuyển String → const char* để phù hợp với publish()
//   client.publish("esp32/data", message.c_str()); // client.publish(topic, data)
//   Serial.println("Published: " + message);
// }

// void setup() {
//   Serial.begin(115200);
//   connectWiFi();
//   client.setServer(mqtt_server, 1883); // thiết lập địa chỉ và cổng của MQTT Broker
// }

// void loop() {
//   if (!client.connected()) connectMQTT();
//   client.loop();
//   publishData();
//   delay(2000);
// }

#include <ESP8266WiFi.h>

// Credenciales wifi


#define ssid Light Speed
#define password 1234567890
// server to connect to and relative path to PHP script
char server[] = "";
String url = "";

bool iterar = true;

void setup()
{
Serial.begin(115200);
Serial.println();

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED)
{
Serial.print(".");
delay(250);
}
Serial.print("\nConectado al Wi-Fi");
Serial.println();
Serial.println("Connecting to server...");
Serial.println(server);
WiFiClientSecure client;
client.setInsecure();
const int httpPort = 443;
if (!client.connect(server, httpPort)) {
Serial.println("connection failed");
return;
}

Serial.print("Requesting URL: ");
Serial.println(url);

client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + server + "\r\n" +
"Connection: close\r\n\r\n");

// Close connecting
Serial.println();
Serial.println("closing connection");
}

void loop(){
} // End Loop
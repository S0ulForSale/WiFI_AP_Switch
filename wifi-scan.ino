#include <WiFi.h>

bool apActive = false;
int lastButtonState = HIGH;

const char* ssid = "My_Network";
const char* password = "09988776";

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(34, INPUT_PULLUP);
    WiFi.mode(WIFI_OFF);
    Serial.println("System Ready. Press button to start AP.");
}

void toggleWiFi() {
    apActive = !apActive;

    if (apActive) {
        WiFi.softAP(ssid, password);
        digitalWrite(2, HIGH);
        Serial.println("Wi-Fi AP: ENABLED");
        Serial.print("IP Address: ");
        Serial.println(WiFi.softAPIP());
    } else {
        WiFi.mode(WIFI_OFF);
        digitalWrite(2, LOW);
        Serial.println("Wi-Fi AP: DISABLED");
    }
    
    delay(300);
}

void loop() {
    int currentButtonState = digitalRead(34);

    if (lastButtonState == HIGH && currentButtonState == LOW) {
        toggleWiFi();
    }

    lastButtonState = currentButtonState;
}
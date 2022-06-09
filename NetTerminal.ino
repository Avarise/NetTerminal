//#include <ESP8266WiFi.h>

// Threading and system
#define MAX_THREADS 16

// System registry
#define REGISTRY_AP_SIZE 32
#define REGISTRY_AP_SSID_SIZE 64


// Thread descriptor structure
struct ThreadDescriptor {
    bool active;
    void *handle;
} thread[MAX_THREADS];

// System registry structures
struct AccessPointInfo {
    char ssid[REGISTRY_AP_SSID_SIZE];
    char encryptionType;
    char bssid[6];
    bool hidden;
    int rssi;
    int channel;
} apRegistry[REGISTRY_AP_SIZE];

// Message box class with methods definition
class MessageBox {
    private:

    public:
    void hello (void) {
        Serial.println(F("\nESP8266 NetTerminal"));
    }

    void notify() {
        Serial.println(F("\nNetTerminal Error: operation missing"));
    }

    void printRegistry() {

    }
}; /* End of MessageBox */
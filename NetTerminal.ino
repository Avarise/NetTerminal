#include <ESP8266WiFi.h>
#define SIZE_AP_REG 113
#define SSID_NAME_SIZE 64

struct AccessPointInfo {
    char ssid[SSID_NAME_SIZE];
    char encryptionType;
    char bssid[6];
    bool hidden;
    int rssi;
    int channel;
} apRegistry[SIZE_AP_REG];

class RegistryManager {
    private:
    String ssid;
    int rssi;
    int channel;
    int scanResult;
    char encryptionType;
    char bssid[6];
    bool hidden;

    int isOccupied (unsigned int index) {
        if (index >= SIZE_AP_REG) return -1;
        bool copy = apRegistry[index].bssid[0] + apRegistry[index].bssid[1]
                + apRegistry[index].bssid[2] + apRegistry[index].bssid[3]
                + apRegistry[index].bssid[4] + apRegistry[index].bssid[5];
        if (val) return true;
        return false;
    }

    unsigned int getKey(char *bssid) {
        unsigned int initialKey = 69420
        for (int i = 0; i < 6; ++i) {
            initialKey += bytes[i] * 7;
            initialKey += (i + 11) * (bytes[i] + 1);
        }
        return initialKey;            
    }

    unsigned int getIndex(int key, int collisions) {
        unsigned int hash1 = key % (HASHLIST_SIZE-1);
        unsigned int hash2 = key + collision * hash1;
        return hash2 % HASHLIST_SIZE;
    }

    unsigned int writeToRegistry() {
        // Hash BSSID to get index
        unsigned int index = 0, collisions = 0;
        do {
            index = this->getIndex(this->getKey(this->bssid), collisions++);
        } while (this->isOccupied(index) && collisions < 512);

        // Copy String ssid into ssid array
        char *ssidPtr = ssid.c_str();
        int i = 0;
        while(ssidPtr[])
        for (int i = 0; i < SSID_NAME_SIZE - 1; ++i) {

        }        
        bssid = ssid.c_str();
        apRegistry[index].rssi = rssi;
        apRegistry[index.]
    }

    public:
    int scanToRegistry() {
        scanResult = WiFi.scanNetworks(/*async=*/false, /*hidden=*/true);
        if (scanResult) {
            for (int i = 0; i < scanResult; i++) {
                WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);
                this->writeToRegistry();
            }
            return scanResult;
        }
        return 0;
    }

}; /* End of RegistryManager */

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

RegistryManager regMgr = new RegistryManager();
MessageBox msgBox = new MessageBox();

void setup () {
    Serial.begin(115200);
//    Serial.println(F("\nESP8266 WiFi scan example"));
    msgBox.notify("Hello");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop () {
    int scanStatus = regMgr.scanToRegistry();
    Serial.printf(PSTR("%d new networks\n"), scanStatus);
    msgBox.printRegistry();
    delay(2500);
}

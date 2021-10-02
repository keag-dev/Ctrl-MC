/***  Ctrl-MC // An open source Motorcycle Controller Arduino project by KI Hestad: https://github.com/KIHestad/Ctrl-MC  ***/

// Enums
enum RelayStatus { relayOn, relayOff, relayInactive };

// Model used to retrive serial communication data
class SerialCommunicationDataReceived {
    public:
        bool success = false;
        uint8_t code;
        uint8_t value;
};
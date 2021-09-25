/***  Ctrl-MC // An open source Motorcycle Controller Arduino project by KI Hestad: https://github.com/KIHestad/Ctrl-MC  ***/

// System enums
enum TemperatureDefaultType { tempCelcius, tempFarenheit };
enum PinType {pinDigital, pinAnalog };

// Bike main status
enum BikeStatusIgnition { ignOff, ignPasswordMode, ignOn };
enum BikeStatusEngine { engStopped, engStartMotorEngaged, engUnknownStatus, engRunning };
enum BikeStatusLights { lightsOff, lightsPark, lightsMain };
enum BikeStatusLightsHiLo { lightsLow, lightsHigh };
class BikeStatus {
    public:

        bool debugMode; // Flag for running in debug mode
        unsigned long displayOffTimestamp; // Timestamp for when display off was initiated
        bool displayOffProgressRunning; // Flag set to true when progress is running 
        unsigned long displayStatusTextRemoveTimeStamp; // Set timestamp to the future for auto remove status text
        bool communicationOK; // Flag that indicates that communitcation to relay module is OK
        unsigned long communicationLastPing; // Last successful ping to relay, for triggering new ping after ping interval set in settings
        unsigned long displayMenuTimestamp; // The timestamp for last display menu next or select action is selected, used for determing auto shutdown
        int8_t displayMenyScrollSelector; // No menu item selected by default, counts upwards for each menu next button press
        unsigned long displayMenyShowRunningStopWatch; // Set to actual time [millis()] to update time each second
        unsigned long ignitionOnTimestamp; // Set timestamp for when iginition was last turned on, used for stopwatch
        BikeStatusIgnition ignition;
        BikeStatusEngine engine;
        BikeStatusLights lights;
        BikeStatusLightsHiLo lightHilo;
};

// Used to define pins allocation for inputs and custom features for button inputs
class Input {
    public:
        bool enabled; // If input is to be used or not
        uint8_t pin; // Arduino borad pin
        PinType pinType; // Digital is best, alternative analoge with valuerange
        uint8_t analogValueExpected; // If analog pin, the expected value returned has to be set
        unsigned long activateOnLongPress = 0; // Number of milliseconds, 0 = long not activated

};

// Model used to retrive serial communication data
class SerialCommunicationDataReceived {
    public:
        bool dataRead;
        bool success;
        uint8_t codeGroup;
        uint8_t code;
};

// Model for menu items
class MenuItem {
    public:
        uint8_t id; // Identifier used by code to know what to do
        String displayName; // Name of menu item to show on display
};


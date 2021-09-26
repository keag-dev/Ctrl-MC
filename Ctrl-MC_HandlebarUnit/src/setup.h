/***  Ctrl-MC // An open source Motorcycle Controller Arduino project by KI Hestad: https://github.com/KIHestad/Ctrl-MC  ***/

class Setup {
    private:
        // Set Arduino pins according to congig
        void setInputPin(Input input) {
            if (input.enabled) {
                if (input.pinType == pinDigital)
                    pinMode(input.pin, INPUT_PULLUP);
                else if (input.pinType == pinAnalog) {
                    pinMode(input.pin, INPUT);
                }
            }
                
        }

    public:
        
        void init() {
            setPinMode();
            bikeStatus = BikeStatus();
            setBikeStatus();
            controlDisplay = ControlDisplay();
            controlDisplay.init();
            serialCommunication = SerialCommunication();
            controlIgnition = ControlIgnition();
        }
        
        void setPinMode() {
            // Input pins
            setInputPin(INPUT_CLUTCH);
            setInputPin(INPUT_HORN);
            setInputPin(INPUT_HILO);
            setInputPin(INPUT_IND_LEFT);
            setInputPin(INPUT_IND_RIGHT);
            setInputPin(INPUT_MENU_SELECT);
            setInputPin(INPUT_MENU_NEXT);
            setInputPin(INPUT_START_STOP);
            setInputPin(INPUT_BRAKE_FRONT);
            // Onboard LED pin
            pinMode(ONBOARD_LED_PIN, OUTPUT);
            digitalWrite(ONBOARD_LED_PIN, ONBOARD_LED_OFF);
        }

        void setBikeStatus() {
            bikeStatus.debugMode = false;
            bikeStatus.communicationOK = false;
            bikeStatus.communicationLastPing = millis();
            bikeStatus.ignitionOnTimestamp = millis();
            
            bikeStatus.displayMenyScrollSelector = 0; // No display menu selected
            bikeStatus.displayMenySubLevelSelector = 0; // no sub menu level selected
            bikeStatus.displayOffTimestamp = 0;
            bikeStatus.displayOffProgressRunning = false;
            bikeStatus.displayStatusTextRemoveTimeStamp = 0;
            bikeStatus.displayMenuTimestamp = 0;
            bikeStatus.displayMenyShowRunningStopWatch = 0;
            
            bikeStatus.ignition = ignOff;
            bikeStatus.engine = engStopped;
            bikeStatus.lights = lightsOff;
            bikeStatus.lightHilo = lightsLow;
        }

};
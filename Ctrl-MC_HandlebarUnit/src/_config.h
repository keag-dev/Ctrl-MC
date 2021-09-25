/***  Ctrl-MC // An open source Motorcycle Controller Arduino project by KI Hestad: https://github.com/KIHestad/Ctrl-MC  ***/

/*****************************************************************************
 *   Output Pins cofiguration settings   
 *****************************************************************************/

// Pin to arduino onboard led
const uint8_t ONBOARD_LED_PIN = LED_BUILTIN;              // The pin number or ref to board variable for the pins controlling onboard led
const uint8_t ONBOARD_LED_ON = LOW;                       // Set HIGH or LOW to determin what sets the onboard led on or off
const uint8_t ONBOARD_LED_OFF = HIGH;                     // Ex: for Arduino Uno/Nano led in on using HIGH, but for NodeMCU led is on using LOW

/*****************************************************************************
 *   Featuere activation and digital input pins cofiguration settings   
 *****************************************************************************/
const Input INPUT_CLUTCH =        { true,  D3, pinDigital };   // Clutch lever
const Input INPUT_HORN =          { false, 0, pinDigital };   // Horn, activated using long press
const Input INPUT_HILO =          { true, D7, pinDigital };     // Toggle headlight between High and Low beam
const Input INPUT_IND_LEFT =      { false, 0, pinDigital };    // Indicator (turn signal) Left
const Input INPUT_IND_RIGHT =     { false, 0, pinDigital };    // Indicator (turn signal) Right

const Input INPUT_MENU_SELECT =   { true,  D5, pinDigital };   // Button for Display Menu select/toggle/activate option
const Input INPUT_MENU_NEXT =     { true,  D6, pinDigital };   // Button for Display Mneu for goto next menu/option on display
const Input INPUT_START_STOP =    { false, 0, pinDigital };    // Engine start and ttop
const Input INPUT_BRAKE_FRONT =   { false, 0, pinDigital };    // Front brake Lever

const uint8_t INPUT_ANALOG_DEVIATION_ACCEPTED = 50;            // For analog value read the signal will vary, this set +/- acceptance according to expected value

/*****************************************************************************
 *   OLED Display settings, according to Adafruit library
 *****************************************************************************/
const bool DISPLAY_POWERED_ON = true;                             // Initially the display is powered on
const uint8_t DISPLAY_PIN_SDA = D2;                               // The Pin attached to the display, for Arduino Nano: A4, for NodeMCU D2
const uint8_t DISPLAY_PIN_SCL = D1;                               // The Pin attached to the display, for Arduino Nano: A5, for NodeMCU D1
const uint8_t DISPLAY_SCREEN_ADDRESS = 0x3C;                      // See datasheet for Address; normally 0x3D for 128x64, 0x3C for 128x32
const int8_t DISPLAY_OLED_RESET = -1;                             // Reset pin # (or -1 if sharing Arduino reset pin)
const uint8_t DISPLAY_SCREEN_WIDTH = 128;                         // OLED display width, in pixels
const uint8_t DISPLAY_SCREEN_HEIGHT = 64;                         // OLED display height, in pixels
const uint8_t DISPLAY_TEXT_SIZE = 1;                              // Desired text size. 1 is default 6x8, 2 is 12x16, 3 is 18x24, etc these numbers include one extra pixel for space
const uint8_t DISPLAY_TEXT_CHAR_WIDTH = 6 * DISPLAY_TEXT_SIZE;    // Width of text INCLUDING ONE PIXEL FOR SEPARATION BETWEEN CHARS written to display, adjusted according to text size
const uint8_t DISPLAY_TEXT_CHAR_HEIGHT = 7 * DISPLAY_TEXT_SIZE;   // Height of text EXCLUDING PIXEL FOR SEPARATION BETWEEB ROWS written to display, adjusted according to text size
const unsigned long DISPLAY_OFF_WAIT_TIME = 4000;                 // Delay time in ms to auto turn off display after initiated, showing progressbar
const unsigned long DISPLAY_STATUSTEXT_OFF_WAIT_TIME = 3000;      // Delay time in ms to remove status text when inititated


/*****************************************************************************
 *   System Settings
 *****************************************************************************/

const bool SYSTEM_DEBUGMODE_DEFAULT_ON = true;                          // Option from menu to set in debug mode, this is inititally value
const bool SYSTEM_HANDSHAKE_IGNORE_COMM_ERROR = true;                   // For debugging only, should always be set to true. If set false comm errors are ignoerd.
const long SYSTEM_HANDSHAKE_CHECK_INTERVAL = 15;                        // Number of seconds for each ping to relay unit for checking that communication is OK
const TemperatureDefaultType SYSTEM_TEMP_DEFAULT_TYPE = tempCelcius;    // Default temp display type

/*****************************************************************************
 *   Ignition control
 *****************************************************************************/

const bool IGN_PW_ENABLED = true;                 // Enable to turn on ignition using password
const Input IGN_PW_START_BUTTON = INPUT_CLUTCH;   // Button to start / reset password input
const uint8_t IGN_PW_LENGTH = 3;                  // Number of button presses for password
const Input IGN_PW[IGN_PW_LENGTH] = {             // The password as an array of inputs
    INPUT_MENU_SELECT,
    INPUT_MENU_NEXT,
    INPUT_MENU_SELECT 
};


/*****************************************************************************
 *   Display Menues
 *****************************************************************************/

// Display settings
const uint8_t MENU_SHUTDOWN_WAIT = 15; // Number of seconds a menu item is shown before automatically shut down and go back to status screen

// List of available menu items, do not remove any or change ID, name can be modified / translated
const MenuItem MENU_IGNITION = { 1, "IGNITION" }; // Show ignition status, possible to turn off
const MenuItem MENU_STOPWATCH = { 2, "STOPWATCH" }; // Built in timer
const MenuItem MENU_TEMP_OUTSIDE = { 3, "TEMPERATURE" }; // Read from handlebar unit
const MenuItem MENU_TEMP_SYSTEM = { 4, "SYSTEM TEMP" }; // Read from relay unit
const MenuItem MENU_LIGHTS = { 5, "LIGHTS" }; // Control Ligths - OFF / PARK / ON

// Selected menu items in the order they will appear
const uint8_t MENUS_AVAILABLE_LENGTH = 5;
const MenuItem MENUS_AVAILABLE[MENUS_AVAILABLE_LENGTH] = {
    MENU_LIGHTS,
    MENU_IGNITION,
    MENU_STOPWATCH,
    MENU_TEMP_OUTSIDE,
    MENU_TEMP_SYSTEM
};



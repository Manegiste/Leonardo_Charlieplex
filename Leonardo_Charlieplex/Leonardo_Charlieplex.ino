// First attempt at Charlieplexing.
//
//     12 LEDS on 4 pins


// Structure to store the LED's "settings": pins to use, and pins values to light a specific LED
typedef struct {
  int pin[4];
  int LED[4][12];
} t_CharliePlex4 ;

// Global variable to store LEDs settings
t_CharliePlex4 myLEDs;

// lightLED: function to light a specific LED
void lightLED (int LED)
{
  // 4 pins are used, set state for each
  for (int i = 0; i < 4; i++)
  { 
    // if a pin has a state of -1 or 1 it is an output  
    if (myLEDs.LED[i][LED - 1])
    {
      pinMode(myLEDs.pin[i], OUTPUT);
      // -1 indicates LOW 
      if (myLEDs.LED[i][LED - 1] == -1)
        digitalWrite(myLEDs.pin[i], LOW);
      else
      // 1 indicates HIGH
        digitalWrite(myLEDs.pin[i], HIGH);
    }
    // else set its mode to INPUT to trigger the "tri" state
    else
       pinMode(myLEDs.pin[i], INPUT);
  }

}

void setup() {

  myLEDs.pin[0] = 4;
  myLEDs.pin[1] = 5;
  myLEDs.pin[2] = 6;
  myLEDs.pin[3] = 7;

  myLEDs.LED[0][0] = 1;
  myLEDs.LED[1][0] = -1;
  myLEDs.LED[2][0] = 0;
  myLEDs.LED[3][0] = 0;

  myLEDs.LED[0][1] = -1;
  myLEDs.LED[1][1] = 1;
  myLEDs.LED[2][1] = 0;
  myLEDs.LED[3][1] = 0;

  myLEDs.LED[0][2] = 0;
  myLEDs.LED[1][2] = 1;
  myLEDs.LED[2][2] = -1;
  myLEDs.LED[3][2] = 0;

  myLEDs.LED[0][3] = 0;
  myLEDs.LED[1][3] = -1;
  myLEDs.LED[2][3] = 1;
  myLEDs.LED[3][3] = 0;

  myLEDs.LED[0][4] = 0;
  myLEDs.LED[1][4] = 0;
  myLEDs.LED[2][4] = 1;
  myLEDs.LED[3][4] = -1;

  myLEDs.LED[0][5] = 0;
  myLEDs.LED[1][5] = 0;
  myLEDs.LED[2][5] = -1;
  myLEDs.LED[3][5] = 1;

  myLEDs.LED[0][6] = 1;
  myLEDs.LED[1][6] = 0;
  myLEDs.LED[2][6] = -1;
  myLEDs.LED[3][6] = 0;

  myLEDs.LED[0][7] = -1;
  myLEDs.LED[1][7] = 0;
  myLEDs.LED[2][7] = 1;
  myLEDs.LED[3][7] = 0;


  myLEDs.LED[0][8] = 1;
  myLEDs.LED[1][8] = 0;
  myLEDs.LED[2][8] = 0;
  myLEDs.LED[3][8] = -1;

  myLEDs.LED[0][9] = -1;
  myLEDs.LED[1][9] = 0;
  myLEDs.LED[2][9] = 0;
  myLEDs.LED[3][9] = 1;

  myLEDs.LED[0][10] = 0;
  myLEDs.LED[1][10] = 1;
  myLEDs.LED[2][10] = 0;
  myLEDs.LED[3][10] = -1;

  myLEDs.LED[0][11] = 0;
  myLEDs.LED[1][11] = -1;
  myLEDs.LED[2][11] = 0;
  myLEDs.LED[3][11] = 1;

  lightLED(1);
  delay(100);
  lightLED(12);
  delay(100);
}

void loop() {




  for (int i = 1; i <= 12; i++)
  {
    lightLED(i);
    delay(100);
  }


}

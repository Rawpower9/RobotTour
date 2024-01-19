#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_SmartRobotCarxxx0;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2 ;  // the number of the pushbutton pin
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int delayTime = 1000;

void setup() {
  AppMotor.DeviceDriverSet_Motor_Init();
  // for (Application_SmartRobotCarxxx0.Motion_Control = 0; Application_SmartRobotCarxxx0.Motion_Control < 9; Application_SmartRobotCarxxx0.Motion_Control = Application_SmartRobotCarxxx0.Motion_Control + 1)
  // {
  //   ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
  //   delay(1000);
  // }

  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  delay(2000);
}

void pause(){
      Application_SmartRobotCarxxx0.Motion_Control=5;
    ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    delay(delayTime);
}

void forward(){
    //Travel 50cm forward
    Application_SmartRobotCarxxx0.Motion_Control=0;
    ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    delay(1045);
    pause();
}

void turn_clockwise(){
      //Turn by 90 degrees clockwise (distance sensor is the front)
      Application_SmartRobotCarxxx0.Motion_Control=4;
      ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
      delay(425);
      pause();
}

void turn_anticlockwise(){
      //Turning by 90 degrees anticlockwise (distance sensor is the front)
      Application_SmartRobotCarxxx0.Motion_Control=3;
      ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
      delay(430);
      pause();
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {

    //Travel by 25cm (initialization)
    // Application_SmartRobotCarxxx0.Motion_Control=0;
    // ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    // delay(550);

    //Travel 50cm
    //       Application_SmartRobotCarxxx0.Motion_Control=0;
    // ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    // delay(1045);

    //Turn by 90 degrees clockwise (distance sensor is the front)
      //     Application_SmartRobotCarxxx0.Motion_Control=4;
      // ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
      // delay(425);
    for(int i =0; i < 4; i++){
      turn_clockwise();
    //       //Turning by 90 degrees anticlockwise (distance sensor is the front)
    //       Application_SmartRobotCarxxx0.Motion_Control=3;
    //   ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    //   delay(430);

    // Application_SmartRobotCarxxx0.Motion_Control=5;
    // ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    // delay(1000);
    }

    //stop at the end
    Application_SmartRobotCarxxx0.Motion_Control=5;
    ApplicationFunctionSet_SmartRobotCarMotionControl(Application_SmartRobotCarxxx0.Motion_Control /*direction*/, 200 /*speed*/);
    delay(100);
  }
}

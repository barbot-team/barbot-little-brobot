/**
 * Project: Barbot v0.1 'Little Brobot'
 * Authors: Chris Woodall, Benjamin Havey
 * Date: 2013-06-16
 */
#include <Servo.h> 

#define __VERSION__ "0.1"

#define CHA_OPEN  'a'
#define CHA_CLOSE 'A'
#define CHA_OPEN_STATE 0
#define CHA_CLOSE_STATE 180

#define CHB_OPEN  'b'
#define CHB_CLOSE 'B'
#define CHB_OPEN_STATE  180
#define CHB_CLOSE_STATE 0

#define CHC_OPEN  'c'
#define CHC_CLOSE 'C'
#define CHC_OPEN_STATE  180
#define CHC_CLOSE_STATE 0

Servo servoA, servoB, servoC;
 
void setup() { 
  servoA.attach(9);
  servoB.attach(10);
  servoC.attach(11);
  servoA.write(CHA_CLOSE_STATE);
  servoB.write(CHB_CLOSE_STATE;
  servoC.write(CHC_CLOSE_STATE);
  Serial.begin(9600);
  Serial.println("Welcome to Barbot v0.1 'Little Brobot'");
  delay(100);
} 
 
void loop() { 
  if (Serial.available()) {
    char inByte = Serial.read();
    Serial.print(inByte); // echo back

    switch(inByte) {
      case CHA_OPEN:
        servoA.write(CHA_OPEN_STATE);
        Serial.print('!');
        break;
      case CHA_CLOSE:
         Serial.print('!');
        servoA.write(CHA_CLOSE_STATE);
        break;
      case CHB_OPEN:
        Serial.print('!');
        servoB.write(CHB_OPEN_STATE);
        break;
      case CHB_CLOSE:
        Serial.print('!');
        servoB.write(CHB_CLOSE_STATE);
        break;
      case CHC_OPEN:
        Serial.print('!');
        servoC.write(CHC_OPEN_STATE);
        break;
      case CHC_CLOSE:
        Serial.print('!');
        servoC.write(CHC_CLOSE_STATE);
        break;
    case '\n': // IGNORE \n
        break;
    case '\r': // IGNORE \r
        break;
      default:
        Serial.print('?');
        break;
    }
  }
} 

/*
*/
#include <Servo.h>  // servo library

// current state: 0 = down, 1 = up
int currentState;
const int servoPin = 9;
const int buttonPin = 2;
const int outputPin = 13;
Servo boardServo;

void setup()
{
    // set input on button
    pinMode(buttonPin, INPUT);
    
    // set output to ??
    // Current goes to led.
    pinMode(outputPin, OUTPUT);
    
    // Where's my servo at?
    boardServo.attach(servoPin);
}

void loop()
{
    int buttonState;
    
    buttonState = digitalRead(buttonPin);
    
    if(buttonState == LOW)
    {
        // off
        if(currentState == 1)
        {
            boardServo.attach(servoPin);
            digitalWrite(outputPin, LOW);
            boardServo.write(90);
            delay(1000);
            currentState = 0;
            boardServo.detach();
        }
        else
        {
            boardServo.attach(servoPin);
            digitalWrite(outputPin, HIGH);
            boardServo.write(180);
            delay(1000);
            boardServo.detach();
            currentState = 1;
        }
    }
}

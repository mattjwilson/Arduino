/*
Matt's awesome experiments with sensors and things and stuff.

The one in which he tries to make a temperature indicator that lights a LED.
*/

const int temperaturePin = 0;
const int ledPin = 9;
const int potentPin = 5;  // A5
int state = 0; // 0 = off, 1 = on
float minOnVoltage = 0.6;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

float getVoltage(int pin)
{
    return(analogRead(pin) * 0.004882814); // Converts 0 - 1023 (reading from the pin) to the 0.0 - 5.0 voltage.
}

void loop()
{
    int tempValue, potentValue;
    float voltage, potentVoltage, degreesC, degreesF;
    
    tempValue = analogRead(temperaturePin);
    potentValue = analogRead(potentPin);
    voltage = getVoltage(temperaturePin);
    potentVoltage = getVoltage(potentPin);
  
    // This formula comes from the temperature sensor datasheet:
    degreesC = (voltage - 0.5) * 100.0;
    
    // This is the classic C to F conversion formula:
    degreesF = degreesC * (9.0/5.0) + 32.0;
    
    Serial.print("temperature: ");
    Serial.print(tempValue);
    Serial.print(" voltage: ");
    Serial.print(voltage);
    Serial.print("  deg C: ");
    Serial.print(degreesC);
    Serial.print("  deg F: ");
    Serial.println(degreesF);
    
    Serial.print("Potent: ");
    Serial.print(potentValue);
    Serial.print(" Potent voltage: ");
    Serial.println(potentVoltage);
    Serial.println("");
    
    if(voltage <= potentVoltage)
    {
        // turn off.
        digitalWrite(ledPin, LOW);
    }
    else
    {
        // turn on.
        digitalWrite(ledPin, HIGH);
    }
    
    delay(2000);
}

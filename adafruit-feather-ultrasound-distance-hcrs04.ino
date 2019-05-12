/* 
 *******************************************************************************
 * Description:
 * Sample code to read data from Ultrasonic Ranging Module HC-SR04
 * GitHub: https://github.com/flaviomauro/adafruit-feather-ultrasound-distance-hcrs04
 *******************************************************************************
 * Item list:
 * 
 * - 1 x Adafruit Feather
 * - 1 x Ultrasonic Ranging Module HC-SR04
 * - 1 x MB102 Power Supply Module
 * - 1 x USB Cable Type A/Type A or a Power supply for MB102
 * - 1 x Micro USB cable
 * - 4 x Jumper cables M/M

   External Library list:

 *******************************************************************************
 * @author: Flavio H. C. Mauro
 * @date:   11-Jan-2017
 * LinkedIn: https://br.linkedin.com/in/flaviomauro
 *******************************************************************************
 */
const int ECH_PIN = 15; // HC SR04 Echo pin connected to GPIO 15/D8
const int TRG_PIN = 14; // HC SR04 Trigger pin connected to GPIO 14/D5
const char* UNIT = "cm";

float duration = 0;
float distance = 0;

void setup(){                                                                                          
  Serial.begin(9600);
  
  pinMode(TRG_PIN, OUTPUT);
  pinMode(ECH_PIN, INPUT);

}

void loop() {
  digitalWrite(TRG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRG_PIN, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRG_PIN, LOW);
  
  duration = pulseIn(ECH_PIN, HIGH);
  
  distance = getDistance();

  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" " + String(UNIT));

  delay(2000);
}

float getDistance()
{
  if (UNIT == "cm")
  {
    return (duration/2) / 29.1;
  }
  else if  (UNIT == "in")
  {
    return (duration/2) / 74.1;
  }
  
}

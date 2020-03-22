#include <HC_SR04.h>

#define ENABLE_MOTOR 3
#define Extra_Volt_Pin 2
#define ECHO_PIN 12
#define TRIG_PIN 11
#define RIGHT_MOTOR_FORWARD 7
#define RIGHT_MOTOR_BACKWARD 8
#define LEFT_MOTOR_FORWARD 9
#define LEFT_MOTOR_BACKWARD 10
#define ECHO_INT 1

int sensorPin = A2;
int sensorPin2 = A0;

int sensorValue = 0;
int sensorValue2 = 0;

int threshold = 1023;
int SensorDifference;
int closeness = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Extra_Volt_Pin, OUTPUT);
  pinMode(ENABLE_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly    
    digitalWrite(1, HIGH);


    sensorValue = analogRead(sensorPin);
    sensorValue2 = analogRead(sensorPin2);
    SensorDifference = abs(sensorValue - sensorValue2);

    Serial.print(sensorValue);
    Serial.print(", ");
    Serial.println(sensorValue2);
    digitalWrite(Extra_Volt_Pin, HIGH);
    //Check if robot can move forward
    if( sensorValue <= threshold &&
        sensorValue2 <= threshold &&
        sensorValue >= 600 &&
        sensorValue2 >= 600 &&
        SensorDifference <= closeness) {
      digitalWrite(ENABLE_MOTOR, HIGH);
      digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
      digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    }
   
    
    //check if robot is at destination
    else if (sensorValue >= 1000 &&
             sensorValue2 >= 1000){
      digitalWrite(ENABLE_MOTOR, LOW);
      digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
      digitalWrite(LEFT_MOTOR_FORWARD, LOW);
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
              
    }
    else{

      digitalWrite(ENABLE_MOTOR, LOW);
      digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
      digitalWrite(LEFT_MOTOR_FORWARD, LOW);
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
       
    }

  delay(10);
}

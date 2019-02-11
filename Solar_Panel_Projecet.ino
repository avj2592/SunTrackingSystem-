
#include <Stepper.h>

const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11:
Stepper myStepperB(stepsPerRevolution, 4, 5, 6, 7);
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int Time = 0;

void setup(){
  Serial.begin(9600);

  myStepper.setSpeed(15);
  myStepper.setSpeed(15);


while ( Time < 48 ) {

  int stepCount = 0;          // number of steps the motor has taken
  int stepCountB = 0;

  int stepatminA = 0;
  int stepatminB = 0;
  int stepatminC = 0;
  int stepatminD = 0;


  float maxlightA = 10;
  float maxlightB = 10;
  float maxlightC = 10;
  float maxlightD = 10;
  float voltageA = 0;
  float voltageC = 0;

  Time++;
  int i = 0;

  for (int i = 0; i < 201; i++){

     // step one step:
    myStepper.step(1);
    Serial.print("\t");
    Serial.print("step:");
    Serial.println(stepCount);
    stepCount++;
    delay(100);
    
    int lightsensorA = analogRead(A0);
    int lightsensorB = analogRead(A1);
    float voltageA = lightsensorA * (10.0 / 1023.0);
    float voltageB = lightsensorB * (10.0 / 1023.0);
  
    Serial.println();
    
    if (maxlightA > voltageA){
      maxlightA = voltageA;
      stepatminA = i;
      Serial.print(maxlightA);
    }

    else {
      Serial.print(maxlightA);
      Serial.print(" at ");
      Serial.print(stepatminA);
    }

    if (maxlightB > voltageB){
      maxlightB = voltageB;
      stepatminB = i;
      Serial.print("\t");
      Serial.print(maxlightB);
    }

    else {
      Serial.print("\t");
      Serial.print(maxlightB);
      Serial.print(" at ");
      Serial.print(stepatminB);
    }
  }

  
  int cal = round((stepatminA + stepatminB)/2);
  myStepper.step(-(201 - cal));
  Serial.print(" worked ");
  Serial.print(cal);


  
  for (int i = 0; i < 101; i++){

     // step one step:
    myStepperB.step(1);
    Serial.print("\t");
    Serial.print("step:");
    Serial.println(stepCountB);
    stepCountB++;
    delay(100);
    
    int lightsensorC = analogRead(A2);
    int lightsensorD = analogRead(A3);
    float voltageC = lightsensorC * (10.0 / 1023.0);
    float voltageD = lightsensorD * (10.0 / 1023.0);
  
    Serial.println();
    
    if (maxlightC > voltageC){
      maxlightC = voltageC;
      stepatminC = i;
      Serial.print(maxlightC);
    }

    else {
      Serial.print(maxlightC);
      Serial.print(" at ");
      Serial.print(stepatminC);
    }

    if (maxlightD > voltageD){
      maxlightD = voltageD;
      stepatminD = i;
      Serial.print("\t");
      Serial.print(maxlightD);
    }

    else {
      Serial.print("\t");
      Serial.print(maxlightD);
      Serial.print(" at ");
      Serial.print(stepatminD);
    }
  }  
  
  int calB = round((stepatminC + stepatminD)/2);
  myStepperB.step(-(101 - calB));
  Serial.print(" worked ");
  Serial.print(calB);
  

  delay (900000);
  
  }

}





void loop ()
{
 
}

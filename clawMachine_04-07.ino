#include <Stepper.h>

const int stepsPerRevolution = 200;  // the number of steps per revolution for your motor
const int maxStepRangeX = 850;
const int maxStepRangeY = 850;

// initialize the stepper library on pins 8 through 11:
Stepper motorY1(stepsPerRevolution, 2, 3, 4, 5);
Stepper motorX1(stepsPerRevolution, 6, 7, 8, 9);
Stepper motorX2(stepsPerRevolution, 10, 11, 12, 13);

int stepPosX = 0;  // number of steps the motor has taken
int stepPosY = 0;

//int dir_x1 = 1; //1 is clockwise, -1 is counterclockwise
//int dir_x2 = 1;
//int dir_y1 = 1;

byte val1;
byte val2;
int x;
int y;

void setup() {
  // do nothing here
  Serial.begin(9600);
  moveX(-stepsPerRevolution, 50);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  x = 0;
  y = 0;
  while(!Serial.available()){}
  if(Serial.available() > 0){
    val1 = Serial.read();
    //Serial.println(val1);
    delay(2);
    val2 = Serial.read();
    //Serial.println(val2);
    delay(2);
    x = val1*256 + val2;
    //Serial.println(val);
    //serialFlush();
    //Serial.println("----");
    delay(2);

    val1 = Serial.read();
    //Serial.println(val1);
    delay(2);
    val2 = Serial.read();
    //Serial.println(val2);
    delay(2);
    y = val1*256 + val2;
    //Serial.println(y);
    //serialFlush();

    
    
    if(y != 0){
      moveY(stepPosY-y, 50);
      stepPosY = y;
    }
    if(x!=0){
      moveX(stepPosX-x, 50);
      stepPosX = x;
    }
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }

}

void moveY(int steps, int motorSpeed){
    int stepCount = 0;
    int dir;
    if(steps >= 0){
      dir = 1;
    }
    else{
      dir = -1;
    }
    steps *= dir;
    
    motorY1.setSpeed(motorSpeed);
    while(stepCount < steps){
      motorY1.step(dir * 1);
      stepCount++;
    }
    delay(50);
}

void moveX(int steps, int motorSpeed){
    int stepCount = 0;
    int dir;
    if(steps >= 0){
      dir = 1;
    }
    else{
      dir = -1;
    }
    steps *= dir;
    
    motorX1.setSpeed(motorSpeed);
    motorX2.setSpeed(motorSpeed);
    while(stepCount < steps){
      motorX1.step(dir * 1);
      motorX2.step(dir * -1);
      stepCount++;
    }
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}   

//int moveto(int x, int y, int motorSpeed){
//    if(y > maxStepRangeY){
//      return -1;
//    }
//    else if(y < 0){
//      return -1;
//    }
//    if(stepPos_y1 < y){
//      move(motorY1,1, motorSpeed,y-stepPos_y1);
//      stepPos_y1 = y;
//      
//    }
//    else if(stepPos_y1 > y){
//      move(motorY1,-1, motorSpeed,stepPos_y1-y);
//      stepPos_y1 = y;
//    }
//    else{
//    //dont move
//    }
//    return 1;
//}


  //moveto(val, 0, 50);
  
//  if(){
//
//  }
//  else{
//    
//  }

  
//  if(val == 119){
//    if(stepPos_x1 + distance > maxStepRangeX){
//      distance = maxStepRangeX - stepPos_x1;
//    }
//    move2(motorX1, motorX2, 1, 30, distance);
//    stepPos_x1 += distance;
//    stepPos_x2 += distance;
//  }
//  else if(val == 115){
//    if(stepPos_x1 - distance < 0){
//      distance = stepPos_x1;
//    }
//    move2(motorX1, motorX2, -1, 30, distance);
//    stepPos_x1 -= distance;
//    stepPos_x2 -= distance;
//  }
//  else{}
//  
//  if(val == 97){
//    if(stepPos_y1 + distance > maxStepRangeY){
//      distance = maxStepRangeY - stepPos_y1;
//    }
//    move(motorY1, 1, 30, distance);
//    stepPos_y1 += distance;
//  }
//  else if(val == 100){
//    if(stepPos_y1 - distance < 0){
//      distance = stepPos_y1;
//    }
//    move(motorY1, -1, 30, distance);
//    stepPos_y1 -= distance;
//  }
//  else{}

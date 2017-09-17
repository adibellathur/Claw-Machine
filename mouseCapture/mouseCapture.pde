import processing.serial.*;

Serial myPort;  // Create object from Serial class

 int currentx;
 int currenty;
 int num;
 int num2;
 int oldnum = 0;
 int oldnum2 = 0;

void setup(){
  size(850,850);
  scale(-1,-1);
  background(200,100,100);
  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}

void draw(){
 background(200,100,100);
 strokeWeight(4);
 stroke(255,255,255);
 line(width/2,0 , width/2,height);
 line(0,height/2 , width,height/2);
 ellipse(mouseX, mouseY, 20, 20);
 
 num = mouseX;
 num2 = mouseY;
 if(!mousePressed && (num != oldnum || num2 != oldnum2)){
   myPort.write(num/256);
   //println(num/256);
   myPort.write(num%256);
   print(num);
   print(" , ");
   //delay(10);
   
   myPort.write(num2/256);
   //println(num2/256);
   myPort.write(num2%256);
   println(num2);
   //println("---------");
   delay(200);
   
   oldnum = num;
   oldnum2 = num2;
 }
}
//void update(){
//  if(mousePressed == false){
//    //send the coordinate to the Myo
//    mouse
//  }
//}
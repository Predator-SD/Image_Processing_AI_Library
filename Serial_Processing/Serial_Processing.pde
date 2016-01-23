import processing.serial.*;
int counter=0;
Serial sp;
int val;
static float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170680;
float rtdx(float t, float r){
  float rad;
  rad = radians(t);
  float x = r*(cos(rad));
  return x;
}
float rtdy(float t, float r){
  float rad;
  rad = radians(t);
  float y = r*(sin(rad));
  return y;
}
void setup() {
  size(500, 500);
  frameRate(10);
  stroke(0,0,255);
  sp = new Serial(this, 9600);
}
void draw() {
  if(0<sp.available()){
    val = sp.read();
  }
  counter=counter+1;
  //Save Button
  text("Save",16,25);
  line(10,30,50,30);
  line(50,10,50,30);
  line(50,10,10,10);
  line(10,10,10,30);
  /*
  line(mouseX, mouseY, 700, 500);
  line(mouseX, mouseY, 0, 0);
  line(mouseX, mouseY, 700, 0);
  line(mouseX, mouseY, 0, 500);
  //ellipse(mouseX, mouseY, 80, 80);
  if(mousePressed){
    saveFrame("output-####.png");
  }
  */
}
void mouseClicked() {
  if(mouseButton == LEFT&&mouseY>10&&mouseY<50&&mouseX>0&&mouseX<50){
    saveFrame("output-####.png");
  }
}
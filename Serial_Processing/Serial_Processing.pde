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
float ftx(float OX, float OY, float xp, float yp){
  return OX + xp;
}
float fty(float OX, float OY, float xp, float yp){
  return OY - yp;
}
float sftx(float xp, float yp){
  return 250 + xp;
}
float sfty(float xp, float yp){
  return 250 - yp;
}
float sfty(float OX, float OY, float xp, float yp){
  return OY - yp;
}
void setup() {
  size(500, 500);
  frameRate(10);
  stroke(0,0,255);
  //sp = new Serial(this, 9600);
}
void draw() {
  /*
  if(0<sp.available()){
    val = sp.read();
  }
  */
  counter=counter+1;
  
  //Save Button
  text("Save",16,25);
  line(10,30,50,30);
  line(50,10,50,30);
  line(50,10,10,10);
  line(10,10,10,30);
  //End
  
  //Draw Test
  line(sftx(0,0),sfty(0,0),sftx(0,100),sfty(0,100));
  //End
  
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
  /*
  if(counter==1){
    print(ftx(250,250,0,0));
    print(fty(250,250,0,0));
    print(ftx(250,250,1,0));
    print(fty(250,250,1,0));
  }
  */
}
void mouseClicked() {
  if(mouseButton == LEFT&&mouseY>10&&mouseY<50&&mouseX>0&&mouseX<50){
    saveFrame("output-####.png");
  }
}
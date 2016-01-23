import processing.serial.*;
int counter=0;
Serial sp;
float[] indata;
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
void dti(float t1,float r1,float t2,float r2,float times){
  float[] pos1={rtdx(t1,r1*times),rtdy(t1,r1*times)};
  float[] pos2={rtdx(t2,r2*times),rtdy(t2,r2*times)};
  line(sftx(pos1[0],pos1[1]),sfty(pos1[0],pos1[1]),sftx(pos2[0],pos2[1]),sfty(pos2[0],pos2[1]));
}
void setup() {
  size(500, 500);
  frameRate(10);
  stroke(0,0,255);
  //sp = new Serial(this, 9600);
}
void draw() {
  indata = new float[181];
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
  for(int i=0;i<=180;i++){
    if(i<180){
      dti(i,2,i+1,2,100);
      //dti(i,indata[i],i+1,indata[i],100);
    }else{
      dti(i,2,0,2,100);
      //dti(i,indata[i],0,indat[i],100);
    }
  }
  //End
  
  //Debug Area
  if(counter==1){
    print();
  }
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
}
void mouseClicked() {
  if(mouseButton == LEFT&&mouseY>10&&mouseY<50&&mouseX>0&&mouseX<50){
    saveFrame("output-####.png");
  }
}
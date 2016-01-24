import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Serial_Processing extends PApplet {


int command=0;
boolean draw=false;
int counter=0;
Serial sp;
float[] indata;
static float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170680f;
public float rtdx(float t, float r){
  float rad;
  rad = radians(t);
  float x = r*(cos(rad));
  return x;
}
public float rtdy(float t, float r){
  float rad;
  rad = radians(t);
  float y = r*(sin(rad));
  return y;
}
public float ftx(float OX, float OY, float xp, float yp){
  return OX + xp;
}
public float fty(float OX, float OY, float xp, float yp){
  return OY - yp;
}
public float sftx(float xp, float yp){
  return 250 + xp;
}
public float sfty(float xp, float yp){
  return 400 - yp;
}
public float sfty(float OX, float OY, float xp, float yp){
  return OY - yp;
}
public void dti(float t1,float r1,float t2,float r2,float times){
  float[] pos1={rtdx(t1,r1*times),rtdy(t1,r1*times)};
  float[] pos2={rtdx(t2,r2*times),rtdy(t2,r2*times)};
  line(sftx(pos1[0],pos1[1]),sfty(pos1[0],pos1[1]),sftx(pos2[0],pos2[1]),sfty(pos2[0],pos2[1]));
}
public void setup() {
  
  frameRate(10);
  background(200, 200, 200);
  sp = new Serial(this,"COM3", 9600);
  //Change the COM here!!!
}
public void draw() {
  
  command=sp.read();
  if(command==1){
    draw=true;
  }
  
  indata = new float[181];
  if(0<sp.available()){
    for(int i =0;i<=180;i++){
      indata[i] = sp.read();
    }
  }
  
  counter=counter+1;
  
  //Save Button
  stroke(0,0,0);
  text("Save",16,25);
  line(10,30,50,30);
  line(50,10,50,30);
  line(50,10,10,10);
  line(10,10,10,30);
  //End
  
  //Scan Button
  stroke(0,0,0);
  text("Scan",16+50,25);
  line(10+50,30,50+50,30);
  line(50+50,10,50+50,30);
  line(50+50,10,10+50,10);
  line(10+50,10,10+50,30);
  //End
  
  //Clear Button
  stroke(0,0,0);
  text("Clear",16+50+50,25);
  line(10+50+50,30,50+50+50,30);
  line(50+50+50,10,50+50+50,30);
  line(50+50+50,10,10+50+50,10);
  line(10+50+50,10,10+50+50,30);
  //End
  if(draw==true){
    //Draw Test
    for(int i=0;i<=180;i++){
      if(i<180){
        stroke(0,0,255);
        //dti(i,2,i+1,2,100);
        dti(i,indata[i],i+1,indata[i],100);
      }else{
        stroke(0,0,255);
        //dti(i,2,0,2,100);
        dti(i,indata[i],0,indata[i],100);
      }
    }
    draw=false;
    //End
  }
  
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
public void mouseClicked() {
  if(mouseButton == LEFT&&mouseX>10&&mouseX<50&&mouseY>0&&mouseY<50){
    print("Save!!!");
    saveFrame("output-####.png");
  }
  if(mouseButton == LEFT&&mouseX>60&&mouseX<100&&mouseY>0&&mouseY<50){
    print("Scan!!!");
    int a=0;
    sp.write(a);
    //draw=true;
  }
  if(mouseButton == LEFT&&mouseX>110&&mouseX<150&&mouseY>0&&mouseY<50){
    print("Clear!!!");
    for(int ct=0;ct<=20;ct++){
      for(int i=0;i<=180;i++){
        if(i<180){
          stroke(200,200,200);
          //dti(i,2,i+1,2,100);
          dti(i,indata[i],i+1,indata[i],100);
        }else{
          stroke(200,200,200);
          dti(i,2,0,2,100);
          dti(i,indata[i],0,indata[i],100);
        }
      }
    }
  }
}
  public void settings() {  size(500, 500); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Serial_Processing" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

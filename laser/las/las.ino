boolean recdata = true;
boolean data;
int buf[64];
int rc=0;


void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);
}

void loop()
{
  static unsigned long t = 0;
  if (millis() > (t + 2000)){ 
    Serial1.write("*00084553#");
    t = millis();
  }
  getdist();
  if (recdata) t = millis();
}


int getdist(){
  int litera;
  
  if (Serial1.available() > 0){
    while (Serial1.available() > 0){
      litera = Serial1.read();
      if (litera == 42) { 
        data = true;
      }

      if (litera == 35) { 
        data = false;     
        recdata = true;  
      }
      if(data==true && rc<40 && litera>47){
        litera = litera-48;
        buf[rc] = litera; 
        rc++;
      }
    }
  }else{
    if (recdata == true){
      boolean dig=true;
      int countdata=0;    
      int data=0;         
      int sum=0;          
      int src=0;          
      int countLaser=0;   
      int dist=0;         
      for(int p = 0; p<rc; p++){
        if(dig){
          data = buf[p]*10;
          countdata++;
        }else{
          data += buf[p]; 
          if(countdata<10)sum+=data;
          if(countdata==5)countLaser=data;
          if(countdata==7)dist=data*10000;
          if(countdata==8)dist+=data*100;
          if(countdata==9)dist+=data;
          if(countdata==10)src=data;
          Serial.print(data);
          Serial.print(" ");
          data=0;
        }
        buf[p]='\0';
        dig=!dig;
      }
    
      if(sum >= 100) {
        int a=sum;
        sum=sum/100;
        sum=sum*100;
        sum =a-sum;
      }
      if(sum==src){
//        Serial.print(" ");
//        Serial.print(sum);
//        Serial.print(" ");
//        Serial.print(src);
        Serial.print("\t");
        Serial.print(countLaser);
        Serial.print("\t");
        Serial.print(dist);
        if(countLaser==99){
         Serial1.write("*00084553#"); 
        }
      }
      src = 0;
      countdata = 0;
      countLaser = 0;
      rc=0;
      recdata = false;
      Serial.println();
    }
  }
}


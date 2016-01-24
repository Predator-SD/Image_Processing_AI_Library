boolean recdata = true;
boolean data;
int buf[64];
int rc=0;

void setup()
{
Serial.begin(115200);
Serial1.begin(115200);
//Serial.println("Start...");
}

void loop()
{
static unsigned long t = 0;
if (millis() > (t + 2000)){ // timer start when no data from the sensor 
Serial1.write("*00084553#");
t = millis();
}
getdist();
if (recdata) t = millis(); // Reset the timer when it receives data from the sensor 
}

int getdist(){
int litera;

if (Serial1.available() > 0){
while (Serial1.available() > 0){
litera = Serial1.read();
if (litera == 42) { // If adopted a "*" 
data = true; //Then set the sign of the beginning of the packet 
}

if (litera == 35) { // If adopted, the "#" 
data = false; //Then set the sign of the end of the package ... 
recdata = true; //And install a sign to obtain data for the control (reset) the timer and further processing of the packet 
}
if(data==true && rc<40 && litera>47){ // If there is a sign of the beginning of the packet, the packet length is reasonable and litera has a numeric value to ASCII, the ... 
litera = litera-48;// convert ASCII to figure ... 
buf[rc] = litera; // And add it to the array. 
rc++;
}
}
}else{
if (recdata == true){
boolean dig=true; //This variable will work to separate the package into categories 2 digits 
int countdata=0; //This variable will be considered level 
int data=0; //This variable will take the values ​​of bits 
int sum=0; //This sum of all digits except for the last 
int src=0; //This is the last category (10), which defines the checksum 
int countLaser=0; //This is an internal counter in the 5th digit 
int dist=0; //It is the distance, we calculate 
for(int p = 0; p<rc; p++){="" if(dig){="" data="buf[p]*10;//Here" we="" have="" the="" first="" sign="" of="" any="" new="" discharge="" multiply="" by="" 10="" ....="" countdata++;="" }else{="" data="" +="buf[p];" and="" here="" we="" add="" to="" it,="" the="" second="" value.="" if(countdata<10)sum+="data;//here" podschitvaem="" checksum="" if(countdata="=5)countLaser=data;//here" to="" see="" the="" counter="" if(countdata="=7)dist=data*10000;//" here="" believe="" distantsiyayu="" ---------|="" if(countdata="=8)dist+=data*100;//" |="" if(countdata="=9)dist+=data;//------------------------------------------|" if(countdata="=10)src=data;//here" extract="" the="" checksum="" of="" the="" package="" serial.print(data);="" serial.print("="" ");="" data="0;" }="" buf[p]="\0" ;="" dig="!dig;" }="" if(sum="">= 100) {// If the checksum is greater than 99, then cut off the excess, leaving only the last two 
int a=sum;
sum=sum/100;
sum=sum*100;
sum =a-sum;
}
if(sum==src){// If the amount of bits (except the last) is the checksum (last digit) then ... 
// Serial.print(" ");
// Serial.print(sum);
// Serial.print(" ");
// Serial.print(src);
Serial.print("\t");
Serial.print(countLaser); //Output data of the internal counter
Serial.print("\t");
Serial.print(dist);//Output the distance and ... 
if(countLaser==99){// if the counter has reached the limit, then ... 
Serial1.write("*00084553#"); //give the command to start a new cycle 
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

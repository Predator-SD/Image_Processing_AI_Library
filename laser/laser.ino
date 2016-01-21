#include <Servo.h>
#include <SoftwareSerial.h>
int sum=0;
int input;
int a[181];
SoftwareSerial PC(2,3); // RX, TX
SoftwareSerial LASER(4, 5); // RX, TX
Servo myservo;
int pos = 0;
int strstart_P(const char *s1, const char * PROGMEM s2)
{
    return strncmp_P(s1, s2, strlen_P(s2)) == 0;
}
int getdist(void)
{
    char buf[64];
    char *comma;
    int dist;
    int rc;
    for (;;) {
        rc = LASER.readBytesUntil('\n', buf, sizeof(buf));
        buf[rc] = '\0';
        if (!strstart_P(buf, PSTR("Dist: ")))
            continue;
        comma = strchr(buf, ',');
        if (comma == NULL)
            continue;
        *comma = '\0';
        dist = atoi(buf + strlen_P(PSTR("Dist: ")));
        return dist;
    }
}
void setup(void)
{
    LASER.begin(115200);
    PC.begin(9600);
    myservo.attach(9);
}
void loop(void)
{
    if(sum=180){
      sum=0;
    }
    for(pos = 0; pos <= 180; pos += 1)
    {
      myservo.write(pos);
      delay(15);
      int dist_mm;
      int dist_m;
      char buf[128];
      dist_mm = getdist();
      /*dist_m = dist_mm / 1000;
      snprintf_P(buf, sizeof(buf),
          PSTR("Laser distance: %d.%dm"),
          dist_m, dist_mm % 1000);
      Serial.println(buf);
      */
      if(sum<181){
        input=dist_mm;
        a[sum]=input;
        sum++;
      }else{
        PC.println("ERROR!!!");
      }
    }
    for (int i=0; i<181; i++) { PC.write(a[i]); }  
}

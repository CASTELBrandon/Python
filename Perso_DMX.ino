
int universize = 512;
uint8_t master = 255;
uint8_t dmxbuffer [512] = { };

void setup() {
  // put your setup code here, to run once:
  if (universize < 24){
    universize = 24;
  }
    dmxbuffer [0] = 255;      // Master at 100%
    dmxbuffer [1] = 255;      // Red at 100%
    dmxbuffer [3] = 0;      // Blue at 100%
    dmxbuffer [4] = 0;        // Auto
    dmxbuffer [5] = 0;
    
    pinMode(1, OUTPUT);
}
  

void loop() {

  //master = (analogRead(A4)) >> 2;
  //dmxbuffer [0] = (analogRead(A5)) >> 2;
  if (dmxbuffer [1] == 255)
    {
     dmxbuffer [1] = 0;
    }
  else {
    dmxbuffer [1]++;
    }
   if (dmxbuffer [2] == 0)
    {
     dmxbuffer [2] = 255;
    }
  else {
    dmxbuffer [2]--;
    }
  if (dmxbuffer [3] == 255)
    {
     dmxbuffer [3] = 0;
    }
  else {
    dmxbuffer [3]++;
    }
 
  digitalWrite(1, LOW);
  delayMicroseconds(88);
  
  Serial.begin(250000, SERIAL_8N2);                //  1 start bit at 0 and 2 stop bits at 1
  Serial.write(0);     // Start-code 8x0

  for (int i=1; i <= universize; i++) {
  Serial.write(dmxbuffer[i-1]*master/255);
  }

  Serial.end();
}

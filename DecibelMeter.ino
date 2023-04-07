const int sampleWindow = 50;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int I = 0;
#define SENSOR_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode (SENSOR_PIN, INPUT); // Set the signal pin as input 
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
 
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(SENSOR_PIN);                    //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   }
 
   peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
   int db = map(peakToPeak,20,900,49.5,90);        
 //  Serial.println(db);
//   int db_digital = map(db,)
  if (db > 49.5) {
    I = 1;
    Serial.println("1");
  }else{
    I = 0;
    Serial.println("0");
    }
    /*
  if (I == 1) {
    digitalWrite(LED, HIGH); // ถ้าค่า val เท่ากับ 1 สั่งให้ LED ติด
  //  Serial.println("LED_ON");
    millis();
    I = 0;
  }
  if (I == 2) {
    digitalWrite(LED, LOW); // ถ้าค่า val ไม่ใช่ 1 สั่งให้ LED ดับ
    //Serial.println("LED_OFF");
    I = 0;
  }
  */
}

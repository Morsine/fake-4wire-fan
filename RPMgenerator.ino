/* 

   ________    _                                   __ 
  / ____/ /_  (_)___  ____  ___  _________  __  __/ /_
 / /   / __ \/ / __ \/ __ \/ _ \/ ___/ __ \/ / / / __/
/ /___/ / / / / /_/ / /_/ /  __/ /  / / / / /_/ / /_  
\____/_/ /_/_/ .___/ .___/\___/_/  /_/ /_/\__,_/\__/  
            /_/   /_/         


Visit us: www.chippernut.com 
Written by: 
Jon Gulbrandson 
12/28/2014 

Kudos to: 
Adafruit (www.adafruit.com) 
Arduino (www.arduino.com) 

RPM SIGNAL GENERATOR 

This generates a square wave using the Arduino TONE command. 
The output is currently confiqured to Digital Pin #5. 
Wire this pin directly to the input of your SHIFT LIGHT TACH SIGNAL IN 
No Transistor is needed. 

*/ 

/********** CONFIGURATION **********/ 

/* INSTRUCTIONS 
Set your RPM lowpoint (RPM_MIN) to the lowest point, do not 
go lower than 2000 RPM. Set your RPM highpoint (RPM_MAX) to 
the redline of your vehicle. The Accel_Rate variable is used for 
the speed at which the generator sweeps through the RPM range. 
A higher Accel_Rate variable will result in a slower speed. Try to keep 
this between (10 - 50). 
*/ 

float RPM_MIN = 760; 
float RPM_MAX = 6000; 
int Accel_Rate = 10; 



/********** DEFINITIONS **********/ 


boolean accel = false; 
int x; 
long previousMillis = 0;
unsigned long currentMillis=0;


/********** SETUP **********/ 


void setup() { 
Serial.begin(9600);
pinMode(0, OUTPUT); 
RPM_MIN = (RPM_MIN / 60); 
RPM_MAX = (RPM_MAX / 60); 
x = RPM_MIN; 
} 


/********** MAIN LOOP **********/ 

void loop() { 

//tone(5,70);

      while (accel==false){
         currentMillis = millis();
        if(currentMillis - previousMillis > Accel_Rate) {
        previousMillis = currentMillis;         
        x++; 
        tone(5,x); 
        if (x>RPM_MAX){accel=true;} 
        }
      }
       
      while (accel==true){
         currentMillis = millis();
        if(currentMillis - previousMillis > Accel_Rate) {
        previousMillis = currentMillis;         
        x--; 
        tone(5,x); 
        if (x<RPM_MIN){accel=false;} 
        }
      }
  }


   

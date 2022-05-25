
/* Flashing tachometer
*
* Reads input from potentiometer and flashes a set of leds
* Designed to eventually be used as a flashing led car tachometer
*
*/

int potPin = 2;                 // select the input pin for the potentiometer
int firstGear = 2;              // select the pin output for first gear
int secondGear = 3;             // select the pin output for second gear led
int thirdGear = 4;              // select the pin output for third gear led
int fourthGear = 5;             // select the pin output for fourth gear led
int fifthGear = 6;              // select the pin output for fifth gear led
int rpmRead = 0;                // variable to store the value coming from the sensor

void setup() {
//Sets gear pins to OUTPUT
 pinMode(firstGear, OUTPUT);     
 pinMode(secondGear, OUTPUT);   
 pinMode(thirdGear, OUTPUT);     
 pinMode(fourthGear, OUTPUT);   
 pinMode(fifthGear, OUTPUT); 
 
 //Opens serial   
 Serial.begin(9600);
}

void loop() {
 int rpmRead = analogRead(potPin);    // reads the value from the sensor
 
 //if rpm value is greater than 100, firstgear led turns on
 if(rpmRead > 100) {
   digitalWrite(firstGear, HIGH);
 } else {
   digitalWrite(firstGear, LOW);
 }
 
 //if rpm value is greater than 200, second gear led turns on
 if(rpmRead > 200) {
   digitalWrite(secondGear, HIGH);
 } else {
   digitalWrite(secondGear, LOW);
 }
 
 //if rpm value is greater than 300, third led turns on
 if(rpmRead > 300) {
   digitalWrite(thirdGear, HIGH);
 } else {
   digitalWrite(thirdGear, LOW);
 }
 
 //if rpm value is greater than 400, fourth gear led turns on
 if(rpmRead > 400) {
   digitalWrite(fourthGear, HIGH);
 } else {
   digitalWrite(fourthGear, LOW);
 }
 
 //if rpm value is greater than 500, fifth gear led turns on
 if(rpmRead > 500) {
   digitalWrite(fifthGear, HIGH);
 } else {
   digitalWrite(fifthGear, LOW);
 }
 
 //if rpm value is greater than 600, sixth gear led turns on
 if(rpmRead > 600) {
   digitalWrite(firstGear, HIGH);
   digitalWrite(secondGear, HIGH);
   digitalWrite(thirdGear, HIGH);
   digitalWrite(fourthGear, HIGH);
   digitalWrite(fifthGear, HIGH);
   
   //delay. will determine how fast LEDs flash when RPMs are maxed out
   delay(100);
   
   
   //turns off all gear LEDs
   digitalWrite(firstGear, LOW);
   digitalWrite(secondGear, LOW);
   digitalWrite(thirdGear, LOW);
   digitalWrite(fourthGear, LOW);
   digitalWrite(fifthGear, LOW);

 }//while
 
 //prints rpm value
 Serial.print(rpmRead);
 delay(200);
}
/*
 * This program switches between red, green, and blue every fourth click.
 */

int pushButton = A0;
int counter = 0;
int redLED = 12;
int greenLED = 27;
int blueLED = 33;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initializing LED pin outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  // initializing input pin as input
  pinMode(A0, INPUT);
}

void loop() {
  // read button input
  int buttonState = digitalRead(pushButton);
  delay(100);
  if (buttonState == HIGH) {
    counter++;
    delay(100);
  }
  Serial.println(counter);

  // Red state
  if(counter == 4) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  //green state
  else if(counter == 8) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  }
  //Blue state
  else if(counter == 12) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
  }
  //White state
  else if(counter == 16) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH); 
  }
  //default state
  else {
    counter=0;
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }

}

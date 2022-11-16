// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

String spd = "speed";
String dir = "direction";

void setup() {
  //Serial monitor
  Serial.begin(9600);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  analogWrite(enA, 255);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}


void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}


void loop() {
  Serial.println("Would you like to change speed (1) or direction (0)?");

  while (Serial.available() == 0) {
  }
  
  int input = Serial.parseInt();

  serialFlush();

  //Read direction
  if(input == 0){

    Serial.println("Would you like to spin clockwise (1) or counterclockwise (0)?");

    while (Serial.available() == 0) {
    }
  
    int directionChoice = Serial.parseInt();
    serialFlush();

    if(directionChoice){
      Serial.println("Spinning clockwise");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }else{
      Serial.println("Spinning counter-clockwise");
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
    
  }else if(input == 1){

    Serial.println("Choose a speed integer value 0-5.");
    
    while (Serial.available() == 0) {
    }
    
    int speedChoice = Serial.parseInt();
    serialFlush();

    if(speedChoice == 0){
        analogWrite(enA, 0);
        Serial.println("Speed 0");
    }else if(speedChoice == 1){
        analogWrite(enA, 50);
        Serial.println("Speed 1");
    }else if(speedChoice == 2){
        analogWrite(enA, 100);
        Serial.println("Speed 2");
    }else if(speedChoice == 3){
        analogWrite(enA, 150);
        Serial.println("Speed 3");
    }else if(speedChoice == 4){
        analogWrite(enA, 200);
        Serial.println("Speed 4");
    }else if(speedChoice == 5){
        analogWrite(enA, 255);
        Serial.println("Speed 5");
    }
  }

}

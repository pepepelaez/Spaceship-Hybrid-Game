int motherPinA = 44;
#include <Servo.h>

int playerPin1A = 50;
int playerPin2A = 52;
int alienPin1A = 46;
int alienPin2A = 48;
int motherPinB = 45;
int playerPin1B = 51;
int playerPin2B = 53;
int alienPin1B = 47;
int alienPin2B = 49;
int motherPinC = 34;
int playerPin1C = 40;
int playerPin2C = 42;
int alienPin1C = 36;
int alienPin2C = 38;
int motherPinD = 35;
int playerPin1D = 39;
int playerPin2D = 43;
int alienPin1D = 37;
int alienPin2D = 41;
int motherbuzzer = 24;
int winRoomApin = 30;
int winRoomBpin = 31;
int winRoomCpin = 28;
int winRoomDpin = 29;
int h;
int h1;
int f1a;
int f1b;
int f1c;
int f1d;
int f2a;
int f2b;
int f2c;
int f2d;
int m;

Servo winRoomA;
Servo winRoomB;
Servo winRoomC;
Servo winRoomD;

void setup() {
  Serial.begin(19200);
  pinMode(playerPin1A, OUTPUT);
  pinMode(playerPin2A, OUTPUT);
  pinMode(playerPin1B, OUTPUT);
  pinMode(playerPin2B, OUTPUT);
  pinMode(motherPinA, OUTPUT);
  pinMode(motherPinB, OUTPUT);
  pinMode(motherPinC, OUTPUT);
  pinMode(motherPinD, OUTPUT);
  pinMode(alienPin1A, OUTPUT);
  pinMode(alienPin2A, OUTPUT);
  pinMode(alienPin1B, OUTPUT);
  pinMode(alienPin2B, OUTPUT);
  pinMode(alienPin1C, OUTPUT);
  pinMode(alienPin2C, OUTPUT);
  pinMode(alienPin1D, OUTPUT);
  pinMode(alienPin2D, OUTPUT);
  pinMode(playerPin1C, OUTPUT);
  pinMode(playerPin2C, OUTPUT);
  pinMode(playerPin1D, OUTPUT);
  pinMode(playerPin2D, OUTPUT);
  pinMode(motherbuzzer, OUTPUT);
  winRoomA.attach(winRoomApin);
  winRoomB.attach(winRoomBpin);
  winRoomC.attach(winRoomCpin);
  winRoomD.attach(winRoomDpin);
  //h is used to check when a player is in a position. 
  // the most recent equivalent of h will determine where the player is
  // thus determining what the player can do.
 h = 'h';
 h1 = 'h';
 // f is used to check if there is an alien in a specific room
 // it has to be specific for one alien so f1a is alien1A
 f1a = 'f';
 f1b = 'f';
 f1c = 'f';
 f1d = 'f';
 f2a = 'f';
 f2b = 'f';
 f2c = 'f';
 f2d = 'f';
 m = 'm';
 winRoomA.write(90);
 winRoomB.write(90);
 winRoomC.write(90);
 winRoomD.write(90);
}


void loop() {
 char x = Serial.read();
 
//light player 1 in A
if (x == 'a') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin1A, HIGH);
  digitalWrite(playerPin1B, LOW);
  digitalWrite(playerPin1C, LOW);
  digitalWrite(playerPin1D, LOW); 
  h = 'a';
}

//ligh player 1 in B
else if (x == 'b') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin1A, LOW);
  digitalWrite(playerPin1B, HIGH);
  digitalWrite(playerPin1C, LOW);
  digitalWrite(playerPin1D, LOW);
  h = 'b';
}

//light player 1 in C
else if (x == 'c') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin1A, LOW);
  digitalWrite(playerPin1B, LOW);
  digitalWrite(playerPin1C, HIGH);
  digitalWrite(playerPin1D, LOW);
  h = 'c';
}

//light player 1 in D
else if (x == 'd') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin1A, LOW);
  digitalWrite(playerPin1B, LOW);
  digitalWrite(playerPin1C, LOW);
  digitalWrite(playerPin1D, HIGH);
  h = 'd';
}

//light player 2 in A
else if (x == 'r') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin2A, HIGH);
  digitalWrite(playerPin2B, LOW);
  digitalWrite(playerPin2C, LOW);
  digitalWrite(playerPin2D, LOW);
  h1 = 'a';
}

//light player 2 in B
else if (x == 'p') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin2A, LOW);
  digitalWrite(playerPin2B, HIGH);
  digitalWrite(playerPin2C, LOW);
  digitalWrite(playerPin2D, LOW);
  h1 = 'b';
}
//light player 2 in C
else if (x == 'q') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin2A, LOW);
  digitalWrite(playerPin2B, LOW);
  digitalWrite(playerPin2C, HIGH);
  digitalWrite(playerPin2D, LOW);
  h1 = 'c';
}
//light player 2 in D
else if (x == 'l') {
  tone(motherbuzzer, 1000);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(playerPin2A, LOW);
  digitalWrite(playerPin2B, LOW);
  digitalWrite(playerPin2C, LOW);
  digitalWrite(playerPin2D, HIGH);
  h1 = 'd';
}

//spawn alien1 in A
else if (x == 's') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin1A, HIGH);
  f1a = 'a';
}

//spawn alien1 in B
else if (x == 't') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin1B, HIGH);
  f1b = 'b';
}

//spawn alien1 in C
else if (x == 'u') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin1C, HIGH);
  f1c = 'c';
}

//spawn alien1 in D
else if (x == 'v') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin1D, HIGH);
  f1d = 'd';
}

//spawn alien2 in A
else if (x == 'w') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin2A, HIGH);
  f2a = 'a';
}

// spawn alien2 in B
else if (x == 'x') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin2B, HIGH);
  f2b = 'b';
}

//spawn alien2 in C
else if (x == 'y') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin2C, HIGH);
  f2c = 'c';
}

//spawn alien2 in D
else if (x == 'z') {
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  tone(motherbuzzer, 200);
  delay(200);
  noTone(motherbuzzer);
  digitalWrite(alienPin2D, HIGH);
  f2d = 'd';
}

// killing alien1 by player1 in A
if ((h == 'a') && (f1a == 'a')) {
  if (x == 'k') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1A, LOW);
    f1a = 'f'; 
  }
  }
//killing alien1 by player1 in B
if ((h == 'b') && (f1b == 'b')) {
  if (x == 'k') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1B, LOW);
    f1b = 'f'; 
  }
}

//killing alien1 by player 1 in C
if ((h == 'c') && (f1c == 'c')) {
  if (x == 'k') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1C, LOW);
    f1c = 'f'; 
  }
}

//killing alien1 by player 1 in D
if ((h == 'd') && (f1d == 'd')) {
  if (x == 'k') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1D, LOW);
    f1d = 'f'; 
  }
}

//killing alien1 by player2 in A
if ((h1 == 'a') && (f1a == 'a')) {
  if (x == 'e') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1A, LOW);
    f1a = 'f';
  }   
}

//killing alien1 by player2 in B
if ((h1 == 'b') && (f1b == 'b')) {
  if (x == 'e') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1B, LOW);
    f1b = 'f';
  }   
}

//killing alien1 by player2 in C
if ((h1 == 'cr') && (f1c == 'c')) {
  if (x == 'e') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1C, LOW);
    f1c = 'f';
  }   
}

//killing alien1 by player2 in D
if ((h1 == 'd') && (f1d == 'd')) {
  if (x == 'e') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin1D, LOW);
    f1d = 'f';
  }   
}

//killing alien2 by player1 in A
if ((h == 'a') && (f2a == 'a')) {
  if (x == 'f') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2A, LOW);
    f2a = 'f';  
  }
}

//killing alien2 by player1 in B
if ((h == 'b') && (f2b == 'b')) {
  if (x == 'f') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2B, LOW);
    f2b = 'f';  
  }
}
  
//killing alien2 by player1 in C
if ((h == 'c') && (f2c == 'c')) {
  if (x == 'f') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2C, LOW);
    f2c = 'f';  
  }
}

//killing alien2 by player1 in D
if ((h == 'd') && (f2d == 'd')) {
  if (x == 'f') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2D, LOW); 
    f2d = 'f'; 
  }
}

//killing alien2 by player2 in A
if ((h1 == 'a') && (f2a == 'a')) {
  if (x == 'h') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2A, LOW);
    f2a = 'f';
  }   
}

//killing alien2 by player2 in B
if ((h1 == 'b') && (f2b == 'b')) {
  if (x == 'h') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2B, LOW);
    f2b = 'f';
  }   
}
//killing alien2 by player2 in C
if ((h1 == 'c') && (f2c == 'c')) {
  if (x == 'h') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2C, LOW);
    f2c = 'f';
  }   
}
//killing alien2 by player2 in D
if ((h1 == 'd') && (f2d == 'd')) {
  if (x == 'h') {
    tone(motherbuzzer, 1000);
    delay(100);
    tone(motherbuzzer, 500);
    delay(100);
    tone(motherbuzzer, 1000);
    delay(100);
    noTone(motherbuzzer);
    digitalWrite(alienPin2D, LOW);
    f2d = 'f';
  }   
}

//setting roomA by player1 
if ((h == 'a') && (f1a == 'f') && (f2a == 'f')) {
  if (x == 'g') {
    tone(motherbuzzer, 1000);
    winRoomA.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}

//setting roomB by player1
if ((h == 'b') && (f1b == 'f') && (f2b == 'f')) {
  if (x == 'g') {
    tone(motherbuzzer, 1000);
    winRoomB.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomC by player1
if ((h == 'c') && (f1c == 'f') && (f2c == 'f')) {
  if (x == 'g') {
    tone(motherbuzzer, 1000);
    winRoomC.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomD by player1
if ((h == 'd') && (f1d == 'f') && (f2d == 'f')) {
  if (x == 'g') {
    tone(motherbuzzer, 1000);
    winRoomD.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomA by player2
if ((h1 == 'a') && (f1a == 'f') && (f2a == 'f')) {
  if (x == 'i') {
    tone(motherbuzzer, 1000);
    winRoomA.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomB by player2
if ((h1 == 'b') && (f1b == 'f') && (f2b == 'f')) {
  if (x == 'i') {
    tone(motherbuzzer, 1000);
    winRoomB.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomC by player2
if ((h1 == 'c') && (f1c == 'f') && (f2c == 'f')) {
  if (x == 'i') {
    tone(motherbuzzer, 1000);
    winRoomC.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//setting roomD by player2
if ((h1 == 'd') && (f1d == 'f') && (f2d == 'f')) {
  if (x == 'i') {
    tone(motherbuzzer, 1000);
    winRoomD.write(180);
    delay(1000);
    tone(motherbuzzer, 500);
    delay(600);
    noTone(motherbuzzer);
  }
}
//mother light A
if (x == '1') {
  tone(motherbuzzer, 100);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(motherPinA, HIGH);
  digitalWrite(motherPinB, LOW);
  digitalWrite(motherPinC, LOW);
  digitalWrite(motherPinD, LOW); 
  m = 'a';
}
//mother light B
if (x == '2') {
  tone(motherbuzzer, 100);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(motherPinA, LOW);
  digitalWrite(motherPinB, HIGH);
  digitalWrite(motherPinC, LOW);
  digitalWrite(motherPinD, LOW); 
  m = 'b';
}

//mother light C
if (x == '3') {
  tone(motherbuzzer, 100);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(motherPinA, LOW);
  digitalWrite(motherPinB, LOW);
  digitalWrite(motherPinC, HIGH);
  digitalWrite(motherPinD, LOW); 
  m = 'c';
}
//mother light D
if (x == '4') {
  tone(motherbuzzer, 100);
  delay(250);
  noTone(motherbuzzer);
  digitalWrite(motherPinA, LOW);
  digitalWrite(motherPinB, LOW);
  digitalWrite(motherPinC, LOW);
  digitalWrite(motherPinD, HIGH); 
  m = 'd';
}
}



//  digitalWrite(playerPin1A, HIGH);
//  digitalWrite(playerPin2A, HIGH);
//  digitalWrite(playerPin1B, HIGH);
//  digitalWrite(playerPin2B, HIGH);
//  digitalWrite(playerPin1C, HIGH);
//  digitalWrite(playerPin2C, HIGH);
//  digitalWrite(playerPin1D, HIGH);
//  digitalWrite(playerPin2D, HIGH);
//  digitalWrite(motherPinA, HIGH);
//  digitalWrite(motherPinB, HIGH);
//  digitalWrite(motherPinC, HIGH);
//  digitalWrite(motherPinD, HIGH);
//  digitalWrite(alienPin1A, HIGH);
//  digitalWrite(alienPin2A, HIGH);
//  digitalWrite(alienPin1B, HIGH);
//  digitalWrite(alienPin2B, HIGH);
//  digitalWrite(alienPin1C, HIGH);
//  digitalWrite(alienPin2C, HIGH);
//  digitalWrite(alienPin1D, HIGH);
//  digitalWrite(alienPin2D, HIGH);
//  delay(1000);                 
//  digitalWrite(playerPin1A, LOW);
//  digitalWrite(playerPin2A, LOW);
//  digitalWrite(playerPin1B, LOW);
//  digitalWrite(playerPin2B, LOW);
//  digitalWrite(playerPin1C, LOW);
//  digitalWrite(playerPin2C, LOW);
//  digitalWrite(playerPin1D, LOW);
//  digitalWrite(playerPin2D, LOW);
//  digitalWrite(motherPinA, LOW);
//  digitalWrite(motherPinB, LOW);
//  digitalWrite(motherPinC, LOW);
//  digitalWrite(motherPinD, LOW);
//  digitalWrite(alienPin1A, LOW);
//  digitalWrite(alienPin2A, LOW);
//  digitalWrite(alienPin1B, LOW);
//  digitalWrite(alienPin2B, LOW);
//  digitalWrite(alienPin1C, LOW);
//  digitalWrite(alienPin2C, LOW);
//  digitalWrite(alienPin1D, LOW);
//  digitalWrite(alienPin2D, LOW);
//  delay(1000); 

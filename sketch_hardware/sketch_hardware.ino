#include <Math.h>
const int ballSwitch = 2;
const int led = 13;
const int xPot = A0;
const int yPot = A1;

int xPotValue = 0;
int yPotValue = 0;

int prevXPotValue = 10;
int prevYPotValue = 10;

int threshold = 2;

char data[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  pinMode(ballSwitch, INPUT);

  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  for (int i = 0; i < 9; i++) {
    data[i] = 0;
  }
  // put your main code here, to run repeatedly:
  xPotValue = (analogRead(xPot) * 0.9) + (prevXPotValue * 0.1);
  yPotValue = (analogRead(yPot) * 0.9) + (prevYPotValue * 0.1);

  if (abs(xPotValue - prevXPotValue) > 1 || abs(yPotValue - prevYPotValue) > 1) {
    //    Serial.print("xPot Value: ");
    //    Serial.println(xPotValue);
    //    Serial.print("yPot Value: ");
    //    Serial.println(yPotValue);
    int x = xPotValue;
    int y = yPotValue;
    int count = 0;

    //count digits in x
    while (x != 0) {
      x /= 10;
      count++;
    }


    //create array
    if (count != 0) {
      count = 0;
      x = xPotValue;

      while (x != 0) {
        data[3 - count] = x % 10;
        x /= 10;
        count++;
      }
    }


    count = 0; //reset count

    while (y != 0) {
      y /= 10;
      count++;
    }


    //create array
    if (count != 0) {
      count = 0;
      y = yPotValue;

      while (y != 0) {
        data[7 - count] = y % 10;
        y /= 10;
        count++;
      }
    }

    for (int i = 0; i < 9; i++) {
      Serial.print(data[i], DEC);
    }
    Serial.println();



  }
  if (!digitalRead(ballSwitch)) {
    data[8] = 1;

    //Serial.println("Wipe!");
    //Serial.println(sizeof(data));
    //Serial.println(data, BIN);
    //delay(2000);
    for (int i = 0; i < 9; i++) {
      Serial.print(data[i], DEC);
    }
    Serial.println();

  }

  prevXPotValue = xPotValue;
  prevYPotValue = yPotValue;

  delay(100);

}

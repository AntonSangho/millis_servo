#include <Servo.h>

Servo myservo;

const int LED = 11;  
const int analogPin = A0;

unsigned long t1_prev = 0;  
unsigned long t2_prev = 0;  

const unsigned long t1_delay = 4;
const unsigned long t2_delay = 10;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(analogPin, INPUT);
  myservo.attach(3);
  Serial.begin(9600);
}

void loop() {

  //LED 밝기 
  unsigned long t1_now = millis();

  if (t1_now - t1_prev >= t1_delay) { //millis 함수로 받은 현재시간과 이전시간의 차이 값이 t1_delay의 값보다 클 경우
    t1_prev = t1_now;
    int t1_val = analogRead(analogPin);
    analogWrite(LED, t1_val/4);

  }

  //서보모터 제어
  unsigned long t2_now = millis();
  if (t2_now - t2_prev >= t2_delay) { //millis 함수로 받은 현재시간과 이전시간의 차이 값이 t2_delay의 값보다 클 경우
    t2_prev = t2_now;

    int t2_val = analogRead(analogPin);
    t2_val = map(t2_val, 0, 1023, 0, 180);
    myservo.write(t2_val);
  }
}

#include <Servo.h>

const int motor1Pin1 = 7;
const int motor1Pin2 = 8;
const int enablePin1 = 9;

const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
const int enablePin2 = 10;

const int motor3Pin1 = 2;
const int motor3Pin2 = 3;
const int enablePin3 = 4;

const int motor4Pin1 = 4;
const int motor4Pin2 = 5;
const int enablePin4 = 5;

const int servoPin = A0;
Servo myServo;

const int trigPin = 11;
const int echoPin = 12;

const int obstacleDistance = 10;
const int motorSpeed = 200;
bool isMovingForward = true;

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enablePin3, OUTPUT);
  
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enablePin4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  myServo.attach(servoPin);
  myServo.write(90);
  
  Serial.println("DC Motor Control System Ready!");
  delay(2000);
}

void loop() {
  if (checkObstacle()) {
    Serial.println("Obstacle detected! Stopping motors and changing direction.");
    stopAllMotors();
    changeDirection();
    delay(1000);
  }
  
  Serial.println("Moving forward for 30 seconds...");
  moveForward();
  delay(30000);
  
  if (checkObstacle()) {
    Serial.println("Obstacle detected! Stopping motors and changing direction.");
    stopAllMotors();
    changeDirection();
    delay(1000);
  }
  
  Serial.println("Moving backward for 1 minute...");
  moveBackward();
  delay(60000);
  
  if (checkObstacle()) {
    Serial.println("Obstacle detected! Stopping motors and changing direction.");
    stopAllMotors();
    changeDirection();
    delay(1000);
  }
  
  Serial.println("Alternating right and left turns for 1 minute...");
  alternateTurns();
  
  isMovingForward = true;
}

bool checkObstacle() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance < obstacleDistance;
}

void changeDirection() {
  isMovingForward = !isMovingForward;
  if (isMovingForward) {
    Serial.println("Changed to forward direction");
  } else {
    Serial.println("Changed to backward direction");
  }
}

void moveForward() {
  Serial.println("Moving FORWARD");
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  
  analogWrite(enablePin1, motorSpeed);
  analogWrite(enablePin2, motorSpeed);
  analogWrite(enablePin3, motorSpeed);
  analogWrite(enablePin4, motorSpeed);
}

void moveBackward() {
  Serial.println("Moving BACKWARD");
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
  
  analogWrite(enablePin1, motorSpeed);
  analogWrite(enablePin2, motorSpeed);
  analogWrite(enablePin3, motorSpeed);
  analogWrite(enablePin4, motorSpeed);
}

void turnRight() {
  Serial.println("Turning RIGHT");
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
  
  analogWrite(enablePin1, motorSpeed);
  analogWrite(enablePin2, motorSpeed);
  analogWrite(enablePin3, motorSpeed);
  analogWrite(enablePin4, motorSpeed);
}

void turnLeft() {
  Serial.println("Turning LEFT");
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  
  analogWrite(enablePin1, motorSpeed);
  analogWrite(enablePin2, motorSpeed);
  analogWrite(enablePin3, motorSpeed);
  analogWrite(enablePin4, motorSpeed);
}

void alternateTurns() {
  unsigned long startTime = millis();
  unsigned long duration = 60000;
  bool shouldTurnRight = true;
  
  while (millis() - startTime < duration) {
    if (millis() % 500 == 0) {
      if (checkObstacle()) {
        Serial.println("Obstacle detected! Stopping motors and changing direction.");
        stopAllMotors();
        changeDirection();
        delay(1000);
        return;
      }
    }
    
    if (shouldTurnRight) {
      turnRight();
      delay(3000);
    } else {
      turnLeft();
      delay(3000);
    }
    
    shouldTurnRight = !shouldTurnRight;
  }
  
  stopAllMotors();
}

void stopAllMotors() {
  Serial.println("Stopping all motors");
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  
  analogWrite(enablePin1, 0);
  analogWrite(enablePin2, 0);
  analogWrite(enablePin3, 0);
  analogWrite(enablePin4, 0);
} 
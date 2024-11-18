
#include <AFMotor.h>
 
AF_DCMotor motor1(1);  // Create motor #1 using M1 connector
AF_DCMotor motor2(2);  // Create motor #2 using M2 connector
AF_DCMotor motor3(3);  // Create motor #3 using M3 connector
AF_DCMotor motor4(4);  // Create motor #4 using M4 connector
 
char command;
 
void setup() {
    Serial.begin(9600);  // Start serial communication at 9600 baud rate
    motor1.setSpeed(255);  // Set initial motor speeds
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
}
 
void loop() {
    if (Serial.available() > 0) {
        command = Serial.read();  // Read the incoming command
 
        if (command == 'F') {
            forward();
        } else if (command == 'B') {
            backward();
        } else if (command == 'L') {
            turnLeft();
        } else if (command == 'R') {
            turnRight();
        } else if (command == 'S') {
            stop();
        }
    }
}
 
void forward() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
 
void backward() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}
 
void turnLeft() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
 
void turnRight() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}
 
void stop() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}
// Define ultrasonic sensor pin numbers
int triggerPin1 = 2;
int echoPin1 = 3;

int triggerPin2 = 4;
int echoPin2 = 5;

int triggerPin3 = 6;
int echoPin3 = 7;

int triggerPin4 = 8;
int echoPin4 = 9;

int originX = 0;
int originY = 0;
 int chamberwidth =500;
int chamberheight = 600;

// Initialize variables for distances
float sensorUPDistance;
float sensorRIGHTDistance;
float sensorDOWNDistance;
float sensorLEFTDistance;

void setup() {
  // Set pin modes for trigger and echo pins
  pinMode(triggerPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(triggerPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(triggerPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  // Initialize serial communication if needed
  Serial.begin(9600);
}

void loop() {
  // Measure distances for each sensor
  sensorDOWNDistance = measureDistance(triggerPin1, echoPin1);
  sensorRIGHTDistance = measureDistance(triggerPin2, echoPin2);
  sensorUPDistance = measureDistance(triggerPin3, echoPin3);
  sensorLEFTDistance = measureDistance(triggerPin4, echoPin4);

  // Calculate coordinates using the distances
  // Use the measured distances to calculate the x and y coordinates on a 5m by 6m plane

  // Print or display the coordinates
  // For example, you can print the coordinates to the serial monitor
  Serial.print("X Coordinate: ");
  Serial.println(calculateXcoordinate(sensorRIGHTDistance,sensorLEFTDistance));
  Serial.print("Y Coordinate: ");
  Serial.println(calculateYcoordinate(sensorDOWNDistance,sensorUPDistance));
//debounce
  delay(100);
}

float measureDistance(int triggerPin, int echoPin) {
  // Measure distance using ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration / 2) * 0.03432; 
  // Convert duration to distance 
  //and 0.03432 is speed of sound in microSeconds
  // it is divided by 2 because the ultrasonic pulse travels back and forth 

  return distance;
}
float calculateYcoordinate(float downDistance,float UpDistance)
{
  float x = (UpDistance - downDistance)/2.0;
  return constrain(x,0.0,chamberheight);
  
}
float calculateXcoordinate(float rightDistance,float leftDistance)
{
  float x = (rightDistance - leftDistance)/2.0;
  return constrain(x,0.0,chamberwidth);
  
}

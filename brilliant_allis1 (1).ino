const int soilMoisturePin = 2;
const int ledPin = 10;


volatile bool sensorState = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(soilMoisturePin, INPUT);

  attachInterrupt(digitalPinToInterrupt(soilMoisturePin), handleInterrupt, CHANGE);
}

void loop() {

  if (sensorState) {
    // Blink the LED indicating moisture is present
	Serial.println("WET");
    sensorState = false;
    digitalWrite(ledPin, 0);
    delay(1000);
  } else {
    // Turn off the LED when moisture is not present
	Serial.println("DRY");
  }

  // Add a delay to avoid rapid readings
  delay(100);
}

void handleInterrupt() {
  sensorState = true;
  digitalWrite(ledPin, HIGH);
}

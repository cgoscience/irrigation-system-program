#define MOISTURE_PIN A2
#define PUMP_PIN 5

int soilHumidity;   // Soil moisture
int humidity = 50;  // Initialize the humidity

void setup() {
  // Pump control pin initialization
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);
}

void loop() {
  soilHumidity = map(analogRead(MOISTURE_PIN), 0, 1023, 0, 100); // Convert the soil moisture sensor to 0-100%
  if (soilHumidity > humidity) {
    pumpOn();
  } else {
    pumpOff();
  }
}

void pumpOn() {
  digitalWrite(PUMP_PIN, LOW);
}

void pumpOff() {
  digitalWrite(PUMP_PIN, HIGH);
}

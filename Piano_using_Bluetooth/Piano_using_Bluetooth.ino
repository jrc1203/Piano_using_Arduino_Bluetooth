#include <SoftwareSerial.h> // Include the SoftwareSerial library for Bluetooth communication

#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 493
#define NOTE_C_high 524

#define ACTIVATED LOW //Using low(GND) voltage to activate output

const int PIEZO = 11;
const int LED = 13;

const int BUTTON_C = 10;
const int BUTTON_D = 9;
const int BUTTON_E = 8;
const int BUTTON_F = 7;
const int BUTTON_G = 6;
const int BUTTON_A = 5;
const int BUTTON_B = 4;
const int BUTTON_C_high = 3;

// Bluetooth setup
const int BLUETOOTH_TX = 2; // Connect HC-05 TX to Arduino pin 2
const int BLUETOOTH_RX = 12; // Connect HC-05 RX to Arduino pin 12
SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX); // Create a SoftwareSerial object for Bluetooth

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C, HIGH);
  pinMode(BUTTON_D, INPUT);
  digitalWrite(BUTTON_D, HIGH);
  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E, HIGH);
  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F, HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G, HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A, HIGH);
  pinMode(BUTTON_B, INPUT);
  digitalWrite(BUTTON_B, HIGH);
  pinMode(BUTTON_C_high, INPUT);
  digitalWrite(BUTTON_C_high, HIGH);

  digitalWrite(LED, LOW);

  // Initialize Serial Monitor
  Serial.begin(9600); // Set the baud rate for the Serial Monitor

  // Initialize Bluetooth communication
  bluetooth.begin(9600); // Set the baud rate for the HC-05 module

  Serial.println("System initialized. Ready to receive inputs.");
}

void loop()
{
  // Button functionality
  while (digitalRead(BUTTON_C) == ACTIVATED)
  {
    tone(PIEZO, NOTE_C);
    digitalWrite(LED, HIGH);
    Serial.println("Button C pressed - NOTE_C played");
  }

  while (digitalRead(BUTTON_D) == ACTIVATED)
  {
    tone(PIEZO, NOTE_D);
    digitalWrite(LED, HIGH);
    Serial.println("Button D pressed - NOTE_D played");
  }

  while (digitalRead(BUTTON_E) == ACTIVATED)
  {
    tone(PIEZO, NOTE_E);
    digitalWrite(LED, HIGH);
    Serial.println("Button E pressed - NOTE_E played");
  }

  while (digitalRead(BUTTON_F) == ACTIVATED)
  {
    tone(PIEZO, NOTE_F);
    digitalWrite(LED, HIGH);
    Serial.println("Button F pressed - NOTE_F played");
  }

  while (digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO, NOTE_G);
    digitalWrite(LED, HIGH);
    Serial.println("Button G pressed - NOTE_G played");
  }

  while (digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO, NOTE_A);
    digitalWrite(LED, HIGH);
    Serial.println("Button A pressed - NOTE_A played");
  }

  while (digitalRead(BUTTON_B) == ACTIVATED)
  {
    tone(PIEZO, NOTE_B);
    digitalWrite(LED, HIGH);
    Serial.println("Button B pressed - NOTE_B played");
  }

  while (digitalRead(BUTTON_C_high) == ACTIVATED)
  {
    tone(PIEZO, NOTE_C_high);
    digitalWrite(LED, HIGH);
    Serial.println("Button C_high pressed - NOTE_C_high played");
  }

  // Check for input from Serial Monitor
  if (Serial.available()) // Check if data is available from Serial Monitor
  {
    char input = Serial.read(); // Read the incoming byte

    // Play the corresponding note based on Serial Monitor input
    playNote(input, "Serial Monitor");
  }

  // Check for input from Bluetooth
  if (bluetooth.available()) // Check if data is available from Bluetooth
  {
    char input = bluetooth.read(); // Read the incoming byte

    // Play the corresponding note based on Bluetooth input
    playNote(input, "Bluetooth");
  }

  noTone(PIEZO); // Stop the tone after playing
  digitalWrite(LED, LOW); // Turn off the LED
}

// Function to play a note based on input and log the source
void playNote(char input, const char* source)
{
  switch (input)
  {
    case '1':
      tone(PIEZO, NOTE_C);
      digitalWrite(LED, HIGH);
      delay(500); // Play the note for 500ms
      Serial.print(source);
      Serial.println(" input: 1 - NOTE_C played");
      break;
    case '2':
      tone(PIEZO, NOTE_D);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 2 - NOTE_D played");
      break;
    case '3':
      tone(PIEZO, NOTE_E);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 3 - NOTE_E played");
      break;
    case '4':
      tone(PIEZO, NOTE_F);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 4 - NOTE_F played");
      break;
    case '5':
      tone(PIEZO, NOTE_G);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 5 - NOTE_G played");
      break;
    case '6':
      tone(PIEZO, NOTE_A);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 6 - NOTE_A played");
      break;
    case '7':
      tone(PIEZO, NOTE_B);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 7 - NOTE_B played");
      break;
    case '8':
      tone(PIEZO, NOTE_C_high);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.print(source);
      Serial.println(" input: 8 - NOTE_C_high played");
      break;
    default:
      if (strcmp(source, "Bluetooth") == 0)
      {
        bluetooth.println("Use valid button from 1 to 8"); // Print error message for invalid input
      }
      Serial.print(source);
      Serial.println(" input: Invalid input received");
      break;
  }
}

const int buttonPin = 9;   
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; 

int buttonState = 0;

// Dice patterns for LEDs
const byte dicePatterns[6][7] = {
  {0, 0, 0, 1, 0, 0, 0}, // 1
  {1, 0, 0, 0, 0, 0, 1}, // 2
  {1, 0, 0, 1, 0, 0, 1}, // 3
  {1, 0, 1, 0, 1, 0, 1}, // 4
  {1, 0, 1, 1, 1, 0, 1}, // 5
  {1, 1, 1, 0, 1, 1, 1}  // 6
};

void setup() {
  // Initialize the LED pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Generate a random number between 1 and 6
    int diceRoll = random(1, 7);
    
    // Display the dice number using LEDs
    displayDice(diceRoll);
    
    // Wait until the button is released
    while (digitalRead(buttonPin) == HIGH) {
      delay(10); // Debounce delay
    }
  }
}

void displayDice(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], dicePatterns[num - 1][i]);
  }
}

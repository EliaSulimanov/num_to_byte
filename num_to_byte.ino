#define BYTE_LENGTH 8
#define OUTPUT_PINS_LENGTH 8
const unsigned int output_pins[8] = {2,3,4,5,6,7,8,9};

/**
 * Print bit array, LSB is on the right
 * Output pins mode assumed to be OUTPUT
 */
void printBitArray(const bool * bitArray) {
  for(int i = 0; i < OUTPUT_PINS_LENGTH; i++) {
    if(bitArray[i] == true) {
      digitalWrite(output_pins[i], HIGH);
    }
    else {
      digitalWrite(output_pins[i], LOW);
    }
  }
}

bool* numToBitArray(const int num) {
  bool * res = malloc(sizeof(bool) * 8);
  int temp = num;
  for(int i = 0; i < BYTE_LENGTH; i++) {
    res[i] = temp % 2;
    temp /= 2;
  }
  return res;
}

void setup() {
  for(int i = 0; i < OUTPUT_PINS_LENGTH; i++) {
    pinMode(output_pins[i], OUTPUT);
  }  
}

void loop() {
  for(int i = 0; i < 2^BYTE_LENGTH; i++) {
    bool* arr =  numToBitArray(i);
    printBitArray(arr);
    free(arr);
    delay(500);
  }
}

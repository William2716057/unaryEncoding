# Unary Message Encoder
This project is a C program that converts a text message into a binary representation and then encodes the binary message into a specific format. The encoded message can be used for various applications such as data transmission or storage in a more compact form.

## Features
- Converts each character in the input message to its 7-bit binary representation.
- Encodes the binary message using a specific pattern for compactness.
- Outputs the encoded message.
  
## How It Works
1. Convert Characters to Binary: Each character in the input message is converted to its 7-bit binary representation.
2. Encode Binary Message: The binary message is encoded using specific patterns:
- " 00 0" for a sequence starting with 0
" 0 0" for a sequence starting with 1
- Additional 0 for continuous sequences of the same bit.

## Getting Started
### Prerequisites
- A C compiler (e.g., GCC)
### Compilation
- To compile the program, use the following command:
```
gcc -o binary_encoder encode.c
```
### Usage
1. Run the compiled program.
2. Enter your message when prompted.
3. The encoded message will be displayed as output.

### Example
Input: abc

Output: 0 00 00 0000 0 000 00 000 0 0 00 0 0 00 00 000 0 00

### Code Explanation
The main parts of the code include:

1. charToBinary: Converts a character to its 7-bit binary representation.
2. encodeBinaryMessage: Encodes the binary message using predefined patterns.
3. main: Handles input, calls conversion and encoding functions, and prints the encoded message.

### charToBinary Function
```
void charToBinary(char c, char *binary) {
    for (int i = 6; i >= 0; i--) {
        binary[i] = (c & 1) + '0';
        c >>= 1;
    }
    binary[7] = '\0';
}
```

### encodeBinaryMessage Function
```
void encodeBinaryMessage(const char *binary, char *encodedMessage) {
    char lastChar = ' ';
    const char *encodedBits[2] = {" 00 0", " 0 0"};

    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != lastChar) {
            lastChar = binary[i];
            strcat(encodedMessage, encodedBits[lastChar - '0']);
        } else {
            strcat(encodedMessage, "0");
        }
    }
}
```
### main function
```
int main() {
    char MESSAGE[101];
    char binaryMessage[800] = "";  // Sufficient space for binary representation
    char encodedMessage[1600] = "";  // Sufficient space for encoded message

    // Read the input message
    scanf("%[^\n]", MESSAGE);

    // Convert message to binary
    for (int i = 0; i < strlen(MESSAGE); i++) {
        char binary[8];
        charToBinary(MESSAGE[i], binary);
        strcat(binaryMessage, binary);
    }

    // Encode the binary message
    encodeBinaryMessage(binaryMessage, encodedMessage);

    // Print the encoded message (skip the initial space)
    printf("%s\n", encodedMessage + 1);

    return 0;
}
```

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void charToBinary(char c, char *binary) {
    for (int i = 6; i >= 0; i--) {
        binary[i] = (c & 1) + '0';
        c >>= 1;
    }
    binary[7] = '\0';
}


// Function to encode the binary message
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

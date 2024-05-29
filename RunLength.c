#include <stdbool.h>
#include <stdio.h>
void Encode(char str[], char res[], int len, int *resLen) {

    char current, last;
    size_t startingPos = 0, num = 0;
    for (size_t i = 1; i < len; i++) {
        last = str[i - 1];
        current = str[i];
        if (last != current) {
            res[2 * num] = (i - startingPos);
            res[2 * num + 1] = last;

            startingPos = i;
            num++;
        }
        if (i == len - 1) {
            res[2 * num] = (i - startingPos + 1);
            res[2 * num + 1] = str[startingPos];
            num++;
            res[2 * num] = -1;
            *resLen = 2 * num;
        }
    }
}

void Decode(char encoded[], int encodedLen, char decoded[], int starterLen) {
    size_t pos = 0, i = 0;
    int count = 0;
    char letter;
    for (size_t i = 0; i < encodedLen; i += 2) {
        count = encoded[i];
        letter = encoded[i + 1];
        for (size_t o = 0; o < count; o++) {
            decoded[pos++] = letter;
        }

        if (count + 2 == -1)
            break;
    }
    decoded[pos] = '\0';
}

int main() {
    int starterLen = 14, encodedLen = 2 * starterLen;
    // char starter[14] = "AAAABBCAAFFFFE";      //Shorter encoded
    char starter[14] = "ABCDEFGHJKLMNO"; // Longer encoded
    char encoded[2 * 14] = "";
    char decoded[14] = "";

    printf("STARTER  ");

    for (size_t i = 0; i < starterLen; i++) {
        printf("%c", starter[i]);
    }

    printf("\nENCODED  ");
    Encode(starter, encoded, starterLen, &encodedLen);
    for (size_t i = 0; i < encodedLen; i += 2) {
        printf("%d%c", encoded[i], encoded[i + 1]);
    }

    printf("\nDECODED  ");
    Decode(encoded, encodedLen, decoded, starterLen);
    for (size_t i = 0; i < starterLen; i++) {
        printf("%c", decoded[i]);
    }

    if (encodedLen < starterLen) {
        printf("\nEncoding Shorter");
    } else
        printf("\nEncoding longer, use starter list");

    printf("\n");
}

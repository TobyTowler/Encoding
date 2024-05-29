#include <stdio.h>
void Encode(char str[], char res[], int len) {

    char current, last;
    size_t startingPos = 0, num = 0;
    for (size_t i = 1; i < len; i++) {
        last = str[i - 1];
        current = str[i];
        // printf("%c, %c \n", last, current);
        if (last != current) {
            res[2 * num] = (i - startingPos);
            res[2 * num + 1] = last;

            startingPos = i;
            num++;
        }
        if (i == len - 1) {
            res[2 * num] = (i - startingPos + 1);
            res[2 * num + 1] = str[startingPos];
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
    }
}

int main() {
    int starterLen = 14, encodedLen = starterLen * 2;
    char starter[14] = "AAAABBCAAFFFFE";
    char encoded[2 * 14] = "";
    char decoded[14] = "";

    printf("STARTER  ");

    for (size_t i = 0; i < starterLen; i++) {
        printf("%c", starter[i]);
    }

    printf("\nENCODED  ");
    Encode(starter, encoded, starterLen);
    for (size_t i = 0; i < encodedLen; i += 2) {
        printf("%d", encoded[i]);
        printf("%c", encoded[i + 1]);
    }

    printf("\nDECODED  ");
    Decode(encoded, encodedLen, decoded, starterLen);
    for (size_t i = 0; i < starterLen; i++) {
        printf("%c", decoded[i]);
    }

    printf("\n");
}

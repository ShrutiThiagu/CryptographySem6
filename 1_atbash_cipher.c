#include <stdio.h>
#include <string.h>
#include <ctype.h>
void atbash_cipher(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'Z' - (text[i] - 'A');
            } 
            else {
                text[i] = 'z' - (text[i] - 'a');
            }
        }
    }
}
int main() {
    char text[100];
    printf("Enter the Plaintext:");
    scanf("%s",text);
    atbash_cipher(text);
    printf("Ciphertext: %s\n", text);
    return 0;
}


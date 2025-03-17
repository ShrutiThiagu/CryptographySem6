#include <stdio.h>
#include <string.h>
#include <ctype.h>

void beaufortCipher(char input[], char key[], char output[]) {
    int textLength = strlen(input);
    int keyLength = strlen(key);

    printf("\nCipher Steps:\n");
    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            char keyBase = isupper(key[j % keyLength]) ? 'A' : 'a';
            int shift = key[j % keyLength] - keyBase;  
            
            output[i] = ((shift - (input[i] - base) + 26) % 26) + base;
            
            printf("%c(%d) - %c(%d) -> %c(%d)\n",
                   key[j % keyLength], shift,
                   input[i], input[i] - base,
                   output[i], output[i] - base);
            j++; 
        } else {
            output[i] = input[i]; 
        }
    }
    output[textLength] = '\0';
    printf("Final Output: %s\n", output);
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter keyword: ");
    scanf("%s", key);
    beaufortCipher(plaintext, key, ciphertext);
    printf("\nCiphertext: %s\n", ciphertext);

    // Decryption (same function)
    char decryptedText[100];
    beaufortCipher(ciphertext, key, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}


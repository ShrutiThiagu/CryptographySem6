#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gronsfeldEncrypt(char plaintext[], char key[], char ciphertext[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);

    printf("\nEncryption Steps:\n");
    for (int i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = key[i % keyLength] - '0';  // Convert key digit to integer
            ciphertext[i] = ((plaintext[i] - base + shift) % 26) + base;

            printf("%c(%d) + %d -> %c(%d)\n",
                   plaintext[i], plaintext[i] - base,
                   shift,
                   ciphertext[i], ciphertext[i] - base);
        } else {
            ciphertext[i] = plaintext[i];  // Keep non-alphabet characters unchanged
        }
    }
    ciphertext[textLength] = '\0';
    printf("Final Ciphertext: %s\n", ciphertext);
}

void gronsfeldDecrypt(char ciphertext[], char key[]) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(key);
    char plaintext[textLength + 1];

    printf("\nDecryption Steps:\n");
    for (int i = 0; i < textLength; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int shift = key[i % keyLength] - '0';  // Convert key digit to integer
            plaintext[i] = ((ciphertext[i] - base - shift + 26) % 26) + base;

            printf("%c(%d) - %d -> %c(%d)\n",
                   ciphertext[i], ciphertext[i] - base,
                   shift,
                   plaintext[i], plaintext[i] - base);
        } else {
            plaintext[i] = ciphertext[i];  // Keep non-alphabet characters unchanged
        }
    }
    plaintext[textLength] = '\0';
    printf("Final Decrypted Text: %s\n", plaintext);
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter numeric key (digits only): ");
    scanf("%s", key);

    gronsfeldEncrypt(plaintext, key, ciphertext);
    gronsfeldDecrypt(ciphertext, key);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

void runningKeyEncrypt(char plaintext[], char key[], char ciphertext[]) {
    int textLength = strlen(plaintext);
    printf("\nEncryption Steps:\n");

    for (int i = 0; i < textLength; i++) {
        char base = isupper(plaintext[i]) ? 'A' : 'a';
        int keyShift = toupper(key[i]) - 'A';

        ciphertext[i] = ((plaintext[i] - base + keyShift) % 26) + base;

        printf("%c(%d) + %c(%d) -> %c(%d)\n",
               plaintext[i], plaintext[i] - base,
               key[i], keyShift,
               ciphertext[i], ciphertext[i] - base);
    }
    ciphertext[textLength] = '\0';
    printf("\nFinal Ciphertext: %s\n", ciphertext);
}

void runningKeyDecrypt(char ciphertext[], char key[], char decryptedText[]) {
    int textLength = strlen(ciphertext);
    printf("\nDecryption Steps:\n");

    for (int i = 0; i < textLength; i++) {
        char base = isupper(ciphertext[i]) ? 'A' : 'a';
        int keyShift = toupper(key[i]) - 'A';

        decryptedText[i] = ((ciphertext[i] - base - keyShift + 26) % 26) + base;

        printf("%c(%d) - %c(%d) -> %c(%d)\n",
               ciphertext[i], ciphertext[i] - base,
               key[i], keyShift,
               decryptedText[i], decryptedText[i] - base);
    }
    decryptedText[textLength] = '\0';
    printf("\nFinal Decrypted Text: %s\n", decryptedText);
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decryptedText[100];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter running key (must be at least as long as plaintext): ");
    scanf("%s", key);

    runningKeyEncrypt(plaintext, key, ciphertext);
    printf("\nCiphertext: %s\n", ciphertext);

    runningKeyDecrypt(ciphertext, key, decryptedText);
    printf("\nDecrypted Text: %s\n", decryptedText);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

void autokeyEncrypt(char plaintext[], char keyword[], char ciphertext[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(keyword);
    char extendedKey[textLength];

    strcpy(extendedKey, keyword);
    strncat(extendedKey, plaintext, textLength - keyLength);
    
    printf("\nExtended Key: %s\n", extendedKey);
    printf("\nEncryption Steps:\n");

    for (int i = 0; i < textLength; i++) {
        char base = isupper(plaintext[i]) ? 'A' : 'a';
        int keyShift = extendedKey[i] - base;
        
        ciphertext[i] = ((plaintext[i] - base + keyShift) % 26) + base;

        printf("%c(%d) + %c(%d) -> %c(%d)\n",
               plaintext[i], plaintext[i] - base,
               extendedKey[i], keyShift,
               ciphertext[i], ciphertext[i] - base);
    }
    ciphertext[textLength] = '\0';
    printf("\nFinal Ciphertext: %s\n", ciphertext);
}

void autokeyDecrypt(char ciphertext[], char keyword[], char decryptedText[]) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(keyword);
    char extendedKey[textLength];

    strcpy(extendedKey, keyword);
    printf("\nDecryption Steps:\n");

    for (int i = 0; i < textLength; i++) {
        char base = isupper(ciphertext[i]) ? 'A' : 'a';
        int keyShift = extendedKey[i] - base;

        decryptedText[i] = ((ciphertext[i] - base - keyShift + 26) % 26) + base;
        extendedKey[i + keyLength] = decryptedText[i];

        printf("%c(%d) - %c(%d) -> %c(%d)\n",
               ciphertext[i], ciphertext[i] - base,
               extendedKey[i], keyShift,
               decryptedText[i], decryptedText[i] - base);
    }
    decryptedText[textLength] = '\0';
    printf("\nFinal Decrypted Text: %s\n", decryptedText);
}

int main() {
    char plaintext[100], keyword[100], ciphertext[100], decryptedText[100];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter keyword: ");
    scanf("%s", keyword);

    autokeyEncrypt(plaintext, keyword, ciphertext);
    printf("\nCiphertext: %s\n", ciphertext);

    autokeyDecrypt(ciphertext, keyword, decryptedText);
    printf("\nDecrypted Text: %s\n", decryptedText);

    return 0;
}

	

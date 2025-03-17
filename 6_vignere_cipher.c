#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char plaintext[], char keyword[], char ciphertext[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(keyword);

    printf("\nEncryption Steps:\n");
    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char keyBase = isupper(keyword[j % keyLength]) ? 'A' : 'a';
            int shift = keyword[j % keyLength] - keyBase;
            ciphertext[i] = ((plaintext[i] - base + shift) % 26) + base;

            printf("%c(%d) + %c(%d) -> %c(%d)\n",
                   plaintext[i], plaintext[i] - base,
                   keyword[j % keyLength], shift,
                   ciphertext[i], ciphertext[i] - base);
            
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[textLength] = '\0';
    printf("Final Ciphertext: %s\n", ciphertext);
}

void vigenereDecrypt(char ciphertext[], char keyword[]) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(keyword);
    char plaintext[textLength + 1];

    printf("\nDecryption Steps:\n");
    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            char keyBase = isupper(keyword[j % keyLength]) ? 'A' : 'a';
            int shift = keyword[j % keyLength] - keyBase;
            plaintext[i] = ((ciphertext[i] - base - shift + 26) % 26) + base;

            printf("%c(%d) - %c(%d) -> %c(%d)\n",
                   ciphertext[i], ciphertext[i] - base,
                   keyword[j % keyLength], shift,
                   plaintext[i], plaintext[i] - base);
            
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[textLength] = '\0';
    printf("Final Decrypted Text: %s\n", plaintext);
}

int main() {
    char plaintext[100], keyword[100], ciphertext[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter keyword: ");
    scanf("%s", keyword);
    vigenereEncrypt(plaintext, keyword, ciphertext);
    vigenereDecrypt(ciphertext, keyword);
    return 0;
}

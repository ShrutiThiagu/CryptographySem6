#include <stdio.h>
#include <ctype.h>

void caesar_cipher(char *t, int s) {
    for (int i = 0; t[i]; i++)
        if (isalpha(t[i]))
            t[i] = isupper(t[i]) ? 'A' + (t[i] - 'A' + s) % 26 : 'a' + (t[i] - 'a' + s) % 26;
}
void caesar_decipher(char *t, int s) {
    caesar_cipher(t, 26 - (s % 26));
}

int main() {
    char text[100];
    int shift;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter Shift Value: ");
    scanf("%d", &shift);

    printf("\nENCRYPTION:\n");
    caesar_cipher(text, shift);
    printf("Ciphertext: %s", text);

    printf("\nDECRYPTION:\n");
    caesar_decipher(text, shift);
    printf("Plaintext: %s", text);
    return 0;
}

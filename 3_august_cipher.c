#include <stdio.h>
#include <ctype.h>

void august_cipher(char *t) {
    for (int i = 0; t[i]; i++)
        if (isalpha(t[i]))
            t[i] = isupper(t[i]) ? 'A' + (t[i] - 'A' + 1) % 26 : 'a' + (t[i] - 'a' + 1) % 26;
}
void august_decipher(char *t) {
    for (int i = 0; t[i]; i++)
        if (isalpha(t[i]))
            t[i] = isupper(t[i]) ? 'A' + (t[i] - 'A' - 1 + 26) % 26 : 'a' + (t[i] - 'a' - 1 + 26) % 26;
}
int main() {
    char text[100];
    int shift;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("\nENCRYPTION:\n");
    august_cipher(text);
    printf("Ciphertext: %s", text);

    printf("\nDECRYPTION:\n");
    august_decipher(text);
    printf("Plaintext: %s", text);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void atbash_cipher(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'Z' - (text[i] - 'A');
            } else {
                text[i] = 'z' - (text[i] - 'a');
            }
        }
    }
}
// Atbash Cipher is self-inverse - Use the same encrypt function to decrypt
void atbash_decrypt(char *text) {
    atbash_cipher(text); 
}

int main() {
    char text[100];
    int choice;
    printf("Enter text: ");
    scanf("%s", text);
    
    printf("ENCRYPTION:\n");
    atbash_cipher(text);
    printf("Ciphertext: %s\n\n", text);
    
    printf("DECRYPTION:\n");
    atbash_decrypt(text);
    printf("Plaintext: %s\n", text);
    return 0;
}

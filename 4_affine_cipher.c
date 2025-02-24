#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int mod_inverse(int A, int m) {
    for (int i = 1; i < m; i++)
        if ((A * i) % m == 1)
            return i;
}
int get_user_A() {
    int coprimes[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    int A;
    printf("Valid values for A (coprime with 26): ");
    for (int i = 0; i < 12; i++) 
        printf("%d ", coprimes[i]);
    printf("\nChoose A: ");
    scanf("%d", &A);
    for (int i = 0; i < 12; i++) 
        if (A == coprimes[i]) 
            return A;
}

void affine_cipher(char *t, int A, int B) {
    printf("\nENCRYPTION: \n");
    printf("Numeric values: ");
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            printf("%d ", x);
        }
    }
    printf("\nApplying formula (%dx + %d): ", A, B);
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            int transformed = (A * x + B);
            printf("%d ", transformed);
        }
    }
    printf("\nApplying mod 26: ");
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            int mod_result = (A * x + B) % 26;
            printf("%d ", mod_result);
            t[i] = (isupper(t[i]) ? 'A' : 'a') + mod_result;
        }
    }
    printf("\nCiphertext: %s\n", t);
}

void affine_decipher(char *t, int A, int B) {
    int A_inv = mod_inverse(A, 26);
    printf("DECRYPTION: \n");
    printf("Ciphertext: %s", t);
    printf("Numeric values: ");
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            printf("%d ", x);
        }
    }
    printf("\nApplying inverse formula %d(x - %d): ", A_inv, B);
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            int transformed = A_inv * (x - B + 26);
            printf("%d ", transformed);
        }
    }
    printf("\nApplying mod 26: ");
    for (int i = 0; t[i]; i++) {
        if (isalpha(t[i])) {
            int x = t[i] - (isupper(t[i]) ? 'A' : 'a');
            int mod_result = (A_inv * (x - B + 26)) % 26;
            printf("%d ", mod_result);
            t[i] = (isupper(t[i]) ? 'A' : 'a') + mod_result;
        }
    }
    printf("\nPlaintext: %s\n", t);
}

int main() {
    srand(time(NULL));
    int A = get_user_A(), B;
    printf("Choose B: ");
    scanf("%d", &B);
    char t[100];
    printf("Text: ");
    getchar();
    fgets(t, sizeof(t), stdin);
    affine_cipher(t, A, B);
    affine_decipher(t, A, B);
    return 0;
}


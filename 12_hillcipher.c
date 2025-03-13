#include <stdio.h>
#include <string.h>

#define MOD 26
#define SIZE 3

int charToNum(char c) {
    return c - 'A';
}

char numToChar(int n) {
    return (n % MOD + MOD) % MOD + 'A';
}

int modInverse(int a) {
    a = a % MOD;
    for (int x = 1; x < MOD; x++) {
        if ((a * x) % MOD == 1) {
            return x;
        }
    }
    return -1;
}

int determinant(int matrix[SIZE][SIZE]) {
    return (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
            matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
            matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0])) % MOD;
}

void inverseMatrix(int key[SIZE][SIZE], int inverse[SIZE][SIZE]) {
    int det = determinant(key);
    if (det < 0) det += MOD;
    int detInv = modInverse(det);

    if (detInv == -1) {
        return;
    }
    int adj[SIZE][SIZE] = {
        { (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % MOD, (key[0][2] * key[2][1] - key[0][1] * key[2][2]) % MOD, (key[0][1] * key[1][2] - key[0][2] * key[1][1]) % MOD },
        { (key[1][2] * key[2][0] - key[1][0] * key[2][2]) % MOD, (key[0][0] * key[2][2] - key[0][2] * key[2][0]) % MOD, (key[0][2] * key[1][0] - key[0][0] * key[1][2]) % MOD },
        { (key[1][0] * key[2][1] - key[1][1] * key[2][0]) % MOD, (key[0][1] * key[2][0] - key[0][0] * key[2][1]) % MOD, (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD }
    };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inverse[i][j] = (adj[i][j] * detInv) % MOD;
            if (inverse[i][j] < 0) inverse[i][j] += MOD;
        }
    }
}

void hillCipherEncrypt(char plaintext[], int key[SIZE][SIZE]) {
    int textVector[SIZE], cipherVector[SIZE];
    int i, j, k = 0, textLength = strlen(plaintext);
    while (textLength % SIZE != 0) {
        plaintext[textLength++] = 'X';
    }
    plaintext[textLength] = '\0';
    printf("\nOriginal Plaintext: %s\n", plaintext);
    printf("\nCiphertext Computation:\n");
    for (k = 0; k < textLength; k += SIZE) {
        printf("\nBlock %d: ", k / SIZE + 1);
        for (i = 0; i < SIZE; i++) {
            textVector[i] = charToNum(plaintext[k + i]);
            printf("%c(%d) ", plaintext[k + i], textVector[i]);
        }
        printf("\nMultiplication steps:\n");
        for (i = 0; i < SIZE; i++) {
            cipherVector[i] = 0;
            for (j = 0; j < SIZE; j++) {
                cipherVector[i] += key[i][j] * textVector[j];
                printf("(%d * %d)", key[i][j], textVector[j]);
                if (j < SIZE - 1) printf(" + ");
            }
            cipherVector[i] %= MOD;
            printf(" = %d (mod 26)\n", cipherVector[i]);
        }
        printf("Ciphertext Block: ");
        for (i = 0; i < SIZE; i++) {
            printf("%c(%d) ", numToChar(cipherVector[i]), cipherVector[i]);
        }
        printf("\n");
    }
}

void hillCipherDecrypt(char ciphertext[], int key[SIZE][SIZE]) {
    int inverseKey[SIZE][SIZE];
    inverseMatrix(key, inverseKey);

    printf("\nDecryption Using Inverse Key Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", inverseKey[i][j]);
        }
        printf("\n");
    }

    int textVector[SIZE], plainVector[SIZE];
    int i, j, k = 0, textLength = strlen(ciphertext);

    printf("\nDecryption Computation:\n");
    for (k = 0; k < textLength; k += SIZE) {
        printf("\nBlock %d: ", k / SIZE + 1);
        for (i = 0; i < SIZE; i++) {
            textVector[i] = charToNum(ciphertext[k + i]);
            printf("%c(%d) ", ciphertext[k + i], textVector[i]);
        }

        printf("\nMultiplication steps:\n");
        for (i = 0; i < SIZE; i++) {
            plainVector[i] = 0;
            for (j = 0; j < SIZE; j++) {
                plainVector[i] += inverseKey[i][j] * textVector[j];
                printf("(%d * %d)", inverseKey[i][j], textVector[j]);
                if (j < SIZE - 1) printf(" + ");
            }
            plainVector[i] %= MOD;
            printf(" = %d (mod 26)\n", plainVector[i]);
        }
        printf("Plaintext Block: ");
        for (i = 0; i < SIZE; i++) {
            printf("%c(%d) ", numToChar(plainVector[i]), plainVector[i]);
        }
        printf("\n");
    }
}

int main() {
    char plaintext[100], ciphertext[100];
    int key[SIZE][SIZE];
    int i, j;
    printf("Enter plaintext (Enter in uppercase): ");
    scanf("%s", plaintext);
    printf("Enter 3x3 key matrix (row-wise):\n");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &key[i][j]);
    hillCipherEncrypt(plaintext, key);
    printf("\nEnter ciphertext to decrypt: ");
    scanf("%s", ciphertext);
    hillCipherDecrypt(ciphertext, key);
    return 0;
}

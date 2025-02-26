#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

void getKeyOrder(char *key, int *order) {
    int keyLen = strlen(key);
    int sortedIndex[MAX_LEN];
    for (int i = 0; i < keyLen; i++)
        sortedIndex[i] = i;
    for (int i = 0; i < keyLen - 1; i++) {
        for (int j = i + 1; j < keyLen; j++) {
            if (key[sortedIndex[i]] > key[sortedIndex[j]]) {
                int temp = sortedIndex[i];
                sortedIndex[i] = sortedIndex[j];
                sortedIndex[j] = temp;
            }
        }
    }
    int rank = 1;
    order[sortedIndex[0]] = rank;
    for (int i = 1; i < keyLen; i++) {
        if (key[sortedIndex[i]] != key[sortedIndex[i - 1]]) {
            rank++;
        }
        order[sortedIndex[i]] = rank;
    }
}

void myszkowskiEncrypt(char *plaintext, char *key, char *ciphertext) {
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);
    int rows = (textLen + keyLen - 1) / keyLen;

    char matrix[rows][keyLen];
    memset(matrix, 'X', sizeof(matrix));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (index < textLen) {
                matrix[i][j] = plaintext[index++];
            }
        }
    }
    int order[keyLen];
    getKeyOrder(key, order);
    printf("\nKey Order: ");
    for (int i = 0; i < keyLen; i++)
        printf("%c ", key[i]);
    printf("\nColumn No: ");
    for (int i = 0; i < keyLen; i++)
        printf("%d ", order[i]);
    printf("\n");
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    index = 0;
    for (int rank = 1; rank <= keyLen; rank++) {
        int hasMultiple = 0;
        for (int col = 0; col < keyLen; col++) {
            if (order[col] == rank) {
                hasMultiple++;
            }
        }
        if (hasMultiple > 1) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < keyLen; col++) {
                    if (order[col] == rank) {
                        ciphertext[index++] = matrix[row][col];
                    }
                }
            }
        }
        else {
            for (int col = 0; col < keyLen; col++) {
                if (order[col] == rank) {
                    for (int row = 0; row < rows; row++) {
                        ciphertext[index++] = matrix[row][col];
                    }
                }
            }
        }
    }
    ciphertext[index] = '\0';
}
int main() {
    char plaintext[MAX_LEN], key[MAX_LEN], ciphertext[MAX_LEN];
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter key: ");
    scanf("%s", key);
    myszkowskiEncrypt(plaintext, key, ciphertext);
    printf("\nCipher Text: %s\n", ciphertext);
    return 0;
}

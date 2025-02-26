#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

void routeCipherEncrypt(char *plaintext, int rows, char *ciphertext) {
    int len = strlen(plaintext);
    int cols = (int)ceil((float)len / rows);
    char matrix[MAX][MAX];

    int index = 0;
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            matrix[i][j] = (index < len) ? plaintext[index++] : 'Q';
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    index = 0;
    while (index < rows * cols) {
        for (int i = top; i <= bottom; i++) ciphertext[index++] = matrix[i][right];
        if (--right < left) break;

        for (int i = right; i >= left; i--) ciphertext[index++] = matrix[bottom][i];
        if (--bottom < top) break;

        for (int i = bottom; i >= top; i--) ciphertext[index++] = matrix[i][left];
        if (++left > right) break;

        for (int i = left; i <= right; i++) ciphertext[index++] = matrix[top][i];
        if (++top > bottom) break;
    }
    ciphertext[index] = '\0';
}
int main() {
    char text[MAX], encrypted[MAX];
    int rows;
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    routeCipherEncrypt(text, rows, encrypted);
    printf("\nEncrypted Text: %s\n", encrypted);
    return 0;
}

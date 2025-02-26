#include <stdio.h>
#include <string.h>

void rail_fence_encrypt(char *PT, int rails, char *CT) {
    int len = strlen(PT);
    char rail[rails][len];
    memset(rail, ' ', sizeof(rail));
    int row = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = PT[i];
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            printf("%c ", rail[i][j]);
        }
        printf("\n");
    }
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] != ' ') {
                CT[index++] = rail[i][j];
            }
        }
    }
    CT[index] = '\0';
}

void rail_fence_decrypt(char *CT, int rails, char *PT) {
    int len = strlen(CT);
    char rail[rails][len];
    memset(rail, ' ', sizeof(rail));

    int row = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len) {
                rail[i][j] = CT[index++];
            }
        }
    }

    row = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        PT[i] = rail[row][i];
        if (row == 0) direction = 1;
        else if (row == rails - 1) direction = -1;
        row += direction;
    }
    PT[len] = '\0';
}

int main() {
    char text[100];
    printf("Enter text: ");
    scanf("%s", text);
    int rails;
    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    char encrypted[100], decrypted[100];
    rail_fence_encrypt(text, rails, encrypted);
    printf("\nEncrypted Text: %s\n", encrypted);
    rail_fence_decrypt(encrypted, rails, decrypted);
    printf("\nDecrypted Text: %s\n", decrypted);
    
    return 0;
}

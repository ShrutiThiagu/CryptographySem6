#include <stdio.h>
#include <string.h>

void optimalNgramSplit(char text[]) {
    int len = strlen(text);
    printf("Text Length: %d\n", len);
    printf("Optimal N-gram split:\n");

    int i = 0;
    while (len - i > 4) {
        printf("%.3s\n", text + i);
        i += 3;
    }
    if (len - i == 4) {
        printf("%.2s\n", text + i);
        printf("%.2s\n", text + i + 2);
    } else {
        printf("%s\n", text + i);
    }
}

int main() {
    char text[100];

    printf("Enter text: ");
    scanf("%s", text);

    optimalNgramSplit(text);

    return 0;
}


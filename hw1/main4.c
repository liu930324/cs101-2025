#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char input[30];
    scanf("%29s",input);
    int len = strlen(input);

    for (int i = 0; i < len / 2; i++) {
        swap(&input[i], &input[len - 1 - i]);
    }

    printf("%s\n", input);
    return 0;
}

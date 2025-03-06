#include <stdio.h>
int main() {
    char input[30];
    char output[60];
    scanf("%29s",input);
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
    int j = 0;
    for (int i = 0; i < len; i += 2) {
        char c = a[i];
        int count = a[i+1] - '0'; 
        for (int k = 0; k < count; k++) {
            original[j++] = c;
        }
    }
    original[j] = '\0';
    printf("%s\n", original);
    return 0;
}

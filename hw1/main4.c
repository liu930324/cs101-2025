#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char a[] = "Hello123";
    int len = strlen(a);

    for (int i = 0; i < len / 2; i++) {
        swap(&a[i], &a[len - 1 - i]);
    }

    printf("%s\n", a);
    return 0;
}

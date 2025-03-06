#include <stdio.h>

void print_sp(int i, int n) {
    for (int m = 0; m < (n - i); m++) {
        printf(" ");
    }
}

void print_num(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", n);
        if (i < n) printf(" ");
    }
    printf("\n");
}

int main() {
    int rows;
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++) {
        print_sp(i, rows);
        print_num(i);
    }
    return 0;
}

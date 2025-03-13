#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int price;
    char title[50];
} Book;

Book books[] = {
    {1, 1000, "All the Light We Cannot See"},
    {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
    {3, 1000, "The Ballad of Songbirds and Snakes"},
    {4,  550, "Killers of the Flower Moon"},
    {5,  870, "Elon Musk"},
    {6, 1344, "Milk and Honey 12-Month 2024"}
};

int total_price() {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += books[i].price;
    }
    return sum;
}

void list_books(int id) {
    printf("%d %s\n", books[id - 1].price, books[id - 1].title);
}

int main() {
    int input;
    scanf("%d", &input);

    if (input == 0) {
        printf("%d\n", total_price());
    } else {
        list_books(input);
    }

    return 0;
}

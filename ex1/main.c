#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    
    FILE* fp;

    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        printf("無法打開文件...\n");
        exit(1);
    }

    if (fwrite(a, sizeof(int), sizeof(a) / sizeof(int), fp) != sizeof(a) / sizeof(int)) {
        printf("寫入整數陣列時出錯...\n");
        fclose(fp);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    int read_a[3];
    if (fread(read_a, sizeof(int), sizeof(a) / sizeof(int), fp) != sizeof(a) / sizeof(int)) {
        printf("讀取整數陣列時出錯...\n");
        fclose(fp);
        exit(1);
    } else {
        for (int i = 0; i < 3; i++) {
            printf("%d ", read_a[i]);
        }
        printf("\n");
    }

    fseek(fp, 0, SEEK_END);
    if (fwrite(b, sizeof(char), sizeof(b), fp) != sizeof(b)) {
        printf("寫入字符串陣列時出錯...\n");
        fclose(fp);
        exit(1);
    }

    fseek(fp, sizeof(a), SEEK_SET);
    char read_b[4];
    if (fread(read_b, sizeof(char), sizeof(b), fp) != sizeof(b)) {
        printf("讀取字符串陣列時出錯...\n");
        fclose(fp);
        exit(1);
    } else {
        printf("%s\n", read_b);
    }

    fseek(fp, 0, SEEK_END);
    if (fwrite(c, sizeof(float), sizeof(c) / sizeof(float), fp) != sizeof(c) / sizeof(float)) {
        printf("寫入浮點數陣列時出錯...\n");
        fclose(fp);
        exit(1);
    }

    fseek(fp, sizeof(a) + sizeof(b), SEEK_SET);
    float read_c[3];
    if (fread(read_c, sizeof(float), sizeof(c) / sizeof(float), fp) != sizeof(c) / sizeof(float)) {
        printf("讀取浮點數陣列時出錯...\n");
        fclose(fp);
        exit(1);
    } else {
        for (int i = 0; i < 3; i++) {
            printf("%2f ", read_c[i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}


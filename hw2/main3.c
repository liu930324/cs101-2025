#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* mainfp = fopen("main.c", "r");
    FILE* outfp = fopen("main.txt", "w");

    // 檢查檔案是否成功開啟
    if (!mainfp || !outfp) {
        printf("無法開啟檔案！\n");
        if (mainfp) fclose(mainfp);
        if (outfp) fclose(outfp);
        return 1;
    }

    char buffer[256];  // 用來存儲每一行的內容
    int line_number = 0;
    int found = 0;

    while (fgets(buffer, sizeof(buffer), mainfp) != NULL) {
        line_number++;
        // 檢查當前行是否包含 "int main()"
        if (strstr(buffer, "int main()") != NULL) {
            fprintf(outfp, "%d\n", line_number);
            found = 1;
            break;  // 找到就停止
        }
    }

    // 若沒有找到 "int main()"
    if (!found) {
        fprintf(outfp, "找不到 int main()\n");
    }

    fclose(mainfp);
    fclose(outfp);
    return 0;
}

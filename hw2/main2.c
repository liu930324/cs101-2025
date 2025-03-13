#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp=fopen("main.txt","w");
    FILE* mainfp = fopen("main.c", "r");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), mainfp) != NULL) {
        fprintf(fp, "%s", buffer);
    }
    fclose(fp);
    fclose(mainfp);
    return 0;
}

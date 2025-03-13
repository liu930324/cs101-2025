#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ARRAY_SIZE 7

int generateRandomNumber(int previous) {
    int num=rand()%69+1;
    while (num==previous){num=rand()%69+1;}
    return num;
}

void generateRandomArray(int arr[]) {
    bool used[70] = {false};
    int num;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        do {
            num = rand() % 69 + 1;
        } while (used[num]);
        arr[i] = num;
        used[num] = true;
    }
}

char* date(){
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t current_time=time(NULL);
    return asctime(localtime(&current_time));
}
int main(){
    char lotto[1000];
    srand(1);
    int arr[ARRAY_SIZE],x,j,k;
    FILE*fp=fopen("lotto.txt","w");
    printf("歡迎光臨長庚樂透購買機台\n請問您要買幾組樂透彩:");
    scanf("%d",&x);
    printf("已為您購買的%d組樂透組合輸出至lotto.txt\n",x);
    fprintf(fp,"========= lotto649 =========\n");
    for(j=0; j<x; j++){
        generateRandomArray(arr);
        fprintf(fp,"[%d]: ", j+1);
        for(int i = 0; i<ARRAY_SIZE-1; i++) {
            fprintf(fp,"%02d ", arr[i]);
        }
        fprintf(fp,"%02d", arr[6]);
        fprintf(fp,"\n");
    }
    for(k=j; k<5;k++){fprintf(fp,"[%d]: __ __ __ __ __ __ __\n", k+1);}
    fprintf(fp,"========= csie@CGU =========\n");
    fclose(fp);
}

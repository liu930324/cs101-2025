#include <stdio.h>
#include <string.h>

void print_sp(int i,int n){
    for(int m=0;m<=(i-n)-1;m++){
        printf(" ");
    }
}
void print_num(int n){
    for(int i=1;i<=n;i++){
        printf("%d ",n);
    }
    printf("\n");
}
int main()
{
    char input[30];
    char output[60];
    scanf("%d",input);
    for(int i=1;i<=rows;i++){
        print_sp(rows,i);
        print_num(i);
    }
}

#include <stdio.h>
int main(){
    int j=1;
    for (int i=1;i <= 9;++j) {
        printf("%d*%d=%d\t", i, j, j*i);
        if(j==9){
            j=0;
            i++;
            printf("\n");
        }
    }
    return 0;
}

#include <stdio.h>
int multi(int i,int j){
    if(i==1){
        printf("%d*%d=%d ",i,j,i*j);
        return 0;
    }
    else{
        multi(i-1,j);
        printf("%d*%d=%d ",i,j,i*j);
    }
}

int main()
{
    int i = 9;
    for(int j =1;j<=9;j++){
        multi(i,j);
        printf("\n");
    }
    return 0;
}

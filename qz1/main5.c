#include <stdio.h>
int main(){
    int i=2097151;
    int count=0;
    while(i!=0){
        if(i&1){
            count++;
        }
        i>>=1;
    }
    printf("%d",count);
    return 0;
}

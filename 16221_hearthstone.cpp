#include <stdio.h>

int main(void){

    int n;
    scanf("%d",&n);

    int array[1000000];
    int define;
    int imsi;
    int count = 0;
    int death = 0;
    for(int i = 0; i<n; i++){
        scanf("%d %d",&define, &imsi);
        if(define == 1){
            array[imsi-1]++;
        }else{
            array[imsi-1]--;
        }
        count = 0;
        death = 0;
        while(array[count]!=0){
            death += array[count];
            count++;
        }
        printf("%d\n", death);
    }
    return 0;
}
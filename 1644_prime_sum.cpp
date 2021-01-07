#include <iostream>
using namespace std;

int main(void){

    int count = 0;
    int m = 4000000;
    int* array = new int[m+1];
    
    for(int i = 0; i<=m;i++){
        array[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(array[i]==0) continue; 
        for(int j=i;j<=m; j+=i) {
            if(j!=i){
                array[j] = 0;
            }
        }
    }
    array[1] = 0;
    int c= 2;
    int prime_count = 0;
    int prime_array[1000000];
    while(c<=m){
        if(array[c]==c){
            prime_array[prime_count] = c;
            prime_count++;
        }
        c++;
    }
    int n;
    scanf("%d",&n);
    int imsi = 0;
    int p_count;
    for( int count = 0; count<prime_count; count++){
        if(prime_array[count]>n){
            p_count = count;
            break;
        }
    }
    // printf("count: %d\n",p_count);
    // for(int i = 1; i<10;i++){
    //     printf("%d ", prime_array[i]);
    // }
    // printf("\n");

    int possible_count = 0;
    for(int i = 0; i< p_count; i++){
        for(int j = i;j< p_count;j++){
            imsi += prime_array[j];
            if(imsi == n){
                possible_count++;
                imsi = 0;
                break;
            }else if(imsi> n){
                imsi = 0;
                break;
            }
        }
    }
        
    printf("%d\n", possible_count);
    
    delete [] array;



return 0;
}
#include <iostream>
using namespace std;

int main(void){

    int n = 100000000, m = 1000000000;
    int* array = new int[1000000001];
    
    for(int i = 0; i<=m;i++){
        array[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(array[i]==0) continue; 
        for(int j=i*i;j<=m; j+=i) {
            array[j] = 0;
        }
    }
    array[1] = 0;

    for(int i = 100000000; i<=1000000000 ; i++){

        if(array[i]!=0){
            printf("%d\n", i);
        }
        
    }
    delete [] array;

return 0;
}
#include <iostream>
using namespace std;

int main(void){

    int n,m;
    scanf("%d %d", &n,&m);
    int* array = new int[m+1];
    
    for(int i = 0; i<=m;i++){
        array[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(array[i]==0) continue; 
        for(int j=2*i;j<=m; j+=i) {
            array[j] = 0;
        }
    }
    array[1] = 0;

    for(int i = n; i<=m ; i++){

        if(array[i]!=0){
            printf("%d\n", i);
        }
        
    }
    delete [] array;



return 0;
}
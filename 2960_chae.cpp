#include <iostream>
using namespace std;

int main(void){

    int count = 0;
    int n,m;
    scanf("%d %d", &m,&n);
    int* array = new int[m+1];
    
    for(int i = 0; i<=m;i++){
        array[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(array[i]==0) continue; 
        for(int j=i;j<=m; j+=i) {
            if(array[j]!=0){
                array[j] = 0;
                count++;
                if(count == n){
                    printf("%d\n",j);
                }
            }
            
        }
    }
    delete [] array;



return 0;
}
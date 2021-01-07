#include <iostream>
using namespace std;

int main(void){
    int m;
    scanf("%d",&m);

    while(m!=0){
        int count = 0;
        int* array = new int[2*m+1];
        
        for(int i = 0; i<=2*m;i++){
            array[i] = i;
        }
        for(int i=2;i<=2*m;i++) {
            if(array[i]==0) continue; 
            for(int j=2*i;j<=2*m; j+=i) {
                array[j] = 0;
            }
        }
        array[1] = 0;

        for(int i = m+1; i<=2*m ; i++){

            if(array[i]!=0){
                count++;
            }
            
        }
        printf("%d\n",count);
        delete [] array;
        scanf("%d",&m);
    }



    return 0;
}
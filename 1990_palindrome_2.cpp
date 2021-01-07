#include <iostream>
using namespace std;

int main(void){

    int n,m;
    cin>> n>>m;
    if(m>=10000000){
        m = 10000000;
    }
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

    for(int i = n; i<=m ; i++){
        if(array[i] !=0){
            int reverse = 0;
            for( int k = i; k > 0; k /= 10 ){
                int p = k % 10;
                reverse = (reverse * 10) + p;
            }
            if(reverse == i){
                cout<<i<<endl;
            }
        }
    }
    cout<<-1<<endl;
    delete [] array;



return 0;
}
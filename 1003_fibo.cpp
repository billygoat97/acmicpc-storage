#include <iostream>
#include <cmath>

using namespace std;


int count_zero = 0;
int count_one = 0;
int arr[1000][3];
int fibo(int num){

    if( num == 0){
        arr[num][0] = 0;
        arr[num][1] = 1;
        arr[num][2] = 0;
        return 0;
    }else if(num == 1){
        arr[num][0] = 1;
        arr[num][1] = 0;
        arr[num][2] = 1;
        return 1;
    }else{
        if( arr[num][0] >0){
            return arr[num][0];
        }
        arr[num][0] = fibo(num-1) + fibo(num-2);
        arr[num][1] = arr[num-1][1] + arr[num-2][1];
        arr[num][2] = arr[num-1][2] + arr[num-2][2];
        return arr[num][0];
    }



}

int main(){

    int n;
    cin >> n;

    for(int i = 0; i< n; i++){
        int inp;
        cin >> inp;
        int result;
        result = fibo(inp);
        cout<< arr[inp][1]<<" "<< arr[inp][2]<<endl;
    }



    return 0;
}

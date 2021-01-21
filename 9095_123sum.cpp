#include <iostream>
#include <cmath>

using namespace std;

int arr[1000];

int func(int num){

    if (num == 1){
        arr[1] = 1;
    }else if (num ==2){
        arr[2] = 2;
    }else if (num == 3){
        arr[3] = 4;
    }

    if(arr[num] != 0)return arr[num];


    //arr[num] = arr[num-1]+arr[num-2]+arr[num-3];
    arr[num] = func(num-1) + func(num-2) + func(num-3);
    return arr[num];


}


int main(){

    int n;
    cin >> n;

    for(int i = 0; i< n; i++){
        int inp;
        cin >> inp;
        int result;
        result =func(inp);
        cout<< result<<endl;
    }



    return 0;
}
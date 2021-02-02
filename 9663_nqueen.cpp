#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arr[15]={0,};
int cnt = 0;
int n;
bool check(int k){

    for(int i = 0; i<k;i++){
        if(arr[i] == arr[k] || abs(arr[i]-arr[k]) == k-i){
            return false;
        }
    }
    return true;
}

void func(int k, int num){ // k 현재, n 총

    if(k == num){
        cnt++;
    }else{
        for(int i = 0; i<num; i++){
            arr[k] = i;
            if(check(k)== true){
                func(k+1,num);
            }
        }
    }

    

}

int main(){

    cin>> n;
    
    func(0,n);
    cout<< cnt<<endl;


    return 0;
}
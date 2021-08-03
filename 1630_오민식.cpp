#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define BIG 987654321

using namespace std;
int arr[1000001];

int main(){
    for(int i = 1; i<=1000000;i++){
        arr[i] = i;
    }
    for(int i = 2; i<=1000000;i++){
        int cur = arr[i];
        for(int j = 2*i; j<=1000000;j+=i){
            arr[j] /= cur;
        }
    }
    int n;
    cin >> n;
    double sum = 1;
    for(int i = 1; i<=n; i++){
        sum = (sum*arr[i]);
        if(sum /BIG >1){
            sum -= ((double)(int)(sum /BIG))*BIG;
        }
    }
    cout<<(int)sum<<endl;


    return 0;
}
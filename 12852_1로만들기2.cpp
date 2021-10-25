#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1000001];
int dp[1000001];
int main(){


    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i<= n; i++){
        arr[i] = i;
        if(i % 3 == 0){
            arr[i] = i/3;
        }
        if(i % 2 == 0){
            arr[i] = i/2;
        }else{
            arr[i] = i-1;
        }
    }
    arr[0] = 0;
    arr[1] = 0;
	arr[2] = 1;
    arr[3] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i<=n;i++) {
        arr[i] = arr[i-1] + 1;
        dp[i] = i-1;
        if(i % 3 == 0) {
            if(arr[i/3] + 1 < arr[i]){
                arr[i] = arr[i/3] + 1;
                dp[i] = i/3;
            }
        }
        if(i%2 == 0) {
            if(arr[i/2] + 1 < arr[i]){
                arr[i] = arr[i/2] + 1;
                dp[i] = i/2;
            }
        }
    }
    cout<<arr[n]<<endl;
    cout<<n<<" ";
    int cur = dp[n];
    while(cur != 0){
        cout<<cur<<" ";
        cur = dp[cur];
    }


    return 0;
}
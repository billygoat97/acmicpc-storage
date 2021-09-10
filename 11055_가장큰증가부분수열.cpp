#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n] = {0,};
    int dp[n] = {0,};
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j< i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    sort(dp,dp+n);
    cout<<dp[n-1]<<endl;

    return 0;
}
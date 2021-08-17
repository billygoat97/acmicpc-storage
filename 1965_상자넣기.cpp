#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;
    int dp[1001] = {0,};
    int arr[1001] = {0,};
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    sort(dp,dp+n);
    cout<<dp[n-1]<<endl;

    return 0;
}
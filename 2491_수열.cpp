#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int main(){

    int n;
    cin >> n;
    int dp[n][2] = {0,}; // 0 up 1 down
    int arr[n] ={0,};
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout<<1 <<endl;
        return 0;
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    int ans = 0;
    for(int i = 1; i<n ; i++){
        if(dp[i-1][0] == 0){
            dp[i-1][0] = 1;
        }
        if(dp[i-1][1] == 0){
            dp[i-1][1] = 1;
        }
        if(arr[i] > arr[i-1]){
            dp[i][0] = dp[i-1][0]+1;
        }
        if(arr[i] < arr[i-1]){
            dp[i][1] = dp[i-1][1]+1;
        }
        if(arr[i] == arr[i-1]){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1] + 1;
        }
        ans = max(max(ans, dp[i][0]),dp[i][1]);
    }
    cout<<ans<<"\n";
}
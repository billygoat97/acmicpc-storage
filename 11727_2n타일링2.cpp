#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){


    int n;
    cin >> n;
    int dp[n+1];
    fill(dp,dp+n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i<= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2)%10007;
    }
    cout<<dp[n]<<endl;
    return 0;
}
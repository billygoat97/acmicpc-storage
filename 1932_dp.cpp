#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];
int main(){

    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i;j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;

    return 0;
}
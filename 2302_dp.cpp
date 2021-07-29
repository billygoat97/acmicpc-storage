#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;
int n,m;
int dp[41];
int main(){
    cin >>  n >> m;
    int cur = 0;
    int sum = 1;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(int i = 0; i<m; i++){
        int inp;
        cin >> inp;
        sum *= dp[inp - cur -1];
        cur = inp;
    }
    sum *= dp[n-cur];
    cout<<sum<<endl;

    return 0;
}
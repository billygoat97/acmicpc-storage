#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int dp[1001];

int main(){

    int n;

    cin >> n;
    dp[1] = 1;
    for(int i = 2; i<= 1000; i++){
        dp[i] = dp[i-1]+1;
    }

    for(int i = 2; i<=1000; i++){
        for(int j = 2; i*j <= 1000; j++){
            dp[i*j] = min(dp[i*j], dp[i] + j);
        }
        for(int j = 1000; j>= 2; j--){
            dp[j-1] = min(dp[j-1],dp[j]+1);
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
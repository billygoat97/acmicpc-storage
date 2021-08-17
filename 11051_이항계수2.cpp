#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int dp[1001][1001]={0,};


int func(int n, int k){
    if(dp[n][k] != 0)return dp[n][k];


    return dp[n][k] = (func(n-1,k-1) + func(n-1,k))%10007;

}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        dp[i][1] = i;
    }
    
    cout<<func(n,k)<<endl;


    return 0;
}
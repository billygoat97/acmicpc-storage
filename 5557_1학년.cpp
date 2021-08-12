#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v;
long long dp[101][21];
int main(){

    int n;
    cin >> n;
    v.push_back(0);
    for (int i = 1; i<=n; i++){
        cin >> v[i];
    }
    
    dp[1][v[1]] = 1;
    for(int i = 2; i<n; i++){
        for(int j = 0; j<=20; j++){
            if(v[i] + j <=20){
                dp[i][v[i]+j] += dp[i-1][j];
            }
            if(-v[i] + j >= 0){
                dp[i][-v[i]+j] += dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n-1][v[n]];

    return 0;
}
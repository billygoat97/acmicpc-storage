#include <iostream>
#include <vector>
#define div 1000000000
using namespace std;

using ll = long long;

ll dp[100][10][1024] = {0,};
int n;
ll ans;
int main(){

    cin >> n;
    if(n <10 )ans = 0;
    for(int i = 1; i<10; i++){
        dp[0][i][1<<i] = 1;
    }
    for(int i = 0; i<99; i++){
        for(int j = 0; j<10; j++){
            for(int k = 0; k<1024; k++){
                if(dp[i][j][k] >= div)dp[i][j][k] =  dp[i][j][k] % div;
                if(j == 0){
                    dp[i+1][j+1][k | 1<< (j+1)] += dp[i][j][k];
                }else if(j == 9){
                    dp[i+1][j-1][k | 1<< (j-1)] += dp[i][j][k];
                }else {
                    dp[i+1][j-1][k | 1<< (j-1)] += dp[i][j][k];
                    dp[i+1][j+1][k | 1<< (j+1)] += dp[i][j][k];
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i<10; i++){
        sum += dp[n-1][i][1023];
    }
    cout<<sum%div;


    return 0;
}
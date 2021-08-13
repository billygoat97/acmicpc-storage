#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

int main(){

    int n;
    cin >> n;
    long long dp[64][10];
    for(int i = 0; i<10;i++){
        dp[0][i] = 1;
    }
    
    for(int i = 0; i<64; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i<64; i++){
        for(int j = 1; j<10; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    for(int a = 0; a<n; a++){
        int inp;
        cin >>inp;
        inp--;
        long long sum = 0;
        for(int i = 0; i<10; i++){
            sum += dp[inp][i];
        }
        cout<<sum<<endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int main(){
    // dp네
    int casen;
    cin >> casen;
    long long int dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i<=100; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    for(int i = 0; i<casen; i++){
        int inp;
        cin >> inp;
        cout<<dp[inp]<<endl;
    }

    return 0;
}
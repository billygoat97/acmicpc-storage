#include<iostream>
#include <cmath>
using namespace std;

int dp[1000][3];
int sum[1000][3];



int main(){
    int n;
    cin >> n;

    for(int i = 0; i< n; i++){
        cin >> dp[i][0] >>dp[i][1] >>dp[i][2] ;
    }

    sum[0][0] = dp[0][0];sum[0][1] = dp[0][1];sum[0][2] = dp[0][2];

    for(int i = 1;i<n; i++){
        sum[i][0] = min(sum[i-1][1]+dp[i][0],sum[i-1][2]+dp[i][0]);
        sum[i][1] = min(sum[i-1][0]+dp[i][1],sum[i-1][2]+dp[i][1]);
        sum[i][2] = min(sum[i-1][0]+dp[i][2],sum[i-1][1]+dp[i][2]);
    }
    cout<< min(sum[n-1][2],min(sum[n-1][0],sum[n-1][1]))<<endl;



    return 0;
}
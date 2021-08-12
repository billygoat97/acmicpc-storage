#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define DIV 1000000000

using namespace std;
int n,k;
int dp[201][201];

int main(){

    cin >> n >> k;
    for(int i = 1; i<=k; i++){
        dp[i][0] = 1; // i개로 0을 만드는 방법 => 1개 0000000
    }
    for(int i = 0; i<=n; i++){
        dp[1][i] = 1; // 1개로 i를 만드는 방법 => 1개 1,2,3,4,5,6,7,8
    }
    for(int i = 1; i<=k; i++){
        for(int j = 1;j<=n;j++ ){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000000;
        }
    }
    /*
        설명하자면 다음과 같다
        (K-1)개 + 1개 => N의 값
        (K-1)개 => N - 1개의 값
        1개의 값 L(0~N)
        k-1개로 N-L 만드는 개수
        dp[k-1][0~N]
        dp[k][n] = dp[k-1][0~N]
        다르게 얘기하면
        dp[k][n-1] = dp[k-1][0~N-1]
        dp[k][n] = dp[k][n-1] + dp[k-1][N] 
        따라서
        dp[i][j] = dp[i][j-1] + dp[i-1][j]로 점화식이 구축된다
        */
    cout<<dp[k][n];


    return 0;
}
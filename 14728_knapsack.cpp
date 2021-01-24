#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, t;
    cin >> n >> t; // n은 단원 갯수 , t는 전체 시간
    int dp[n+1][t+1];
    int arr[n+1][2];

    for(int i = 1; i<=n; i++){
        cin >> arr[i][0] >> arr[i][1]; // 0은 시간 // 1은 배점
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=t; j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }else if(arr[i][0]<=j){ // 이거 그거 가능함 그 뭐냐 시간 내에 공부 가능
                dp[i][j] = max(arr[i][1]+ dp[i-1][j-arr[i][0]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][t]<<endl;






    return 0;
}
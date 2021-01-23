#include <iostream>
#include <cmath>

using namespace std;


int main(){


    int n,k; // n 은 물건 총 갯수, k는 버틸수 있는 무게
    cin >> n >>k;
    int dp[n+1][k+1];
    int things[n+1][2]; // 무게 / 가치
    for(int i = 1; i<= n;i++){
        cin>> things[i][0] >>things[i][1]; // 무게 & 가치
    }

    for(int i = 0 ; i<=n;i++){
        for(int j = 0; j<=k; j++){
            if(i==0 || j == 0){ // 기본 세팅
                dp[i][j] = 0;
            }else if(things[i][0] <= j&& things[i][0]>0){ // 아예 조건을 벗어나는 것 --> 무슨 뜻이냐면 애초에 가방에 안들어간다 이말
                dp[i][j]  = max(things[i][1] + dp[i-1][j-things[i][0]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for(int i  = 0 ; i<= n ;i++){
    //     for(int j = 0 ; j<=k;j++){
    //         cout<<dp[i][j]<<" ";

    //     }
    //     cout<< endl;
    // }
    cout<<dp[n][k]<<endl;

    return 0;

}
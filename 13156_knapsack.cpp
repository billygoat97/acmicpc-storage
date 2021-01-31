#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int n,m;
    cin >> n>> m;
    int arr[m+1][n+1];
    for(int i = 1; i<=m; i++){
        for(int j = 1 ; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i<=m; i++){
        for(int j =0 ; j<=n; j++){
            if(i==0||j==0){
                arr[i][j] = 0;
            }
        }
    }
    
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++){ // 물건 갯수 번호
        // int imsi = -99999;
        for(int j = 0; j<=n; j++){ // 사람 
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i<=m; i++){ // 물건 갯수 번호
        // int imsi = -99999;
        for(int j = 0; j<=n; j++){ // 사람 

            for(int k = 0; k<=j;k++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(arr[i][k]>0){
                    dp[i][j] = max(dp[i-1][j-k] +arr[i][k], dp[i][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            // imsi = max(imsi, arr[i][j]);
            
        }
    }
    
    // cout<<endl<<endl;
    // for(int i = 0; i<=m; i++){ // 사람 번호
    //     for(int j = 0; j<=n; j++){ // 총 갯수 판매
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<< dp[m][n]<<endl;
    return 0;
}
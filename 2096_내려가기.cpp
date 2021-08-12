#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n;
int main(){

    
    cin >> n;
    int dp[2][3], sdp[2][3], a[3];
    for(int i = 0; i<n; i++){
        cin >> a[0] >> a[1] >> a[2];
        if(i == 0){
            for(int j = 0; j<3; j++){
                dp[1][j] = a[j];
                sdp[1][j] = a[j];
            }
        }else{
            for(int j = 0; j<3; j++){
                dp[0][j] = dp[1][j];
                sdp[0][j] = sdp[1][j];
            }
            dp[1][0] = max(dp[0][0], dp[0][1]) + a[0];
            dp[1][1] = max(dp[0][2],max(dp[0][0], dp[0][1])) + a[1];
            dp[1][2] = max(dp[0][2], dp[0][1]) + a[2];
            sdp[1][0] = min(sdp[0][0], sdp[0][1]) + a[0];
            sdp[1][1] = min(sdp[0][2],min(sdp[0][0], sdp[0][1])) + a[1];
            sdp[1][2] = min(sdp[0][2], sdp[0][1]) + a[2];
        }
    }
    // for(int i = 0; i<3; i++){
    //     dp[0][i] = arr[0][i];
    //     sdp[0][i] = arr[0][i];
    // }
    // for(int i = 1; i<n;i++){
    //     dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i][0];
    //     dp[i][1] = max(dp[i-1][2],max(dp[i-1][0], dp[i-1][1])) + arr[i][1];
    //     dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + arr[i][2];
    //     sdp[i][0] = min(sdp[i-1][0], sdp[i-1][1]) + arr[i][0];
    //     sdp[i][1] = min(sdp[i-1][2],min(sdp[i-1][0], sdp[i-1][1])) + arr[i][1];
    //     sdp[i][2] = min(sdp[i-1][2], sdp[i-1][1]) + arr[i][2];
    // }
    cout<<max(max(dp[1][0],dp[1][1]),dp[1][2]) <<" "<<min(min(sdp[1][0],sdp[1][1]),sdp[1][2]);
    


    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10001];
int dp[10001];
int n;
int main(){

    cin >> n;
    for(int i = 0;i<n; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(dp[1],max(arr[0] + arr[2], arr[1]+arr[2]));
    for(int i = 3; i<n; i++){
        dp[i] = max(dp[i-1],max(dp[i-3] + arr[i-1] + arr[i], arr[i] + dp[i-2]));
    }
    if(n>=2){
        cout<<dp[n-1]<<endl;
    }else{
        cout<<dp[0]<<endl;
    }
    return 0;
}
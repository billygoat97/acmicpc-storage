#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int n;
    int arr[1000];
    int dp[1000];
    cin >>n;
    for(int i = 0; i<n; i++){
        // vector<int> v;
        // vector<int> dp;
        int ans=-9999999;
        int len;
        cin >>len;
        for(int j = 0; j< len; j++){
            cin >>arr[j];
        }
        dp[0] = arr[0];
        ans = dp[0];
        for(int j = 1; j<len;j++){
            int mx = max(dp[j-1],0)+arr[j];
            dp[j] = mx;
            ans = max(ans, dp[j]);
        }
        
        
        cout<<ans<<endl;
    }
    
    return 0;

}
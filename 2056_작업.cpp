#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[10001];
    vector<int> v[10001];
    int cnt;
    for(int w = 1; w<=n; w++){
        cin >> arr[w];
        cin >> cnt;
        for(int i = 0; i<cnt; i++){
            int inp;
            cin >>inp;
            v[w].push_back(inp);
        }
    }
    int dp[10001] = {0,};
    dp[1] = arr[1];
    for(int i = 2; i<=n; i++){
        int waiting = 0;
        for(int j = 0; j<v[i].size();j++){
            waiting = max(waiting, dp[v[i][j]]);
        }
        dp[i] = waiting + arr[i];
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans;

    return 0;
    
}
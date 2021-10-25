#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

vector<int>v;
int dp[100001][5][5];
int diff[5][5] = {
    {INF,2,2,2,2},
    {INF,0,3,4,3},
    {INF,3,0,3,4},
    {INF,4,3,0,3},
    {INF,3,4,3,0}
};
int func(int cnt, int l, int r){
    if(cnt ==0){
        if(l == 0 && r == 0)
        return 0;
        return INF;
    }
    if(l == r)return INF;
    
    if(l != v[cnt] && r != v[cnt]){
        return INF;
    }
    if(dp[cnt][l][r] != -1 && dp[cnt][l][r] != INF)return dp[cnt][l][r];
    dp[cnt][l][r] = INF;
    for(int i = 0; i<=4; i++){
        dp[cnt][l][r] = min(func(cnt-1,i,r) +diff[i][l], dp[cnt][l][r]);
        dp[cnt][l][r] = min(func(cnt-1,l,i) +diff[i][r], dp[cnt][l][r]);
    }
    return (dp[cnt][l][r]);
}



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    v.push_back(0);
    while(true){
        int inp;
        cin >> inp;
        if(inp == 0)break;
        v.push_back(inp);
    }
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++)dp[i][j][k] = -1;
        }
    }
    int ans = INF;
    for(int i = 0; i<=4; i++){
        for(int j = 0; j<=4; j++){
            ans = min(ans,func(v.size()-1,i,j));
        }
    }

    for(int a = 0; a<v.size();a++){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout<<dp[a][i][j]<<"\t";
        }
        cout<<endl;
    }
        cout<<"=====================\n";
    }
    cout<<ans<<"\n";
    return 0;
}
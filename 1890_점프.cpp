#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int arr[100][100];
long long dp[100][100];
int dx[2] = {1,0};
int dy[2] = {0,1};
long long dfs(int x, int y){

    if(x == n-1 && y == n-1){
        return 1;
    }
    if(arr[x][y] == 0)return dp[x][y];
    for(int i = 0; i<2; i++){
        
        int nx = x + dx[i]*arr[x][y];
        int ny = y + dy[i]*arr[x][y];
        if(nx >= n || ny >= n)continue;
        if(dp[nx][ny] == 0){
            dp[x][y] += dfs(nx,ny);
        }else{
            dp[x][y] += dp[nx][ny];
        }
    }
    return dp[x][y];
}


int main(){

    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    dfs(0,0);
    cout<<dp[0][0]<<"\n";


    return 0;
}
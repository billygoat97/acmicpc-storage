#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n,m;
int arr[500][500]={0,};
int dp[500][500]={0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

int dfs(int x, int y){
    
    if(x == n-1 && y == m-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;
    
    for(int i = 0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx <0 || ny <0 || nx>=n || ny >=m){

        }else{
            if(arr[nx][ny] <arr[x][y]){ // 갔던곳도 가도 됨 dp[nx][ny] == -1 할 필요 없음
            // 왜 없느냐? 그것은 이전에 썼던거 정보 받아와야 해서 그런거지 고로 다이죠부
                dp[x][y] += dfs(nx,ny);
            }
        }
    }
    return dp[x][y];
}

int main(){

    cin >> n >>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            dp[i][j]=-1;
        }
    }
    
    cout<<dfs(0,0)<<endl;

    return 0;
}
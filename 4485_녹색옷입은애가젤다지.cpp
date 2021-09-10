#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

int main(){

    int n;
    int cnt = 0;
    while(true){
        cin >> n;
        cnt++;
        if(n == 0)break;
        int dp[n][n] = {0,};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dp[i][j] = INF;
            }
        }
        int arr[n][n] = {0,};
        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};
        for(int i = 0; i <n; i++){
            for(int j = 0; j< n; j++){
                cin >> arr[i][j];
            }
        }
        using T = pair<int,int>;
        queue<T> q;
        q.push({0,0});
        dp[0][0] = arr[0][0];
        while(q.size()!= 0){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <0 || ny <0 || nx >= n || ny >= n)continue;
                if(dp[x][y] + arr[nx][ny] < dp[nx][ny]){
                    dp[nx][ny] = dp[x][y] + arr[nx][ny];
                    if(nx == n-1 && ny == n-1)continue;
                    q.push({nx,ny});
                }
            }
        }
        
        cout<<"Problem " << cnt << ": ";
        cout<<dp[n-1][n-1]<<"\n";
    }

    return 0;
}
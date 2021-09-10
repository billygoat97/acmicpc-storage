#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n;

int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};


int main(){

    cin >> n;
    int th = 0;
    int arr[n][n] = {0,};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
            th = max(th,arr[i][j]);
        }
    }
    int height = 0;
    int ans = 0;
    using T = pair<int,int>;
    while(height < th){
        int visited[n][n] = {0,};
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j]==0 && arr[i][j] > height){
                    queue<T> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(q.size()!= 0){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int a = 0; a<4; a++){
                            int nx = x + dx[a];
                            int ny = y + dy[a];
                            if(nx <0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] <=height || visited[nx][ny] == 1)continue;
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                        }
                    }
                    cnt++;
                }
            }
        }
        
        ans = max(cnt, ans);
        height++;
    }
    cout<< ans<<"\n";
    return 0;
}
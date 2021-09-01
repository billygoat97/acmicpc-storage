#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1000][1000] = {0,};
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int visited[1000][1000][2] = {0,};
int ans = -1;

using T = pair<int,int>;
void bfs(){

    queue<pair<T,T>> q; // ((x,y),(cnt,crack))
    q.push({{0,0},{1,0}});
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    int curcnt = 1;
    while(q.size() != 0){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int crack = q.front().second.second;
        q.pop();
        if(x == n-1 && y == m-1){
            ans = cnt;
            return;
        }

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny <0 || nx >= n || ny >= m)continue;
            int ncrack = crack;
            if(arr[nx][ny] == 1){
                if(crack == 0){
                    ncrack = 1;
                }else{
                    continue;
                }
            }
            if(visited[nx][ny][ncrack] == 1)continue;
            visited[nx][ny][ncrack] = 1;
            q.push({{nx,ny},{cnt+1,ncrack}});
        }
    }
}


int main(){

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        for(int j = 0; j<m; j++){
            arr[i][j] = str[j] -'0';
        }
    }

    bfs();
    cout<<ans <<endl;


    return 0;
}
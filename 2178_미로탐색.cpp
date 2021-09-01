#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;


int cnt = INF;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int visited[100][100]={false,};
int arr[100][100] = {0,};
int n,m;
using T = pair<int,int>;



int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        for (int j = 0 ;j<m; j++){
            arr[i][j] = str[j] -'0';
        }
    }
    visited[0][0] = true;

    queue<pair<T,int>> q;

    q.push({{0,0},1});
    while(q.size()!= 0){
        int px = q.front().first.first;
        int py = q.front().first.second;
        int time = q.front().second;
        q.pop();
        if(px == n-1 && py == m-1){
            cnt = min(cnt,time);
            break;
        }
        for(int i = 0 ;i<4; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            if(nx <0 || nx>=n|| ny<0 || ny>=m)continue;
            if(arr[nx][ny] == 0)continue;
            if(visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({{nx,ny},time+1});
            }
        }
    }


    cout<<cnt;
    


    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

using T = pair<int,int>;
int arr[50][50]={0,};
int h[50][50]={0,};
int n;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
vector <T> v;
T visited[50][50];
int main(){
    cin >> n;
    int px=0,py=0;
    for(int i = 0;i<n; i++){
        for(int j = 0; j<n; j++){
            char inp;
            cin >> inp;
            if(inp == 'P'){
                arr[i][j] = 2;
                px = i;
                py = j;
            }else if(inp == 'K'){
                arr[i][j] = 1;
                v.push_back({i,j});
            }
        }
    }
    for(int i = 0;i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> h[i][j];
        }
    }
    queue <T> q1;
    queue <T> q2;
    q1.push({px,py});
    q2.push({h[px][py], h[px][py]});
    while(q1.size()!= 0){
        int x = q1.front().first;
        int y = q1.front().second;
        int d = q2.front().first;
        int t = q2.front().second;
        q1.pop();
        q2.pop();
        for(int i = 0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd, nt;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
            if(nx == px && ny == py)continue;
            nd = min(h[nx][ny],d);
            nt = max(h[nx][ny],t);
            // cout<<nx<<","<<ny<<":"<<nd<<","<<nt<<endl;
            if(visited[nx][ny].first == 0 && visited[nx][ny].first == 0){
                visited[nx][ny] = {nd,nt};
                q1.push({nx,ny});
                q2.push(visited[nx][ny]);
            }else if(visited[nx][ny].second - visited[nx][ny].first > nt - nd){
                visited[nx][ny].second = min(visited[nx][ny].second, nt);
                visited[nx][ny].first = max(visited[nx][ny].first,nd);
                q1.push({nx,ny});
                q2.push(visited[nx][ny]);
            }
        }
    }

    int top = 0, down = 987654321; 
    for(int i = 0; i<v.size();i++){
        down = min(down, visited[v[i].first][v[i].second].first);
        top = max(top, visited[v[i].first][v[i].second].second);
        // cout<<v[i].first<<","<<v[i].second<<";"<<top<<","<<down<<endl;
    }
    cout<< top - down << "\n";
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;

int dx[] ={0,0,1,-1};
int dy[] ={-1,1,0,0};
using T = pair<int,int>;
int n,m;
int p1 = 0, p2 = 0;
bool visited[100][100] = {false,};
int arr[100][100]={0,};
string str;

int main(){

    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> str;
        for(int j = 0;j<str.size();j++){
            arr[i][j] = 1;
            if(str[j] == 'W')arr[i][j] =2;
        }
    }
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            if(visited[i][j] == true)continue;
            int cnt = 0;
            
            queue <T> q;
            q.push({i,j});
            visited[i][j] = true;
            while(q.size()!= 0){
                cnt++;
                int px = q.front().first;
                int py = q.front().second;
                q.pop();
                for(int a = 0; a<4; a++){
                    int nx = px + dx[a];
                    int ny = py + dy[a];
                    if(nx>=m || nx<0 || ny<0 || ny >= n)continue;
                    if(arr[nx][ny]!=arr[i][j])continue;
                    if(visited[nx][ny]==false){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            if(arr[i][j] == 1){
                p2 += cnt*cnt;
            }else{
                p1 += cnt*cnt;
            }


        }
    }
    cout<<p1 <<" " <<p2<<"\n";

    return 0;
}
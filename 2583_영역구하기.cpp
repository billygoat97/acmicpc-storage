#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int arr[101][101];
int m,n,k;
vector<int> v;
using T = pair<int,int>;
queue<T> q;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs(int x,int y){
    int cnt = 0;
    arr[x][y] = 2;
    q.push(make_pair(x,y));
    
    // cout<<x<<"::"<<y<<endl;
    while(q.size()!= 0){
        cnt ++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny < 0 || nx >= n || ny >=m){

            }else{
                if(arr[nx][ny]==0){
                    arr[nx][ny] = 3;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    v.push_back(cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int a = 0;a<k; a++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1;i<x2; i++){
            for(int j = y1; j<y2; j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                bfs(i,j);
            }
        }
    }
    if(v.size() == 0){
        cout<<0<<"\n";
        return 0;
    }

    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(int i = 0; i<v.size();i++){
        cout<< v[i]<<" ";
    }
    cout<<"\n";




    return 0;
}
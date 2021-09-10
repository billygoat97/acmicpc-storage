#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int getdist(int x1,int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1) - 1;
}

int n;  
int main(){

    cin >> n;
    int imsi[n][n] = {0,};
    int arr[n][n] = {0,};
    using T = pair<int, int>;
    int dx[] = {-1,0,0,1};
    int dy[] = {0,1,-1,0};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> imsi[i][j];
            arr[i][j] = 0;
        }
    }
    int color=0;
    for(int i = 0; i<n; i++){
        for(int j= 0; j<n; j++){
            if(imsi[i][j]==1 && arr[i][j] ==0){
                color++;
                queue<T> q;
                q.push({i,j});
                arr[i][j] = color;
                while(q.size()!= 0){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int a = 0; a<4; a++){
                        int nx = x + dx[a];
                        int ny = y + dy[a];
                        if (nx < 0 || ny <0 || nx >= n || ny >= n)continue;
                        if(arr[nx][ny] != 0 || imsi[nx][ny] == 0)continue;
                        arr[nx][ny] = color;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    // cout<<"----------------------------"<<endl;
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"----------------------------"<<endl;

    ////////////////////////// 다른 대륙과 구분 끝
    int bridge = 987654321;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] != 0){
                color = arr[i][j];
                queue<T> q;
                bool visited[n][n] = {false,};
                for(int a = 0; a<n; a++){
                    for(int b = 0; b<n; b++)visited[a][b] = false;
                }
                q.push({i,j});
                visited[i][j] = true;
                while(q.size()!= 0){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int a = 0; a<4; a++){
                        int nx = x + dx[a];
                        int ny = y + dy[a];
                        if(nx <0 || ny <0 || nx >= n || ny >= n)continue;
                        if(arr[nx][ny] == color || visited[nx][ny] == true)continue;
                        visited[nx][ny] = true;
                        if(arr[nx][ny] != 0 && arr[nx][ny] != color){
                            // if(getdist(nx,ny,i,j) < bridge){
                            //     cout<<i<<j <<":"<<nx<<ny<<" "<< getdist(nx,ny,i,j)<<"\n";
                            // }
                            bridge = min(bridge, getdist(nx,ny,i,j));
                            q = queue<T>();
                            break;
                        }
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout<<bridge<<"\n";



    return 0;
}
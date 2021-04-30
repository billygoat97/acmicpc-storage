#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 0 ,1};
int dy[] = {0, -1, 1, 0};
int n;
int arr[50][50] = {0,};
int visited[50][50] = {0,};
int main(){
    cin >> n;

    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        for(int j = 0; j<n; j++){
            arr[i][j] = str[j] - 48;
            visited[i][j] = 9999;
        }
    }
    // cout<<endl;
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    visited[0][0] = 0;
    int v_cnt = 0;
    vector<pair<int,int> > v;
    v.push_back(make_pair(0,0));
    while(v.size() > v_cnt){
        int x = v[v_cnt].first;
        int y = v[v_cnt].second;
        v_cnt++;
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || nx >=n || ny <0 || ny >= n){

                }else{
                    if(arr[nx][ny] == 0){// 막힘
                        if(visited[nx][ny] > visited[x][y]+1){
                            visited[nx][ny] = visited[x][y]+1;
                            v.push_back(make_pair(nx,ny));
                        }
                    }else{ // 뚫려있음
                        if(visited[nx][ny] > visited[x][y]){
                            visited[nx][ny] = visited[x][y];
                            v.push_back(make_pair(nx,ny));
                        }else{
                            //visited[x][y] = visited[nx][ny]; --> 이거 하면 뚫은것도 리셋되니까 하면 안됨
                        }
                    }
                }
            }
        }

    }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<visited[i][j];
    //     }
    //     cout<<endl;
    // }

    cout<<visited[n-1][n-1]<<endl;
    

    return 0;
}

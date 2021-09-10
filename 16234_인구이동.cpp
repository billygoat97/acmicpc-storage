#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[50][50] = {0,};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, l , r;
using T = pair<int,int>;

int main(){

    cin >> n >> l >> r;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int day = 0;
    while(true){
        bool visited[50][50] = {false,};
        int flag = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] == true)continue;
                vector<T> v;
                queue<T> q;
                int sum = 0;
                q.push({i,j});
                v.push_back({i,j});
                visited[i][j] = true;
                while(q.size()!= 0){
                    int x = q.front().first;
                    int y=  q.front().second;
                    sum += arr[x][y];
                    q.pop();
                    for(int a = 0; a< 4; a++){
                        int nx = x + dx[a];
                        int ny = y + dy[a];
                        if(nx < 0 || ny <0 || nx >= n || ny >= n)continue;
                        if(visited[nx][ny] == true)continue;
                        int diff = abs(arr[x][y] - arr[nx][ny]);
                        if(diff >= l && diff <= r){
                            visited[nx][ny] = true;
                            flag = 1;
                            q.push({nx,ny});
                            v.push_back({nx,ny});
                        }  
                    }
                }
                sum /= v.size();
                for(int i = 0 ;i<v.size();i++){
                    int x = v[i].first;
                    int y= v[i].second;
                    arr[x][y] = sum;
                }

            }
        }
        if(flag == 0)break;
        day++;



    }

    cout<< day <<endl;

    return 0;
}
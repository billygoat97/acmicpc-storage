#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    using T = pair<int,int>;
    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};
    bool visited[n][m] = {false};
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                for(int a = 0; a<n; a++){
                    fill(visited[a], visited[a]+ m, false);
                }
                queue<T> q;
                queue<int> t;
                q.push({i,j});
                t.push(0);
                visited[i][j] = true;
                while(q.size()!= 0){
                    int x= q.front().first;
                    int y= q.front().second;
                    int time = t.front();
                    t.pop();
                    q.pop();
                    for(int a = 0; a<8; a++){
                        int nx = x + dx[a];
                        int ny = y + dy[a];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])continue;
                        visited[nx][ny] = true;
                        if(arr[nx][ny] == 1){
                            
                            
                            if(time+1 > ans){
                                // cout<< i <<","<< j << "||"<<nx <<", "<<ny<<"???????"<<time<<endl;

                                ans = time+1;
                            }
                            queue<T>nq;
                            q = nq;
                            break;
                        }else{
                            q.push({nx,ny});
                            t.push(time + 1);
                        }
                    }
                }
                
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;
using T = pair<int,int>;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int main(){

    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        char arr[m][n];
        T cur;
        vector<T> f;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@') cur = {i,j};
                if(arr[i][j] == '*') f.push_back({i,j});
            }
        }
        queue<T>fq;
        queue<T>df;
        for(int i = 0; i<f.size();i++){
            fq.push(f[i]);
            df.push({1,0});
        }
        fq.push(cur);
        df.push({0,0});
        int ans = 987654321;
        while(fq.size()!= 0){
            int x = fq.front().first;
            int y = fq.front().second;
            int def = df.front().first; // 0 사람,1 불
            int sec = df.front().second; // 시간
            fq.pop();
            df.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(def == 1){
                    if(nx <0 || ny < 0 || nx >= m || ny >= n || arr[nx][ny] == '#' ||arr[nx][ny] == '*' )continue;
                    arr[nx][ny] = '*';
                    
                }else if(def == 0){
                    if(nx <0 || ny < 0 || nx >= m || ny >= n){
                        ans = sec+1; 
                        queue<T> end;
                        fq = end;
                        break;
                    }else{
                        if(arr[nx][ny] == '#' ||arr[nx][ny] == '*' || arr[nx][ny] == '@')continue;
                        arr[nx][ny] = '@';
                    }
                }
                fq.push({nx,ny});
                df.push({def,sec+1});
            }
            // for(int i = 0; i<m; i++){
            //     for(int j = 0; j<n; j++){
            //         cout<<arr[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<"=============\n";
        }
        if(ans == 987654321){
            cout<<"IMPOSSIBLE\n";
            continue;
        }else{
            cout<<ans<<"\n";
        }
    }
    


    return 0;
}
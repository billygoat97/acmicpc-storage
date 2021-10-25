#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,k;
    cin >> n >>m >>k;
    int arr[n][m];
    for(int i = 0; i<n; i++){
        fill(arr[i],arr[i]+m,0);
    }
    for(int i = 0; i<k; i++){
        int x,y;
        cin >> x >> y;
        arr[x-1][y-1] = 1;
    }

    using T = pair<int,int>;
    queue<T> q;
    int ans = 0;
    int dx[] = {-1,0,0,1};
    int dy[] = {0,-1,1,0};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 1){
                int imsi = 0;
                q.push({i,j});
                arr[i][j] = 0;
                imsi++;
                while(q.size()!= 0){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int a= 0; a<4; a++){
                        int nx = x + dx[a];
                        int ny = y + dy[a];
                        if(nx<0 || ny < 0 || nx>= n || ny >= m)continue;
                        if(arr[nx][ny] == 0)continue;
                        q.push({nx,ny});
                        arr[nx][ny] = 0;
                        imsi++;
                    }
                }
                ans = max(imsi,ans);
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
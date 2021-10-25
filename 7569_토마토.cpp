#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;
int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

class pos{
    public:
        int x;
        int y;
        int z;
        int day;
    pos(int a, int b, int c, int d){
        x = a;
        y = b;
        z = c;
        day = d;
    }
};

int main(){
    int n,m,h;
    cin >> n >> m >> h;
    int arr[h][m][n];
    // bool visited[h][m][n];
    queue<pos> q;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<n; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k]==1){
                    q.push(pos(j,k,i,0));
                    // visited[i][j][k] = true;
                }
            }
        }
    }
    int maxday = 0;
    while(q.size()!= 0){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int day = q.front().day;
        maxday = max(day,maxday);
        q.pop();
        for(int i = 0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || ny <0 || nz <0 || nx >= m || ny >=n || nz >= h)continue;
            if(arr[nz][nx][ny]!=0)continue;
            arr[nz][nx][ny] = 1;
            q.push(pos(nx,ny,nz,day+1));
        }
    }
    for(int i = 0;i<h; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<n; k++){
                if(arr[i][j][k] == 0){
                    cout<<-1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<maxday<<"\n";
    return 0;
}
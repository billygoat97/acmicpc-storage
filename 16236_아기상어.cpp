#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n;
int arr[20][20]={0,};
int curX, curY;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int sz = 2;
int ate = 0;
int cnt = 0;
using T = pair<int,int>;
int able = 1;
int target = 0;
int tx,ty,tt;
void findEdible(){
    queue<T> q;
    queue<int> time;
    q.push({curX,curY});
    time.push(0);
    bool visited[n][n]={false,};
    for(int i = 0; i<n; i++){
        fill(visited[i], visited[i] + n, false);
    }
    able = 0;
    visited[curX][curY] = true;
    tx = 99, ty = 99,tt = 999999;

    while(q.size()!= 0){
        int x = q.front().first;
        int y = q.front().second;
        int curt = time.front();
        time.pop();
        q.pop();
        
        for(int i = 0; i<4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = curt + 1;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
            if(visited[nx][ny] == true)continue;
            
            if(arr[nx][ny]>sz)continue;
            if(nt > tt)continue;
            if(arr[nx][ny] < sz && arr[nx][ny] > 0){
                if(nx < tx){
                    tx = nx;
                    ty = ny;
                    tt = nt;
                }else if(nx == tx){
                    if(ny < ty){
                        tx = nx;
                        ty = ny;
                        tt = nt;
                    }
                }
                visited[nx][ny] = true;
            }else if(arr[nx][ny] == sz || arr[nx][ny] == 0){
                if(tt != 999999)continue;
                q.push({nx,ny});
                time.push(nt);
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){

    cin >> n;
    
    // 자기보다 작으면 먹을수 있고, 자기 크기만큼 먹으면 몸집 + 1, 자기와 사이즈가 같으면 통과 가능
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                curX = i;
                curY = j;
            }
        }
    }
    while(able == 1){
        findEdible();
        if(tt != 999999){
            arr[curX][curY] = 0;
            cnt += tt;
            curX = tx;
            curY = ty;
            able = 1;
            ate++;
            arr[tx][ty] = 9;
            if(ate == sz){
                sz++;
                ate = 0;
            }
        }


    }
    cout<<cnt<<"\n";

    return 0;
}
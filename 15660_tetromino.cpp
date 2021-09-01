#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int arr[501][501];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
bool visited[501][501];
int imsiX[4],imsiY[4];
vector<int> saveX[4],saveY[4];
int sum = 0;
int totalsum = 0;
void firstdfs(int x, int y, int cnt){
    
    imsiX[cnt] = x;
    imsiY[cnt] = y;
    if(cnt == 3){
        int cursum =0;
        for(int i = 0; i<4; i++){
            cursum += arr[imsiX[i]][imsiY[i]];
        }
        if(cursum == sum){
            for(int i = 0; i<4; i++){
                saveX[i].push_back(imsiX[i]);
                saveY[i].push_back(imsiY[i]);
            }
        }else if(cursum > sum){
            sum = cursum;
            for(int i = 0; i<4; i++){
                saveX[i].clear();
                saveY[i].clear();
                saveX[i].push_back(imsiX[i]);
                saveY[i].push_back(imsiY[i]);
            }
        }
        return;
    }
    for(int i = 0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx <0 || ny <0 || nx >=n || ny >= m){

        }else{
            if(visited[nx][ny]==false){
                visited[nx][ny] = true;
                firstdfs(nx,ny,cnt+1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main(){
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            memset(visited,false,sizeof(visited));
            visited[i][j] = true;
            firstdfs(i,j,0);
        }
    }
    ////
    /// 여기서 전체순회 하면서 ㅗ ㅏ ㅜ ㅓ
    ////
    totalsum = sum;
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            memset(visited,false,sizeof(visited));
            visited[i][j] = true;
            firstdfs(i,j,0);
        }
    }

    
    return 0;
}
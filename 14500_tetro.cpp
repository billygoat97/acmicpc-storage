#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int M=-9999999;
int n,m;
int ax[4] ={0,0,1,-1};
int ay[4] ={1,-1,0,0};
void dfs(int x, int y, int num,int imsi_sum, int** visited, int**arr);
void leftover(int x,int y, int**arr);
int main(){
    
    cin >>n>>m;

    int** arr = new int *[n];
    for(int i = 0; i<n;i++){
        arr[i] = new int [m];
    }
    int** visited = new int *[n];
    for(int i = 0; i<n;i++){
        visited[i] = new int [m];
    }
    for(int i = 0 ; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0 ; i<n; i++){
        for (int j = 0; j<m; j++){
            visited[i][j] = 0;
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            visited[i][j] = 1;
            dfs(i,j,0,arr[i][j],visited,arr);
            visited[i][j] = 0;
            leftover(i,j,arr);
        }
    }
    for(int i = 0;i<n;i++){
        delete [] arr[i];
    }
    delete [] arr;
    cout<<M<<endl;
    return 0;
}



void dfs(int x, int y, int num,int imsi_sum, int** visited, int**arr){
    if(num==3){
        //imsi_sum += arr[x][y];
        M = max(M, imsi_sum);
        return;
    }else if(num<3){
        for(int i = 0; i<4;i++){
            int nx = x + ax[i];
            int ny = y + ay[i];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(visited[nx][ny]==0){
                visited[nx][ny]=1;
                dfs(nx,ny,num+1,imsi_sum+arr[nx][ny],visited,arr);
                visited[nx][ny] = 0;
            }
        }
    }
}

void leftover(int x, int y, int ** arr) {
    int sum = 0;
    //ㅏ
    if(x<n-1&&y<m-2){
        sum = arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1];
        M = max(sum,M);
    }

    //ㅜ
    if(x<n-2&&y<m-1){
        sum = arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y+1];
        M = max(sum,M);
    }

    //ㅓ
    if(x<n-1&&y<m-2){
        sum = arr[x+1][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x+1][y+2];
        M = max(sum,M);
    }

    //ㅗ
    if(x<n-2&&y<m-1){
        sum = arr[x][y+1] + arr[x+1][y+1] + arr[x+2][y+1] + arr[x+1][y];
        M = max(sum,M);
    }
}
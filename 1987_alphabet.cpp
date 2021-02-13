#include<iostream>
#include <cmath>

using namespace std;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
int R,C;
int ans=0;
char arr[20][20]={0,};
int visited[26]={0,};

void dfs(int y,int x,int count){
    
    ans = max(ans,count);
    
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=R || nx<0 || nx>=C){ // 범위 초과
            continue;
        }   
        int imsi;
        imsi = (int)arr[ny][nx]-65;// 0 ~ 25
        if(visited[imsi]){
            continue;
        }else{
            visited[imsi]++;
            dfs(ny,nx,count+1);
            visited[imsi]--;
        }
    }
}


int main(){

    cin >>R >>C;

    for(int i= 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0]-65] = 1;
    dfs(0,0,1);

    cout<< ans <<endl;

    return 0;

}
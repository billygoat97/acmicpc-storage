#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 3
102
 4
 5
*/
int dice[] = {1,4,3,2,5,6};
int n,m,k, ans = 0;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
//0 동 1 북 2 서 3 남
int arr[20][20] = {0,};
bool visit[20][20] = {false,};
int reverse(int dir){
    return (dir + 2)%4;
}
int changeDir(int dir, int diff){
    if(diff >0){
        return (4 + dir-1)%4;
    }else if(diff<0){
        return (dir+1)%4;
    }
    return dir;
}

void move(int dir){ // 걍 노가다 하자
    int imsi = 0;
    if(dir == 0){ // 동
        imsi = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = imsi;
    }else if(dir == 1){ //북
        imsi = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[3];
        dice[3] = imsi;
    }else if(dir == 2){ // 서
        imsi = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = imsi;
    }else if(dir == 3){ // 남
        imsi = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[3];
        dice[3] = imsi;
    }
}




int main(){

    // 가장 왼쪽 좌표 1,1
    // 가장 오른쪽 n,m
    // 가장 처음 이동 동쪽
    // 
    cin >> n >> m >> k; // k는 이동 횟수
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >>arr[i][j];
        }
    }
    // 중복 계산 ㄴㄴ -> 그냥 값 저장하면 됨 20 * 20 = 400 가지
    int x = 0, y = 0, dir = 0, nx = 0, ny = 0;
    for(int i = 0; i<k; i++){
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(nx <0 || ny <0 || nx>=n || ny >= m){
            dir = reverse(dir);
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        // 점수 계산
        
        for(int a = 0; a<n; a++){
            for(int b = 0; b<m; b++){
                visit[a][b] = false;
            }
        }
        queue<pair<int,int>> q;
        


        move(dir);
        dir = changeDir(dir, dice[0] - arr[nx][ny]);
        x = nx;
        y = ny;
    }

    return 0;
}
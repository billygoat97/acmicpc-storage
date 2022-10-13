#include <iostream>
using namespace std;
int n,x,y,px,py,nx,ny,answer = 0;
int dx[] ={-2,-1,-1,-1,0,0,0,1,1,1,2}; 
int dy[] ={0,-1,0,1,-2,-1,0,-1,0,1,0};
int times[] = {2,10,7,1,5,0,0,10,7,1,2};
int arr[499][499] = {0,};
int funcX(int dir, int i){
    if(dir==0)return dy[i];
    if(dir==1)return dx[i];
    if(dir==2)return -dy[i];
    if(dir==3)return -dx[i];
    return 0;
}
int funcY(int dir, int i){
    if(dir==0)return -dx[i];
    if(dir==1)return -dy[i];
    if(dir==2)return dx[i];
    if(dir==3)return dy[i];
    return 0;
}
void move(int dir){
    if(dir ==0)x--;
    if(dir ==1)y++;
    if(dir ==2)x++;
    if(dir ==3)y--;
    int imsi = 0;
    for(int i = 0; i<11;i++){
        nx = x + funcX(dir,i);
        ny = y + funcY(dir,i);
        if(i == 5){
            px = nx;
            py = ny;
        }
        if(nx <0 || ny <0 || nx >= n || ny >=n){
            imsi += (times[i]*arr[x][y])/100;
            answer += (times[i]*arr[x][y])/100;
        }else{
            imsi += (times[i]*arr[x][y])/100;
            arr[nx][ny] += (times[i]*arr[x][y])/100;
        }
    }
    if(px <0 || py <0 || px >= n || py >=n){
        answer += (arr[x][y] - imsi);
    }else{
        arr[px][py] += (arr[x][y] - imsi);
    }
    arr[x][y] = 0;   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j= 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    x = (n-1)/2; 
    y = (n-1)/2;
    for(int i = 1; i<n;i++){
        if(i%2 == 1){
            for(int j = 0; j<i;j++){
                move(3);
            }
            for(int j = 0; j<i;j++){
                move(2);
            }
        }else{
            for(int j = 0; j<i;j++){
                move(1);
            }
            for(int j = 0; j<i;j++){
                move(0);
            }
        }
    }
    for(int i = 0; i<n-1;i++){
        move(3);
    }
    cout<< answer <<endl;
}
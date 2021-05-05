#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int dice[] = {0,0,0,0,0,0,0};
int temp[] = {0,0,0,0,0,0,0};
int arr[20][20]={0,};
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int n,m,x,y,num;

void move(int i){
    int nx = x + dx[i];
    int ny = y + dy[i];

    //cout<<nx<<" "<<ny<<endl;
    if(nx<0 || nx >= n || ny <0 || ny >=m)return;
    x = nx;
    y = ny;
    for(int i = 1; i<7; i++){
        temp[i] = dice[i];
    }
    if(i ==1){//동
        dice[1] = temp[4];
        dice[2] = temp[2];
        dice[3] = temp[1];
        dice[4] = temp[6];
        dice[5] = temp[5];
        dice[6] = temp[3];
    }else if(i == 2){ //서
        dice[1] = temp[3];
        dice[2] = temp[2];
        dice[3] = temp[6];
        dice[4] = temp[1];
        dice[5] = temp[5];
        dice[6] = temp[4];
    }else if(i == 3){ //남
        dice[1] = temp[2];
        dice[2] = temp[6];
        dice[3] = temp[3];
        dice[4] = temp[4];
        dice[5] = temp[1];
        dice[6] = temp[5];
    }else if(i == 4){ // 북
        dice[1] = temp[5];
        dice[2] = temp[1];
        dice[3] = temp[3];
        dice[4] = temp[4];
        dice[5] = temp[6];
        dice[6] = temp[2];
    }
    if(arr[x][y]==0){
        arr[x][y] = dice[6];
    }else{
        dice[6] = arr[x][y];
        arr[x][y] = 0;
    }
    cout<<dice[1]<<endl;
}


int main(){

    cin >> n >> m >> x >> y >> num;
    
    
    for(int i = 0; i< n;i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> v;
    for(int i = 0; i< num; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }

    for(int i = 0; i< v.size(); i++){
        move(v[i]);
    }
    

    return 0;
}

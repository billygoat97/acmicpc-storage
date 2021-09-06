#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n;
char arr[50][50];
int big = 0;
int dx[] = {1,0};
int dy[] = {0,1};


void check(int x, int y){
    char cur = arr[x][0];
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(cur == arr[x][i]){
            cnt++;
        }else{
            cur = arr[x][i];
            cnt = 1;
        }
        big = max(big, cnt);

    }
    cur = arr[0][y];
    cnt = 0;
    for(int i = 0; i<n; i++){
        if(cur == arr[i][y]){
            cnt++;
        }else{
            cur = arr[i][y];
            cnt = 1;
        }
        big = max(big, cnt);

    }

}

void func(int x, int y){

    for(int i = 0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(arr[nx][ny] == arr[x][y])continue;
        if(nx >= n || ny >= n)continue;
        char imsi = arr[x][y];
        arr[x][y] = arr[nx][ny];
        arr[nx][ny] = imsi;
        check(x,y);
        check(nx,ny);
        imsi = arr[x][y];
        arr[x][y] = arr[nx][ny];
        arr[nx][ny] = imsi;
    }

}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            cin >>arr[i][j];
        }
    }

    for(int i =0; i<n;i++){
        for(int j = 0; j<n; j++){
            check(i,j);
        }
    }
    for(int i =0; i<n;i++){
        for(int j = 0; j<n; j++){
            func(i,j);
        }
    }

    cout<<big <<"\n";


    return 0;
}
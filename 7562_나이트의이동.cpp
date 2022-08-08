#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n; // tc;
int sz; // 
int l; // 체스판 크기
int sx,sy, dx,dy; // 시작점, 도착하려는 점
int arr[300][300] = {0,};
int px[8][2] = {{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};

bool checkValid(int a, int b){
    if(a <0 || b <0 || a >= l || b >= l){
        return false;
    }
    if(arr[a][b] == 1){
    return false;
    }

    return true;
}

int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >> n;

    for(int i = 0; i<n; i++){
        
        queue<pair<int, int>> q;
        queue<int> cnt;
        for(int xx = 0; xx<300; xx++){
            for(int yy = 0; yy<300; yy++){
                arr[xx][yy] = 0;
            }
        }
        arr[300][300] = {0,};
        cin >> l;
        cin >> sx >> sy;
        cin >> dx >> dy;
        if(sx == dx && sy == dy){
            cout << 0 <<endl;
            continue;
        }
        
        q.push(make_pair(sx,sy));
        cnt.push(0);
        while(q.size()!= 0){
            int nx,ny,nCnt;
            sx = q.front().first;
            sy = q.front().second;
            q.pop();
            nCnt = cnt.front() + 1;
            cnt.pop();
            
            for(int j = 0; j<8; j++){
                nx = sx + px[j][0];
                ny = sy + px[j][1];
                if(checkValid(nx,ny)){
                    if(nx == dx && ny == dy){
                        cout << nCnt <<endl;
                        break;
                    }else{
                        arr[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                        cnt.push(nCnt);
                    }
                }
            }
            if(nx == dx && ny == dy)break;
        }
    }


    return 0;
}
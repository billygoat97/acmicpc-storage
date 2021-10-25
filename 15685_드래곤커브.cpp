#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
bool map[101][101] = {false,};
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
using T = pair<int,int>;
int main(){

    int n;
    cin >> n;
    for(int c = 0; c<n; c++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        map[y][x] = true;
        queue<T> q1,q2;
        stack<T> s1,s2;
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        q1.push({y,x});
        q1.push({ny,nx});
        int cx = nx,cy = ny;
        for(int i = 0; i<g; i++){
            if(q1.size() != 0){
                while(q1.size()!= 0){
                    int py = q1.front().first;
                    int px = q1.front().second;
                    q1.pop();
                    int dx = px - cx;
                    int dy = py - cy;
                    nx = cx - dy;
                    ny = cy - dx;
                    map[ny][nx] = true;
                    q2.push({ny,nx});

                    if(q1.size() == 0){
                        cx = px;
                        cy = py;
                    }
                }
            }else{
                while(q2.size()!= 0){
                    int py = q2.front().first;
                    int px = q2.front().second;
                    q2.pop();
                    int dx = px - cx;
                    int dy = py - cy;
                    nx = cx - dy;
                    ny = cy - dx;
                    map[ny][nx] = true;
                    q1.push({ny,nx});

                    if(q2.size() == 0){
                        cx = px;
                        cy = py;
                    }
                }
            }
        }
    }

    for(int i = 0; i<=100; i++){
        for(int j = 0; j<= 100; j++){
            cout<<(int)map[i][j]<<" ";
        }
        cout<<endl;
    }

    int cnt = 0;
    for(int i = 0; i<=100; i++){
        for(int j = 0; j<= 100; j++){
            if(i+1 >100 || j + 1 > 100)continue;
            if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1] == true)cnt++;
        }
    }
    cout<<cnt<<"\n";

    return 0;
}
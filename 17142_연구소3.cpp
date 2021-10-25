#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;
using T = pair<int,int>;
int arr[50][50]={0,};
int imsi[50][50]={0,};
vector<T> v; // 바이러스 위치 저장
int n, vnum;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
bool vchk[10] = {false,};
int ans = 987654321;
int cntzero = 0;
void bfs(){
    queue<T> q;
    queue<int> day;
    for(int i = 0; i<v.size(); i++){
        if(vchk[i] == true){
            q.push({v[i].first,v[i].second});
            day.push(0);
        }else{
            imsi[v[i].first][v[i].second] = 3;
        }
    }
    int curmax = 0;
    while(q.size()!= 0){
        int x = q.front().first;
        int y = q.front().second;
        int d = day.front();
        curmax = max(d,curmax);
        q.pop();
        day.pop();
        if(cntzero == 0)continue;
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >= n)continue;
            if(imsi[nx][ny] == 1 || imsi[nx][ny] == 2)continue;
            if(imsi[nx][ny] == 0){
                cntzero--;
            }
            imsi[nx][ny] = 2;
            q.push({nx,ny});
            day.push(d+1);
        }
    }
    if(cntzero== 0)ans = min(curmax,ans);
}
void comb(int cur, int idx){
    if(cur == vnum){
        cntzero = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                imsi[i][j] = arr[i][j];
                if(imsi[i][j] == 0)cntzero++;
            }
        }
        bfs();
    }else{
        for(int i = idx; i<v.size();i++){
            vchk[i] = true;
            comb(cur+1,i+1);
            vchk[i] = false;
        }
    }
}




int main(){
    cin >> n >> vnum;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back({i,j});
            }
        }
    }
    comb(0,0);

    if(ans == 987654321)ans = -1;
    cout<<ans<<"\n";

    return 0;
}


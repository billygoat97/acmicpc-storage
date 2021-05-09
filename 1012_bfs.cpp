#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <sstream>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int n,m,x,y,k,inp;
string str;
vector<int> v,v1,v2;
vector<pair<int,int> > vv;
map<int,int> ma;

int main(){
    int num;
    cin >> num;
    while(num--){
        int arr[50][50] = {0,};
        bool visited[50][50] = {false,};
        cin >> n >> m>>k;
        for(int i = 0; i< k; i++){
            cin >> x >> y;
            arr[x][y] = 1;
            vv.push_back(make_pair(x,y));
        }

        queue<pair<int, int> > q;
        int cnt = 0;
        for(int i = 0; i<vv.size(); i++){
            if(visited[vv[i].first][vv[i].second] == true)continue;
            cnt++;
            q.push(make_pair(vv[i].first, vv[i].second));
            //visited[vv[i].first][vv[i].second] = true;
            while(q.size()!=0){
                int px = q.front().first, py = q.front().second;
                
                q.pop();
                if(visited[px][py] == true)continue;
                visited[px][py] = true;
                for(int j = 0; j<4; j++){
                    int nx = px + dx[j];
                    int ny = py + dy[j];
                    if(nx <0 || nx >=n || ny <0 || ny >=m){

                    }else{
                        if(arr[nx][ny]==1){
                            if(visited[nx][ny]==false){
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<'\n';
        vv.clear();
        

    }
    

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int n,m;
int arr[8][8];
int imsi[8][8];
int visited[8][8] = {0,};

int dy[] = {1,0,0,-1};
int dx[] = {0,1,-1,0};
vector<pair<int,int> > virus;
vector<pair<int,int> > space;
int total = 0;


void bfs(int x1, int y1, int x2, int y2, int x3, int y3){

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            imsi[i][j] = arr[i][j];
        }
    }
    imsi[x1][y1] = 1;
    imsi[x2][y2] = 1;
    imsi[x3][y3] = 1;
    queue<pair<int, int> > q;
    for(int i = 0; i< virus.size();i++){
        q.push(make_pair(virus[i].first,virus[i].second));
    }
    while(q.empty()==false){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || nx >= n || ny <0 || ny >=m){

            }else{
                if(imsi[nx][ny]==0){
                    imsi[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(imsi[i][j] == 0)cnt++;
        }
    }
    if (cnt > total)total = cnt;

}

void solve(){
    for(int i= 0; i<space.size()-2;i++){
        for(int j= i; j<space.size();j++){
            for(int k= j; k<space.size();k++){
                if(i== j || j==k || i == k){

                }else{
                    // cout<< space[i].first<<","<<space[i].second<<" "<<space[j].first<<","<<space[j].second<<" "<<space[k].first<<","<<space[k].second<<endl;
                    bfs(space[i].first, space[i].second,space[j].first, space[j].second,space[k].first, space[k].second);
                }
            }
        }
    }
    
    


}

int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);

    fill(arr[0],arr[0]+64,-1);
    fill(imsi[0],imsi[0]+64,-1);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 2)virus.push_back(make_pair(i,j));
            if (arr[i][j] == 0)space.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<space.size();i++){
        // cout<< space[i].first<<" "<<space[i].second<<endl;
    }
    solve();


    cout<< total<<endl;

    return 0;
}

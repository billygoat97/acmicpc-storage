#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,sx,sy,dir,dist;
int arr[51][51] = {0,};
int arrPos[51][51] = {0,};
vector<int> v; // 구슬이 순서대로 (원형으로 있는 것)
queue<pair<int,int>>order; // 주문 순
int ans[4] = {0,};


void arrToVec(){
    // arr 좌표를 vec 순서로 -> 초기에만 하면 됨
    int x = sx; 
    int y = sy;
    int cnt = -1;
    for(int i = 1; i<n; i++){
        if(i%2 == 1){
            for(int j = 0; j<i;j++){
                y--;cnt++;
                arrPos[x][y] = cnt;
                v.push_back(arr[x][y]);
            }
            for(int j = 0; j<i;j++){
                x++;cnt++;
                arrPos[x][y] = cnt;
                v.push_back(arr[x][y]);
            }
        }else{
            for(int j = 0; j<i;j++){
                y++;cnt++;
                arrPos[x][y] = cnt;
                v.push_back(arr[x][y]);
            }
            for(int j = 0; j<i;j++){
                x--;cnt++;
                arrPos[x][y] = cnt;
                v.push_back(arr[x][y]);
            }
        }
    }
    for(int j = 0; j<n-1;j++){
        y--;cnt++;
        arrPos[x][y] = cnt;
        v.push_back(arr[x][y]);
    }
}

void changeV(){ // 구슬 새로 생성
    vector<int>imsiV;
    int cur = v[0];
    int cnt = 1;
    if(cur!= 0){
        for(int i = 1; i<v.size(); i++){
            if(v[i] == cur){

            }else{
                imsiV.push_back(cnt);
                imsiV.push_back(cur);
                cur = v[i];
                cnt = 0;
            }
            cnt++;
        }
        imsiV.push_back(cnt);
        imsiV.push_back(cur);
    }
    while(imsiV.size()>=n*n)imsiV.pop_back();
    while(imsiV.size()!= n*n-1){
        imsiV.push_back(0);
    }
    v = imsiV;
}

bool boom(){
    bool flag = false;
    int cur = v[0];
    int cnt = 1;
    int i = 1;
    while(1){
        if(i >=v.size())break; // 등호 모르겠음
        
        if(v[i] == cur){

        }else{
            if(cnt >=4){
                ans[cur] += cnt;
                for(int j = 0; j<cnt;j++){
                    v[i-j-1] = 0;
                }
                flag = true;
            }
            cnt = 0;
            cur = v[i];
        }
        if(v[i] == 0)break;
        cnt++;
        i++;
    }

    if(cnt >=4){
        ans[cur] += cnt;
        for(int j = 0; j<cur;j++){
            v[i-j-1];
        }
        cnt = 0;
        cur = v[i];
    }

    vector<int> imsiV;
    for(int i = 0; i<v.size();i++){
        if(v[i]!= 0)imsiV.push_back(v[i]);
    }
    v = imsiV;

    return flag;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    sx = n/2;
    sy = n/2;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >>arr[i][j];
        }
    }
    arrToVec();
    
    
    for(int i = 0; i<m; i++){
        cin >> dir >> dist; // 1상2하3좌4우
        for(int j = dist; j>0;j--){
            switch(dir){
                case 1:
                    v.erase(v.begin() + arrPos[sx-j][sy]);
                    break;
                case 2:
                    v.erase(v.begin() + arrPos[sx+j][sy]);
                    break;
                case 3:
                    v.erase(v.begin() + arrPos[sx][sy-j]);
                    break;
                case 4:
                    v.erase(v.begin() + arrPos[sx][sy+j]);
                    break;
            }
        }
        while(boom()){

        }
        changeV();
    }
    cout<<ans[1] + ans[2]*2 + ans[3]*3 <<"\n";

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[300][300] = {0,};
bool visited[300][300] = {false,};
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int cnt = 0;

void melt(){
    int imsi[300][300] = {0,};
    for(int i = 1; i<n-1; i++){
        for(int j= 1; j<m-1; j++){
            for(int a = 0; a<4; a++){
                int nx = i + dx[a];
                int ny = j + dy[a];
                if(arr[nx][ny] == 0)imsi[i][j]++;
            }
        }
    }
    for(int i = 1; i<n-1; i++){
        for(int j= 1; j<m-1; j++){
            arr[i][j] = max(arr[i][j] - imsi[i][j], 0);
        }
    }
}

int sum(){
    int ice = 0;
    for(int i = 1; i<n-1; i++){
        for(int j= 1; j<m-1; j++){
            ice += arr[i][j];
        }
    }
    return ice;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    while(1){
        if(sum() == 0){
            cout<< 0;
            return 0;
        }
        bool flag = false;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(arr[i][j] != 0 && visited[i][j] == false){
                    if(flag == true){
                        cout<<cnt <<endl;
                        return 0;
                    }
                    flag = true;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    while(q.size()!=0){
                        int cx = q.front().first;
                        int cy = q.front().second;
                        q.pop();
                        for(int a= 0; a<4; a++){
                            int nx = cx + dx[a];
                            int ny = cy + dy[a];
                            if(arr[nx][ny] != 0  && visited[nx][ny] == false){
                                q.push(make_pair(nx,ny));
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                visited[i][j] = false;
            }
        }
        // 이제 두동강 이상이 났는지 확인
        
        melt();
        // cout<<"================\n";
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"================\n";
        cnt++;
    }
    
    return 0;
}
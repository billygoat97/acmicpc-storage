#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int arr[100][100]={0,};
int v[100][100] = {0,};
int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};
bool check[100][100] = {false};
int n,m;

void djikstra(){


    queue <pair<int, int> > q;
    q.push(make_pair(0,0));

    //cout<<arr[0][0]<<endl;
    while(q.empty()== false){

        int x = q.front().first;
        int y = q.front().second;
        // cout<<x<<','<<y<<endl;
        // for(int i = 0; i<m;i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<v[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<"==============\n";
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || nx >= m || ny <0 || ny >= n){

            }else{

                if(check[nx][ny] == false){
                    if(arr[nx][ny]== 1){
                        v[nx][ny] = v[x][y];
                        v[nx][ny]++;
                        q.push(make_pair(nx,ny));
                        check[nx][ny] = true;
                    }else{
                        check[nx][ny] = true;
                        v[nx][ny] = v[x][y];
                        q.push(make_pair(nx,ny));

                    }
                }else{
                    if(arr[nx][ny]== 1){
                        if(v[nx][ny]> v[x][y]+1){
                            v[nx][ny] = v[x][y];
                            v[nx][ny]++;
                            q.push(make_pair(nx,ny));
                        }
                    }else{
                        if(v[nx][ny]> v[x][y]){
                            v[nx][ny] = v[x][y];
                            q.push(make_pair(nx,ny));
                        }

                    }
                }
                
            }
        }
    }

    
    cout<<v[m-1][n-1]<<'\n';
}

int main(){

    string str;
    cin >> n >>m;
    for(int i = 0; i<m; i++){
        cin >> str;
        for(int j = 0; j< str.size();j++){
            arr[i][j] = str[j]-48;
        }
    }
    djikstra();

}

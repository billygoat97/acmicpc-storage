#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int n,m;
int arr[1000][1000];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n>>m;
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      cin >> arr[i][j];
    }
  }
  queue<pair<int,int> >q;
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n;j++){
      if(arr[i][j] == 1){
        q.push(make_pair(i,j));
      }
    }
  }
  int cnt = 0;
  q.push(make_pair(-1,-1));
  while(q.size()!=0){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(x == -1 && y == -1){
      if(q.size()!=0){
        cnt++;
        q.push(make_pair(-1,-1));
      }
    }
    for(int i = 0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx <0 || ny <0 || nx >= m || ny >= n)continue;
      if(arr[nx][ny]==0){
        arr[nx][ny] = 1;
        q.push(make_pair(nx,ny));
      }
    }
  }


  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j] == 0){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<cnt<<endl;


  return 0;
  
}
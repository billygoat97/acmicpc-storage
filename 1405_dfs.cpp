#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
double dir[4];
double simple = 0;
double total = 0;

int arr[30][30];
int dx[]={1,-1,0,0};
int dy[] = {0,0,1,-1};

double dfs(int x, int y, int depth){

  double cur = 0;
  if(depth == n){
    return 1;
  }else{
    for(int i = 0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(arr[nx][ny]==0){
        arr[nx][ny] = 1;
        cur += dir[i]*dfs(nx,ny,depth+1);
        arr[nx][ny] = 0;  
      }
    }
  }
  return cur;
}

int main(){

  cin.tie(NULL);
	cin.sync_with_stdio(false);
  
  cin >> n >> dir[0] >> dir[1] >> dir[2] >> dir[3];
  for(int i = 0; i<4; i++)dir[i]/=100;

  arr[15][15] = 1;
  simple = dfs(15,15,0);
  cout.precision(9);
  cout<< simple<<endl;
  return 0;
}
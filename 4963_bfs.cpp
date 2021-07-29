#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int n;
int arr[50][50];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while(true){
    int w,h;
    cin >> w >> h;
    if( w== 0 && h == 0) return 0;
    for(int i = 0 ; i<h; i++){
      for(int j = 0; j<w; j++){
        cin >> arr[i][j];
      }
    }
    


    queue <pair<int, int> > q;
    int cnt = 0;
    for(int i = 0; i<h; i++){
      for(int j = 0; j<w; j++){
        if(arr[i][j] == 1){
          arr[i][j] = 0;
          cnt++;
          q.push(make_pair(i,j));
          while(q.size()!= 0){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int m = 0; m<8; m++){
              int nx = x + dx[m];
              int ny = y + dy[m];
              if(nx <0 || ny <0 || nx >= h || ny >= w){

              }else{
                if(arr[nx][ny] == 1){
                  arr[nx][ny] = 0;
                  q.push( (make_pair(nx,ny)) );
                }
              }
            }
          }
        }
        
      }
    }
    cout<<cnt<<endl;
  }

  return 0;
  
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int tc;
int n;
int arr[100001];
bool visit[100001];
int cnt;// n명에서 빠지고 남은 수
vector<int>v;
int flag = 0;

void dfs(int node, int start){
  if(arr[node]==0){ // 만약에 다음거가 애초에 없으면
    for(int i = 0; i<v.size();i++){
      if(visit[v[i]]==true){ // track 지우기
          visit[v[i]] = false;
          arr[v[i]] = 0;
      }
    }
    return;
  }
  if(node==start){ // 만약에 원으로 돌아서 자기로 왔다!
    for(int i = 0; i<v.size(); i++){
      if(visit[v[i]]==true){
        visit[v[i]] = false;
        arr[v[i]] = 0;
        cnt--;
      }
    }
    return;
  }
  if(visit[node]==false){
    visit[node] = true;
    v.push_back(node);
    dfs(arr[node],start);
  }else{
    for(int i = 0; i<v.size(); i++){
      if(v[i] == node){
        flag = 1;
      }
      if(visit[v[i]]==true){
        arr[v[i]] = 0;
        visit[v[i]] = false;
        if(flag == 1){
          cnt--;
        }
      }
    }
    return;
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> tc;


  for(int q = 0; q<tc;q++){
    cin >>n;
    memset(arr,0,sizeof(n+1));
    cnt = n;
    for(int i = 1 ;i<=n; i++){
      cin >> arr[i];
    }

    /// so far so good
    for(int i = 1; i<=n; i++){
      if(arr[i]!=0){
        flag = 0;
        v.push_back(i); // track
        visit[i] = true; // 감
        dfs(arr[i],i); // dfs로 출발
        v.clear(); // track 삭제
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
  
}
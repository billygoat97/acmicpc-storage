#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

int n,m;
vector<pair<int, int> > arr[801];
int d[801];


void dijkstra(int start){
  using T = pair<int,int>;
  priority_queue<T, vector<T>,greater<T>>pq;
  pq.push({0,start});
  d[start] = 0;
  while(pq.size()!= 0){
    int dist = pq.top().first;
    int now = pq.top().second;
    pq.pop();
    if(d[now]<dist)continue;
    for(int i = 0; i<arr[now].size();i++){
      int cost = dist + arr[now][i].second;
      if(cost < d[arr[now][i].first]){
        d[arr[now][i].first] = cost;
        pq.push(make_pair(cost,arr[now][i].first));
      }
    }
    
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  fill(d,d+n, INF);
  for(int i = 0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    arr[a-1].push_back({b-1,c});
  }
  int start,dest;
  cin >> start >> dest;
  dijkstra(start-1);
  cout<<d[dest-1]<<endl;
  return 0;
  
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int V,E;
vector<pair<int, int> > v[10001];
bool visited[10001];

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // 프림 알고리즘
  cin >> V >> E;
  for(int i = 0; i<E; i++){
    int a, b,c;
    cin >> a>> b >> c;
    v[a].push_back(make_pair(c,b));
    v[b].push_back(make_pair(c,a));
  }
  priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;
  for(int i = 0; i<v[1].size(); i++){
    pq.push(make_pair(v[1][i].first,v[1][i].second));
  }
  int total = 0;
  visited[1] = true;
  while(pq.size()!=0){
    int value = pq.top().first;
    int next = pq.top().second;
    pq.pop();
    if(visited[next] == true)continue;
    visited[next] = true;
    total += value;
    for(int i = 0; i<v[next].size();i++){
      pq.push(make_pair(v[next][i].first,v[next][i].second));
    }
  }
  cout<<total<<endl;
  return 0;
  
}
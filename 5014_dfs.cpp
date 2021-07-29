#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int F,S,G,U,D;
queue<pair<int, int> >q;
int cur,time;
int least= BIG;
int visit[1000001];

void bfs(int S){
  q.push(make_pair(S,0));
  while(q.size()!= 0){
    cur = q.front().first;
    time = q.front().second;
    visit[cur] = 1;
    q.pop();

    int curU = cur + U;
    int curD = cur - D;
    if(curU == G || curD == G){
      least = time+1;
      break;
    }
    if(curU <= F){
      if(visit[curU]==0){
        
        visit[curU] = 1;
        q.push(make_pair(curU,time+1));
      }
    }
    if(curD >= 1){
      if(visit[curD]==0){
        
        visit[curD] = 1;
        q.push(make_pair(curD,time+1));
      }
    }
  }


}

int main(){

  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> F >> S >> G >> U >> D;
  if(S==G){
    cout<<0<<endl;
    return 0;
  }
  bfs(S);
  if(least == BIG){
    cout<<"use the stairs"<<endl;
  }else{
    cout<< least<<endl;
  }
  return 0;

}
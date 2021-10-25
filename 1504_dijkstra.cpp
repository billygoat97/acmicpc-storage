#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;


int n,m;
vector<pair<int, int> > imsi[801];
vector<pair<int, int> > arr[801];
int d[801];


void dijkstra(int start){
    priority_queue<pair<int,int>>pq;
    pq.push({0,start});
    d[start] = 0;
    while(pq.size()!= 0){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now]<dist)continue;
        for(int i = 0; i<arr[now].size();i++){
            int cost = dist + arr[now][i].second;
            if(cost < d[arr[now][i].first]){
                d[arr[now][i].first] = cost;
                pq.push(make_pair(-cost,arr[now][i].first));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a-1].push_back({b-1,c});
        arr[b-1].push_back({a-1,c});
    }
    int mid1,mid2;
    int ans = 0;
    cin >> mid1 >> mid2;
    fill(d,d+n, INF);
    dijkstra(0);
    int a1 = d[mid1-1], b1 = d[mid2-1];
    
    fill(d,d+n, INF);
    dijkstra(n-1);
    int a2 = d[mid1-1], b2 = d[mid2-1];
    fill(d,d+n, INF);
    dijkstra(mid1-1);
    ans += d[mid2-1] + min(a1+b2, a2+b1);
    if(ans >= INF || ans < 0){
        ans = -1;
    }
    cout<<ans<<endl;



    return 0;
  
}
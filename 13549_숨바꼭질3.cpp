#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 987654321

using namespace std;


int n,k;
vector<pair<int, int> > arr[100001];
int d[100001];

void dijkstra(int start){
    using T = pair<int,int>;
    priority_queue<T,vector<T>,greater<T> >pq;
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


    cin >> n>> k;
    int end = 100000;
    arr[0].push_back({1,1});
    arr[end].push_back({end-1,1});
    for(int i = 1; i<=end/2; i++){
        arr[i].push_back({i-1,1});
        arr[i].push_back({i+1,1});
        arr[i].push_back({2*i,0});
    }
    for(int i = end/2+1; i<end; i++){
        arr[i].push_back({i-1,1});
        arr[i].push_back({i+1,1});
    }
    fill(d,d+end+1,INF);
    dijkstra(n);
    cout<<d[k]<<endl;

    return 0;
}
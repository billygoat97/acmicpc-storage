#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#define INF 987654321
using namespace std;
using T = pair<int,int>;

vector<T> arr[101];
int value[101] = {0,};
int n,m,r;
int d[101] = {0,};
void djikstra(int start){
    priority_queue<T,vector<T>,greater<T>> pq; 
    pq.push({0,start});
    d[start] = 0;
    while(pq.size()!= 0){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(d[node] < cost)continue;
        for(int i = 0; i<arr[node].size(); i++){
            int next = arr[node][i].second;
            int dist = arr[node][i].first;
            if(d[next] > cost + dist){
                pq.push({cost+dist,next});
                d[next] = cost + dist;
            }
        }
    }

}


int main(){

    cin >> n >> m >> r;
    for(int i = 1; i<=n; i++){
        cin >> value[i];
    }
    for(int i = 0; i<r; i++){
        int to, from, dist;
        cin >> to >> from >> dist;
        arr[to].push_back({dist,from});
        arr[from].push_back({dist,to});
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++)d[j] = INF;
        djikstra(i);
        int imsi = 0;
        for(int j = 1; j<= n; j++){
            if(d[j] <= m)imsi+= value[j];
        }
        ans = max(ans,imsi);

    }
    cout<<ans<<"\n";

    return 0;
}
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        int m,n;
        cin >> m >> n;
        if(m == 0 && n == 0)break;
        using T = pair<int,int>;
        vector<T>v[m]; // 왼쪽거가 비용, 오른쪽거가 가는 곳
        int ans = 0;
        for(int i = 0; i<n; i++){
            int from, to, cost;
            cin >> from>>to >>cost;
            v[from].push_back({cost,to});
            v[to].push_back({cost,from});
            ans += cost;
        }
        bool visited[m];
        fill(visited,visited+m,false);
        priority_queue<T,vector<T>,greater<T>> q;
        // visited[0] = true;
        // for(int i = 0; i<v[0].size(); i++){
        //     q.push(v[0][i]);
        // }
        q.push({0,0});
        while(q.size()!= 0){
            int cost = q.top().first;
            int cur = q.top().second;
            q.pop();
            if(visited[cur] == true)continue;
            ans -= cost;
            visited[cur] = true;
            for(int i = 0; i<v[cur].size(); i++){
                int next = v[cur][i].second;
                int dist = v[cur][i].first;
                if(visited[next] == true)continue;
                q.push(v[cur][i]);
            }
        }
        cout<<ans<<"\n";
    }

    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#define INF 987654321
using namespace std;


int main(){

    int caseN;
    cin >> caseN;
    while(caseN--){
        using T = pair<int,int>;
        vector<T> v[10001];
        int far[10001]={0,};
        int n=0,d=0,c=0;
        cin >> n >> d >> c;
        fill(far,far+n+1,INF);
        for(int i = 0; i<d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            // v[a].push_back(make_pair(b,s));
            v[b].push_back(make_pair(a,s));
        }

        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push(make_pair(0,c));
        far[c] = 0;
        while(pq.size()!= 0){
            int dist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(far[cur] < dist)continue;
            for(int i = 0; i<v[cur].size();i++){
                int cost = dist + v[cur][i].second;
                if(far[v[cur][i].first] > cost){
                    far[v[cur][i].first] = cost;
                    pq.push(make_pair(cost, v[cur][i].first));
                }
            }
            // cout<<"hi";
        }

        int ans=0, big = 0;
        for(int i = 1; i<=n; i++){
            
            // if(far[i] == INF)continue;
            // if(far[i]== 0)continue;
            // cout<<far[i]<<endl;
            if(far[i]!=INF){
                ans++;
                if(big <far[i]){
                    big = far[i];
                }
            }
        }
        cout<< ans <<" "<<big<<endl;
        for(int i = 1; i<=n;i++){
            v[i].clear();
        }
        fill(far,far+n+1,INF);
    }


    return 0;
}
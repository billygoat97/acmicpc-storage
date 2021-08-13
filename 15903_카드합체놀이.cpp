#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

int main(){
    using ll = long long;
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(int i = 0;i<n; i++){
        ll inp;
        cin >> inp;
        pq.push(inp);
    }
    for(int i = 0; i<m; i++){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    ll sum = 0;
    while(pq.size()!= 0){
        sum += pq.top();
        pq.pop();
    }
    cout<<sum;


    return 0;
}
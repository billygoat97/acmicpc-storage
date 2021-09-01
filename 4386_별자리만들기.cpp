#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main(){

    using T = pair<double,double>;
    vector<T> arr[100];
    T inp[100];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        double a, b;
        cin >> a >> b;
        inp[i] = {a,b};
    }
    for(int i = 0; i<n; i++){
        int x1 = inp[i].first, y1 = inp[i].second;
        for(int j = 0; j<n; j++){
            int x2 = inp[j].first, y2 = inp[j].second;
            arr[i].push_back({sqrt(pow(abs(x2-x1),2) + pow(abs(y2-y1),2)),j});
        }
    }
    priority_queue<T, vector<T>, greater<>>pq;
    pq.push({0,0});
    int cnt = 0;
    bool visited[100]={false,};
    double sum = 0;
    while(pq.size()!= 0){
        double dist = pq.top().first;
        double where = pq.top().second;
        int dest = (int)where;
        pq.pop();
        if(visited[dest]==true)continue;
        cnt++;
        sum+= dist;
        visited[dest] = true;
        if(cnt == n)break;
        for(int i = 0; i<arr[dest].size();i++){
            if(visited[(int)arr[dest][i].second]==false){
                pq.push({arr[dest][i].first,arr[dest][i].second});
            }
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<sum<<"\n";


    return 0;
}
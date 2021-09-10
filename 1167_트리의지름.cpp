#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using T = pair<int,int>;
vector<T> v[100001];
bool visited[100001] = {false,};
int n;
int ans = 0;
int Longest = 0;
void dfs(int start, int subtot){
    if(subtot > ans){
        ans = max(ans,subtot);
        Longest = start;
    }
    for(int i = 0; i<v[start].size();i++){
        int dest = v[start][i].first;
        int dist = v[start][i].second;
        if(visited[dest] == true)continue;
        visited[dest] = true;
        dfs(dest,subtot + dist);
        visited[dest] = false;
    }
}

int main(){

	cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i<n ;i++){
        
        int start,to,len;
        cin >> start;
        while(true){
            cin >> to;
            if(to == -1)break;
            cin >> len;
            v[start].push_back({to,len});
        }
    }
    visited[1] = true;
    dfs(1,0);
    visited[1] = false;
    int imsi = ans;
    ans = 0;
    int next = Longest;
    Longest = 0;
    visited[next] = 1;
    dfs(next,0);
    visited[next] = 0;

    cout<<max(ans, imsi)<<"\n";
    

    return 0;
}
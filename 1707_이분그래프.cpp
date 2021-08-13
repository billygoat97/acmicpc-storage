#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;

vector<int> arr;
int v, e;
vector<vector<int> > node;
vector<bool> visited;
void dfs(int i, int color){
    visited[i] = true;
    arr[i] = color;
    color = color %2 + 1;
    for(int j = 0; j<node[i].size();j++){
        if(visited[node[i][j]]==false){
            dfs(node[i][j], color);
        }
    }
}


int main(){

    int tc;
    cin >> tc;
    while(tc--){
        cin >> v >> e;
        node.resize(v+1);
        arr.resize(v+1);
        visited.resize(v+1);
        for(int i = 0; i<e; i++){
            int a, b;
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        string ans = "YES";
        for(int i = 1; i<=v; i++){
            if(arr[i] ==0){
                dfs(i,1);
            }
        }
        for(int i = 1; i<=v; i++){
            for(int j = 0; j<node[i].size();j++){
                // cout<<i<<","<<node[i][j]<<":"<<arr[i]<<","<<arr[node[i][j]]<<endl;
                if(arr[node[i][j]] == arr[i]){
                    ans = "NO";
                    i = v+1;
                    break;
                }
            }
        }
        
        
        for(int i = 1; i<=v;i++){
            node[i].clear();
        }
        
        
        visited.clear();
        arr.clear();
        cout<<ans<<"\n";
    }

    return 0;
}
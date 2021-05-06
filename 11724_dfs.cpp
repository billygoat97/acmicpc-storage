#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


int n,k;
int cnt =0;
vector<int >ans;
map<int,int> m;
bool visited[1001]={false,};
vector<int >v[1001];

void dfs(int num){

    visited[num] = true;
    for(int i = 0; i<v[num].size();i++){
        if(visited[v[num][i]]==false){
            dfs(v[num][i]);
        }
    }

}

int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n>>k;
    for(int i = 0; i<k; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i<=n;i++){
        if(visited[i]==false){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;

    
    return 0;
}

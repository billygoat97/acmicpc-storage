#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n;

class Node{
    public:
        int parent = 0;
        int level = 0;
        bool child = false;
};
Node ND[500001];
vector<int>v[500001];

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n-1;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    ND[1].parent = 1;

    q.push(1);
    while(q.size()!=0){
        int par = q.front();
        q.pop();
        for(int i = 0; i<v[par].size();i++){
            int cur = v[par][i];

            if(ND[cur].parent !=0)continue;

            ND[par].child = true;
            ND[cur].parent = par;
            ND[cur].level = ND[par].level + 1;
            q.push(cur);
        }
    }

    int sum = 0;
    for(int i = 1; i<= n; i++){
        if(ND[i].child == false){
            sum += ND[i].level;
            sum %= 2;
        }
    }
    if(sum == 1){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
    return 0;
}
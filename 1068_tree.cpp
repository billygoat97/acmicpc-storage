#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int main(){

    vector<int> v[51];
    int n,head;
    cin >> n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        if(inp ==-1){
            head = i;
        }
        v[inp].push_back(i);
    }
    int node;
    cin >> node;
    if(node == head){
        cout<< 0 <<endl;
        return 0;
    }
    v[node].clear();
    int cnt=0;
    queue<int>q;
    q.push(head);
    while(q.size()!= 0){
        int cur = q.front();
        q.pop();
        if(cur == node)continue;
        if(v[cur].size() == 0){
            cnt++;
        }else{
            if(v[cur].size() == 1 && v[cur][0] == node){
                cnt++;
                continue;
            }
            for(int i = 0; i<v[cur].size();i++){
                q.push(v[cur][i]);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
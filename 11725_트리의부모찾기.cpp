#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<int> v[100001];
int arr[100001];

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    for(int i = 1; i<n; i++){
        int a,b;
        cin >> a >>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    arr[1] = 1;
    
    queue<int> q;
    for(int i = 0; i<v[1].size(); i++){
        arr[v[1][i]] = 1;
        q.push(v[1][i]);
    }
    while(q.size()!=0){
        int parent = q.front();
        q.pop();
        for(int i = 0; i<v[parent].size();i++){
            if(arr[v[parent][i]]!= 0)continue;
            arr[v[parent][i]] = parent;
            q.push(v[parent][i]);
        }
    }
    

    for(int i = 2; i<=n; i++){
        cout<<arr[i]<<"\n";
    }

    return 0;
}
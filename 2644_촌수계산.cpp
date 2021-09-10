#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int p[101] = {0,};
int n, start, dest, m;
int child, parent;

int main(){

    cin >> n >> start >> dest;
    cin >> m;
    for(int i = 0; i<m; i++){
        cin >> parent >> child;
        p[child] = parent;
    }    
    vector<int> v1,v2;
    int cur = start;
    while(true){
        v1.push_back(cur);
        if(p[cur]==0)break;
        cur = p[cur];
    }
    cur = dest;
    while(true){
        v2.push_back(cur);
        if(p[cur]==0)break;
        cur = p[cur];
    }
    if(v1[v1.size()-1] != v2[v2.size()-1]){
        cout<<-1<<"\n";
        return 0;
    }else{
        for(int i = 0; i<v1.size();i++){
            for(int j = 0; j<v2.size();j++){
                if(v1[i] == v2[j]){
                    cout<< i + j << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}
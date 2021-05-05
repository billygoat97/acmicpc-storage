#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){

    vector<string> v[60];
    int n;
    cin >>n;
    for(int i= 0; i<n;i++){
        string inp;
        cin >> inp;
        int len = inp.size();
        v[len].push_back(inp);
    }
    for(int i = 0; i<51;i++){
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    }

    for(int i = 0; i<51; i++){
        for(int j = 0; j<v[i].size();j++){
            cout<<v[i][j]<<endl;
        }
    }
    


    return 0;
}

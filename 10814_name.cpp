#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>

using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    stack<int>s;
    int n;
    cin >>n;
    vector<string> v[201];
    for(int i = 0; i<n; i++){
        int y;
        string name;
        cin >> y >> name;
        v[y].push_back(name);
    }
    // for(int i = 0; i<201;i++)
    // sort(v.begin(),v.end());
    for(int i = 0; i<201;i++){
        for(int j =0; j<v[i].size();j++){
            cout<<i <<' '<<v[i][j]<<'\n';
        }
    }


    return 0;
}

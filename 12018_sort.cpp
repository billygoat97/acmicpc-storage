#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <sstream>
using namespace std;


int n,m,x,y,inp;
string str;
vector<int> v,v1,v2;
map<int,int> ma;

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        for(int j = 0; j< x; j++){
            cin >> inp;
            v1.push_back(inp);
        }
        sort(v1.begin(),v1.end());
        if(y > x){
            v.push_back(1);
        }else{
            v.push_back(v1[x -y]);
        }
        v1.clear();
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i<n; i++){
        // cout<<v[i]<<endl;
        sum+=v[i];
        if(sum<=m)cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}

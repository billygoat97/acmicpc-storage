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


int n,m,x,y;
int cnt = 0;
int sum = 0;
char c;
vector<int> v;

string str;
int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(),v.end());
    cout<< v[0]*v[v.size()-1]<<'\n';
    



    return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int>v[2];
int n;
int idx[100001] = {0,};


void func(int l1, int r1, int l2, int r2){
    if(r1 < l1 || r2 < l2)return;
    int root = v[1][r2];
    cout<<root<<" ";
    func(l1, idx[root]-1, l2, l2 + (idx[root]-l1)-1 );
    func(idx[root]+1, r1, l2 + (idx[root]-l1), r2-1);


}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int inp;
    for(int i = 0; i<n; i++){
        cin >> inp;
        v[0].push_back(inp);
    }
    for(int i = 0; i<n; i++){
        cin >> inp;
        v[1].push_back(inp);
    }
    for(int i = 0; i<n; i++){
        idx[v[0][i]] = i;
    }
    func(0,n-1,0,n-1);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int n, c;
    cin >> n  >> c;
    int cur = 0;
    int inp;
    v.push_back(0);
    for(int i = 0; i< n; i++){
        cin >> inp;
        cur += inp;
        v.push_back(cur);
    }
    int a,b;
    for(int i = 0; i<c; i++){
        cin >> a >> b;
        cout<< v[b] - v[a-1] << "\n";
    }

    return 0;
}
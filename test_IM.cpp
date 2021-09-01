#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    int n;
    cin >> n;
    using T = pair<int,int>;
    vector<T> v;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    for(int i = 0; i<n; i++){
        cout<<v[i].second<<" "<<v[i].first<<"\n";
    }

    
    return 0;


}
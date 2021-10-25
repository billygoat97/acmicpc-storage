#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>v;
    int inp;
    for(int i = 0; i<n; i++){
        cin >> inp;
        int idx = (lower_bound(v.begin(),v.end(),inp) - v.begin());
        if(idx+1 > v.size()){
            v.push_back(inp);
        }else{
            v[idx] = inp;
        }
    }
    // for(int i = 0; i<v.size(); i++){
    //     cout<<v[i] <<" ";
    // }
    cout<<v.size();


    return 0;
}
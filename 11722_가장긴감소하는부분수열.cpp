#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v1,v2;
    int inp;
    for(int i = 0; i<n; i++){
        
        cin >> inp;
        v1.push_back(inp);
    }

    for(int i = n-1; i>= 0; i--){
        inp = v1[i];
        int idx = (lower_bound(v2.begin(),v2.end(),inp) - v2.begin());
        if(idx+1 > v2.size()){
            v2.push_back(inp);
        }else{
            v2[idx] = inp;
        }
    }
    cout<<v2.size();


    return 0;
}
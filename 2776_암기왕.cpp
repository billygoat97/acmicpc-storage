#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
int getNum(int t){
    int l  = 0, r = v.size()-1;
    while(l <= r){
        int mid = (l + r )/ 2;
        if(v[mid]> t){
            r = mid -1;
        }else if(v[mid] < t){
            l = mid +1;
        }else{
            return 1;
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        v.clear();
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            int inp;
            cin >> inp;
            v.push_back(inp);
        }
        sort(v.begin(),v.end());
        cin >>n;
        for(int i = 0; i<n; i++){
            int inp;
            cin >> inp;
            cout<<getNum(inp)<<"\n";
        }
        
    }

    return 0;
}
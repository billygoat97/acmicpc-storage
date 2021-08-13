#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int main(){

    string inp;
    cin >> inp;
    string str ="";
    int ans = 0;
    for(int a =inp.size()-1; a>=0;a--){
        str = inp[a] + str;
        vector<int>pi(str.size());
        for(int i = 1,j = 0;i<str.size();i++){
            while(j>0 && str[i] != str[j]){
                j = pi[j-1];
            }
            if(str[i] == str[j]){
                j++;
                pi[i] = j;
            }
        }
        sort(pi.begin(),pi.end(),greater<>());
        ans = max(ans,pi[0]);
    }
    cout<<ans<<endl;


    return 0;
}
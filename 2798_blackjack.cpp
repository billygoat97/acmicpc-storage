#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    vector<int>v;
    int n,sum;
    cin >>n>>sum;
    for(int i = 0; i<n; i++){
        int a;
        cin >>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int result =0;

    for(int i = 0; i<v.size()-2;i++){
        for(int j = i+1; j<v.size()-1;j++){
            for(int k = j+1; k<v.size();k++){
                if(i ==j || j==k || k == i ){

                }else{
                    if(v[i] + v[j] + v[k] <=sum && v[i] + v[j] + v[k] > result){
                        result = v[i] + v[j] + v[k];
                    }
                }
            }
        }
    }
    
    cout<<result<<"\n";


    return 0;
}

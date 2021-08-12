#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){

    vector<int> v;
    int n, score, p;
    cin >> n >> score >> p;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }

    if(n == 0){
        if(p == 0){
        cout<<-1<<endl;
        }else{
            cout<<1<<endl;
        }
        return 0;
    }


    int cnt = 1;
    sort(v.begin(),v.end(), greater<>());
    if(p==n &&v[n-1] >= score){
            cout<<-1<<endl;
            return 0;
    }else{
        for(int i = 0; i<=n; i++){
            if(v[i] > score){
                cnt++;
            }else{
                break;
            }
        }
    }
    cout<<cnt<<endl;
    

    return 0;
}
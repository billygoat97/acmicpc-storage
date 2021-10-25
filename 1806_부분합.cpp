#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main(){

    int n,m;
    cin >> n >> m;
    n++;
    ll arr[n]={0,};

    arr[0] = 0;
    for(int i = 1; i<n; i++){
        ll inp;
        cin >> inp;
        arr[i] = arr[i-1] + inp;
    }
    int s = 0, e = 1;
    int len = 987654321;
    while(e != n){
        ll diff = arr[e]-arr[s];
        if(diff >= m){
            len = min(len,e-s);
            s++;
        }else{
            e++;
        }
    }
    if(len == 987654321)len = 0;
    cout<<len<<endl;


    return 0;
}
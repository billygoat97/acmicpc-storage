#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int arr[1000001];
vector<int> v;


int main(){
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n<8){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 2; i<=n; i++){
        arr[i] = i;
    }
    for(int i = 2;i<=n;i++){
        if(arr[i]==0)continue;
        if(i*i > n)break;
        for(int j = (i*i); j<=n; j+=i){
            arr[j] = 0;
        }
    }
    for(int i = 2; i<=n; i++){
        if(arr[i] == i)v.push_back(i);
    }
    if(n%2==0){
        cout<< "2 2 ";
        n-=4;
    }else{
        cout<< "2 3 ";
        n-=5;
    }
    for(int i=0; i<v.size();i++){
        for(int j = 0; j<v.size();j++){
            if(v[i] + v[j]>n)break;
            if(v[i] + v[j]==n){
                cout<<min(v[i],v[j])<<" "<<max(v[i],v[j])<<endl;
                return 0;
            }
        }
    }

    return 0;
}
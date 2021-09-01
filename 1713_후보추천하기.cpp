#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>

using namespace std;



int main(){

    int num;
    int n;
    cin >> num;
    cin >> n;
    int vote;

    using T = pair<int,int>;
    int arr[101] = {0,};
    vector<int> v;
    for(int i = 0; i<n; i++){
        cin >> vote;
        arr[vote]++;
        if(arr[vote]!=1){
            continue;
        }
        if(v.size()<num){
            v.push_back(vote);
        }else{
            int check = 987654321;
            int target = 0;
            for(int j = 0; j<v.size(); j++){
                if(check> arr[v[j]]){
                    target = j;
                    check = arr[v[j]];
                }
            }
            arr[v[target]] = 0;
            v.erase(v.begin()+target);
            v.push_back(vote);
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i<v.size();i++){
        cout<< v[i]<<" ";
    }
    cout<<"\n";


    return 0;
}
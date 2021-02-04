#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(){
    long long mini,maxi;
    cin >> mini>>maxi;
    int leng = maxi - mini +1;
    long long m;
    if(1000000 < maxi){
        m = 1000000;
    }else{
        m = maxi;
    }
    long long arr[m+1];
    for(int i = 2; i<= m; i++){
        arr[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(arr[i]==0) continue; 
        for(int j=2*i;j<=m; j+=i) {
            arr[j] = 0;
        }
    }
    vector<long long> v;
    for(long long i = 2; i<= m; i++){
        if(arr[i] == i){
            v.push_back(i*i);
        }
    }
    vector<int>test(leng,1);

    for(int i =0; i<v.size();i++){
        long long s = mini/v[i]; // 여기가 아이디어가 좋은게, 이미 v[i]의 배수를 그냥 이것저것 넣어보는게 아니라 그냥 넣는것(/ 하는거니까)
        if(mini % v[i] != 0){ // 
            s++;
        }
        while(s*v[i] <= maxi){
            test[s*v[i]-mini] = 0;
            s++;
        }
        
    }
    int cnt = 0; 
    for(int i = 0 ; i<=leng; i++){
        if(test[i] == 1){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
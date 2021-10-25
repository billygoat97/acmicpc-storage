#include <iostream>
#include <vector>
using namespace std;

int main(void){

    int count = 0;
    int m = 4000000;
    int* array = new int[m+1];
    
    for(int i = 0; i<=m;i++){
        array[i] = i;
    }
    for(int i=2;i<=m;i++) {
        if(array[i]==0) continue; 
        for(int j=i;j<=m; j+=i) {
            if(j!=i){
                array[j] = 0;
            }
        }
    }
    array[1] = 0;
    int c= 2;
    vector<long long>prime;
    prime.push_back(0);
    while(c<=m){
        if(array[c]==c){
            prime.push_back(prime[prime.size()-1] + c);
        }
        c++;
    }
    int n;
    cin >> n;
    int imsi = 0;
    
    int s = 0, e = 1;
    while(true){
        if(prime[e] - prime[s] == n){
            imsi ++;
            s ++;
        }else if(prime[e] - prime[s] > n){
            s++;
        }else if(prime[e] - prime[s] < n){
            e ++;
        }
        if(e == prime.size()|| prime[e] - prime[e-1] > n)break;
    }
    cout<<imsi<<"\n";
    return 0;
}
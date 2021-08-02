#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;

int n,k;
int check(){
    int cnt = 0;
    int imsi = n;
    while(imsi != 0){
        if(imsi%2 == 1)cnt++;
        imsi/=2;
    }
    return cnt;
}


int main(){
    int ans = 0;
    cin >> n>> k;
  
    //cout<<check()<<endl;
    while(true){
        int imsi = check();
        if(imsi<=k)break;
        ans++;
        n++;
    }
    
    cout<<ans<<endl;
    return 0;
}
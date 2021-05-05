#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){

    int n,m;
    cin>>n >>m;
    if(m>= 45){
        m-=45;
    }else{
        if(n== 0){
            n= 24;
        }
        n--;
        m += 15;
    }
    cout<<n <<' '<<m<<endl;




    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

long long n,p,q;

map<long long,long long> arr;
long long recursive(long long a){
    if(a == 0) return 1;
    long long imsi = a/p;
    long long ans1 = arr[imsi];
    if(arr[imsi] ==0){
        ans1 = recursive(imsi);
        arr[imsi] = ans1;
    }
    imsi = a/q;
    long long ans2 = arr[imsi];

    if(arr[imsi] ==0){
        ans2 = recursive(imsi);
        arr[imsi] = ans2;
    }
    return ans1 + ans2;

}

int main(){

    cin >> n >> p >> q;

    cout<< recursive(n)<<endl;

    return 0;

}

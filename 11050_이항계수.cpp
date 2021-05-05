#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
using namespace std;

float func(float i){
    if(i == 0)return 1;

    return i*func(i-1);
}

int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    float n,k;
    cin >>n>>k;

    cout<<func(n)/(func(k)*func(n-k))<<'\n';
    
    return 0;
}

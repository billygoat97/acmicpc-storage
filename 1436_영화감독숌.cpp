#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void check(int x){
    int imsi = x;
    int cnt = 0;
    while(imsi!= 0){
        if(imsi%10 == 6){
            cnt++;
        }else{
            cnt = 0;
        }
        imsi/=10;
        if(cnt == 3){
            v.push_back(x);
            return;
        }
    }
}



int main(){

    int i = 666;
    while(v.size()<=10000){
        check(i);
        i++;
    }
    int n;
    cin >> n;
    cout<<v[n-1];

    return 0;
}
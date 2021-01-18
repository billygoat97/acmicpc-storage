#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int gcd ,lcm;
vector<int> v; 

int euclidean(int a, int b){
    int r= a%b;
    if( r== 0){
        return b;
    }else{
        return euclidean(b,r);
    }
}

int main(){
    
    cin >> gcd  >> lcm;

    int ab = lcm/gcd;

    for(int i = 1; i*i<=ab;i++){
        int abb = ab %i;
        if(abb == 0 && euclidean(i, ab/i)==1 ){
            v.push_back(i);
        }
    }
    int dap1 = ab/v[v.size()-1], dap2 = v[v.size()-1];
    if(dap2 < dap1){
        int temp = dap2;
        dap2 = dap1;
        dap1 = temp;
    }
    cout<< dap1*gcd << " " << dap2*gcd<<endl;



    return 0;
}
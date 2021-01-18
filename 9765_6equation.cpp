#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long euc(long long a,long long b ){
    long long temp = a%b;

    if(temp == 0){
        return b;
    }else{
        return euc(b, temp);
    }
}


int main(){

    long long c1,c2,c3,c4,c5,c6, x1,x2,x3,x5,x6,x7;

    cin >> c1>>c2>>c3>>c4>>c5>>c6;


    x2 = euc(c1,c5);
    x1 = c1/x2;
    x3 = c5/x2;
    x6 = euc(c3,c6);
    x7 = c3/x6;
    x5 = c6/x6;

    cout<<x1<<' '<<x2<<' '<<x3<<' '<<x5<<' '<<x6<<' '<<x7<<endl;

    return 0;

}
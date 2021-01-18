#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int euclid(int a, int b, int who){
    if( a < b){
        int imsi = a;
        a = b;
        b = imsi;
    }
    int temp = a %b;
    if(temp == 0){
        return who;
    }else{
        if(a/b >= 2){
            return who;
        }else{
            return euclid(b, temp, who+1);
        }
        
    }
}



int main(){

    int n=-1, m=-1;
    while(1){
        cin >> n>>m;
        if( n== 0 && m == 0) return 0;
        int who = 0;
        who = euclid(n,m,0);
        if( who % 2 == 0){
            cout <<"A wins"<<endl;
        }else{
            cout<<"B wins"<<endl;
        }
    }
    


    
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


int n,m,x,y;
int cnt = 0;
int sum = 0;

void func(int x,int y, int nx, int ny,int mx, int my){

    int midx = (nx+mx)/2;
    int midy = (ny+my)/2;

    if(x==nx && y == ny){
        //sum++; 
        return;
    }
    int quad = (mx-nx)*(my-ny)/4;
    if(midx > x && midy > y){
        sum += 0;
        func(x,y,nx,ny,midx,midy);
    }else if(midx <= x && midy > y){
        sum += 2*quad;
        func(x,y,midx,ny,mx,midy);
    }else if(midx > x && midy <= y){
        sum += quad;
        func(x,y,nx,midy,midx,my);
    }else if(midx <= x && midy <= y){
        sum += 3*quad;
        func(x,y,midx,midy,mx,my);
    }

}

int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n>>x>>y;
    
    func(x,y,0,0,pow(2,n),pow(2,n));

    cout<< sum <<'\n';
    
    


    return 0;
}

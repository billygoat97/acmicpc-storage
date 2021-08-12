#include <iostream>
#include <cmath>

using namespace std;

int n;
int A[] = {2,3,5,7};
int B[] = {1,3,5,7,9};

bool check(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i==0)return false;
    }
    return true;
}

void recursive(int inp, int cnt){
    if(cnt == n){
        cout<< inp<<endl;
    }else{
        for(int i = 0; i<5;i++){
            int temp = inp*10;
            temp = temp+B[i];
            if(check(temp)){
                recursive(temp,cnt+1);
            }
        }
    }
}

int main(){


    cin>>n;
    for(int i = 0; i<4; i++){
        recursive(A[i],1);
    }


    return 0;
}
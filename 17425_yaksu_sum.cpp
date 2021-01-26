#include <iostream>
#include <cmath>

int main(){
    long long array[1000001]={0,};
    
    for(int i = 1; i<=1000000;i++){
        for(int j = i; j<=1000000;j+=i){
            array[j]+=i;
        }
        array[i]+= array[i-1];
    }
    
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        int inp;
        scanf("%d", &inp);
        printf("%lld\n",array[inp]);
    }



    return 0;
}
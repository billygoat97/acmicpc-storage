#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int visited[1000001]={0,};
int func(int x){
    int sum = x;
    while(x!= 0){
        sum += x%10;
        x/=10;
    }
    return sum;
}

int main(){

    
    for(int i = 1; func(i)<1000000;i++){
        if(visited[func(i)]== 0)
        visited[func(i)] = i;
    }
    int n;
    cin >> n;
    cout<<visited[n]<<endl;

    return 0;
}
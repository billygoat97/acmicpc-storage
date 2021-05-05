#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(){

    int n,L;
    cin >> n >> L;
    for(int i = L; i<=100;i++){
        if((n-(i*i + i)/2)%i == 0){
            if((n-(i*i + i)/2)/i + 1<0)continue;
            for(int j = 1; j<=i; j++){
                cout<<(n-(i*i + i)/2)/i + j << ' ';
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}

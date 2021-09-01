#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int comp[8];
bool visited[8] = {false,};
void func(int k){
    if(k == m){
        for(int i = 0; i<m; i++){
            cout<<comp[i]<<" ";
        }
        cout<<"\n";
        return;
    }else{
        for(int i = 1; i<=n; i++){
            if(visited[i] == false){
                visited[i] = true;
                comp[k] = i;
                func(k+1);
                visited[i] = false;
            }
            
        }
    }
}


int main(){

    cin >> n >>m;
    func(0);
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int arr[9][9];
int hubo[9][9];
using T = pair<int,int>;
vector<T> v;

bool check(int x, int y){ // 가로,세로, 네모
    // 가로
    for(int i = 0; i<9; i++){
        if(i == x)continue;
        if(arr[i][y] == arr[x][y]){
            return false;
        }
    }
    for(int i = 0; i<9; i++){
        if(i == y)continue;
        if(arr[x][i] == arr[x][y]){
            return false;
        }
    }
    int wx[] = {0,3,0,3,0,3,3,6,3,6,3,6,6,9,6,9,6,9};
    int wy[] = {0,3,3,6,6,9,0,3,3,6,6,9,0,3,3,6,6,9};
    for(int a = 0; a<18;a+=2){
        if(wx[a]<=x && x<wx[a+1] && wy[a]<=y && y<wy[a+1] ){
            for(int i = wx[a]; i<wx[a+1]; i++){
                for(int j = wy[a]; j<wy[a+1]; j++){
                    if(i == x && j == y)continue;
                    if(arr[i][j] == arr[x][y]){
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int backtracking(int k){
    if(v.size() == k)return 1;
    int x = v[k].first;
    int y = v[k].second;
    int result = 0;
    for(int i = 1; i<= 9; i++){
        arr[x][y] = i;
        if(check(x,y)){
            result = backtracking(k+1);
            if(result ==1)break;
        }
        arr[x][y] = 0;
    }
    
    return result;

}
int main(){
    // 백트래킹 문제 + bitmasking
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    backtracking(0);
    
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
    



    return 0;
}
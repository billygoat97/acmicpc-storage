#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <sstream>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int n,m,x,y,k,inp;
string str;
vector<int> v,v1,v2;
// bool visited[9] ={false,};
int arr[9] ={0,};
map<int,int> ma;

void func(int num, int cnt){

    if(cnt == m){
        for(int i = 0; i<m; i++){
            cout<< arr[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i = num; i<= n; i++){
            
            arr[cnt] = i;
            func(i, cnt+1);
        }
    }
    

}

int main(){
    int num;
    cin >> n >> m;

    func(1,0);
    

    

    return 0;
}

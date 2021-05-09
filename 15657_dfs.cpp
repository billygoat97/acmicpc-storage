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
int sum = 0;
// bool visited[9] ={false,};
int arr[9] ={0,};
map<int,int> ma;

void func(int num, int cnt){

    if(cnt == m){
        // int flag = 0;
        // for(int i = 0; i<m-1; i++){
        //     for(int j = i+1; j<m; j++){
        //         if(v1[i] == v1[j])flag =1;
        //     }
        // }
        //if(flag == 0){
        for(int i = 0; i<m; i++){
            cout<< v1[i]<<' ';
        }
        cout<<'\n';
        //}
    }else{
        
        for(int i = num; i< n; i++){
                v1[cnt] = v[i];
                func(i, cnt+1);
        }
    }
    

}

int main(){
    int num;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> inp;
        v.push_back(inp);
        v1.push_back(0);
    }
    sort(v.begin(), v.end());
    func(0,0);
    

    

    return 0;
}

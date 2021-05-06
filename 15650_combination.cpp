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
char c;
vector<int> v;

	


int arr[1002][1002] ={0,};

int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >> n>>m;

    for(int i= 0; i<n; i++){
        v.push_back(i+1);
    }
    vector<int> ans[8];
    do{
        int flag = 0;
	    for(int i = 1; i < m; i++){
            if(v[i] <v[i-1])flag =1;
        }
        if(flag == 0){
            for(int i = 0; i < m; i++){
                cout<<v[i]<<' ';
            }
            cout<<'\n';
        }else if(m == 1){
            cout<<v[0]<<'\n';
        }

			

        reverse(v.begin() + m, v.end()); 

	}while(next_permutation(v.begin(), v.end()));   



    return 0;
}

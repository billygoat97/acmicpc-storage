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
    string str1, str2;
    cin >> str1;
    cin >> str2;
    str1 = "0" + str1;
    str2 = "0" + str2;

    for(int i = 1 ; i<str2.size();i++){
        arr[i][0] =0;
        for(int j = 1; j<str1.size();j++){
            if(str2[i] == str1[j]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
        if(arr[i][str1.size()-1] > sum)sum = arr[i][str1.size()-1];
    }
    cout<<sum<<'\n';



    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


int n, k;
vector<string> arr;
bool visited[26];
int imsi = 0;
int ans = 0;
// a c i n t 는 기본임


void dfs(int cur, int depth){

    if(depth == k){
        imsi = 0;
        for(int i = 0; i<n; i++){
            int flag  = 0;
            for(int j = 0; j<arr[i].size(); j++){
                if(visited[arr[i][j]-'a']==false){
                    // cout<<arr[i][j]<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                //cout<<imsi<<endl;
                imsi++;
            }
        }
        ans = max(imsi,ans);
    }else{
        for(int i = cur; i<26; i++){
            if(visited[i]== false){
                visited[i]= true;
                dfs(i,depth+1);
                visited[i] = false;
            }
        }
    }


}

int main(){

    cin >> n >> k;
    for(int i = 0 ; i<n; i++){
        string str;
        cin >> str;
        arr.push_back(str);
    }
    if(k<5){
        cout<<0<<endl;
        return 0;
    }
    visited['a'-'a'] = true;
    visited['c'-'a'] = true;
    visited['i'-'a'] = true;
    visited['n'-'a'] = true;
    visited['t'-'a'] = true;
    dfs(0,5);

    cout<< ans<<endl;
    return 0;
}
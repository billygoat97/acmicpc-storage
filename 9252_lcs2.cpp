#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001];
string lcs[1001][1001];
int main(){

    string str1, str2;
    cin >> str1 >> str2;
    str1 = "a" + str1;
    str2 = "b" + str2;
    int sz1 = str1.size();
    int sz2 = str2.size();
    int posx,posy,len = 0;
    for(int i = 1; i<sz1; i++){
        for(int j = 1; j< sz2; j++){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                lcs[i][j] = lcs[i-1][j] + str1[i-1];
            }else{
                dp[i][j]
            }
        }
    }
    cout<<endl;

    return 0;
}
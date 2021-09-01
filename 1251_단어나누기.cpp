#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){

    string str;
    cin >> str;
    vector<char> v1,v2,v3;
    string ans = "";
    for(int i = 0; i<str.size();i++){
        ans += "z";
    }
    for(int i = 1; i<str.size()-2; i++){
        for(int j = i+1; j<str.size();j++){
            string str1 = str.substr(0,i);
            string str2 = str.substr(i,j-i);
            string str3 = str.substr(j);
            reverse(str1.begin(),str1.end());
            reverse(str2.begin(),str2.end());
            reverse(str3.begin(),str3.end());
            string imsi = str1 + str2 + str3;
            ans = min(ans, imsi);
        }
    }
    cout<< ans<<endl;


    return 0;
}
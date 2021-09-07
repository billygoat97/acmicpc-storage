#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){

    string str;
    cin >> str;
    string ans = "";
    string num = "";
    int bsu = 0;
    int cnt = 0;
    for(int i =0; i<str.size();i++){
        if(str[i] == '+' || str[i] == '-'){
            ans += str[i];
        }else if(str[i] == 'x'){
            if(cnt == 0)bsu = stoi(num);
            cnt++;
            if(i+1 == str.size() || str[i+1] != 'x'){
                cnt++;
                bsu /= cnt;
                if(bsu != 1)ans += to_string(bsu);
                for(int j = 0; j<cnt;j++)ans+='x';
                cnt = 0;
                bsu = 0;
                num = "";
            }
        }else{
            num += str[i];
        }
    }
    if(num!= "" && num !="0"){
        if(num != "1")ans += num;
        ans += 'x';
    }
    if(num != "0"){
        ans += '+';
    }
    ans += 'W';

    cout<<ans<<"\n";

    return 0;
}
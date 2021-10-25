#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main(){

    string ans = "";
    string hr = "";
    for(int i = 0; i<80;i++){
        hr += "-";
    }
    hr += "\n";
    int len = 0;
    string str;
    while (cin>>str){
        if(len > 80){
            ans += "\n";
            len = 0;
        }
        if(str == "<br>"){
            ans += "\n";
            len = 0;
        }else if(str == "<hr>"){
            if(len != 0)ans += "\n";
            ans += hr;
            len = 0;
        }else{
            if(str.size() + len > 80){
                ans += "\n";
                len = 0;
            }
            ans += str;
            ans += " ";
            len += str.size() + 1;
        }
        
    }
    cout<<ans<<"\n";

    return 0;
}
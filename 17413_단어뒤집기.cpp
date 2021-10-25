#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int main(){

    stack<char> s;
    string str;
    getline(cin, str);
    string ans = "";
    int flag = 0;
    for(int i =0;i<str.size(); i++){
        if(flag == 0){
            if(str[i] == '<'){
                while(s.size()!= 0){
                    ans += s.top();
                    s.pop();
                }
                flag = 1;
                ans += str[i];
            }else if(str[i] == ' '){
                while(s.size()!= 0){
                    ans += s.top();
                    s.pop();
                }
                ans += str[i];
            }else{
                s.push(str[i]);
            }
        }else if(flag == 1){
            ans += str[i];
            if(str[i] == '>'){
                flag = 0;
            }
        }

    }
    while(s.size()!= 0){
        ans += s.top();
        s.pop();
    }
    cout<<ans<<"\n";


    return 0;
}
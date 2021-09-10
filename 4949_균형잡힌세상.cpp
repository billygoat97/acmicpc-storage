#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int main(){

    string str = "";
    while(true){
        getline(cin,str);
        if(str == ".")break;
        stack<char> s;
        int flag = 0;
        for(int i = 0; i<str.size(); i++){
            if(str[i] == '(' || str[i] == '[')s.push(str[i]);
            if(str[i] == ')' ){
                if(s.size() == 0 || s.top() != '('){
                flag = 1;
                break;
                }else{
                    s.pop();
                }
            }else if(str[i] == ']'){
                if(s.size() == 0 || s.top() != '['){
                    flag = 1;
                    break;
                }else{
                    s.pop();
                }
            }
        }

        if (s.size()!= 0){
            flag = 1;
        }

        if(flag == 1){
            cout<<"no\n";
        }else{
            cout<<"yes\n";
        }
    }



    return 0;
}
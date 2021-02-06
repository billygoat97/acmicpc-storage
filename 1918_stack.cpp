#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;

stack<char> s;


int main(){

    string input;
    cin >>input;
    string answer="";

    for(int i = 0; i<input.length();i++){
        if(input[i]>= 'A' && input[i] <= 'Z'){
            answer += input[i];
        }else if(input[i] == '('){
            s.push(input[i]);
        }else if(input[i] == '*' || input[i] == '/'){
            while(s.size()!= 0 && (s.top() == '*' || s.top() == '/')){
                answer += s.top();
                s.pop();
            }
            s.push(input[i]);
        }else if(input[i] == '+' || input[i] == '-'){
            while(s.size() != 0 && s.top() != '('){
                answer += s.top();
                s.pop();
            }
            s.push(input[i]);
        }else if(input[i] == ')'){
            while(s.top()!= '('){
                answer += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while(s.size()!= 0){
        answer += s.top();
        s.pop();
    }

    cout<<answer<<endl;



}
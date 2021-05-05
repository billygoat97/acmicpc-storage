#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>

using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    int n;
    cin >>n;
    stack<int> s;
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        if( str == "push"){
            int num;
            cin >> num;
            s.push(num);
        }else if(str == "top"){
            if(s.empty()==true){
                cout<<-1<<'\n';
            }else{
                cout<<s.top()<<'\n';
            }
        }else if(str == "pop"){
            if(s.empty()==true){
                cout<<-1<<'\n';
            }else{
                cout<<s.top()<<'\n';
                s.pop();
            }
        }else if(str == "empty"){
            if(s.empty()==true){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(str == "size"){
            
            cout<<s.size()<<'\n';
            
        }
    }
    return 0;
}

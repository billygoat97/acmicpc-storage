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
    stack<int>s;
    int n;
    cin >>n;
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        int flag = 0;
        for(int j = 0; j<str.size();j++){
            if(str[j] == '('){
                s.push(1);
            }else{
                if(s.empty() == true){
                    cout<<"NO"<<'\n';
                    flag = 1;
                    break;
                }else{
                    s.pop();
                }
            }
            
        }
        // cout<<i+1 <<':';
        // for(int k = 0; k<s.size();k++){
        //     cout<<s.top();
        //     s.pop();
        // }
        // cout<<endl;
        if(s.empty() == false){
            flag =1;
            cout<<"NO"<<"\n";
        }
        if(flag ==0){
            cout <<"YES"<<'\n';
        }
        while(s.empty()== false){
            s.pop();
        }
    }


    return 0;
}

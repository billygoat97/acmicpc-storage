#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    int n;
    cin >>n;
    deque<int> d;
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        if( str == "push_front"){
            int a;
            cin >> a;
            d.push_front(a);
        }else if(str == "push_back"){
            int a;
            cin >> a;
            d.push_back(a);
        }else if(str == "pop_front"){
            if(d.size()==0){
                cout<<-1<<'\n';
            }else{
                cout<<d.front()<<"\n";
                d.pop_front();
            }

        }else if(str == "pop_back"){
            if(d.size()==0){
                cout<<-1<<'\n';
            }else{
                cout<<d.back()<<"\n";
                d.pop_back();
            }
        }else if(str == "size"){
            cout<<d.size()<<"\n";
                
        }else if(str == "empty"){
            cout<<d.empty()<<"\n";
        }else if(str == "front"){
            if(d.size()==0){
                cout<<-1<<'\n';
            }else{
                cout<<d.front()<<"\n";
            }
        }else if(str == "back"){
            if(d.size()==0){
                cout<<-1<<'\n';
            }else{
                cout<<d.back()<<"\n";
            }
        }
    }
    return 0;
}

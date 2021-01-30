#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int main(){

    queue<int> q;
    int n; //number of input
    cin >> n;
    for(int i = 0; i<n; i++){
        string inp;
        int imsi;
        cin >> inp;
        if(inp == "push"){
            cin >>imsi;
            q.push(imsi);
        }else if(inp == "pop"){
            if(q.size()==0){
                cout<<-1<<endl;
            }else{
                cout<<q.front()<<endl;
                q.pop();
            }
        }else if(inp == "size"){
            cout<<q.size()<<endl;
        }else if(inp == "empty"){
            cout<<q.empty()<<endl;
        }else if(inp == "front"){
            if(q.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<q.front()<<endl;
            }
        }else if(inp == "back"){
            if(q.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<q.back()<<endl;
            }
        }

    }


    return 0;
}
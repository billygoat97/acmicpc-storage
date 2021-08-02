#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <list>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    string inst;
    string inp;
    cin >> n;
    for(int i = 0; i<n; i++){
        deque<int> v;
        int len;
        cin >> inst>>len>> inp;
        string imsi = "";
        for(int j = 1; j<inp.size();j++){
            if(inp[j] != ',' && inp[j] != ']'){
                imsi += inp[j];
            }else{
                if(imsi != ""){
                    v.push_back(stoi(imsi));
                    imsi = "";
                }
            }
            // cout<<imsi<<endl;
        }
        int flag = 0;
        
        bool reverse = false;
        for(int j = 0; j<inst.size();j++){
            if(inst[j] == 'D'){
                if(v.size() == 0){
                    cout<<"error"<<"\n";
                    flag = 1;
                    break;
                }
                if(reverse){
                    v.pop_back();
                }else{
                    v.pop_front();
                }
                
            }else if(inst[j] == 'R'){
                reverse = !reverse;
            }
        }
        if(flag == 0){
            cout<<"[";
            
            while(v.size()!=0){
                if(!reverse){
                    cout<<v.front();
                    v.pop_front();
                }else{
                    cout<<v.back();
                    v.pop_back();
                }
                if(v.size()!= 0){
                    cout<<",";
                }
            }
            cout<<"]"<<"\n";
        }


        v.clear();
        
    }
    
}

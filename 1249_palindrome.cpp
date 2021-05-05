#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){

    
    string str;
    while(1){
        vector<int> v;
        cin>> str;
        if(strcmp(str.c_str(),"0")==0)break;
        for(int i = 0;i<str.size();i++){
            v.push_back(str[i]-48);
        }
        int flag = 0;
        for(int i = 0;i<v.size()/2;i++){
            if(v[i]!= v[v.size()-1-i]){
                flag =1;
                cout<<"no"<<endl;
                break;
            }
        }
        if(flag ==0){
            cout<<"yes"<<endl;
        }
    
    }
    
    


    return 0;
}

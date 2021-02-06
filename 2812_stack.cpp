#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    
    string s;
    string imsi;
    cin >> imsi;
    for(int i = 0; i<n; i++){
        int inp = imsi[i];
        int slen = s.length();
        // cout<<"slen: "<<slen<<endl;
        // cout<<"i:" <<i <<" k: "<<k<<endl;
        if(k!=0){
            if(slen==0){
                s += inp;
            }else{
                while(s.length()>0 && k>0){
                    slen = s.length();
                    if(int(s[slen-1]) < inp){
                        s.pop_back();
                        // cout<<"pop!"<<endl;
                        k--;
                    }else{
                        break;
                    }
                }
                s += inp;
                
            }
        }else{
            s += inp;
        }
        
    }
    for(int i = 0; i<k; i++){
        s.pop_back();
    }
    cout<<s;


    cout<<"\n";
    return 0;
}
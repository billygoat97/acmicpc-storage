#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string input, bomb, ans;
    string s;
    cin >> input;
    cin >> bomb;

    int inp_len = input.length();
    int bomb_len = bomb.length();

    for(int i = 0; i<inp_len; i++){

        s += input[i];
        int slen = s.length();
        if(slen<bomb_len || s[slen-1] != bomb[bomb_len-1]){

        }else{
            int flag = 0;
            while(flag == 0){
                flag = 0;
                int imsi = s.size();
                for(int j = 0; j< bomb_len;j++){
                    if(s[imsi-j-1] != bomb[bomb_len - j-1]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){ // not a bomb
                    break;
                }else{
                    for(int j = 0; j< bomb_len; j++){
                        s.pop_back();
                    }
                    // s = s.substr(0,imsi - bomb_len);
                }
            }
        }
    }

    if(s.length() > 0){
        cout<<s;
    }else{
        cout<<"FRULA";
    }
    cout<<"\n";








    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main(){

    int n;
    cin>> n;
    string str;
    cin >> str;
    string imsi = "";
    bool flag = false;
    int cnt = 0;
    int cur = 0;
    stack<char> s;
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            imsi += str[i];
        }else{
            int num;
            if(imsi != "")num = stoi(imsi);
            imsi = "";
            if(cnt == 0)cur = num;
            cnt++;
            if(s.size()!= 0){
                char eq = s.top();
                s.pop();
                if(eq == 'S'){
                    cur -= num;
                }else if(eq == 'M'){
                    cur *= num;
                }else if(eq == 'U'){
                    cur /= num;
                }else if(eq == 'P'){
                    cur += num;
                }
            }
            if(str[i] == 'C'){
                flag = true;
                cout<< cur<<" ";
            }else{
                s.push(str[i]);
            }
        }
    }
    if(flag == false){
        cout<<"NO OUTPUT\n";
        return 0;
    }
    cout<<"\n";



    return 0;
}
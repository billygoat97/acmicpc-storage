#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int c = 1; c<= n; c++){
        cout<<"URL #" << c<<"\n";
        string output[4];
        output[0] = ""; // protocol
        output[1] = ""; // host
        output[2] = ""; // port
        output[3] = ""; // path
        string str;
        cin >> str;
        int cnt = 0;
        for(int i = 0; i<str.size();i++){
            if(cnt == 0){
                if(str[i] == ':'){
                    cnt++;
                    i+=2;
                    continue;
                }
            }else if(cnt == 1){
                if(str[i] == ':'){
                    cnt++;
                    continue;
                }else if(str[i] == '/'){
                    cnt+=2;
                    continue;
                }
            }else if(cnt == 2){
                if(str[i] == '/'){
                    cnt++;
                    continue;
                }
            }
            output[cnt] += str[i];
        }

        for(int i = 0; i<4;i++){
            if(output[i] == "")output[i] = "<default>";
        }

        cout<<"Protocol = " << output[0]<<"\n";
        cout<<"Host     = " << output[1]<<"\n";
        cout<<"Port     = " << output[2]<<"\n";
        cout<<"Path     = " << output[3]<<"\n";
        if(c == n) return 0;
        cout<<"\n";

    }

}
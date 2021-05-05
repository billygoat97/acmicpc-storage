#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



// č	c=
// ć	c-
// dž	dz=
// đ	d-
// lj	lj
// nj	nj
// š	s=
// ž	z=

int main(){

    string str;
    cin>> str;
    int cnt=0;
    for(int i = 0; i<str.size();i++){

        if(str[i] == 'c'){
            if(i+1<str.size()){
                if(str[i+1]=='=' ||str[i+1]=='-'){
                    i++;
                }
            }
        }else if(str[i] == 'd'){
            if(i+2<str.size()){
                if(str[i+1]=='z' &&str[i+2]=='='){
                    i+=2;
                }
            }
            if(i+1<str.size()){
                if(str[i+1]=='-'){
                    i++;
                }
            }
        }else if(str[i] == 'l'){
            if(i+1<str.size()){
                if(str[i+1]=='j'){
                    i++;
                }
            }
        }else if(str[i] == 'n'){
            if(i+1<str.size()){
                if(str[i+1]=='j'){
                    i++;
                }
            }
        }else if(str[i] == 's'){
            if(i+1<str.size()){
                if(str[i+1]=='='){
                    i++;
                }
            }
        }else if(str[i] == 'z'){
            if(i+1<str.size()){
                if(str[i+1]=='='){
                    i++;
                }
            }
        }
        cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}

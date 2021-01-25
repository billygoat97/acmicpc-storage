#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    int n;
    string str;

    cin>>n;
    cin >>str;

    int len = str.size();
    char bigyo[len];
    for( int i= 0; i<len;i++){
        bigyo[i] = str[i];
    }
    for(int i = 1; i<n; i++){
        cin >> str;
        for(int j = 0; j<len;j++){
            if(str[j] != bigyo[j]){
                bigyo[j] = '?';
            }
        }
        
    }
    for(int i = 0 ;i<len;i++)
    cout<<bigyo[i];
    cout<<endl;
    return 0;
}
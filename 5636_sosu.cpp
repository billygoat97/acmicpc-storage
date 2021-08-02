#include <iostream>
#include <cmath>
#include <cstring>

int arr[100001];

using namespace std;

int main(){

    for(int i = 2; i<=100000; i++){
        arr[i] = i;
    }
    for(int i = 2; i<= 100000;i++){
        if(arr[i]==0)continue;
        if(i*i>100000)break;
        for(int j = i*i; j<=100000;j+=i){
            arr[j] = 0;
        }
    }

    while(true){
        string str;
        cin >> str;
        if(str == "0")break;
        int imsi = 0;
        for(int i = 0; i<str.size(); i++){
            string temp = "";
            for(int j = 0; j<5; j++){
                if(i+j>=str.size())break;
                temp += str[i+j];
                int check = stoi(temp);
                if(arr[check]!= 0)imsi = max(check,imsi);
            }
        }
        cout<<imsi<<endl;
    }


    return 0;
}
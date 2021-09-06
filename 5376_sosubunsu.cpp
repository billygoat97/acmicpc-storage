#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    ll imsi;
    if(b> a){
        swap(a,b);
    }
    while(b !=0){
        imsi = a % b;
        a = b;
        b = imsi;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        double num;
        ll bunja, bunmo;
        if(str.find("(") <= str.size()){
            string nocon = "";
            string con = "";
            double cnt = 0;
            for(int i = 0; i< str.size();i++){
                if(str[i] == '.'){
                    cnt = i;
                    continue;
                }
                if(str[i] != '('){
                    nocon += str[i];
                    con += str[i];
                }
                if(str[i] == '('){
                    i++;
                    while(str[i] != ')'){
                        nocon += str[i];
                        i++;
                    }
                }
            }
            bunja = stol(nocon) - stol(con);
            bunmo = ( pow(10,nocon.length()-cnt) - 1 ) - (pow(10,con.length()-cnt)-1);
        }else{
            num = stod(str);
            double cnt = str.size()-2;
            bunja = num*pow(10,cnt);
            bunmo = pow(10,cnt);
        }
        if(gcd(bunja,bunmo) == 0){
            cout<<0<<"\n";
        }else{
            cout<<bunja/gcd(bunja,bunmo) <<"/"<<bunmo/gcd(bunja,bunmo)<<"\n";
        }
    }


    return 0;
}
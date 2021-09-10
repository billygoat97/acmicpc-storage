#include <iostream>

using namespace std;

int main(){

    long long n;
    cin >> n;
    int check = n % 7;
    if(check == 2 || check == 0){
        cout<<"CY";
    }else{
        cout<<"SK";
    }
    return 0;

}
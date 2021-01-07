#include <iostream>
#include <cstring>
using namespace std;

string input;
int length;
int palindrome(int idx ){
    for (int i = 0; idx + i < length - i - 1; i++){
        if (input[idx + i] != input[length-i-1]){
            return -1;
        }
    }
    return 1;
}

int main(void){
    cin >> input;
    length = input.size();
    int result = 0;
    for(int i = 0; i< length; i++){
        if(palindrome(i) == 1){
            result = length + i;
            cout<< result << endl;
            return 0;
        }
    }

return 0;
}
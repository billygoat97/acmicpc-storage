#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class TN{

    public:
        TN *child[26];
    
    TN(){
        for(int i = 0; i<26; i++){
            child[i] = NULL;
        }
    }
    void insert(char* str){
        

    }

    TN find(char* str){

        return this;
    }
};



int main(){

    string str;
    int tc;
    cin >> tc;
    while(tc--){
        vector<string> v;
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> str;
            v.push_back(str);
        }
    }


    return 0;
}
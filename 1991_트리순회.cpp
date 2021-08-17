#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

class node{
    public:
        int left = -1;
        int right = -1;
};

node arr[26];

void func1(int n){
    if(n==-1)return;
    cout<< char(65+n);
    func1(arr[n].left);
    func1(arr[n].right);
}
void func2(int n){
    if(n==-1)return;
    func2(arr[n].left);
    cout<< char(65+n);
    func2(arr[n].right);
}

void func3(int n){
    if(n==-1)return;
    func3(arr[n].left);
    func3(arr[n].right);
    cout<< char(65+n);
}


int main(){

    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        char a,b,c;
        cin >> a >> b>> c;
        if(b != '.'){
            arr[a-'A'].left = b - 'A';
        }
        if(c != '.'){
            arr[a-'A'].right = c - 'A';
        }
    }

    // 전위 순회
    func1(0);
    cout<<"\n";
    // 중위 순회
    func2(0);
    cout<<"\n";
    // 후위 순회
    func3(0);
    cout<<"\n";



    return 0;
}
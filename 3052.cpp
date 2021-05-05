#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){

    vector<int> v;

    for(int i= 0; i<10;i++){
        int inp;
        cin >> inp;
        v.push_back(inp%42);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<endl;




    return 0;
}

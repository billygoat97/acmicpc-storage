#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(){

    int e,s,m;
    cin >> e >> s >> m;
    int ce=1,cs=1,cm=1;
    int cnt = 1;
    
    while( (ce == e && cs == s && cm == m) == false){
        ce++;
        cs++;
        cm++;
        if(ce >15)ce = 1;
        if(cs >28)cs = 1;
        if(cm >19)cm = 1;
        cnt++;
    }
    cout<< cnt<<endl;
    


    return 0;
}

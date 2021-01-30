#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int main(){

    int num;
    cin >>num;
    queue<int> q;
    queue<int> q_sort;
    for(int i = 0; i<num;i++){

        int t_cnt, when;
        cin >>t_cnt>>when;
        int max = 0;
        for(int j = 0; j<t_cnt; j++){
            int n;
            cin >> n;
            q.push(n);
            q_sort.push(n);
        }





    }



    return 0;
}
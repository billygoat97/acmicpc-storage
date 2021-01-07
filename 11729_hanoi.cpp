#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

void recursion(int n, int from, int via, int to);

queue<int> Q;
int main(){
    int n;
    // cin >> n;
    scanf("%d", &n);
    recursion(n,1,2,3);

    // printf("%d\n", Q.size());
    printf("%d\n",int(Q.size()/2));
    while(Q.size() != 0){
        int from;
        int to;
        from = Q.front();
        Q.pop();
        to = Q.front();
        Q.pop();
        printf("%d %d\n", from, to);
    }
    return 0;
}

void recursion(int n, int from, int via, int to){
    if( n== 1 ){
        //cout<<from<<" "<<to<<endl;
        // printf("%d %d\n", from, to);
        Q.push(from);
        Q.push(to);
        // count++;
    }else{
        recursion(n-1, from, to ,via);
        //cout<<from<<" "<<via<<endl;
        // printf("%d %d\n", from, to);
        Q.push(from);
        Q.push(to);
        // count++;
        recursion(n-1, via, from ,to);
    }
}
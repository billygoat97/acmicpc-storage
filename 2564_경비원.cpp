#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n,m;

int main(){

    cin >> n >> m; // arr[m][n]
    using T = pair<int, int>;
    vector<T> v;
    int c;
    cin >> c;
    for(int i = 0; i<=c; i++){
        int x, y;
        cin >> x >> y;
        switch(x){ // 북, 남, 서, 동
            case 1:
                v.push_back({m,y});
                break;
            case 2:
                v.push_back({0,y});
                break;
            case 3:
                v.push_back({m-y,0});
                break;
            case 4:
                v.push_back({m-y,n});
                break;
        }
    }
    int x1=v[c].first, y1 = v[c].second;
    int sum = 0;
    for(int i = 0; i<c; i++){
        int x2 = v[i].first;
        int y2 = v[i].second;
        if(abs(x1 - x2)==m){
            sum += m + min(n-y1 + n-y2, y1+y2);
        }else if(abs(y1 - y2) == n){
            sum += n + min(m-x1 + m-x2, x1+x2);
        }else{
            sum += abs(x1 - x2) + abs(y1 - y2);
        }
    }
    cout<<sum<<"\n";

    return 0;
}
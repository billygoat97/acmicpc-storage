#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

using T = pair<long, long>;
double dist (T p1, T p2){
    return sqrt(pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2));
}
int right(T p1, T p2, T p3){
    double ccw = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second - p2.first*p1.second - p3.first*p2.second - p1.first*p3.second;
    
    if(ccw > 0)return 1;
    else if(ccw == 0)return 0;
    return -1;
}


int main(){

    int n;
    vector<T> v;
    cin >> n;
    for(int i = 0; i<n; i++){
        long x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    T p = v[0];
    double total = 0;
    for(int i = 1; i<v.size()-1; i++){
        T p1 = v[i];
        T p2 = v[i+1];
        double l1 = dist(p1,p2);
        double l2 = dist(p2,p);
        double l3 = dist(p1,p);
        double s = (l1 + l2 + l3)/2;
        double size = sqrt(s*(s-l1)*(s-l2)*(s-l3));
        size *= right(p,p1,p2);
        // cout<<"size:" << size<<endl;
        total += size;
    }
    total = abs(total);
    total *= 10;
    total = round(total);
    total /= 10;
    cout<<fixed;
    cout.precision(1);
    cout<<total<<endl;


    return 0;
}
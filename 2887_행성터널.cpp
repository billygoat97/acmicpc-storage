#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

class Point{

    public:
        int x, y, z;
    Point(){

    }

    Point(int a, int b, int c){
        x = a;
        y = b;
        z = c;
    }

};

long dist(Point p1, Point p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}

void mst(int start){
    
}


int main(){

    int n;
    cin >> n;
    Point star[n];
    for(int i = 0; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        star[i] = Point(x,y,z);
    }
    return 0;
}



#include <iostream>
using namespace std;

int main(){


string first;
string second;
string danwui;
unsigned long long answer= 0;
cin >> first>>second >> danwui;
if (first.compare("black")==0){
    answer += 0;
}else if(first.compare("brown")==0){
answer += 10;
}else if(first.compare("red")==0){
answer += 20;
}else if(first.compare("orange")==0){
answer += 30;
}else if(first.compare("yellow")==0){
answer += 40;
}else if(first.compare("green")==0){
answer += 50;
}else if(first.compare("blue")==0){
answer += 60;
}else if(first.compare("violet")==0){
answer += 70;
}else if(first.compare("grey")==0){
answer += 80;
}else if(first.compare("white")==0){
answer += 90;
}
if (second.compare("black")==0){
answer += 0;
}else if(second.compare("brown")==0){
answer += 1;
}else if(second.compare("red")==0){
answer += 2;
}else if(second.compare("orange")==0){
answer += 3;
}else if(second.compare("yellow")==0){
answer += 4;
}else if(second.compare("green")==0){
answer += 5;
}else if(second.compare("blue")==0){
answer += 6;
}else if(second.compare("violet")==0){
answer += 7;
}else if(second.compare("grey")==0){
answer += 8;
}else if(second.compare("white")==0){
answer += 9;
}

if (danwui.compare("black")==0){
answer *= 1;
}else if(danwui.compare("brown")==0){
answer *= 10;
}else if(danwui.compare("red")==0){
answer *= 100;
}else if(danwui.compare("orange")==0){
answer *= 1000;
}else if(danwui.compare("yellow")==0){
answer *= 10000;
}else if(danwui.compare("green")==0){
answer *= 100000;
}else if(danwui.compare("blue")==0){
answer *= 1000000;
}else if(danwui.compare("violet")==0){
answer *= 10000000;
}else if(danwui.compare("grey")==0){
answer *= 100000000;
}else if(danwui.compare("white")==0){
answer *= 1000000000;
}

cout<<answer <<endl;
    return 0;
}
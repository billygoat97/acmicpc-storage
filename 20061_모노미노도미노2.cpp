#include <iostream>


using namespace std;

int blue[4][6] = {0,};
int green[4][6] = {0,};
int totalBlock = 0;
int point = 0;

void pushBlue(int level){ // 어디부터 누르냐!
    for(int i = level; i>0; i--){
        for(int j = 0; j<4; j++){
            blue[j][i] = blue[j][i-1];
        }
    }
    for(int i = 0; i<4; i++){
        blue[i][0] = 0;
    }
}

void pushGreen(int level){
    
    for(int i = level; i>0; i--){
        for(int j = 0; j<4; j++){
            green[j][i] = green[j][i-1];
        }
    }
    
    for(int i = 0; i<4; i++){
        green[i][0] = 0;
    }
    
}

void startBlue(int t, int x, int y){
    switch(t){
        case 1:
        // x는 그대로 x로 감 y는 0부터 5까지 직진
            for(int i = 0; i<6; i++){
                if(blue[x][i] != 0){
                    blue[x][i-1] = 1;
                    break; 
                }
                if(i == 5){
                    blue[x][i] = 1;
                }
            }

            break;
        case 2:
        //  x,y //// x,y+1 -> 이건 그대로 쭉쭉 내려감. y값은 안중요
            for(int i = 0; i<6; i++){
                if(blue[x][i] != 0){
                    blue[x][i-1] = 1;
                    blue[x][i-2] = 1;
                    break; 
                }
                if(i == 5){
                    blue[x][i] = 1;
                    blue[x][i-1] = 1;
                }
            }
            break;
        case 3:
        // x,y //// x+1,y -> 이건 동시 check
            for(int i = 0; i<6; i++){
                if(blue[x][i] != 0 || blue[x+1][i] != 0){
                    blue[x][i-1] = 1;
                    blue[x+1][i-1] = 1;
                    break; 
                }
                if(i == 5){
                    blue[x][i] = 1;
                    blue[x+1][i] = 1;
                }
            }
            break;
    }
    // 이제 점수를 얻는지 내려가는지 계산!
    for(int i = 5; i>=2;i--){
        int sum = 0;
        for(int j = 0; j<4; j++){
            sum+= blue[j][i];
        }
        if(sum == 4){
            pushBlue(i);
            point++;
            i++;
        }
    }
    //위에서 내림. 근데 만약에 0,1 level쪽에 문제가 생기면?
    bool flag1 = false, flag0 = false;
    for(int i = 0; i<4; i++){
        if(blue[i][1] == 1)flag1 = true;
        if(blue[i][0] == 1)flag0 = true;
    }
    if(flag1)pushBlue(5);
    if(flag0)pushBlue(5);
}

void startGreen(int t, int x, int y){
    switch(t){
        case 1:
        // x는 그대로 x로 감 y는 0부터 5까지 직진
            for(int i = 0; i<6; i++){
                if(green[x][i] != 0){
                    green[x][i-1] = 1;
                    break; 
                }
                if(i == 5){
                    green[x][i] = 1;
                }
            }
            break;
        case 2:
        //  x,y //// x,y+1 -> 이건 그대로 쭉쭉 내려감. y값은 안중요
            for(int i = 0; i<6; i++){
                if(green[x][i] != 0){
                    green[x][i-1] = 1;
                    green[x][i-2] = 1;
                    break; 
                }
                if(i == 5){
                    green[x][i] = 1;
                    green[x][i-1] = 1;
                }
            }
            break;
        case 3:
        // x,y //// x+1,y -> 이건 동시 check
            for(int i = 0; i<6; i++){
                if(green[x][i] != 0 || green[x+1][i] != 0){
                    green[x][i-1] = 1;
                    green[x+1][i-1] = 1;
                    break; 
                }
                if(i == 5){
                    green[x][i] = 1;
                    green[x+1][i] = 1;
                }
            }
            break;
    }
    
    // 이제 점수를 얻는지 내려가는지 계산!
    for(int i = 5; i>=2;i--){
        int sum = 0;
        for(int j = 0; j<4; j++){
            sum+= green[j][i];
        }
        if(sum == 4){
            
            pushGreen(i);
            point++;
            i++;
        }
    }
    
    //위에서 내림. 근데 만약에 0,1 level쪽에 문제가 생기면?
    bool flag1 = false, flag0 = false;
    for(int i = 0; i<4; i++){
        if(green[i][1] == 1)flag1 = true;
        if(green[i][0] == 1)flag0 = true;
    }
    if(flag1)pushGreen(5);
    if(flag0)pushGreen(5);    
    
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, x, y;
    cin >> n;

    for(int a = 0; a<n; a++){
        cin >> t >> x >> y;
        if(t == 1)startGreen(1,y,x);
        if(t == 2)startGreen(3,y,x);
        if(t == 3)startGreen(2,y,x);
        startBlue(t,x,y);
    }

    cout<< point <<endl;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<6; j++){
            totalBlock += blue[i][j] + green[i][j];
        }
    }
    cout<< totalBlock<<endl;


    return 0;
}
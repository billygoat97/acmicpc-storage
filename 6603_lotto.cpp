#include <iostream>
using namespace std;

int lotto[6];
void getCombi(int start, int depth,int* array,int n);
int main(){

    int n;

    cin >> n;
    while(n != 0){

        int *array = new int[n];
        for(int i = 0; i<n; i++){
            cin >> array[i];
        }
        
        getCombi(0,0,array,n);


        delete []array;
        cin >> n;
    }
    return 0;
}

void getCombi(int start, int depth,int* array,int n) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	//start부터 k-1 까지 순서
	for (int i = start; i < n; i++) {
		lotto[depth] = array[i];
		getCombi(i+1, depth+1,array,n);
	}
}
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void merge_sort(int start, int end, long long **array);
void merge(int start, int mid, int end, long long** array);

int main(){
    int a,b;
    cin >>a>>b;
    long long **arrayA = new long long*[a];
    long long **arrayB = new long long*[a];
    long long **arrayC = new long long*[a];
    for(int i = 0; i<a;i++){
        arrayA[i] = new long long[2];
        arrayB[i] = new long long[2];
        arrayC[i] = new long long[2];
    }
    for(int i = 0; i<a;i++){ // 배열 a,c에 똑같은 값 (첫째줄)입력
        cin>>arrayA[i][0];
        arrayC[i][0] = arrayA[i][0];
        arrayA[i][1] = i;
        arrayC[i][1] = i;
    }
    
    
    for(int i = 0; i<a;i++){ //배열 b에  (둘쨰줄) 입력, c에서 뻄, abs로 절대값 얻음
        cin>>arrayB[i][0];
        arrayC[i][0] -= arrayB[i][0];
        arrayC[i][0] = abs(arrayC[i][0]);
        arrayB[i][1] = i;
    }

    merge_sort(0,a-1,arrayC); // 절대값이 가장 큰것을 

    
    int temp[80000];
    int order[80000];
    for(int i = 0; i<a;i++){
        temp[i] = arrayA[arrayC[i][1]][0];
        order[i] = arrayA[arrayC[i][1]][1];
    }

    for(int i = 0; i<a;i++){
        arrayA[i][0] = temp[i];
        arrayA[i][1] = order[i];
    }   
    
    for(int i = 0; i<b;i++){
        arrayB[arrayC[a-i-1][1]][0] = -1;
    }
    
    merge_sort(0,a-1,arrayB);
    long long sumA = 0,sumB = 0;
    for(int i = 0; i<b;i++){
        sumA += arrayA[a-i-1][0];
    }
    for(int i = 0; i<b;i++){
        sumB += arrayB[a-i-1][0];
    }
    cout << sumA-sumB<<endl;

    return 0;
}

void merge_sort(int start, int end, long long **array){

    int mid;
    if(start < end){
        mid = (start + end)/2;
        merge_sort(start, mid,array);
        merge_sort(mid +1,end,array);
        merge(start, mid, end, array);
    }
}


void merge(int start, int mid, int end, long long** array){
	
    long long i, j, k, temp[end-start+1], order[end-start +1];
	i = start;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= end){
		if (array[i][0] < array[j][0]){
			temp[k] = array[i][0];
            order[k] = array[i][1];
			k++;
			i++;
		}else{
			temp[k] = array[j][0];
            order[k] = array[j][1];
			k++;
			j++;
		}
	}
	while (i <= mid){
		temp[k] = array[i][0];
        order[k] = array[i][1];
        
		k++;
		i++;
	}
	while (j <= end){
		temp[k] = array[j][0];
        order[k] = array[j][1];
		k++;
		j++;
	}
	for (i = start; i <= end; i++){
		array[i][0] = temp[i-start];
		array[i][1] = order[i-start];
	}
}
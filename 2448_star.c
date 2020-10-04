#include <stdio.h>

void star(int n, int x, int y);

char arr[3072][6144];

int main(void) {
	int n,i,j;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n;j++){
			arr[i][j]=' ';
		}
	}
	star(n,n-1,0);
	
	for(i=0;i<n;i++){
		for(j=0;j<2*n;j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void star(int n, int x, int y){
	
	if(n==3){
		arr[y][x]='*';
		arr[y+1][x-1]='*';
		arr[y+1][x+1]='*';
		for(int i=0;i<5;i++){
			arr[y+2][x-2+i]='*';
		}
	}
	else{
		n/=2;
		star(n,x,y);
		star(n,x-n,y+n);
		star(n,x+n,y+n);
	}
}

#include<stdio.h>

int main(){
	int N,n;
	scanf("%d",&N);
	int M=1,m=0,mask=1;
	int tr;
	int cnt=0;
	tr=N;
	for(M=1;tr>9;){
		tr/=10;
		M++;
	}
	int num[N][M];
	for(n=0;n<N;n++){
		int tran,nn;
		tran=n+1;
		nn=n+1;
		for(mask=1;tran>9;){
			tran/=10;
			mask*=10;
		}
		for(m=0;mask>0;m++){
			num[n][m]=nn/mask;
			if(num[n][m]==1){
				cnt++;
			}
			nn%=mask;
			mask/=10;
		}
	}
	
	printf("f(n)=%d\n",cnt);
	
	return 0;
}

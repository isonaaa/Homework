#include<stdio.h>

int self(int n);
int plus(int num[5]);
int multi(int num[5]);

int main(){
	int n=100;
	int m=2;
	int a,b,c,cnt=0;
	float all=0.0f;
	
	for(n=100;n<10001;n++){
		a=self(n);
		if(a==1){	//�����Ѿ������� 
			int num[5]={0};
			int mask=1,N=n,M=n;
			while(N>9){
				N/=10;
				mask*=10;
			}
			for(int t=0;t<5,mask>0;t++){	//�ó���λ�� 
				num[t]=M/mask;
				M%=mask;
				mask/=10;
			}
			b=plus(num);
			c=multi(num);
			if(b==1 && c==1){	//��λ���ĺ͡�ƽ�����Ѿ������� 
				printf("%d\n",n);
				cnt++;
				all+=n;
			}
		}
	}
	
	printf("%f\n",all/cnt);
	
	return 0;
}

//�ж������Ƿ�Ϊ���� 
int self(int n){
	int m,cnt=0;
	for(m=2;m<n;m++){
		if(n%m==0){
			cnt++;
		}
	}
	if(cnt==0){
		return 1;
	}else{
		return 0;
	}
}

//�жϸ�λ���ĺ��Ƿ�Ϊ����
int plus(int num[5]){
	int h=0;
	for(int t=0;t<5;t++){
		h+=num[t];
	}
	int cnt=0;
	for(int m=2;m<h;m++){
		if(h%m==0){
			cnt++;
		}
	}
	if(cnt==0){
		return 1;
	}else{
		return 0;
	}
}

//�жϸ�λ����ƽ�����Ƿ�Ϊ����
int multi(int num[5]){
	int pfh=0;
	for(int t=0;t<5;t++){
		pfh+=num[t]*num[t];
	}
	int cnt=0;
	for(int m=2;m<pfh;m++){
		if(pfh%m==0){
			cnt++;
		}
	}
	if(cnt==0){
		return 1;
	}else{
		return 0;
	}
}

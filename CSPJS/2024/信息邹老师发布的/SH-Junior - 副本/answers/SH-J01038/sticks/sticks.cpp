#include<cstdio>
#include<cstring>
#include<cmath>
const int N = 100100;
int biao[10]={6,2,5,5,4,5,6,3,7,6};
int w[10]={0,0,1,2,4,7,8};//num
int c[10]={0,6,2,5,4,3,7};//stick
int w2[10]={0,1,2,4,6,7,8};
int c2[10]={0,2,5,4,6,3,7};
int t,n,answer[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		memset(answer,0,sizeof(answer));
		scanf("%d",&n);
		int wei=ceil(n/7.0);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n==6){
			printf("6\n");
			continue;
		}
		int sum=0;
		while(sum<wei-1){
			sum++;
			int ss=(wei-sum)*7;
			if(sum==1){
				for(int i=1;i<=6;i++){
					n-=c2[i];
					if(ss>=n){
						answer[sum]=w2[i];
						break;
					}
					n+=c2[i];
				}
			}
			else{
				for(int i=1;i<=6;i++){
					n-=c[i];
					if(ss>=n){
						answer[sum]=w[i];
						break;
					}
					n+=c[i];
				}
			}
		}
		for(int i=1;i<=wei-1;i++){
			printf("%d",answer[i]);
		}
		switch(n){
			case 2:{
				printf("1");
				break;
			}
			case 3:{
				printf("7");
				break;
			}
			case 4:{
				printf("4");
				break;
			}
			case 5:{
				printf("2");
				break;
			}
			case 6:{
				printf("0");
				break;
			}
			case 7:{
				printf("8");
				break;
			}
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

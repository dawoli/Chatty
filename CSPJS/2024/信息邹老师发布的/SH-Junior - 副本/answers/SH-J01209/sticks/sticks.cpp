#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int tmp;
	scanf("%d", &tmp);
	while(tmp--){
		int n;
		scanf("%d",&n);
		if(n==1||n==0){
			printf("-1\n"); 
		}else if(n%7==0){
			int k=n/7;
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");
		}else if(n%7==6){
			int k=(n-6)/7;
			printf("6");
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");
		}else if(n%7==5){
			int k=(n-2)/7;
			printf("2");
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");	
		}else if(n%7==4){
			if(n==4){
				printf("4\n");
			}else{
				printf("20");
				int k=(n-11)/7;
				for(int i=1;i<=k;i++){
					printf("8");
				}
				printf("\n");
			}
		}else if(n%7==3){
			if(n==3){
				printf("7\n");
			}else if(n==10){
				printf("22\n");
			}else{
				printf("200");
				int k=(n-17)/7;
				for(int i=1;i<=k;i++){
					printf("8");
				}
				printf("\n");
			}
		}else if(n%7==2){
			printf("1");
			int k=(n-2)/7;
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");
		}else if(n%7==1){
			printf("10");
			int k=(n-8)/7;
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}

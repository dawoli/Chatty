#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n%7==0){
			int cnt=n/7;
			for(int j=1;j<=cnt;j++){
				printf("8");
			}printf("\n");
		}
		if(n%7==1){
			int cnt=n/7;
			printf("10");
			for(int j=1;j<=cnt-1;j++){
				printf("8");
			}printf("\n");
		}
		if(n%7==2){
			int cnt=n/7;
			printf("1");
			for(int i=1;i<=cnt;i++){
				printf("8");
			}printf("\n");
		}
		if(n%7==3){
			if(n==3){
				printf("7\n");
				continue;
			}else if(n==10){
				printf("22\n");
				continue;
			}
			int cnt=n/7;
			printf("200");
			for(int i=1;i<=cnt-2;i++){
				printf("8");
			}printf("\n");
		}if(n%7==4){
			if(n==4){
				printf("4\n");
				continue;
			}
			int cnt=n/7;
			printf("20");
			for(int i=1;i<=cnt-1;i++){
				printf("8");
			}printf("\n");
		}if(n%7==5){
			int cnt=n/7;
			printf("2");
			for(int i=1;i<=cnt;i++){
				printf("8");
			}printf("\n");
		}if(n%7==6){
			int cnt=n/7;
			printf("6");
			for(int i=1;i<=cnt;i++){
				printf("8");
			}printf("\n");			
		}
	}
	
	
	
	return 0;
}

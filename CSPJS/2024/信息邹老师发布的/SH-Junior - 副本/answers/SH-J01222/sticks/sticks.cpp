#include <bits/stdc++.h>
using namespace std;
const int dx[25]={6,2,5,4,3,7};//3,5,6,9x
int t,n;
int main(){
	freopen("sticks.in ","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d",&n);
		if(n%7==0){
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==1&&n>7){
			printf("10");
			n-=8;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==2){
			printf("1");
			n-=2;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==3&&n>7){
			printf("7");
			n-=3;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==4&&n>7){
			printf("20");
			n-=11;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==5){
			printf("2");
			n-=5;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==6&&n>7){
			printf("80");
			n-=13;
			for(int j=1;j<=n/7;++j){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n==4){
			printf("4\n");
			continue;
		}
		if(n==3){
			printf("7\n");
		}
		printf("6\n");
	}
	return 0;
}

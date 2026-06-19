#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				printf("8");
			}
			printf("\n");
		}else{
			int tmp=n%7;
			if(n<7){
				if(n==2){
					printf("1");
				}else if(n==3){
					printf("7");
				}else if(n==4){
					printf("4");
				}else if(n==5){
					printf("2");
				}else if(n==6){
					printf("6");
				}
				printf("\n");
				continue;
			}
			if(tmp==1){
				printf("10");
			}else if(tmp==2){
				printf("18");
			}else if(tmp==3){
				printf("22");
			}else if(tmp==4){
				printf("20");
			}else if(tmp==5){
				printf("28");
			}else if(tmp==6){
				printf("68");
			}
			for(int i=1;i<=n/7-1;i++){
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}

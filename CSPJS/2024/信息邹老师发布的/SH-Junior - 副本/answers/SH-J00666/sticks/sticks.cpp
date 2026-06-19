#include<bits/stdc++.h>
using namespace std;
const int scn[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n==1) printf("-1\n");
		else if(n<=7){
			switch(n){
				case 2:printf("1\n");
				case 3:printf("7\n");
				case 4:printf("4\n");
				case 5:printf("2\n");
				case 6:printf("6\n");
			}
		}
		else{
			switch(n%7){
				case 0:{
					for(int i=1;i<=n/7;i++)
						printf("8");
					printf("\n");
				}break;
				case 1:{
					printf("10");
					for(int i=1;i<=(n-8)/7;i++)
						printf("8");
					printf("\n");
				}break;
				case 2:{
					printf("1");
					for(int i=1;i<=(n-2)/7;i++)
						printf("8");
					printf("\n");
				}break;
				case 3:{
					printf("2");
					if(n==10) printf("2");
					else{
						printf("00");
						for(int i=1;i<=(n-17)/7;i++)
							printf("8");
					}
					printf("\n");
				}break;
				case 4:{
					printf("20");
					for(int i=1;i<=(n-8)/7;i++)
						printf("8");
					printf("\n");
				}break;
				case 5:{
					printf("2");
					for(int i=1;i<=(n-5)/7;i++)
						printf("8");
					printf("\n");
				}break;
				case 6:{
					printf("6");
					for(int i=1;i<=(n-6)/7;i++)
						printf("8");
					printf("\n");
				}break;
			}
		}
	}
	return 0;
}

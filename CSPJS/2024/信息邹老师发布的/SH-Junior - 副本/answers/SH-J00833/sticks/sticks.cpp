#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
//         0,1,2,3,4,5,6,7,8,9
int ans[1000010]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088};
//                0 ,1 ,2,3,4,5,6,7,8 ,9 ,10,11,12,13,14,15 ,16 ,17 ,18 ,19 ,20 ,21 ,22  ,23  ,24  ,25  ,26  ,27  ,28  ,29   ,30   ,31   
//打表打着打着打出规律乐,打表yyds 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=13){
			printf("%d\n",ans[n]);
		}
		else{
			if(n%7==0){
				for(int i=1;i<=n/7;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==1){
				printf("10");
				for(int i=1;i<=(n-1)/7-1;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==2){
				printf("1");
				for(int i=1;i<=(n-2)/7;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==3){
				printf("200");
				for(int i=1;i<=(n-3)/7-2;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==4){
				printf("20");
				for(int i=1;i<=(n-4)/7-1;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==5){
				printf("2");
				for(int i=1;i<=(n-5)/7-1;i++){
					printf("8");
				}
				printf("\n");
			}
			else if(n%7==6){
				printf("6");
				for(int i=1;i<=(n-6)/7;i++){
					printf("8");
				}
				printf("\n");
			}
		}
	}
	return 0;
}

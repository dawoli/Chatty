#include<bits/stdc++.h>
using namespace std;
int t,n,x,y;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		if(n==1)printf("-1\n");
		else if(n==2)printf("1\n");
		else if(n==3)printf("7\n");
		else if(n==4)printf("4\n");
		else if(n==5)printf("2\n");
		else if(n==6)printf("6\n");
		else if(n==7)printf("8\n");
		else if(n==8)printf("10\n");
		else if(n==9)printf("18\n");
		else if(n==10)printf("22\n");
		else if(n==11)printf("20\n");
		else if(n==12)printf("28\n");
		else if(n==13)printf("68\n");
		else if(n==14)printf("88\n");
		else{
			x=n/7;
			y=n%7;
			if(y==1){
				printf("10");
				x--;
			}
			else if(y==2)printf("1");
			else if(y==3){
				printf("22");
				x--;
			}
			else if(y==4){
				printf("20");
				x--;
			}
			else if(y==5)printf("2");
			else if(y==6)printf("6");
			for(int i=1;i<=x;i++){
				printf("8");
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

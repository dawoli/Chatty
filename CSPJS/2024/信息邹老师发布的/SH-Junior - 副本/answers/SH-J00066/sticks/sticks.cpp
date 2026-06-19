#include<bits/stdc++.h>
using namespace std;
int t,n;
bool flag;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1)printf("-1");
		else if(n==3)printf("7");
		else if(n==4)printf("4");
		else if(n==10)printf("22");
		else{
			if(n%7==1)n-=8,printf("10");
			else if(n%7==2)n-=2,printf("1");
			else if(n%7==3)n-=17,printf("200");
			else if(n%7==4)n-=11,printf("20");
			else if(n%7==5)n-=5,printf("2");
			else if(n%7==6)n-=6,printf("6");
			while(n)n-=7,printf("8");
		}
		printf("\n");
	}
	return 0;
}

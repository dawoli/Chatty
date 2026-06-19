#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n>=15){
			if(n%7==1)	printf("108");
			if(n%7==2)	printf("188");
			if(n%7==3)	printf("200");
			if(n%7==4)	printf("208");
			if(n%7==5)	printf("288");
			if(n%7==6)	printf("688");
			if(n%7==0)	printf("88");
			n-=14;
			for(int i=1;i<=n/7;++i)	printf("8");
		}
		else{
			if(n==1)	printf("-1");
			if(n==2)	printf("1");
			if(n==3)	printf("7");
			if(n==4)	printf("4");
			if(n==5)	printf("2");
			if(n==6)	printf("6");
			if(n==7)	printf("8");
			if(n==8)	printf("10");
			if(n==9)	printf("18");
			if(n==10)	printf("22");
			if(n==11)	printf("20");
			if(n==12)	printf("28");
			if(n==13)	printf("68");
			if(n==14)	printf("88");
		}
		puts("");
	}
	return 0;
} 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
void Main(){
	scanf("%lld",&n);
	if(n==1)printf("-1");
	else if(n==2)printf("1");
	else if(n==3)printf("7");
	else if(n==4)printf("4");
	else if(n==5)printf("2");
	else if(n==6)printf("6");
	else if(n%7==0){
		for(ll i=1;i<=n/7;i++)printf("8");
	}
	else if(n%7==1){
		printf("10");
		for(ll i=1;i<n/7;i++)printf("8");
	}
	else if(n%7==2){
		printf("1");
		for(ll i=1;i<=n/7;i++)printf("8");
	}
	else if(n%7==3){
		printf("22");
		for(ll i=1;i<n/7;i++)printf("8");
	}
	else if(n%7==4){
		printf("20");
		for(ll i=1;i<n/7;i++)printf("8");
	}
	else if(n%7==5){
		printf("2");
		for(ll i=1;i<=n/7;i++)printf("8");
	}
	else if(n%7==6){
		printf("6");
		for(ll i=1;i<=n/7;i++)printf("8");
	}
	printf("\n");
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		Main();
	}
	return 0;
}
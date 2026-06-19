#include<bits/stdc++.h>
#define maxn 57
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,t;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		if(n==1)printf("-1\n");
		else if(n==3)printf("7\n");
		else if(n==4)printf("4\n");
		else if(n==10)printf("22\n");
		else{
			if(n%7==0){
				for(int i=1;i<=n/7;i++)printf("8");
				printf("\n");
			}
			else if(n%7==1){
				printf("10");
				for(int i=1;i<n/7;i++)printf("8");
				printf("\n");
			}
			else if(n%7==2){
				printf("1");
				for(int i=1;i<=n/7;i++)printf("8");
				printf("\n");
			}
			else if(n%7==3){
				printf("200");
				for(int i=2;i<n/7;i++)printf("8");
				printf("\n");
			}
			else if(n%7==4){
				printf("20");
				for(int i=1;i<n/7;i++)printf("8");
				printf("\n");
			}
			else if(n%7==5){
				printf("2");
				for(int i=1;i<=n/7;i++)printf("8");
				printf("\n");
			}
			else{
				printf("6");
				for(int i=1;i<=n/7;i++)printf("8");
				printf("\n");
			}
		}
	}
	return 0;
}

// code written by luogu user #951212

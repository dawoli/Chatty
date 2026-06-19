#include<bits/stdc++.h>
using namespace std;
int rule[9]={0,-1,1,7,4,2,6};
int T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	for(int t=1,n;t<=T;++t){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n%7==0&&n>=100){
			for(int i=1;i<=n/7;++i) printf("8");
			printf("\n");
			continue;
		}
		if(n%7==1&&n>=100){
			printf("10");
			for(int i=3;i<=ceil(n*1.0/7);++i) printf("8");
			continue;
		}
	}
	return 0;
}

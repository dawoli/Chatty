#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans[22]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,608};
//int f[9][4]={-1,-1,-1,-1}{-1,-1,-1,-1}{1,-1,-1,-1}{7,-1,-1,-1}{4,-1,-1,-1}{2,3,5,-1}{0,6,9,-1}{8,-1,-1,-1};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=20) printf("%d",ans[n]);
		else if(n%7==0){
			int x=n/7;
			while(x--) printf("8");
		}
		else printf("-1");
		printf("\n");
	}
	return 0;
} 

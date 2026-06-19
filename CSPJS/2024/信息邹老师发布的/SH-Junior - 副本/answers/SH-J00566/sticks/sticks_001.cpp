#include<bits/stdc++.h>
using namespace std;
int t,n,a[10]={-1,-1,1,7,4,2,0,8},b[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int minid,minn=2e9,bfn;
		scanf("%d",&n);
		if(n==6){
			printf("6\n");
			continue;
		}
		if(n<8){
			printf("%d\n",a[n]);
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;++i)
				printf("8");
			printf("\n");
			continue;
		}
		if(n%7==1){
			printf("10");
			for(int i=1;i<n/7;++i)
				printf("8");
			printf("\n");
			continue;
		}
		for(int i=1;i<=9;++i){
			bfn=n;
			bfn-=b[i];
			int xxx;
			if(bfn%7==1){
				bfn-=8;
				xxx=3+bfn/7;
			}
			else if(bfn%7==0)
				xxx=1+bfn/7;
			else xxx=2+bfn/7;
			if(xxx<minn){
				minn=xxx;
				minid=i;
			}
		}
		printf("%d",minid);
		n-=b[minid];
		if(n%7==0)
			for(int i=1;i<=n/7;++i)
				printf("8");
		else if(n%7==1){
			printf("01");
			n-=8;
			for(int i=1;i<=n/7;++i)
				printf("8");
		}
		else{
			printf("%d",a[n%7]);
			for(int i=1;i<=n/7;++i)
				printf("8");
		}
		printf("\n");
	}
	return 0;
}

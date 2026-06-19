#include<bits/stdc++.h>
using namespace std;
int req[10]={6,2,5,5,4,5,6,3,7,6};
int ok(int curl,int num,int curn){
	return (curl-1)*7+req[num]>=curn&&(req[num]<curn-1||req[num]==curn);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		if(n==1){
			puts("-1");
			continue;
		}
		int len=(n+6)/7;
		for(int i=len;i;i--){
			if(i!=len&&ok(i,0,n)){
				putchar('0');
				n-=6;
				continue;
			}
			for(int j=1;j<10;j++)
				if(ok(i,j,n)){
					putchar('0'+j);
					n-=req[j];
					break;
				}
		}
		putchar('\n');
	}
	return 0;
}

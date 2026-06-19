#include<bits/stdc++.h>
using namespace std;
int n,num,cum[1000002],sum[11];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		for(int a=1;a<=n;a++){
			scanf("%d",&num);
			cum[num]++;
		}
		for(int b=1;b<=1000000;b++){
			if(cum[b]<=1){
				continue;
			}else{
				sum[i]+=b*(cum[b]-1);
			}
		}
		memset(cum,0,sizeof(cum));
	}
	for(int i=1;i<=T;i++){
		printf("%d\n",sum[i]);
	}
	return 0;
}

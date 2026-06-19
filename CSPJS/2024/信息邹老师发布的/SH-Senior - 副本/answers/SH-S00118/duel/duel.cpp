#include<bits/stdc++.h>
using namespace std;
int n,num[100010],ans,mmin=10000000,mmax=-1; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		num[x]++;
		mmin=min(mmin,x);
		mmax=max(mmax,x);
	}
	ans=num[mmin];
	for(int i=mmin;i<=mmax;i++){
		if(num[i]){
			if(num[i]>=ans) ans=num[i];
//			cout<<num[i]<<" "<<i<<" "<<ans<<endl;
		}
	}
	printf("%d",ans);
	return 0;
}

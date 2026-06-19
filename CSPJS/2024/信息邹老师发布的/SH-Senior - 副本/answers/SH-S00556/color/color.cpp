#include<bits/stdc++.h>
using namespace std;
long long as;
int T,n,a[200010],c[200010],an[200010];
long long ans(){
	long long anss=0;
	an[1]=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[j]==c[i]){
				if(a[i]==a[j]){
					an[i]=a[i];
				}
				else{
					an[i]=0;
				}
				break;
			}
		}
		anss+=an[i];
	}
	return anss;
}
void dfs(int d,int sum,int now){
	if(sum>=d){
		as=max(as,ans());
		return;
	}
	for(int i=now;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			dfs(d,sum+1,now+1);
			c[i]=0;
		}
	}
}
int main(){
freopen("color.in","r",stdin);
freopen("color.out","w",stdout);
scanf("%d",&T);
for(int t=0;t<T;t++){
	memset(a,0,sizeof(a));
	as=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(an,0,sizeof(an));
		dfs(i,0,1);
	}
	printf("%lld\n",as);
}
return 0;
}

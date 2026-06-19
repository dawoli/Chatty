#include<bits/stdc++.h>
const int N=100001;
int n,a[N],ans,x=0;
bool b[N]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans=n;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	std::sort(a,a+n);
	for(int i=0;1;i++){
		x=std::upper_bound(a+x+1,a+n,a[i])-a;
		if(x>=n)break;
		b[x]=1,ans--;
	}
	printf("%d",ans);
	return 0;
}

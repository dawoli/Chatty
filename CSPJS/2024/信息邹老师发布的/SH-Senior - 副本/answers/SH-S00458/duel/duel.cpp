#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],x,hh=0,ans,maxn=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>maxn)
		maxn=x;
		a[x]++;
	}
	ans=n;
	for(int i=1;i<=maxn;i++){
		if(hh==0&&a[i]!=0)
		hh=i;
		else if(a[i]!=0){
			ans-=min(a[hh],a[i]);
			a[i]=a[i]+a[hh]-min(a[i],a[hh]);
			hh=i;
		}
	}
	cout<<ans;
	return 0;
}

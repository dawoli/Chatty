#include <bits/stdc++.h>
using namespace std;
int t,n,maxx,c[1000000],a[1000000],col[1000000];
void ddd(int tt,int ans,int re,int bl){
	if(tt==n+1){
		maxx=max(maxx,ans);
		return;
	}
	
	if(a[re]==a[tt]){
		ddd(tt+1,ans+a[tt],tt,bl);
	}else{
		ddd(tt+1,ans,tt,bl);
	}
	
	
	
	if(a[bl]==a[tt]){
		ddd(tt+1,ans+a[tt],re,tt);
	}else{
		ddd(tt+1,ans,re,tt);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		a[0]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		maxx=0;
		ddd(1,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}

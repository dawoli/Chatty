#include<bits/stdc++.h>
using namespace std;
int n,a[5010],k[5010],cnt=0,jilu;
long long tot;
long long dfs(int cishu,int shu){
	if (cishu==jilu) cnt=0;
	if (cishu==1){
		long long tot1=0;
		for (int i=shu;i<n;++i){
			for (int j=0;j<jilu;++j){
				tot1+=k[j];
			}
			tot1+=a[i];
			if (tot1>a[i]*2){
				tot+=1;
			}
		}
		return 0;
	}
	for (int i=shu;i<n-cishu;++i){
		k[++cnt]=i;
		dfs(cishu-1,shu+1);
	}
}
int main(){
	freopen("polygun.in","r",stdin);
	freopen("polygun.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;++i) cin>>a[i];
	sort (a,a+n);
	for (int i=3;i<=n;++i){
		dfs(i,0);
		jilu=i;
	}
	cout<<tot%998244353; 
	return 0;
}

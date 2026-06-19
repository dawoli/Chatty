#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mx=0,ans=0,ans00,l=1,r,qian[5005],vis[5005];
void dfs(int i,int sum,int idx){
	if(idx>=3&&sum>a[i]*2)ans=(ans+1)%998244353;
	for(int j=i+1;j<=r;j++)dfs(j,sum+a[j],idx+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)qian[i]=qian[i-1]+a[i];
	if(mx==1){
		for(int i=3;i<=n;i++){
			ans00=1;
			for(int j=n;j>i;j--){
				ans00=(ans00*j/(n-j+1))%998244353;
			}
			ans=(ans+ans00)%998244353;
		}
		cout<<ans;
	}else{
		while(r-l+1>=3){
			dfs(l,a[l],1);
			l++;
			while(qian[r]-qian[l-1]<a[r]*2)r--;
		}
		cout<<ans;
	}
	return 0;
}

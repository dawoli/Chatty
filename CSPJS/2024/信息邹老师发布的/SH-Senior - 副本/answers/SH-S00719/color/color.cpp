#include<bits/stdc++.h>
using namespace std;
int a[20],n,ans=0;
bool ok[20];
void count(){
	int cnt=0;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(ok[i]==ok[j])
				if(a[i]==a[j])
					cnt+=a[i];
	ans=max(ans,cnt);
	return;
}
void dfs(int i){
	if(i==n+1){
		count();
		return;
	}
	ok[i]=0;
	dfs(i+1);
	ok[i]=1;
	dfs(i+1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}

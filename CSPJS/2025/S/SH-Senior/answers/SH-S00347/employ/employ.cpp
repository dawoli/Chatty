#include <bits/stdc++.h>
using namespace std;
int n,m,c[502],ans;
bool s[502];
bool check(int x,int dep,int a[]){
	for(int i=1;i<=dep;i++)
		if(a[i]==x)
			return false;
	return true; 
}
void dfs(int dep,int a[]){
	if(dep>n){
		/*for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<"\n";*/
		long long yes=0;
		for(int i=1;i<=n;i++)
			if(yes<c[a[i]]&&s[i])
				yes++;
		if(yes>=m) ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++)
		if(check(i,dep,a))
			a[dep]=i,dfs(dep+1,a);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("employ2.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ff;
		cin>>ff;
		s[i]=ff-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	int a[502]={};
	dfs(1,a);
	cout<<ans<<"\n";
	return 0;
}

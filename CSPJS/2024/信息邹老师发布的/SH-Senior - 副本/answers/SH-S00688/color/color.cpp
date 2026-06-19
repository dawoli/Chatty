#include<bits/stdc++.h>
using namespace std;
int a[200010],n,ans;
bool b[200010];
void dfs(int x,int lstb,int lstr,int s){
	if (x>n){
		if (ans<s){
			ans=s;
		}
		return;
	}
	b[x]=0;
	dfs(x+1,x,lstr,s+(a[lstb]==a[x]&&lstb!=0)*a[lstb]);
	b[x]=1;
	dfs(x+1,lstb,x,s+(a[lstr]==a[x]&&lstr!=0)*a[lstr]);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		for (int i = 1; i <= n; i++) cin>>a[i];
		ans=0;
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

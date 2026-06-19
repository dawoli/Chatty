#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
ll n,a[N],ans;
bool clr[N];
void calc() {
	ll ret=0;
	int r=0,b=0;
	for (int i=1;i<=n;++i) {
		if (clr[i]) { //r
			if (a[r]==a[i]) ret+=a[i];
			r=i;
		}
		else {
			if (a[b]==a[i]) ret+=a[i];
			b=i; 
		}
	}
	ans=max(ans,ret);
}
void dfs(int pos) {
	if (pos==n+1) {calc();return;}
	dfs(pos+1);
	clr[pos]=1;
	dfs(pos+1);
	clr[pos]=0;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while (T--) {
		memset(clr,0,sizeof clr);
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

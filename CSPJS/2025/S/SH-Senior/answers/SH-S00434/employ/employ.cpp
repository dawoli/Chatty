#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int MN=505;

int n,m,c[MN];

int a[MN],vis[MN];
int ans=0;

string s;
void dfs(int now) {
	if(now>n) {
		int cnt=0;
		for(int i=1;i<=n;++i) {
//			cout<<a[i]<<" ";
			if(cnt>=c[a[i]]) cnt++;
			else {
				if(s[i]=='0') cnt++;
			}
		}
		if((cnt+m)<=n) ans++;
		ans%=MOD;
//		cout<<"   - "<<cnt<<" "<<ans<<endl;
	} else {
		for(int i=1;i<=n;++i) {
			if(!vis[i]) {
				vis[i]=1;
				a[now]=i;
				dfs(now+1);
				vis[i]=0;
			}
		}
	}
	return;
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i) {
		scanf("%lld",&c[i]);
	}
	
	bool flagA=1;
	for(int i=1;i<=n;++i) {
		if(s[i]!='1') flagA=0;
	} 
	if(flagA==1) {	
		int nn=0;
		for(int i=1;i<=n;++i) {
			nn+=(c[i]>0);
		} 
		if(nn<m) {
			printf("0\n");
			return 0;
		}	
	}
	
	dfs(1);
	
	printf("%lld\n",ans%MOD);
	return 0;
} 

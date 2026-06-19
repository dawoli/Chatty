#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int N=100005;
int n,m,len,pre[N],a[N],c[N],_,x[10],nw[N],nxt[N];
char s[18][N];
void solve()
{
	int ans=0;
	for(int i=0;i<4;i++) cin>>x[i];
	for(int i=1;i<=n;i++) a[i]=(pre[i]^x[i%4]);
	for(int i=1;i<=m;i++)
	{
		int p=0;
		while((1<<p)<c[i]) p++;
		for(int j=1;j<=n;j++) nw[j]=j;
		for(int j=p;j>=1;j--)
		{
			for(int k=1;k<=(1<<(j-1));k++)
			{
				if(nw[2*k-1]>nw[2*k]) swap(nw[2*k-1],nw[2*k]);
				if(s[j][k]=='0')
				{
					if(a[nw[2*k-1]]>=p-j+1) nxt[k]=nw[2*k-1];
					else nxt[k]=nw[2*k];
				}
				else if(s[j][k]=='1')
				{
					if(a[nw[2*k]]>=p-j+1) nxt[k]=nw[2*k];
					else nxt[k]=nw[2*k-1];
				}
			}
			for(int k=1;k<=(1<<(j-1));k++) nw[k]=nxt[k];
		}
		ans^=(i*nw[1]);
	}
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>pre[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	while((1ll<<len)<n) len++;
	for(int i=len;i>=1;i--)
	{
		for(int j=1;j<=(1<<(i-1));j++) cin>>s[i][j];
	}
	cin>>_;
	while(_--) solve();
	return 0;
}

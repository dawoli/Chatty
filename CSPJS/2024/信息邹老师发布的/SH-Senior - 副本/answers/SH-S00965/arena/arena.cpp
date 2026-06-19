#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=1e5+5;
int t;
int n,m;
string s[32];
int a[MAXN],b[MAXN],c[MAXN];
int ans[MAXN];
int tr[MAXN*4];
int nm[MAXN];

int chg0(int x,int y,int r)
{
	if(x>y) swap(x,y);
	if(b[x]>=r) return x;
	else return y;
}

int chg1(int x,int y,int r)
{
	if(x<y) swap(x,y);
	if(b[x]>=r) return x;
	else return y;
}

void solve(int num){
	int cnt=(int)(log2(num));
	int tmp=(1<<cnt)-1;
	for(int i=1;i<=num;i++) tr[tmp+i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int con=(1<<(cnt-i+1))-1;
		for(int j=1;j<=1<<(cnt-i);j++)
		{
			if(s[i][j-1]=='1') tr[(con+j*2)/2]=chg1(tr[con+j*2-1],tr[con+j*2],i);
			else tr[(con+j*2)/2]=chg0(tr[con+j*2-1],tr[con+j*2],i);
		}
	}
}

signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	while(1<<cnt<n) cnt++;
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1;i<=cnt;i++)
		cin>>s[i];
	cin>>t;
	while(t--)
	{
		int md[4];
		for(int i=0;i<=3;i++) cin>>md[i];
		for(int i=1;i<=n;i++) b[i]=a[i]^md[i%4];
		for(int i=1;i<=m;i++)
		{
			solve(c[i]);
			ans[i]=tr[1];
		}
		int tag=ans[1]*1;
		for(int i=2;i<=m;i++) tag=tag^(ans[i]*i);
		cout<<tag<<endl;
	}
 } 

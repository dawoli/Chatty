#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m,a[N],c[N],x[10];
string s[N];
vector<int> ans[N];
int solve(int l,int r,int dep)
{
	if(l>=r)
	{
		ans[dep].push_back(l);
		return l;
	}
	int mid=(l+r)/2;
	int tl=solve(l,mid,dep-1),tr=solve(mid+1,r,dep-1);
	int uid=(l>>dep);
	int res=0;
	if(s[dep][uid]==0)
		res=(tl>=dep?tl:tr);
	else
		res=(tr>=dep?tr:tl);
	ans[dep].push_back(res);
	return res;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	int t=1,cnt=0;
	while(t*2<=n)
		t*=2,cnt++;
	for(int i=1;i<=cnt+1;i++)
		cin>>s[i];
	int T;
	cin>>T;
	while(T--)
	{
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)
			a[i]^=x[i%4];
		
		solve(0,t-1,cnt);
		int res=0;
		for(int i=1;i<=m;i++)
		{
			int j=0,k=1;
			while(k<c[i])
				j++,k*=2;
			res=res^(i*ans[j][0]);
		}
		cout<<res<<endl;
	}
}

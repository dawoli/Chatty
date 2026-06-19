#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n,m;
bool bt[18];
int p0[20],c[505],sum[20],tp;
int gb(int x,int l)
{
	int res=0;
	for(int i=0;i<l;++i)
	{
		bt[i]=x&1;
		res+=x&1;
		x>>=1;
	}
	for(int i=l-1;i>=0;--i) p0[i]=p0[i+1]+(!bt[i]);
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	char s;
	int gu=0;//give up,right choice for me
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		if(s=='0') gu++;
		else sum[tp+1]=sum[tp]+gu,++tp,gu=0;
	}
	for(int i=1;i<=n;++i)
		cin>>c[i];
	sort(c+1,c+1+n);
	int ans=0;
	for(int i=0;i<(1<<tp);++i)
	{
		if(gb(i,tp)<m) continue;
		long long res=1;
		for(int j=0;j<tp;++j)
		{
//			cout<<sum[j+1]<<' '<<p0[j]<<'\n';
			res=res*(n-(upper_bound(c+1,c+1+n,sum[tp-j]+p0[j])-c-1)-j)%MOD;
//			cout<<res<<' ';
		}
		ans=(ans+res)%MOD;
	}
	cout<<ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

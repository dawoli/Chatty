#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[4][N],ans,cnt[4],rdc[N],mxj[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(cnt,0,sizeof cnt);
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			mxj[i]=0;
			for(int j=1;j<=3;++j)
			{
				cin>>a[j][i];
				if(a[j][i]>a[mxj[i]][i]) mxj[i]=j;
			}
			ans+=a[mxj[i]][i];
			cnt[mxj[i]]++;
			int t=0;
			for(int j=1;j<=3;++j) if(j!=mxj[i]) t=max(t,a[j][i]);
			rdc[i]=a[mxj[i]][i]-t;
		}
		int mx=1;
		for(int i=2;i<=3;++i) if(cnt[i]>cnt[mx]) mx=i;
		if(cnt[mx]>n/2)
		{
			for(int i=1;i<=n;++i) if(mxj[i]!=mx) rdc[i]=1e9;
			sort(rdc+1,rdc+1+n);
			for(int i=1;i<=cnt[mx]-n/2;++i) ans-=rdc[i];
		}
		cout<<ans<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

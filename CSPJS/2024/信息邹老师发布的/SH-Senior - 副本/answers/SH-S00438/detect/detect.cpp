#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef pair<int,int> pii;
int d[N],v[N],a[N],p[N];
pii osa[N];
int bil(int n,int tar,int avd)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(p[mid]*avd<tar) l=mid+1;
		else r=mid;
	}
	return l;
}
int biu(int n,int tar,int avd)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(p[mid]*avd<=tar) l=mid+1;
		else r=mid;
	}
	return l;
}	
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		memset(osa,0,sizeof osa);
		int n,m,l,vlim,upr=-1,lwr=1e9,ans1=0;
		cin>>n>>m>>l>>vlim;
		for(int i=1;i<=n;++i)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;++i)
			cin>>p[i];
		for(int i=1;i<=n;++i)//考虑第i两车 
		{
			if(d[i]>p[m]) ++ans1;
			else if(a[i]==0)
			{
				if(v[i]<=vlim) ++ans1;
				else osa[i]=make_pair(lower_bound(p+1,p+1+m,d[i])-p,m);
			} 
			else if(a[i]>0)
			{
				int dan=biu(m,d[i]*2*a[i]+vlim*vlim-v[i]*v[i],2*a[i]);
				if(dan==m+1) ++ans1;
				else osa[i]=make_pair(dan,m);//左 
			}
			else if(a[i]<0)
			{
				int saf=bil(m,-2*d[i]*a[i]-vlim*vlim+v[i]*v[i],-2*a[i])-1,nrp=lower_bound(p+1,p+1+m,d[i])-p;
//				cout<<"!"<<saf<<"!";
				if(saf<nrp) ++ans1;
				else osa[i]=make_pair(nrp,saf);//右 
			}
		}
//		for(int i=1;i<=n;++i)
//			cout<<osa[i].first<<' '<<osa[i].second<<'\n';
		cout<<n-ans1<<' ';
		sort(osa+1,osa+1+n);
		int ge=1e9,ans2=0;
		for(int i=1;i<=n;++i)//贪心：除非区间结束否则不开测速
		{
			if(osa[i].first>ge) ++ans2,ge=1e9;
			ge=min(ge,(osa[i].second==0?int(1e9):osa[i].second));
		}
		if(ge!=1e9) ++ans2;
		cout<<m-ans2<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

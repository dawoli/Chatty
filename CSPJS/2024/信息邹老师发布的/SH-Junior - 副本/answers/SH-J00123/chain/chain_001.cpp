#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool brute(LL pre_n,LL pre_p,vector<vector<LL> >&v,LL cur,vector<vector<vector<LL> > >&memo,LL lim)
{
	if(memo[cur][pre_p+1][pre_n]!=0)
		return (memo[cur][pre_p+1][pre_n]==1?true:false);
	for(LL i=0;i<v.size();++i)
		if(pre_p!=i)
			for(LL j=v[i].size()-1;j>=1;--j)
				if(v[i][j]==pre_n)
				{
					if(cur>1)
					{
						for(LL k=j-1;k>=j-lim+1&&k>=0;--k)
							if(brute(v[i][k],i,v,cur-1,memo,lim))
							{
								memo[cur][pre_p+1][pre_n]=1;
								return true;
							}
					}
					else
					{
						for(LL k=j-1;k>=j-lim+1&&k>=0;--k)
							if(v[i][k]==1)
							{
								memo[cur][pre_p+1][pre_n]=1;
								return true;
							}
					}
				}
	memo[cur][pre_p+1][pre_n]=-1;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);	
	LL t=0;
	cin>>t;
	while(t--)
	{
		LL n,k,q;
		LL mr=0;
		LL mn=0;
		cin>>n>>k>>q;
		vector<vector<LL> >v(n);
		vector<pair<LL,LL> >task(q);
		for(LL i=0;i<n;++i)
		{
			LL tmp=0;
			cin>>tmp;
			v[i].resize(tmp);
			for(LL j=0;j<tmp;++j)
			{
				cin>>v[i][j];
				mn=max(mn,v[i][j]);
			}
		}
		for(LL i=0;i<q;++i)
		{
			cin>>task[i].first>>task[i].second;
			mr=max(mr,task[i].first);
		}
		vector<vector<vector<LL> > >memo(mr+1,vector<vector<LL> >(n+1,vector<LL>(mn+1,0)));
		for(LL i=0;i<q;++i)
		{
			cout << brute(task[i].second,-1,v,task[i].first,memo,k)<<endl;
		}
	}
	return 0;
}

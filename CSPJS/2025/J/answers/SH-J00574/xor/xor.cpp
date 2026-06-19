#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum[500001];
vector<pair<int,int> > v;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	sum[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int len=1;len<=n-i+1;len++)
		{
			if((sum[i-1]^k)==sum[i+len-1])
			{
				v.push_back({i+len-1,i});
			}
		}
	}
	sort(v.begin(),v.end());
	int maxx=v[0].first;
	cnt=1;
	int vs=v.size();
	for(int i=1;i<vs;i++)
	{
		if(v[i].second>maxx)
		{
			cnt++;
			maxx=v[i].first;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[100002],d[100002];
vector<int> attk,deff;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		if(a[m]==0)
		{
			attk.push_back(m);
			deff.push_back(m);
		}
		a[m]++;
		d[m]++;
	}
	sort(attk.begin(),attk.end());
	sort(deff.begin(),deff.end());
	int po1=0,po2=1,ans=0;
	while(po1<attk.size() && po2<deff.size())
	{
		if(attk[po1]<deff[po2])
		{
			int v=min(a[attk[po1]],d[deff[po2]]);
			a[attk[po1]]-=v;
			d[deff[po2]]-=v;
			ans+=v;
			//cout<<attk[po1]<<" "<<deff[po2]<<" "<<v<<endl;
			if(a[attk[po1]]==0) po1++;
			if(d[deff[po2]]==0) po2++;
		}
		else
		{
			po2++;
		}
	}
	cout<<n-ans;
	//printf("amd+%lld",n);
	return 0;
} 

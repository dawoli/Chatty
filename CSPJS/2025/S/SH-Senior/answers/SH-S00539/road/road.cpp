#include <bits/stdc++.h>
using namespace std;

struct road{
	int fr,to,pay;
} r[100001];

bool bmp(road x,road y)
{
	return x.pay<y.pay; 
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k,no,j=1;
	cin>>n>>m>>k;
	bool c[n+1]={};
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].fr>>r[i].to>>r[i].pay;
	} 
	
	long long ans=0;
	sort(r+1,r+m+1,bmp);
	
	while(n!=0)
	{
		if(c[r[j].to]==1 && c[r[j].fr]==1)
		{
			j++;
		}
		else
		{
			n--;
			c[r[j].fr]=1;
			c[r[j].to]=1;
			ans+=r[j].pay;
			j++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,k,cur,mn,cnt,ind;
int a[500002];
int d[500002];
int nxt[500002];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) d[i] = n+1;
	for(int i=1;i<=n;i++) cin>>a[i];	
	
	for(int i=1;i<=n;i++)
	{
		cur = 0;
		for(int j=i;j<d[i];j++)
		{
			cur ^= a[j];
			if(cur == k) 
			{
				d[i] = j;
			}
		}
	}
	
	//for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	//cout<<'\n';
	
	mn = n+1;d[n+1] = n+1;
	for(int i=n+1;i>=1;i--)
	{
		if(d[mn] > d[i]) mn = i;
		nxt[i] = d[mn];
	}
	//for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
	//cout<<'\n';
	
	ind = 1;cnt = 0;
	while(nxt[ind]<=n)
	{
		cnt++;
		ind = nxt[ind]+1;
	}
	cout<<cnt;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[100005];

int main()
{
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	
	
	
	int n;
	cin>>n;
	long long maxv=0;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		a[x]++;
		maxv=max(maxv,x);
	}
	
	int maxn=0;
	for(int i=0;i<=maxv;i++)
	{
		if(a[i]!=0)
			maxn=max(maxn,a[i]);
		
	}
	cout<<maxn<<endl;

	return 0;
}

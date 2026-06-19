#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
bool s=true;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>2) s=false;
	}	
	if(s==true)
	{
		int p=0,q=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) p++;
			if(a[i]==2) q++; 
		}
		if(q>=p) cout<<q;
		else cout<<p;
		return 0;
	}
	sort(a,a+n+1);
	for(int i=2;i<=n;i++)
	{
		s=false;
		for(int j=i-1;j>=1;j--)
		{
			if(s==false && a[i]>a[j] && a[j]!=0)
			{
				a[j]=0;
				ans--;
				s=true;
			}
		}
	}
	cout<<ans;
	return 0;	
} 

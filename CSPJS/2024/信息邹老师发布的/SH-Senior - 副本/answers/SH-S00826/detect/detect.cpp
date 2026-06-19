#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;


int main() 
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,l,V;
		cin>>n>>m>>l>>V;
		int d[100100]={};
		int v[100100]={};
		int a[100100]={};
		int p[100100]={};
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+1+m);
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]>V&&p[m]>=d[i])
			{
				ans++;
			}
		}
		cout<<ans<<" ";
		if(ans==0)
		{
			cout<<m<<endl;
		}
		else if(m-1>1)
		{
			cout<<m-1<<endl;
		}
		else if(m==1)
		{
			cout<<1<<endl;
		}
	}

	return 0;
}

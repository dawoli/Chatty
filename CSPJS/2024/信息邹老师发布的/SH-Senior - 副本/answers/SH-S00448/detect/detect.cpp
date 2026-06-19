#include<bits/stdc++.h>
using namespace std;
int d[100005]={0},v[100005]={0},a[100005]={0},p[100005]={0};
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	int n,m,L,V;
	
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			{
			if(d[i]>V)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
		cnt-=1;
		cout<<n-cnt;
	}
	return 0;
}

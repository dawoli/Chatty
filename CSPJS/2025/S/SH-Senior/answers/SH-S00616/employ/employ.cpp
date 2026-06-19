#include <bits/stdc++.h>
using namespace std;
char s[505];
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	int tag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==1)
		{
			sum++;
		}
		if(s[i]==0&&!tag1) tag1=true,tag=i;
	}
	bool tag1=false;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]; 
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
	}
	if(sum==n)
	{
		cout<<0<<endl;
		return 0;
	}
	return 0;
}

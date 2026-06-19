#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],t[505];
char s[505];
long long sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	/*for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			t[i+1]=t[i-1]+1;
			t[i]=INT_MAX;
			i++;
		}
		else t[i]=t[i-1];
		cout<<t[i];
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)cin>>c[i];
	//sort(c+1,c+n+1);
	/*for(int i=1;i<=n;i++)
	{
		if(c[i]>t[i])sum++;
		cout<<c[i];
	}
	cout<<endl<<sum<<endl;*/
	for(int i=1;i<=n;i++)
	{
		sum=sum*i%998244353;
	}
	cout<<sum<<endl;
	return 0;
} 

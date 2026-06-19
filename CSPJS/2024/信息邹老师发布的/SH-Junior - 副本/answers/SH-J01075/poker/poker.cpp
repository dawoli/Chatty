#include<bits/stdc++.h>
using namespace std;
string a[1000];
int b[1000],c[1000];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int ans=52;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i][0]=='C') b[i]=100+a[i][1]-'0';
		else if(a[i][0]=='H') b[i]=200+a[i][1]-'0';
		else if(a[i][0]=='S') b[i]=300+a[i][1]-'0';
		 else if(a[i][0]=='D') b[i]=400+a[i][1]-'0';
		if(c[b[i]]==0)
		{
			ans--;
			c[b[i]]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

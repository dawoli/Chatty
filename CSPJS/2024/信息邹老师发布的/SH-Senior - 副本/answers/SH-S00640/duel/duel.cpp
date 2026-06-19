#include<bits/stdc++.h>
using namespace std;

int n,a,ans,b,s[100005];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		//cout<<s[i]<<' ';
		if(s[i]>s[i-1])
		{
			ans=max(ans,b);
			b=0;
		}
		b++;
	}
	//cout<<endl;
	ans=max(ans,b);
	cout<<ans<<endl;
	return 0;
 } 

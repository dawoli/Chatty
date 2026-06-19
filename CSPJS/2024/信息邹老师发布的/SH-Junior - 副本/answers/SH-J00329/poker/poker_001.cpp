#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char c1[4]={'D','C','H','S'};
	char c2[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	int n,i,j,x,ans=0;
	bool f[52];
	string s;
	memset(f,0,sizeof(f));
	cin>>n;
	for(i=0;i<n;i++)
	{
		x=0;
		cin>>s;
		for(j=0;j<4;j++)
		{
			if(s[0]==c1[j])
			{
				x+=j*13;
				break;
			}
		} 
		for(j=0;j<13;j++)
		{
			if(s[1]==c2[j])
			{
				x+=j;
				break;
			}
		}
		f[x]=1;
	}
	for(i=0;i<52;i++)
		if(!f[i])
			ans++;
	cout<<ans;
	return 0;
} 

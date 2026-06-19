#include <iostream>
using namespace std;

int main()
{
	bool vis[70];
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int x=0;
		if(s[0]=='D')
		{
			x+=0;
		}
		if(s[0]=='C')
		{
			x+=13;
		}
		if(s[0]=='H')
		{
			x+=26;
		}
		if(s[0]=='S')
		{
			x+=39;
		}
		if(s[1]=='A')
		{
			x+=1;
		}
		else if(s[1]=='T')
		{
			x+=10;
		}
		else if(s[1]=='J')
		{
			x+=11;
		}
		else if(s[1]=='Q')
		{
			x+=12;
		}
		else if(s[1]=='K')
		{
			x+=13;
		}
		else 
		{
			x+=int(s[1])-48;
		}
		vis[x]=true; 
	}
	int ans=0;
	for(int i=1;i<=52;i++)
	{
		if(!vis[i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


//It's Oct.26 today.I think only T1 is easy.

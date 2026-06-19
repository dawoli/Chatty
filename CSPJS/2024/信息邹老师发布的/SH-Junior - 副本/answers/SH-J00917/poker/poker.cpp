#include <bits/stdc++.h>

using namespace std;
int box[110];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int id;
		id=0;
		if(s[0]=='S')
		{
			id+=1;
		}
		if(s[0]=='D')
		{
			id+=2;
		}
		if(s[0]=='H')
		{
			id+=3;
		}
		if(s[1]=='A')
		{
			id+=4;
		}
		if(s[1]=='T')
		{
			id+=40;
		}
		if(s[1]=='J')
		{
			id+=44;
		}
		if(s[1]=='Q')
		{
			id+=48;
		}
		if(s[1]=='K')
		{
			id+=52;
		}
		if(s[1]>='2'&&s[1]<='9')
		{
			id+=(s[1]-'0')*4; 
		}
		box[id]=true;
	}
	int ans;
	ans=0;
	for(int i=4;i<=55;i++)
	{
		if(!box[i])
		{
			ans++; 
		}
	}
	cout<<ans<<endl;
	return 0;
}

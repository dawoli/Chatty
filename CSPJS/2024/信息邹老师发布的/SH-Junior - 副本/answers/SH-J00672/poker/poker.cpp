#include<bits/stdc++.h>
using namespace std;
char color[4]={'D','C','H','S'};
char num[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	map<string,int> mp;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<13;j++)
		{
			string str="";
			str=str+color[i]+num[j];
			mp[str]=1;
		}
	}
	int n;
	cin>>n;
	char a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		string s="";
		s=s+a+b;
		mp[s]=2;
	}
	int ans=0;
	map<string,int>::iterator mit;
	for(mit=mp.begin();mit!=mp.end();mit++)
	{
		if((*mit).second==1)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

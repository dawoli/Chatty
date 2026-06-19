#include<bits/stdc++.h>
using namespace std;
char a,b;
map<pair<int,int>,int>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int fir,sec;
		if(b=='A')
		{
			sec=1;
		}
		else if(b=='T')
		{
			sec=10;
		}
		else if(b=='J')
		{
			sec=11;
		}
		else if(b=='Q')
		{
			sec=12;
		}
		else if(b=='K')
		{
			sec=13;
		}
		else
		{
			sec=b-'0';
		}
		if(a=='D')
		{
			fir=1;
		}
		else if(a=='C')
		{
			fir=2;
		}
		else if(a=='H')
		{
			fir=3;
		}
		else
		{
			fir=4;
		}
		mp[make_pair(fir,sec)]++;
		//cout<<fir<<" "<<sec<<endl;
	}
	int ans=52;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(mp[make_pair(i,j)]>=1)
			{
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
} 

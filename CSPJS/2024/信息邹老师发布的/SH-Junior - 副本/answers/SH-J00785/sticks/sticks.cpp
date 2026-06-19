#include <bits/stdc++.h>
using namespace std;
map<char,int>m;
struct tui
{
	int s;
}f[21];
void init()
{
	m['0']=6,m['1']=2,m['2']=5,m['3']=5,m['4']=4,m['5']=5,m['6']=6,m['7']=3,m['8']=7,m['9']=6;
	f[1].s=-1,f[2].s=1,f[3].s=7,f[4].s=4,f[5].s=2,f[6].s=6,f[7].s=8;
	for(int i=8;i<=21;i++) f[i].s=INT_MAX;
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			int sum=m[char(i+48)]+m[char(j+48)];
			f[sum].s=min(f[sum].s,i*10+j);
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int sum=m[char(i+48)]+m[char(j+48)]+m[char(k+48)];
				f[sum].s=min(f[sum].s,i*100+j*10+k);
			}
		}
	}
}
int all;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	init();
	while(t--)
	{
		cin>>all;
		if(all<=21) cout<<f[all].s<<"\n";
		else
		{
			switch(all%7)
			{
				case 0:
					for(int i=1;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
				case 1:
					cout<<10;
					for(int i=2;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
				case 2:
					cout<<18;
					for(int i=2;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
				case 3:
					cout<<200;
					for(int i=3;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
				case 4:
					cout<<20;
					for(int i=2;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break; 
				case 5:
					cout<<2;
					for(int i=1;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
				case 6:
					cout<<6;
					for(int i=1;i<=all/7;i++) cout<<8;
					cout<<"\n";
					break;
			}
		}
	}
	return 0;
}

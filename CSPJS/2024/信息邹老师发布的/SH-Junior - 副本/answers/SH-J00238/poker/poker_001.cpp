#include<bits/stdc++.h>
using namespace std;
int ans=52,n,cdhs,num;
bool c_[4][14];
string s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(c_,false,sizeof(c_));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		switch(s[0])
		{
			case 'C':
			{
				cdhs=0;
				break;
			}
			case 'D':
			{
				cdhs=1;
				break;
			}
			case 'H':
			{
				cdhs=2;
				break;
			}
			case 'S':
			{
				cdhs=3;
				break;
			}
		}
		if(s[1]>='2'&&s[1]<='9')
			num=s[1]-'0';
		else
		{
			switch(s[1])
			{
				case 'A':
				{
					num=1;
					break;
				}
				case 'T':
				{
					num=10;
					break;
				}
				case 'J':
				{
					num=11;
					break;
				}
				case 'Q':
				{
					num=12;
					break;
				}
				case 'K':
				{
					num=13;
					break;
				}
			}
		}
		if(!c_[cdhs][num])
		{
			c_[cdhs][num]=true;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

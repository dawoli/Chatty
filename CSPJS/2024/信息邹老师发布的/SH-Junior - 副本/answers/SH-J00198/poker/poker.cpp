#include<bits/stdc++.h>
using namespace std;
int n;
int ans=52;
string s[52];
string st;
int flag;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>st;
		for(int j=1;j<=l;j++)
		{
			if(st==s[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			l++;
			ans--;
			s[l]=st;
		}
	}
	cout<<ans<<endl;
	return 0;
}

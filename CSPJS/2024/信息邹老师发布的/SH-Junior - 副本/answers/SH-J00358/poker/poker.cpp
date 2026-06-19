#include<bits/stdc++.h>
using namespace std;
string s[155];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n, cnt=0;
	cin>>n;
	string b;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[i]==s[j])
			{
				cnt++;
			}
		}
	}
	cout<<52-n+cnt;
	return 0;
}

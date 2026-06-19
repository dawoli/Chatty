#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[60];
bool f;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		f=0;
		for(int j=1;j<i;j++)
			if(s[j]==s[i])
			{
				f=1;
				break;
			}
		if(f==0)
		{
			ans++;
		}
	}
	printf("%d\n",52-ans);
	return 0;
}

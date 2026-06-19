#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	string s[54];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int p=0;
		cin>>s[i];
		for(int j=1;j<i;j++)
		{
			if(s[i]!=s[j]) p=0;
			else
			{
				p=1;
				break;
			}
		}
		if(p==0) cnt++;
	}
	printf("%d\n",52-cnt);
	return 0;
}

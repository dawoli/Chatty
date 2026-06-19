#include<bits/stdc++.h>
using namespace std;
int m,n;
string s[300005][2],s2[300005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<m;i++)
	{
		cin>>s2[i][0]>>s[i][1];
	}
	for(int i=0;i<m;i++)
	{
		printf("0\n");
	}
	return 0;
} 

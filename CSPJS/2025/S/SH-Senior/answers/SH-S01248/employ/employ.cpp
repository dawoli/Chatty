#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int c[1000001];

int jc(int a)
{
	if(a==0) return a+1;
	return a*jc(a-1);
}

int main()
{
	memset(c,0,sizeof(c));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char s[n];
	scanf("%s",&s);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<jc(n-1);
	return 0;
}

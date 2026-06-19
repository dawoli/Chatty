#include<bits/stdc++.h>
using namespace std;
int r[100005],sum=1,cnt;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)r[i]=read();
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(r[i]==r[i+1])
		{
			cnt=1;
			while(r[i]==r[i+1])
			{
				cnt++;
				i++;
			}
			if(cnt>sum)sum=cnt;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

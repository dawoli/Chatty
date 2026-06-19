#include <bits/stdc++.h>
using namespace std;
const int q=1e5+100;
int num;
int mon[q];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>num;
	for(int i=0;i<num;i++)
		cin>>mon[i];
	sort(mon,mon+num);
	int bef=0,noww=0,ans=0,stal=0,maxzhi=0;
	for(int i=0;i<num;i++)
	{
		int defnow=mon[i];
		bef=noww;
		noww=0;
		while(mon[i]==defnow&&i<=num)
		{
			i++;
			noww++;
		}
		i--;
		if(noww<=bef)
		{
			ans+=noww;
			stal+=(bef-noww);
		}
		else
		{
			ans+=bef;
			noww-=bef;
			ans+=min(noww,stal);
			stal=max(0,stal-noww);
		}
	}
	cout<<num-ans;
}

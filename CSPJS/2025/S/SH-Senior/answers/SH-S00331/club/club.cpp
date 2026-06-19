#include <bits/stdc++.h>
using namespace std;
struct p
{
	int a1,a2,a3;
};
const int MAXN=1e5+20;
p pe[MAXN]={0,0,0};
bool compare1(int a,int b)
{
	return a>b;
}
bool Compare(p a,p b)
{
	if(a.a1!=b.a1) return a.a1>b.a1;
	else return a.a2>b.a2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=0;
	cin>>T;
	for(int z=1;z<=T;z++)
	{
		int n=0,ans=0;
		int temp[5]={0};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>temp[1]>>temp[2]>>temp[3];
			sort(temp+1,temp+4,compare1);
			pe[i].a1=temp[1];
			pe[i].a2=temp[2];
			pe[i].a3=temp[3];
		}
		/*
		for(int i=1;i<=n;i++)
		{
			cout<<pe[i].a1<<" "<<pe[i].a2<<" "<<pe[i].a3<<endl;
		}
		*/
		sort(pe+1,pe+n+1,Compare);
		for(int i=1;i<=(n/2);i++)
		{
			ans+=pe[i].a1;
		}
		for(int i=(n/2)+1;i<=n;i++)
		{
			ans+=pe[i].a2;
		}
		cout<<ans<<endl;	
	}
	return 0;	
} 

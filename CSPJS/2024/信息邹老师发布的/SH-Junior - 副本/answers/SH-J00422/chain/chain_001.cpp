#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,l,a[200009],r,c;
struct cn
{
	int p1,n1,p2,n2,t;
	bool operator<(const cn x)const
	{
		return t>x.t;
	}
};
bool dfs(int p,int x,int m)
{
	if(m==r&&x==c)return 1;
	if(m==r)return 0;
	set<cn>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		int p1=it->p1,n1=it->n1,p2=it->p2,n2=it->n2,t=it->t;
		if(n1==x&&p1!=p&&m+t<=r&&dfs(p2,n2,m+t))return 1;
	}
	return 0;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++)
	{
		set<cn> s;
		cin>>n>>k>>q;
		for(int p=1;p<=n;p++)
		{
			cin>>l;
			for(int i=1;i<=l;i++)cin>>a[i];
			for(int i=1;i<=l-k+1;i++)
				for(int j=i+1;j<=l;j++)
					s.insert((cn){p,a[i],p,a[j],1});
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			cout<<dfs(0,1,0)<<endl;
		} 
	}
	return 0;
}

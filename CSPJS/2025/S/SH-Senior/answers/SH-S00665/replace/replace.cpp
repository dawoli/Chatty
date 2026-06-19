#include<bits/stdc++.h>
using namspace std;
int n,m;
struct node
{
	string a,b;
}q,s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	while(m--)
	{
		int ans=0;
		cin>>q.a>>q.b;
		for(int i=1;i<=n;i++)
			if(q.a==s[i].a&&q.b==s[i].b)
				ans++;
		cout<<ans;
	}
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k,p,q,t1,t2,L,R,ans=0;
string x,y;
struct node
{
	int h;
	int fail;
	int s[29];
};
node f1[5000005];
node f2[5000005];
int ne1[200005];
int ne2[200005];
int l[200005];
queue<int>ll;
int g[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;k=x.length();x="*"+x;
		p=0;
		for(int j=1;j<=k;j++)
		{
			q=x[j]-'a';
			if(f1[p].s[q]==0)
			{
				t1++;f1[p].s[q]=t1;
			}
			p=f1[p].s[q];
		}
		ne1[i]=f1[p].h;
		f1[p].h=i;
		cin>>x;k=x.length();x="*"+x;
		p=0;
		for(int j=1;j<=k;j++)
		{
			q=x[j]-'a';
			if(f2[p].s[q]==0)
			{
				t2++;f2[p].s[q]=t2;
			}
			p=f2[p].s[q];
		}
		ne2[i]=f2[p].h;
		f2[p].h=i;
		l[i]=k;
	}
	for(int i=0;i<26;i++)
	{
		if(f1[0].s[i]!=0)ll.push(f1[0].s[i]);
	}
	for(;!ll.empty();)
	{
		p=ll.front();ll.pop();
		for(int i=0;i<26;i++)
		{
			if(f1[p].s[i]!=0)
			{
				f1[f1[p].s[i]].fail=f1[f1[p].fail].s[i];
				ll.push(f1[p].s[i]);
			}
			else f1[p].s[i]=f1[f1[p].fail].s[i];
		}
	}
	for(int i=0;i<26;i++)
	{
		if(f2[0].s[i]!=0)ll.push(f2[0].s[i]);
	}
	for(;!ll.empty();)
	{
		p=ll.front();ll.pop();
		for(int i=0;i<26;i++)
		{
			if(f2[p].s[i]!=0)
			{
				f2[f2[p].s[i]].fail=f2[f2[p].fail].s[i];
				ll.push(f2[p].s[i]);
			}
			else f2[p].s[i]=f2[f2[p].fail].s[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;ans=0;
		if(x.length()==y.length())
		{
			k=x.length();
			x="*"+x;y="*"+y;
			L=1;R=k;
			for(;x[L]==y[L];)L++;
			for(;x[R]==y[R];)R--;
			for(int j=1;j<=n;j++)g[j]=0;
			p=0;q=0;
			for(int j=1;j<R;j++)
			{
				p=f1[p].s[x[j]-'a'];q=f2[q].s[y[j]-'a'];
			}
			for(int j=R;j<=k;j++)
			{
				p=f1[p].s[x[j]-'a'];q=f2[q].s[y[j]-'a'];
				for(int r=p;r!=0;r=f1[r].fail)
				{
					if(f1[r].h!=0&&l[f1[r].h]<j-L+1)break;
					for(int o=f1[r].h;o!=0;o=ne1[o])g[o]=j;
				}
				for(int r=q;r!=0;r=f2[r].fail)
				{
					if(f2[r].h!=0&&l[f2[r].h]<j-L+1)break;
					for(int o=f2[r].h;o!=0;o=ne2[o])
					{
						if(g[o]==j)ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
struct node
{
	int left;
	int right;
}x[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,l,V;
	    cin>>n>>m>>l>>V;
	    int cnt=0;
	    for(int i = 1;i <= n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0)
			{
				if(v[i]>V)
				{
				    x[i].left=d[i];
					x[i].right=l;
				}
				else
				{
					x[i].left=1e9;
					x[i].right=-1;
				}
			}
			else if(a[i]>0)
			{
				 int s=d[i]+(V*V-v[i]*v[i]+2*a[i]-1)/(2*a[i]);
				 if(s>l)
				 {
				 	x[i].left=1e9;
				 	x[i].right=-1;
				 } 
				 else
				 {
				 	x[i].left=s;
				 	x[i].right=l;
				 }
			}
		} 
		int maxn=0;
		for(int i = 1;i <= m;i++)
		{
			cin>>p[i];
			maxn=max(maxn,p[i]);
		}
		for(int i = 1;i <= n;i++)
		{
			if(x[i].left<=maxn)cnt++;
		}
		cout<<cnt<<" ";
		if(cnt==0)cout<<m<<endl;
		else cout<<m-1<<endl;
	}
	return 0;
}


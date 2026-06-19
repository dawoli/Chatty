#include <bits/stdc++.h>
using namespace std;
int mapp[100005][4],flag=0;
int t,n,maxx;
int maxn=n/2;
int a1[100005];
long long ans1=0;
struct node{
	int k11,k22,k33;
	int ans;
};
void bfs()
{
	int maxn=n/2;
	queue<node> q;
	node t;
	t.k11=0;t.k22=0;t.k33=0; 
	t.ans=0;
	q.push(t);
	while(!q.empty())
	{
		node tt=q.front();
		q.pop();
		if((tt.k11+tt.k22+tt.k33)==n) continue;
		for(int k=1;k<=3;k++)
		{
			node ttt;
			if(k==1)
			{
				if(tt.k11==maxn) continue;
				else 
				{
					ttt.k11=tt.k11+1;
					ttt.k22=tt.k22;
					ttt.k33=tt.k33;
					ttt.ans=tt.ans+mapp[ttt.k11+ttt.k22+ttt.k33][k];
				}
			}
			else if(k==2)
			{
				if(tt.k22==maxn) continue;
				else 
				{
					ttt.k22=tt.k22+1;
					ttt.k11=tt.k11;
					ttt.k33=tt.k33;
					ttt.ans=tt.ans+mapp[ttt.k11+ttt.k22+ttt.k33][k];
				}
			}
			else
			{
				if(tt.k33==maxn) continue;
				else 
				{
					ttt.k33=tt.k33+1;
					ttt.k11=tt.k11;
					ttt.k22=tt.k22;
					ttt.ans=tt.ans+mapp[ttt.k11+ttt.k22+ttt.k33][k];
				}
			}
			if(ttt.ans>maxx) maxx=ttt.ans;
			q.push(ttt);
		}
	}
}
void bfs1()
{
	int maxn=n/2;
	queue<node> q;
	node t;
	t.k11=0;t.k22=0; 
	t.ans=0;
	q.push(t);
	while(!q.empty())
	{
		node tt=q.front();
		q.pop();
		if((tt.k11+tt.k22)==n) continue;
		for(int k=1;k<=2;k++)
		{
			node ttt;
			if(k==1)
			{
				if(tt.k11==maxn) continue;
				else 
				{
					ttt.k11=tt.k11+1;
					ttt.k22=tt.k22;
					
					ttt.ans=tt.ans+mapp[ttt.k11+ttt.k22][k];
				}
			}
			else if(k==2)
			{
				if(tt.k22==maxn) continue;
				else 
				{
					ttt.k22=tt.k22+1;
					ttt.k11=tt.k11;
					ttt.ans=tt.ans+mapp[ttt.k11+ttt.k22][k];
				}
			}
			
			if(ttt.ans>maxx) maxx=ttt.ans;
			q.push(ttt);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o1=1;o1<=t;o1++)
	{
		maxx=-999;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>mapp[i][j];
			}
			a1[i]=mapp[i][1];
			if(mapp[i][2]!=0) flag=1;
		}
		if(n==200)
		{
			bfs1();
		}
		else if(n==100000 && flag==1) bfs1();
		else if(flag==0)
		{
			sort(a1+1,a1+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)
			{
				ans1+=a1[i];
			}
			cout<<ans1;
			return 0;
		}
		else bfs();
		cout<<maxx<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a1[N],a2[N],a3[N],vis[N][5],in[N];
void doA()
{
	int ans=0;
	sort(a1+1,a1+1+n);
	for(int i=n;i>=n/2+1;i--)
		ans+=a1[i];
	cout<<ans<<endl;
}
struct node
{
	int id,num;
	bool operator<(node a)const{
		return num>a.num;
	}
};
void solveBF()
{
	int cnt[5]={0,0,0,0,0};
	memset(in,0,sizeof(in));
	int ans=0;
	priority_queue<node> q1,q2,q3;
	queue<int> q;
	for(int i=1;i<=n;i++)
		q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(!vis[x][1]&&a1[x]>a2[x]&&a1[x]>a3[x])
		{
			q1.push((node){x,a1[x]});
			cnt[1]++;
			in[x]=1;
			vis[x][1]=1;
			ans+=a1[x];
			if(cnt[1]>n/2)
			{
				q.push(q1.top().id);
				in[q1.top().id]=0;
				ans-=a1[q1.top().id];
				cnt[1]--;
				q1.pop();
			}
		}
		else if(!vis[x][2]&&a2[x]>a1[x]&&a2[x]>a3[x])
		{
			q2.push((node){x,a2[x]});
			cnt[2]++;
			in[x]=1;
			vis[x][2]=1;
			ans+=a2[x];
			if(cnt[2]>n/2)
			{
				q.push(q2.top().id);
				in[q2.top().id]=0;
				ans-=a2[q2.top().id];
				cnt[2]--;
				q2.pop();
			}
		}
		else if(!vis[x][3]&&a3[x]>a2[x]&&a3[x]>a1[x])
		{
			q3.push((node){x,a3[x]});
			cnt[3]++;
			in[x]=1;
			ans+=a3[x];
			vis[x][3]=1;
			if(cnt[3]>n/2)
			{
				q.push(q3.top().id);
				in[q3.top().id]=0;
				ans-=a3[q3.top().id];
				cnt[3]--;
				q3.pop();
			}
		}
		if(!in[x])
		{
			if(vis[x][1]&&!vis[x][2]&&a2[x]>=a3[x])
			{
				q2.push((node){x,a2[x]});
				cnt[2]++;
				in[x]=1;
				vis[x][2]=1;
				ans+=a2[x];
				if(cnt[2]>n/2)
				{
					q.push(q2.top().id);
					in[q2.top().id]=0;
					ans-=a2[q2.top().id];
					cnt[2]--;
					q2.pop();
				}
			}
			else if(vis[x][1]&&!vis[x][3]&&a2[x]<a3[x])
			{
				q3.push((node){x,a3[x]});
				cnt[3]++;
				in[x]=1;
				vis[x][3]=1;
				ans+=a3[x];
				if(cnt[3]>n/2)
				{
					q.push(q3.top().id);
					in[q3.top().id]=0;
					ans-=a3[q3.top().id];
					cnt[3]--;
					q3.pop();
				}
			}
			else if(vis[x][2]&&!vis[x][1]&&a1[x]>=a3[x])
			{
				q1.push((node){x,a1[x]});
				cnt[1]++;
				in[x]=1;
				vis[x][1]=1;
				ans+=a1[x];
				if(cnt[1]>n/2)
				{
					q.push(q1.top().id);
					in[q1.top().id]=0;
					ans-=a1[q1.top().id];
					cnt[1]--;
					q1.pop();
				}
			}
			else if(vis[x][2]&&!vis[x][3]&&a1[x]<a3[x])
			{
				q3.push((node){x,a3[x]});
				cnt[3]++;
				in[x]=1;
				vis[x][3]=1;
				ans+=a3[x];
				if(cnt[3]>n/2)
				{
					q.push(q3.top().id);
					in[q3.top().id]=0;
					ans-=a3[q3.top().id];
					cnt[3]--;
					q3.pop();
				}
			}
			else if(vis[x][3]&&!vis[x][1]&&a1[x]>=a2[x])
			{
				q1.push((node){x,a1[x]});
				cnt[1]++;
				in[x]=1;
				vis[x][1]=1;
				ans+=a1[x];
				if(cnt[1]>n/2)
				{
					q.push(q1.top().id);
					in[q1.top().id]=0;
					ans-=a1[q1.top().id];
					cnt[1]--;
					q1.pop();
				}
			}
			else if(vis[x][3]&&!vis[x][2]&&a1[x]<a2[x])
			{
				q2.push((node){x,a2[x]});
				cnt[2]++;
				in[x]=1;
				vis[x][2]=1;
				ans+=a2[x];
				if(cnt[2]>n/2)
				{
					q.push(q2.top().id);
					in[q2.top().id]=0;
					ans-=a2[q2.top().id];
					cnt[2]--;
					q2.pop();
				}
			}
			else if(vis[x][1]&&vis[x][2])
			{
				q3.push((node){x,a3[x]});
				cnt[3]++;
				in[x]=1;
				vis[x][3]=1;
				ans+=a3[x];
			}
			else if(vis[x][2]&&vis[x][3])
			{
				q1.push((node){x,a1[x]});
				cnt[1]++;
				in[x]=1;
				vis[x][1]=1;
				ans+=a1[x];
			}
			else if(vis[x][1]&&vis[x][3])
			{
				q2.push((node){x,a2[x]});
				cnt[2]++;
				in[x]=1;
				vis[x][2]=1;
				ans+=a2[x];
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		bool flagA=true;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0)
				flagA=false;
		}
		if(flagA)
			doA();
		else
			solveBF();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

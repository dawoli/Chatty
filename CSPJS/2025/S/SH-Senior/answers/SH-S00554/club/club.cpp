#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n;
int a[N][5]={0};
int mst[N]={0};
int mstn[5]={0};
struct node{
	int frm;
	int dc;
	int num;
	friend bool operator <(node s1,node s2)
	{
		if(s1.dc==s2.dc)
		{
			return s1.num>=s2.num;
		}
		return s1.dc>=s2.dc;
	}
};
bool vis[N]={0};
priority_queue <node> pq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(mstn,0,sizeof(mstn));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2])
			{
				if(a[i][1]>=a[i][3])
				{
					mst[i]=1;
					mstn[1]++;
				}
				else
				{
					mst[i]=3;
					mstn[3]++;
				}
			}
			else
			{
				if(a[i][2]>=a[i][3])
				{
					mst[i]=2;
					mstn[2]++;
				}
				else
				{
					mst[i]=3;
					mstn[3]++;
				}
			}
		}
		int lmt=n>>1;
		int mr=0;
		int mi1=0,mi2=0;
		if(mstn[1]>lmt)
		{
			mr=1;
			mi1=2;
			mi2=3;
		}
		if(mstn[2]>lmt)
		{
			mr=2;
			mi1=1;
			mi2=3;
		}
		if(mstn[3]>lmt)
		{
			mr=3;
			mi1=1;
			mi2=2;
		}
		if(mr==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][mst[i]];
			}
			printf("%d\n",ans);
			continue;
		}
		node inn;
		for(int i=1;i<=n;i++)
		{
			if(mst[i]!=mr) continue;
			inn.frm=i;
			inn.dc=a[i][mr]-a[i][mi1];
			inn.num=mi1;
			pq.push(inn);
			inn.dc=a[i][mr]-a[i][mi2];
			inn.num=mi2;
			pq.push(inn);
		}
		int cnt1=mstn[mi1],cnt2=mstn[mi2];
		int cnt=mstn[mr];
		while(!pq.empty())
		{
			node nw=pq.top();
			pq.pop();
			if(vis[nw.frm]) continue;
			if(nw.num==mi1&&cnt1>=lmt) continue;
			if(nw.num==mi2&&cnt2>=lmt) continue;
			vis[nw.frm]=1;
			mst[nw.frm]=nw.num;
			cnt--;
			if(cnt<=lmt) break;
			if(nw.num==mi1) cnt1++;
			if(nw.num==mi2) cnt2++;
		}
		while(!pq.empty()) pq.pop();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][mst[i]];
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

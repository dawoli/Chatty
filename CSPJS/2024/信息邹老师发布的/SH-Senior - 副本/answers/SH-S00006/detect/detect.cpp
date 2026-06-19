#include <bits/stdc++.h>
using namespace std;
const int q=1e5+100;
struct chao
{
	int b;
	int e;
}ca[q];
int moni[q];
int t;
int ans,nowans,illcar;
int n,m,L,V,cnt,maxcnt;
int ica[q];
bool caught[q];
void dfs(int step)
{
	if(step==m)
	{
//		cout<<cnt<<" "<<nowans<<endl;
		if(maxcnt<cnt)
		{
			maxcnt=cnt;
			ans=nowans;
		}
		else if(cnt==maxcnt)
			ans=min(ans,nowans);
		return;
	}
	memset(ica,0,sizeof(ica));
	int use=0;
	for(int i=0;i<illcar;i++)
	{
		if(caught[i])
			continue;
		if(ca[i].b<=moni[step]&&moni[step]<=ca[i].e)
		{
			cnt++;
			ica[use]=i;
			use++;
			caught[i]=true;
		}
	}
	if(use>0)
	{
		nowans++;
		dfs(step+1);
		nowans--;
		cnt-=use;
		for(int i=0;i<use;i++)
			caught[i]=false;
	}
	memset(ica,0,sizeof(ica));
	dfs(step+1);
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		cin>>n>>m>>L>>V;
		memset(ca,0,sizeof(ca));
		illcar=0;
		for(int i=0;i<n;i++)
		{
			int loc,v0,dv;
			cin>>loc>>v0>>dv;
			if(v0>V&&dv>=0)
			{
				ca[illcar].b=loc;
				ca[illcar++].e=L;
			}
			else if(v0==V&&dv>0&&loc<L)
			{
				ca[illcar].b=loc+1;
				ca[illcar++].e=L;
			}
			else if(dv!=0)
			{
				double s=(V*V-v0*v0)/(2.0*dv);
				if(v0<V&&dv>0)
				{
					s+=loc+0.000001;
					int temp=s;
					if(s<L)
					{
						ca[illcar].b=max(loc,temp);
						ca[illcar++].e=L;
					}
				}
				else if(v0>V&&dv<0)
				{
					int temp=s-0.000001;
					ca[illcar].b=loc;
					ca[illcar++].e=min(L,temp+loc);
				}
			}
		}
//		for(int i=0;i<illcar;i++)
//		{
//			cout<<ca[i].b<<" "<<ca[i].e<<endl;
//		}
		memset(moni,0,sizeof(moni));
		for(int i=0;i<m;i++)
			cin>>moni[i];
		maxcnt=0;
		ans=m;
		nowans=0;
		cnt=0;
		memset(caught,0,sizeof(caught));
		dfs(0);
		cout<<maxcnt<<" "<<ans<<endl;
		t--;
	}
}

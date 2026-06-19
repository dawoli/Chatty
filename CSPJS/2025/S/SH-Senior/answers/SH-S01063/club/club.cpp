#include <bits/stdc++.h>
using namespace std;
int t,n,cb[4],bz[100001],ans;
struct node
{
	int a,b,c,x;
}club[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n;
		cb[1]=cb[2]=cb[3]=0;
		ans=0;
		for(int j=1;j<=n;j++) bz[j]=0;
		for(int j=1;j<=n;j++)
		{
			cin >> club[j].a >> club[j].b >> club[j].c;
			int y=max(club[j].a,max(club[j].b,club[j].c));
			if(y==club[j].a) club[j].x=1;
			else if(y==club[j].b) club[j].x=2;
			else club[j].x=3;
			cb[club[j].x]++;
			ans+=y;
		}
		int bao=0;
		if(cb[1]>n/2) bao=1;
		if(cb[2]>n/2) bao=2;
		if(cb[3]>n/2) bao=3;
		int k=cb[bao]-n/2,cnt=0;
		if(bao!=0)
		{
			for(int j=1;j<=n;j++)
			{
				if(club[j].x!=bao) continue;
				if(bao==1) bz[++cnt]=min(club[j].a-club[j].b,club[j].a-club[j].c);
				else if(bao==2) bz[++cnt]=min(club[j].b-club[j].a,club[j].b-club[j].c);
				else bz[++cnt]=min(club[j].c-club[j].b,club[j].c-club[j].a);
			}
			sort(bz+1,bz+cnt+1);
			for(int j=1;j<=k;j++) ans-=bz[j];
		}
		cout << ans << endl;
	}
} 

#include<bits/stdc++.h>
using namespace std;
struct pt{
	int lft,rgt;
	//lft:start considering as too fast;
	//rgt:stop considering as too fast(1000003 as +infinity);
	//considering (0,0) as never too fast;
} fst[100003],nd[100003];
bool cmp(pt cmp1,pt cmp2)
{
	return cmp1.lft<cmp2.lft||(cmp1.lft==cmp2.lft&&cmp1.rgt<cmp2.rgt);
}
int t,m,n,l,mxv,ans;
int mntr[1000006]; //monitor(s)
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int z = 1;z<=t;z++)
	{
		memset(fst,0,sizeof(fst));
		memset(mntr,0,sizeof(mntr));
		ans = 0;
		scanf("%d%d%d%d",&n,&m,&l,&mxv);
		for(int i = 1;i<=n;i++)
		{
			int d,v,a;
			scanf("%d%d%d",&d,&v,&a);
			if(v>mxv)  //calc the too-fast-place(st~ed)
			{
				fst[i].lft = d-1;
				if(a>=0)
				{
					fst[i].rgt = 1000003;
				}
				else
				{
					fst[i].rgt = d + (mxv*mxv-v*v+1)/(2*a);
				}
			}
			else
			{
				if(a<=0)
				{
					fst[i].lft = 0;
					fst[i].rgt = 0;
				}
				else
				{
					fst[i].rgt = 1000003;
					fst[i].lft = d + (mxv*mxv-v*v-1)/(2*a)+1;
				}
			}
		}
		int p;
		for(int i = 1;i<=m;i++)
		{
			scanf("%d",&p);
			++mntr[p];
		}
		for(int i = 1;i<=1000003;i++) mntr[i] += mntr[i-1];
		for(int i = 0;i<=n;i++)
		{
			int left = mntr[fst[i].lft];
			int right = mntr[fst[i].rgt];
			if(right!=left)
			{
				ans++;
				nd[ans].lft = left;
				nd[ans].rgt = right;
			}
		}
		printf("%d ",ans);
		
		//第一部分性能：约2M一个点，合格
		sort(nd+1,nd+ans+1,cmp);
		int cnt = 1;
		for(int i = 2;i<=ans;i++)
		{
			if(nd[i-1].rgt-nd[i].lft<=0)
			{
				cnt++;
			}
			else
			{
				nd[i].rgt = min(nd[i].rgt,nd[i-1].rgt);
			}
		}
		if(ans==0) cnt = 0;
		printf("%d\n",m-cnt);
		//第2部分炸了O(nlogn),约17M 
	}
	//总之，过不过的去很玄，因为第一部分常数大，第二部分常数小 
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/

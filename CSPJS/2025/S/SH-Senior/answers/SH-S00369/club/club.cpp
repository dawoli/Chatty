#include <bits/stdc++.h>
using namespace std;
const int MM = 100005;
int t,n,a[MM],b[MM],c[MM],cnta,cntb,cntc;
long long ans;
struct node{
	int aa,bb,cc;
	int maxn;
};
node memb[MM];
bool cmpa1(int x,int y){
	return (memb[x].aa-memb[x].bb) < (memb[y].aa - memb[y].bb);}
bool cmpa2(int x,int y){
	return (memb[x].aa-memb[x].cc) < (memb[y].aa - memb[y].cc);}
bool cmpb1(int x,int y){
	return (memb[x].bb-memb[x].aa) < (memb[y].bb - memb[y].aa);}
bool cmpb2(int x,int y){
	return (memb[x].bb-memb[x].cc) < (memb[y].bb - memb[y].cc);}
bool cmpc1(int x,int y){
	return (memb[x].cc-memb[x].aa) < (memb[y].cc - memb[y].aa);}
bool cmpc2(int x,int y){
	return (memb[x].cc-memb[x].bb) < (memb[y].cc - memb[y].bb);}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int tim = 1; tim <= t; tim ++)
	{
		int x; ans = 0;
		scanf("%d",&x);
		n = x;
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
		cnta = cntb = cntc = 0;
		int lim = n/2;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d%d%d",&memb[i].aa,&memb[i].bb,&memb[i].cc);
			memb[i].maxn = max(max(memb[i].aa,memb[i].bb),memb[i].cc);
			if(memb[i].maxn == memb[i].aa) a[++cnta] = i;
			else if(memb[i].maxn == memb[i].bb) b[++cntb] = i;
			else c[++cntc] = i;
			ans += memb[i].maxn;
		}
		if(cnta <= lim && cntb <= lim && cntc <= lim){
			printf("%lld\n",ans);
			continue;
		}
		int i = 1;
		if(cnta > lim){
			sort(a+1,a+1+cnta,cmpa1);
			while(cntb <= lim && cnta > lim){
				cntb ++;
				cnta --;
				b[cntb] = a[i];
				ans -= (memb[a[i]].aa - memb[a[i]].bb);
				i ++;
			}
			if(cnta > lim){
				sort(a+i,a+1+n,cmpa2);
				while(cnta > lim){
					cnta --;
					ans -= (memb[a[i]].aa - memb[a[i]].cc);
				}
			}
		}
		i = 1;
		if(cntb > lim){
			sort(b+1,b+1+cntb,cmpb1);
			while(cnta <= lim && cntb > lim){
				cnta ++;
				cntb --;
				a[cntb] = b[i];
				ans -= (memb[b[i]].bb - memb[b[i]].aa);
				i ++;
			}
			if(cntb > lim){
				sort(b+i,b+1+n,cmpb2);
				while(cntb > lim){
					cntb --;
					ans -= (memb[b[i]].bb - memb[b[i]].cc);
				}
			}
		}
		i = 1;
		if(cntc > lim){
			sort(c+1,c+1+cntc,cmpc1);
			while(cnta <= lim && cntc > lim){
				cnta ++;
				cntc --;
				a[cntb] = c[i];
				ans -= (memb[c[i]].aa - memb[c[i]].bb);
				i ++;
			}
			if(cntc > lim){
				sort(c+i,c+1+n,cmpc2);
				while(cntc > lim){
					cntc --;
					ans -= (memb[c[i]].aa - memb[c[i]].cc);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+20;
const int MAXM=2e5+20;
int n;
int cnt[MAXM];

inline void cjh_input()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int t;
		scanf("%d",&t);
		cnt[t]++;
	}
	return;
} 

int nw;
inline void cjh_solve()
{
	for(int i=0;i<MAXM;++i)
	{
		nw=max(0,nw-cnt[i]);
		nw+=cnt[i];
	}
	return;
}


inline void cjh_output()
{
	printf("%d\n",nw);
	return;
}


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cjh_input();
	cjh_solve();
	cjh_output();
	
	return 0;
}

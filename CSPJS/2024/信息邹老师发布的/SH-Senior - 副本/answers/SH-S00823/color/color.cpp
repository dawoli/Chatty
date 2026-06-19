#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;
int n;
int T;
int c[MAXN];
bool a[MAXN];

inline void cjh_input()
{
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
	}
	return;
} 

int cjh_solve(int dep)
{
	if(dep==n)
	{
		int lbn,lrn;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
//			cout<<ans<<" ";
			if(a[i]==0)
			{
				if(lbn==c[i])ans+=c[i];
				lbn=c[i];
			}
			else
			{
				if(lrn==c[i])ans+=c[i];
				lrn=c[i];
			}
		}
//		cout<<endl;
		return ans;
	}
	a[dep]=0;
	int t1=cjh_solve(dep+1);
	a[dep]=1;
	int t2=cjh_solve(dep+1);
	return max(t1,t2);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	for(int jj=0;jj<T;++jj)
	{
		cjh_input();
		cout<<cjh_solve(1)<<endl;
	}
	
	return 0;
}

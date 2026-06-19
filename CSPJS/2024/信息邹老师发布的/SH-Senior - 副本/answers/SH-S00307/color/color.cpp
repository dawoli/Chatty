#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int t,n;
int a[N];
bool color[N];//1red0blue
long long maxs;

long long cntmax(void)
{
	int nred=0,nblue=0;
	long long score=0;
	for(int i=1;i<=n;i++)
	{
		if(color[i])
		{
			if(a[nred] == a[i])	score+=a[i];
			nred=i;
		}
		else
		{
			if(a[nblue] == a[i]) score+=a[i];
			nblue=i;
		}
	}
	return score;
}

void dfs(int pl)
{
	if(pl == n+1)
	{
		maxs=max(maxs,cntmax());
		return;
	}
	color[pl]=true;
	dfs(pl+1);
	color[pl]=false;
	dfs(pl+1);
	return;
}


int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(color,false,sizeof(color));
		maxs=0;
		cin >> n;
		for(int i=1;i<=n;i++)	cin >> a[i];
		dfs(1);
		cout << maxs << endl;
	}
	return 0;
}


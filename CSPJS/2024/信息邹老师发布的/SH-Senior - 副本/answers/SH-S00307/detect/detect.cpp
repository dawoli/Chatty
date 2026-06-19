#include<bits/stdc++.h>
using namespace std;

int t;
const int N=1e5+10,M=1e5+10;
int n,m;
int L,V;//车辆数，测速仪数，主干道长，道路限速
int d[N],v[N],a[N];//车起点，初速度，加速度 
int p[M];//测速仪位置 
int tot=0;

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		tot=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++)	scanf("%d",&p[i]);
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)	if(v[i] > V && p[m] >= d[i])	tot++;
		printf("%d %d\n",tot,m-1);
	}
	return 0;
}

